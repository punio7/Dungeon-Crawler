#pragma once
#include <string>

class Log4CppLogger
{
public:
	Log4CppLogger();
	virtual ~Log4CppLogger();
	bool Init(std::string initFileName);
	void LogDebug(std::string message);
	void LogInfo(std::string message);
};