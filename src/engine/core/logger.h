#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "engine/define.h"

typedef enum {
	LOG_TYPE_FATAL,
	LOG_TYPE_ERROR,
	LOG_TYPE_WARNING,
	LOG_TYPE_INFO,
	LOG_TYPE_DEBUG,
	LOG_TYPE_TRACE
} log_type_t;

b8 log_init(uint64_t *memory_require, void *state);
void log_shut(void *state);

void log_output(log_type_t type, const char *message, ...);

#define ar_FATAL(message, ...)                                                 \
  log_output(LOG_TYPE_FATAL, message, ##__VA_ARGS__);

#define ar_ERROR(message, ...)                                                 \
  log_output(LOG_TYPE_ERROR, message, ##__VA_ARGS__);

#define ar_WARNING(message, ...)                                               \
  log_output(LOG_TYPE_WARNING, message, ##__VA_ARGS__);

#define ar_INFO(message, ...) log_output(LOG_TYPE_INFO, message, ##__VA_ARGS__);

#define ar_DEBUG(message, ...)                                                 \
  log_output(LOG_TYPE_DEBUG, message, ##__VA_ARGS__);

#define ar_TRACE(message, ...) 												   \
	log_output(LOG_TYPE_TRACE, message, ##__VA_ARGS__);

#endif //__LOGGER_H__
