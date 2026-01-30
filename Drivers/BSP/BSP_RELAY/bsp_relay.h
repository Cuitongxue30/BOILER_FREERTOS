/**
 * @file bsp_relay.h
 * @author Antares (cuitongxue30@gmail.com)
 * @brief 开关量继电器驱动
 * @version 0.1
 * @date 2026-01-27
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef __BSP_RELAY_H
#define __BSP_RELAY_H

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

typedef enum
{
    RELAY_ID_UP_FUEL = 0,
    RELAY_ID_DOWN_FUEL,
    RELAY_ID_CTRL_FUEL,
    RELAY_ID_FIRE_FUEL,
    RELAY_ID_GRATE,
    RELAY_ID_BLOW,
    RELAY_ID_INDUCE,
    RELAY_ID_SEBLOW,
    RELAY_ID_BUMP,
    RELAY_ID_LOOP,
    RELAY_ID_DESLAG,
    RELAY_ID_MAX,
} RelayId_t;

typedef enum
{
    RELAY_STATE_OFF = 0,
    RELAY_STATE_ON,
} RelayState_t;

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
    uint16_t ActiveLevel;
    RelayState_t CurrentState;
} RelayObj_t;

#define RELAY_COUNT_MAX RELAY_ID_MAX
void BSP_Relay_SetState(RelayId_t id, RelayState_t state);
void BSP_Relay_ToggleState(RelayId_t id);
RelayState_t BSP_Relay_GetState(RelayId_t id);

#endif // __BSP_RELAY_H
