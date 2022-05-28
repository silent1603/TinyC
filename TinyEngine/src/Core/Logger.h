#ifndef LOGGER_H
#define LOGGER_H

#include "define.h"
typedef enum log_level{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;


#define LOG_WARN_ENABLED = 1
#define LOG_INFO_ENABLED = 1
#define LOG_DEBUG_ENABLED = 1
#define LOG_TRACE_ENABLED = 1


b8 initalize_logging();
void shutdown_logging();


TAPI void log_output(log_level level,const char* message , ...);

#define TFATAL(message,...) log_output(LOG_LEVEL_FATAL,message, ##__VA_ARGS__); 

#ifndef TERROR
#define TERROR(message,...) log_output(LOG_LEVEL_ERROR,message, ##__VA_ARGS__); 
#endif // ! TERROR


#ifdef  LOG_WARN_ENABLED == 1
#define TWARN(message,...) log_output(LOG_LEVEL_WARN,message, ##__VA_ARGS__); 
#else
#define TWARN(message,...) 
#endif // ! LOG_WARN_ENABLED == 1

#ifdef  LOG_INFO_ENABLED == 1
#define TINFO(message,...) log_output(LOG_LEVEL_INFO,message, ##__VA_ARGS__); 
#else
#define TINFO(message,...) 
#endif // ! LOG_WARN_ENABLED == 1

#ifdef  LOG_DEBUG_ENABLED == 1
#define TDEBUG(message,...) log_output(LOG_LEVEL_DEBUG,message, ##__VA_ARGS__); 
#else
#define TDEBUG(message,...) 
#endif // ! LOG_WARN_ENABLED == 1

#ifdef  LOG_TRACE_ENABLED == 1
#define TTRACE(message,...) log_output(LOG_LEVEL_TRACE,message, ##__VA_ARGS__); 
#else
#define TTRACE(message,...) 
#endif // ! LOG_WARN_ENABLED == 1

#endif