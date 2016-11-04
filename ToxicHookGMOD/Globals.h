#pragma once
#include "CBaseEntity.h"

class Globals
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Globals"/> class.
	/// </summary>
	Globals();
	
	/// <summary>
	/// Gets the Hack Version.
	/// </summary>
	/// <returns>The Hack Version</returns>
	Version GetVersion();

	/// <summary>
	/// Finalizes an instance of the <see cref="Globals"/> class.
	/// </summary>
	~Globals();

	CBaseEntity* LocalPlayer;
};
extern Globals* g_pGlobals;