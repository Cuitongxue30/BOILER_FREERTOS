#include "bsp_relay.h"


static RelayObj_t RelayList[RELAY_COUNT_MAX] =
    {
        {
            .port = UP_RELAY_GPIO_Port,
            .pin = UP_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = DOWN_RELAY_GPIO_Port,
            .pin = DOWN_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = CTRL_RELAY_GPIO_Port,
            .pin = CTRL_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = FIRE_RELAY_GPIO_Port,
            .pin = FIRE_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = GRATE_RELAY_GPIO_Port,
            .pin = GRATE_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = BLOW_RELAY_GPIO_Port,
            .pin = BLOW_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = INDUCE_RELAY_GPIO_Port,
            .pin = INDUCE_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = SEBLOW_RELAY_GPIO_Port,
            .pin = SEBLOW_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = BUMP_RELAY_GPIO_Port,
            .pin = BUMP_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = LOOP_RELAY_GPIO_Port,
            .pin = LOOP_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
        {
            .port = DESLAG_RELAY_GPIO_Port,
            .pin = DESLAG_RELAY_Pin,
            .ActiveLevel = 1,
            .CurrentState = RELAY_STATE_OFF,
        },
};

void BSP_Relay_SetState(RelayId_t id, RelayState_t state)
{
    if (id >= RELAY_COUNT_MAX)
    {
        return;
    }

    RelayObj_t *relay = &RelayList[id];
    if (state == RELAY_STATE_ON)
    {
        HAL_GPIO_WritePin(relay->port, relay->pin, (relay->ActiveLevel) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(relay->port, relay->pin, (relay->ActiveLevel) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
    relay->CurrentState = state;
}

void BSP_Relay_ToggleState(RelayId_t id)
{
    if (id >= RELAY_COUNT_MAX)
    {
        return;
    }

    RelayState_t new_state = (RelayList[id].CurrentState == RELAY_STATE_ON) ? RELAY_STATE_OFF : RELAY_STATE_ON;
    BSP_Relay_SetState(id, new_state);
}

RelayState_t BSP_Relay_GetState(RelayId_t id)
{
    if (id >= RELAY_COUNT_MAX)
    {
        return RELAY_STATE_OFF;
    }

    return RelayList[id].CurrentState;
}
