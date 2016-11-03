#include "Includes.h"


Logger::Logger()
{
}

void Logger::Initialize()
{
	if (AllocConsole())
	{
		freopen("CONOUT$", "w", stderr);
		freopen("CONOUT$", "w", stdout);
		freopen("CONIN$", "r", stdin);
	}
	else
	{
		MessageBoxA(NULL, "Failed to allocate a Console! Terminating...", NULL, NULL);

		g_pHackManager->Stop();

		exit(1);
	}

	Version ver = g_pGlobals->GetVersion();
	
	char buffer[80];
	sprintf(buffer, "ToxicHook Garrys Mod Edition v%i.%i.%i by Lasertrap", ver.m_iMajor, ver.m_iMinor, ver.m_iBuild);

	SetConsoleTitleA(buffer);
}

void Logger::Log(const char* format, ...)
{
	va_list va;
	va_start(va, format);
	std::string str = "[" + g_pUtils->GetFormattedTime("%H:%S:%M") + "] " + g_pUtils->ArgListToString(format, va);
	printf((str + "\n").c_str());
	va_end(va);
}

void Logger::Terminate()
{
	fclose(stdout);
	fclose(stdin);
	fclose(stderr);

	FreeConsole();
}

Logger::~Logger()
{
}
