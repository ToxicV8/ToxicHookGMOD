#pragma once
#include "Windows.h"
#define BADPTR(x) IsBadCodePtr((FARPROC)x)
typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

template<class T> class VTable
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="VTableHook"/> class.
	/// </summary>
	/// <param name="iface">The Pointer of the Interface.</param>
	VTable(T* iface)
	{
		m_pInterface = iface;

		m_pBasePtr = reinterpret_cast<DWORD**>(m_pInterface); // Save the base

		m_pOldVTable = reinterpret_cast<DWORD*>(*m_pBasePtr); // Store the pointer to the old vtable

		for (m_dwVTableSize = 0; m_pOldVTable[m_dwVTableSize]; m_dwVTableSize++) // Get the Size of the VTable
		{
			if (BADPTR(m_pOldVTable[m_dwVTableSize]))
				break;
		}

		m_pNewVTable = new DWORD[m_dwVTableSize]; // allocate space

		memcpy(m_pNewVTable, m_pOldVTable, m_dwVTableSize * sizeof(DWORD)); // Copy the content of the old vtable to the new one

		*m_pBasePtr = m_pNewVTable; // Set the VTable Pointer to the new VTable	

		g_pLogger->Log("Found ClientModeShared at 0x%.8X", (DWORD)m_pInterface);
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="VTable"/> class.
	/// </summary>
	/// <param name="module">The module.</param>
	/// <param name="interfaceName">Name of the interface.</param>
	VTable(std::string module, std::string interfaceName)
	{
		CreateInterfaceFn fn = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(GetModuleHandleA(module.c_str()), "CreateInterface"));

		m_pInterface = reinterpret_cast<T*>(fn(interfaceName.c_str(), 0)); 

		m_pBasePtr = reinterpret_cast<DWORD**>(m_pInterface); // Save the base

		m_pOldVTable = reinterpret_cast<DWORD*>(*m_pBasePtr); // Store the pointer to the old vtable

		for (m_dwVTableSize = 0; m_pOldVTable[m_dwVTableSize]; m_dwVTableSize++) // Get the Size of the VTable
		{
			if (BADPTR(m_pOldVTable[m_dwVTableSize]))
				break;
		}

		m_pNewVTable = new DWORD[m_dwVTableSize]; // allocate space

		memcpy(m_pNewVTable, m_pOldVTable, m_dwVTableSize * sizeof(DWORD)); // Copy the content of the old vtable to the new one

		*m_pBasePtr = m_pNewVTable; // Set the VTable Pointer to the new VTable

		g_pLogger->Log("Found %s at 0x%.8X", interfaceName.c_str(), (DWORD)m_pInterface);
	}
	
	/// <summary>
	/// Get the Interface.
	/// </summary>
	/// <returns>The Interface</returns>
	T* Interface()
	{
		return m_pInterface;
	}

	/// <summary>
	/// Replaces the Address of the function at the specified index with the Address of the new Function.
	/// </summary>
	/// <param name="index">The index.</param>
	/// <param name="newAddress">The new address.</param>
	/// <returns>State of Success</returns>
	bool HookFunction(int index, DWORD newAddress)
	{
		if (m_pOldVTable && m_pNewVTable && index <= m_dwVTableSize) // check pointers
		{
			m_pNewVTable[index] = newAddress;
			return true;
		}

		return false;
	}
	
	/// <summary>
	/// Get a function from the original VTable.
	/// </summary>
	/// <param name="index">The index of the function.</param>
	/// <returns>The function from the original VTable with the specified Index</returns>
	template<typename F>
	F GetFunction(int index)
	{
		return (F)m_pOldVTable[index];
	}

	/// <summary>
	/// Restores the Address of the function at the specified index. Rehook will not restore this function!
	/// </summary>
	/// <param name="index">The index.</param>
	void Unhook(int index)
	{
		if (m_pOldVTable && m_pNewVTable && index <= m_dwVTableSize)
			m_pNewVTable[index] = m_pOldVTable[index];
	}
	
	/// <summary>
	/// Restores the old VTable.
	/// </summary>
	void Unhook()
	{
		if (m_pBasePtr)
			*m_pBasePtr = m_pOldVTable;
	}

	/// <summary>
	/// Apply the new VTable again.
	/// </summary>
	void Rehook()
	{
		if (m_pBasePtr)
			*m_pBasePtr = m_pNewVTable;
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="VTableHook"/> class.
	/// </summary>
	~VTable()
	{
		if (m_pBasePtr)
		{
			*m_pBasePtr = m_pOldVTable;

			delete m_pNewVTable; // free Memory
			delete m_pInterface;
		}
	}

private:
	DWORD *m_pOldVTable, *m_pNewVTable; // The Arrays holding the function adresses
	T* m_pInterface; // The Pointer to the VTable
	DWORD** m_pBasePtr;
	DWORD m_dwVTableSize; // The Size of the VTable 
};

