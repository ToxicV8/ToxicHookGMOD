#pragma once
#include "SDK.h"



class IBaseClientDLL
{
public:
	ClientClass* GetAllClasses()
	{
		return g_pUtils->GetVirtualFunction<ClientClass*(__thiscall*)(void*)>(8, this)(this);
	}
};
extern VTable<IBaseClientDLL> *g_pBaseClientDLL;

#define CLIENT_DLL_INTERFACE_VERSION		"VClient017"