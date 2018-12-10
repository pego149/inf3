#pragma once

enum eLogLevel { INFO, WARNING, ERROR, DEBUG };

class ILogger
{
public:
	virtual void Log(eLogLevel level, const char* text) = 0;
	virtual ~ILogger() {};
};

extern ILogger* logger;