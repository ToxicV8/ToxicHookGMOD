#include "Includes.h"

Utilities::Utilities()
{
}

std::string Utilities::ArgListToString(const char* format, va_list va)
{
	std::string buffer;
	int length;
	va_list apStrLen;
	va_copy(apStrLen, va);
	length = vsnprintf(NULL, 0, format, apStrLen);
	va_end(apStrLen);
	if (length > 0) {
		buffer.resize(length);
		vsnprintf((char *)buffer.data(), buffer.size() + 1, format, va);
	}

	return buffer;
}

std::string Utilities::GetFormattedTime(const char* format)
{
	time_t rtime;
	struct tm * timeinfo;
	char buffer[80]; 
	time(&rtime);
	timeinfo = localtime(&rtime);
	strftime(buffer, 80, format, timeinfo); 
	return std::string(buffer);
}


Utilities::~Utilities()
{
}
