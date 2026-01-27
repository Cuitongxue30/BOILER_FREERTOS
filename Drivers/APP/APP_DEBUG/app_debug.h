/**
 * @file app_debug.h
 * @author Antares (cuitongxue30@gmail.com)
 * @brief printf debug
 * @version 0.1
 * @date 2026-01-27
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef __APP_DEBUG_H
#define __APP_DEBUG_H

#include "usart.h"
#include "stdio.h"
#include "stdarg.h"

#define DEBUG_ENABLE 1
#ifdef DEBUG_ENABLE
#define DEBUG_PRINT(format, ...) printf("[%s:%d]" format "\r\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

#endif // __APP_DEBUG_H
