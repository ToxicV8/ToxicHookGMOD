#pragma once


/// <summary>
/// Struct contains Major-, Minor- and Buildversion
/// </summary>
struct Version
{
	Version(int major, int minor, int build)
	{
		m_iMajor = major;
		m_iMinor = minor;
		m_iBuild = build;
	}

	int m_iMajor;
	int m_iMinor;
	int m_iBuild;
};