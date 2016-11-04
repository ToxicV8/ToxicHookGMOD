#pragma once
#include "SDK.h"



class IBaseClientDLL
{
public:
	ClientClass* GetAllClasses()
	{
		typedef ClientClass*(__thiscall* Fn)(void*);
		return g_pUtils->GetVirtualFunction<Fn>(8, this)(this);
	}
};
extern VTable<IBaseClientDLL> *g_pBaseClientDLL;