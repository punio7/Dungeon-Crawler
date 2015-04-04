#pragma once
#include <string>

class Log4CppLogger
{
public:
	Log4CppLogger();
	virtual ~Log4CppLogger();
	bool Init(std::wstring initFileName);
	void LogDebug(std::wstring message);
	void LogInfo(std::wstring message);
};