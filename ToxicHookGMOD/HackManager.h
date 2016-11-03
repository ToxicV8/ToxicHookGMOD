#pragma once
class HackManager
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="HackManager"/> class.
	/// </summary>
	HackManager();

	/// <summary>
	/// Starts the Hack.
	/// </summary>
	void Start();

	/// <summary>
	/// Stops the Hack.
	/// </summary>
	void Stop();

	/// <summary>
	/// Finalizes an instance of the <see cref="HackManager"/> class.
	/// </summary>
	~HackManager();
};
extern HackManager* g_pHackManager;

