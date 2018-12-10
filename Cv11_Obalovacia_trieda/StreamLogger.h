#pragma once
#include <fstream>
#include "ILogger.h"

using namespace std;

class StreamLogger : public ILogger
{
	ofstream *aFLog;
	void writelog(const char* level, const char* text);
public:
	StreamLogger(const char* menoSuboru);
	virtual ~StreamLogger();

	// Inherited via ILogger
	virtual void Log(eLogLevel level, const char * text) override;
};

