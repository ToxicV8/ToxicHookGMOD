#pragma once
#include "SDK.h"

class IClientUnknown : public IHandleEntity
{
public:
	virtual void*		GetCollideable() = 0;
	virtual IClientNetworkable*	GetClientNetworkable() = 0;
	virtual void*	GetClientRenderable() = 0;
	virtual IClientEntity*		GetIClientEntity() = 0;
	virtual void*		GetBaseEntity() = 0;
	virtual void*	GetClientThinkable() = 0;
};
