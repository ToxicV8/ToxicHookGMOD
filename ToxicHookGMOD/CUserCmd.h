#pragma once
#include "SDK.h"

class CUserCmd
{
public:
	virtual ~CUserCmd() { };
	int		command_number;
	int		tick_count;
	QAngle	viewangles;
	float	forwardmove;
	float	sidemove;
	float	upmove;
	int		buttons;
	byte    impulse;
	int		weaponselect;
	int		weaponsubtype;
	int		random_seed;
	short	mousedx;
	short	mousedy;
	bool	hasbeenpredicted;
	char	padding[284];


	inline bool* context()
	{
		return (bool*)((char*)this + 0x5A);
	}

	inline Vector* contextaim()
	{
		return (Vector*)((char*)this + 0x5C);
	}

	inline char* mousewheel()
	{
		return (char*)((char*)this + 0x59);
	}
};
