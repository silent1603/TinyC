#include "Logger.h"
#include "Platform/platform.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initalize_logging() {
	return TRUE;
}

void shutdown_logging()
{

}

TAPI void log_output(log_level level, const char* message, ...)
{
	const char* levelString[6] = { "[FATAL]: ","[ERROR]: " ,"[WARN]: " ,"[INFO]: " ,"[DEBUG]: " ,"[TRACE]: " };
	b8 isError = level < LOG_LEVEL_WARN ;
	char buffer_message[5000];
	memset(buffer_message, 0, sizeof(buffer_message));
	va_list arg_ptr;
	va_start(arg_ptr, message);
	vsnprintf(buffer_message, 5000,message, arg_ptr);
	va_end(arg_ptr);
	char out_message[5000];
	sprintf(out_message, "%s%s\n", levelString[level], buffer_message);
	if (isError)
	{
		platform_console_write_error(out_message, level);
	}
	else {
		platform_console_write(out_message,level);
	}
}