/**
 * @file app_freertos.h
 * @author Antares (cuitongxue30@gmail.com)
 * @brief 应用层实时系统
 * @version 0.1
 * @date 2026-01-27
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef __APP_FREERTOS_H
#define __APP_FREERTOS_H

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "bsp_key.h"
#include "bsp_relay.h"
#include "app_debug.h"
#include "app_mode.h"

void vTask_KeyScan(void *pvParameters);
void App_FreeRTOS_Start(void);

#endif // __APP_FREERTOS_H
