#include "bsp_key.h"

Button_t ButtonList[] =
    {
        {
            .port = MODE_KEY_GPIO_Port,
            .pin = MODE_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_MODE,
            .id_longEvent = NULL,
        },
        {
            .port = UP_KEY_GPIO_Port,
            .pin = UP_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_UP_FUEL,
            .id_longEvent = NULL,
        },
        {
            .port = DOWN_KEY_GPIO_Port,
            .pin = DOWN_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_DOWN_FUEL,
            .id_longEvent = NULL,
        },
        {
            .port = CTRL_KEY_GPIO_Port,
            .pin = CTRL_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_CTRL_FUEL,
            .id_longEvent = NULL,
        },
        {
            .port = FIRE_KEY_GPIO_Port,
            .pin = FIRE_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_FIRE_FUEL,
            .id_longEvent = NULL,
        },
        {
            .port = GRATE_KEY_GPIO_Port,
            .pin = GRATE_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_GRATE,
            .id_longEvent = NULL,
        },
        {
            .port = BLOW_KEY_GPIO_Port,
            .pin = BLOW_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_BLOW,
            .id_longEvent = NULL,
        },
        {
            .port = SEBLOW_KEY_GPIO_Port,
            .pin = SEBLOW_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_SEBLOW,
            .id_longEvent = NULL,
        },
        {
            .port = INDUCE_KEY_GPIO_Port,
            .pin = INDUCE_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_INDUCE,
            .id_longEvent = NULL,
        },
        {
            .port = BUMP_KEY_GPIO_Port,
            .pin = BUMP_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_BUMP,
            .id_longEvent = NULL,
        },
        {
            .port = LOOP_KEY_GPIO_Port,
            .pin = LOOP_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_LOOP,
            .id_longEvent = NULL,
        },
        {
            .port = DESLAG_KEY_GPIO_Port,
            .pin = DESLAG_KEY_Pin,
            .active_level = 0,
            .state = KEY_STATE_IDLE,
            .time = 0,
            .mode = KEY_MODE_TRIGGER_UP,
            .id_shortEvent = KEY_EVENT_DESLAG,
            .id_longEvent = NULL,
        },
};

uint8_t Botton_Process_Signal(Button_t *button)
{
    uint8_t current_level = HAL_GPIO_ReadPin(button->port, button->pin);
    uint8_t is_pressed = (current_level == button->active_level) ? 1 : 0;
    uint8_t return_id = 0;
    switch (button->state)
    {
    case KEY_STATE_IDLE:
        if (is_pressed)
        {
            button->state = KEY_STATE_DEBOUNCE;
            button->time = 0;
        }
        break;
    case KEY_STATE_DEBOUNCE:
        if (is_pressed)
        {
            button->state = KEY_STATE_PRESSED;
            if (button->mode == KEY_MODE_TRIGGER_DOWN)
            {
                return_id = button->id_shortEvent;
            }
        }
        else
        {
            button->state = KEY_STATE_IDLE;
        }
        break;
    case KEY_STATE_PRESSED:
        if (is_pressed)
        {
            if (button->mode == KEY_MODE_LONG_PRESS)
            {
                button->time++;
                if (button->time >= PRESS_THRESHOLD)
                {
                    return_id = button->id_longEvent;
                    button->state = KEY_STATE_WAIT_RELEASE;
                }
            }
            else if (button->mode == KEY_MODE_TRIGGER_UP)
            {
                return_id = button->id_shortEvent;
            }
        }
        break;
    case KEY_STATE_WAIT_RELEASE:
        if (!is_pressed)
        {
            button->state = KEY_STATE_IDLE;
        }
        break;
    }
    return return_id;
}
uint8_t Key_Scan_All(void)
{
    uint8_t event = 0;
    for (int i = 0; i < BUTTON_COUNT; i++)
    {
        event = Botton_Process_Signal(&ButtonList[i]);
        if (event != 0)
        {
            return event;
        }
    }
    return 0;
}
void Key_Init(void)
{
    // 按键初始化在gpio.c中完成，此处无需重复初始化
}
