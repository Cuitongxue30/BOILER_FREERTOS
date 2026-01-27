/**
 * @file app_mode.h
 * @author Antares (cuitongxue30@gmail.com)
 * @brief 模式切换
 * @version 0.1
 * @date 2026-01-27
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef __APP_MODE_H
#define __APP_MODE_H

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "app_debug.h"
#include "bsp_key.h"
#include "bsp_relay.h"

typedef enum
{
    SYS_MODE_HANDLE = 0,
    SYS_MODE_AUTO,
} SysMode_t;

SysMode_t GetSysMode(void);
void App_Mode_HandleEvent(uint8_t event);

#endif // __APP_MODE_H
