#pragma once


class HookManager
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="HookManager"/> class.
	/// </summary>
	HookManager();

	/// <summary>
	/// Hook Interfaces
	/// </summary>
	void Hook();

	/// <summary>
	/// Finalizes an instance of the <see cref="HookManager"/> class.
	/// </summary>
	~HookManager();
};

extern HookManager* g_pHookManager;