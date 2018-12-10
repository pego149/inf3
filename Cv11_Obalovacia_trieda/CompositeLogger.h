#pragma once
#include "StreamLogger.h"
class CompositeLogger :	public ILogger
{
private:
	ILogger *sLogger;
	ILogger *cLogger;
public:
	CompositeLogger();
	virtual ~CompositeLogger() override;

	// Inherited via ILogger
	virtual void Log(eLogLevel level, const char * text) override;
};

