#pragma once
class Logger
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Logger"/> class.
	/// </summary>
	Logger();
	
	/// <summary>
	/// Initializes this instance.
	/// </summary>
	void Initialize();

	/// <summary>
	/// Logs the specified format.
	/// </summary>
	/// <param name="format">The format.</param>
	/// <param name="">The arguments</param>
	void Log(const char* format, ...);

	/// <summary>
	/// Terminates this instance.
	/// </summary>
	void Terminate();

	/// <summary>
	/// Finalizes an instance of the <see cref="Logger"/> class.
	/// </summary>
	~Logger();
};

extern Logger* g_pLogger;