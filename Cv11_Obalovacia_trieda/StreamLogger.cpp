#include "StreamLogger.h"
#include <ctime>
#include <iostream>

void StreamLogger::writelog(const char * level, const char * text)
{
	time_t cas(time(nullptr));
	char* sCas = ctime(&cas);
	sCas[strlen(sCas) - 1] = '\0';
	if (aFLog)
	{
		*aFLog << level << "[" << sCas << "]" << text << endl;
	}
	else
	{
		cout << level << "[" << sCas << "]" << text << endl;
	}
}

StreamLogger::StreamLogger(const char * menoSuboru)
	:aFLog(menoSuboru && *menoSuboru ? new ofstream(menoSuboru, ios_base::app | ios_base::out) : nullptr)
{
}

StreamLogger::~StreamLogger()
{
	delete aFLog;
}

void StreamLogger::Log(eLogLevel level, const char * text)
{
	switch (level)
	{
	case INFO:
		writelog("INFO:   ", text);
		break;
	case WARNING:
		writelog("WARNING:", text);
		break;
	case ERROR:
		writelog("ERROR:  ", text);
		break;
#ifdef _DEBUG
	case DEBUG:
		writelog("DEBUG:  ", text);
		break;
#endif // _DEBUG
	}
}
