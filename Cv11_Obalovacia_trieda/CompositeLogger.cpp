#include "CompositeLogger.h"



CompositeLogger::CompositeLogger()
	:sLogger(new StreamLogger("C:\\temp\\pole.log")),
	cLogger(new StreamLogger(nullptr))
{
}


CompositeLogger::~CompositeLogger()
{
	delete sLogger;
	delete cLogger;
}

void CompositeLogger::Log(eLogLevel level, const char * text)
{
	if (cLogger)
	{
		cLogger->Log(level, text);
	}
	if (sLogger)
	{
		sLogger->Log(level, text);
	}
}
