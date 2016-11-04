#pragma once
#define READ_NETVAR(X, Y) *reinterpret_cast<X*>(reinterpret_cast<DWORD>(this) + GET_NETVAR(Y))

class CBaseEntity
{
	/// <summary>
	/// Prevents a default instance of the <see cref="CBaseEntity"/> class from being created.
	/// </summary>
	CBaseEntity();

	/// <summary>
	/// Gets the origin.
	/// </summary>
	/// <returns>The Origin</returns>
	Vector GetOrigin();

	/// <summary>
	/// Gets the health.
	/// </summary>
	/// <returns>Entity Health</returns>
	int GetHealth();

	/// <summary>
	/// Gets the team.
	/// </summary>
	/// <returns>The Team</returns>
	int GetTeam();

	/// <summary>
	/// Determines whether the Entity is visible from the specified Start.
	/// </summary>
	/// <param name="start">The start.</param>
	/// <returns>
	///   <c>true</c> if the Entity is visible from the Start Point; otherwise, <c>false</c>.
	/// </returns>
	bool IsVisible(Vector start);

	/// <summary>
	/// Finalizes an instance of the <see cref="CBaseEntity"/> class.
	/// </summary>
	~CBaseEntity();
};