#pragma once
class InterfaceManager
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="InterfaceManager"/> class.
	/// </summary>
	InterfaceManager();

	/// <summary>
	/// Finds the interfaces.
	/// </summary>
	void FindInterfaces();

	/// <summary>
	/// Cleanups this instance.
	/// </summary>
	void Cleanup();

	/// <summary>
	/// Finalizes an instance of the <see cref="InterfaceManager"/> class.
	/// </summary>
	~InterfaceManager();
};

extern InterfaceManager* g_pInterfaceManager;