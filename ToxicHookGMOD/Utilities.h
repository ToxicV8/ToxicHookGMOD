#pragma once
class Utilities
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Utilities"/> class.
	/// </summary>
	Utilities();

	/// <summary>
	/// Arguments the list to a string.
	/// </summary>
	/// <param name="format">The format.</param>
	/// <param name="va">The va.</param>
	/// <returns>The Formatted text as String</returns>
	std::string ArgListToString(const char* format, va_list va);

	/// <summary>
	/// Gets the formatted time.
	/// </summary>
	/// <param name="format">The format.</param>
	/// <returns>
	/// The Formatted Time
	/// </returns>
	std::string GetFormattedTime(const char* format);

	/// <summary>
	/// Finalizes an instance of the <see cref="Utilities"/> class.
	/// </summary>
	~Utilities();
};
extern Utilities* g_pUtils;
