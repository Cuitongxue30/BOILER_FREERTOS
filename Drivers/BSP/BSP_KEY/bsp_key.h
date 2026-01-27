/**
 * @file bsp_key.h
 * @author Antares (cuitongxue30@gmail.com)
 * @brief 控制工业按键控制
 * @version 0.1
 * @date 2026-01-27
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

typedef enum
{
    KEY_EVENT_NONE = 0,
    KEY_EVENT_UP_FUEL,
    KEY_EVENT_DOWN_FUEL,
    KEY_EVENT_CTRL_FUEL,
    KEY_EVENT_FIRE_FUEL,
    KEY_EVENT_GRATE,
    KEY_EVENT_BLOW,
    KEY_EVENT_SEBLOW,
    KEY_EVENT_INDUCE,
    KEY_EVENT_BUMP,
    KEY_EVENT_LOOP,
    KEY_EVENT_DESLAG,
    KEY_EVENT_MODE,
} KeyEventID_t;
typedef enum
{
    KEY_MODE_TRIGGER_UP = 0,
    KEY_MODE_TRIGGER_DOWN,
    KEY_MODE_LONG_PRESS,
} KeyMode_t;

typedef enum
{
    KEY_STATE_IDLE = 0,
    KEY_STATE_DEBOUNCE,
    KEY_STATE_PRESSED,
    KEY_STATE_WAIT_RELEASE,
} KeyState_t;

typedef struct
{
    GPIO_TypeDef *port;    /* GPIO端口 */
    uint16_t pin;          /* GPIO引脚 */
    uint8_t active_level;  /* 有效电平 */
    KeyState_t state;      /* 按键状态 */
    uint32_t time;         /* 计时器 */
    KeyMode_t mode;        /* 按键模式 */
    uint8_t id_shortEvent; /* 短按事件ID */
    uint8_t id_longEvent;  /* 长按事件ID */
} Button_t;

#define BUTTON_COUNT (sizeof(ButtonList) / sizeof(Button_t))
#define PRESS_THRESHOLD 50

uint8_t Botton_Process_Signal(Button_t *button);
uint8_t Key_Scan_All(void);
void Key_Init(void);

#endif // __BSP_KEY_H
