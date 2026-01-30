#include "app_mode.h"

static SysMode_t sys_mode = SYS_MODE_HANDLE;
SysMode_t GetSysMode(void)
{
    return sys_mode;
}
void App_Mode_HandleEvent(uint8_t event)
{
    SysMode_t current_mode = GetSysMode();
    switch (event)
    {
    case KEY_EVENT_MODE:
        if (current_mode == SYS_MODE_HANDLE)
        {
            current_mode = SYS_MODE_AUTO;
        }
        else
        {
            current_mode = SYS_MODE_HANDLE;
        }
        break;
    case KEY_EVENT_UP_FUEL:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_UP_FUEL);
        }
        else
        {
        }
        break;
    case KEY_EVENT_DOWN_FUEL:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_DOWN_FUEL);
        }
        else
        {
        }
        break;
    case KEY_EVENT_CTRL_FUEL:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_CTRL_FUEL);
        }
        else
        {
        }
        break;
    case KEY_EVENT_FIRE_FUEL:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_FIRE_FUEL);
        }
        else
        {
        }
        break;
    case KEY_EVENT_GRATE:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_GRATE);
        }
        else
        {
        }
        break;
    case KEY_EVENT_BLOW:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_BLOW);
        }
        else
        {
        }
        break;
    case KEY_EVENT_INDUCE:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_INDUCE);
        }
        else
        {
        }
        break;
    case KEY_EVENT_SEBLOW:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_SEBLOW);
        }
        else
        {
        }
        break;
    case KEY_EVENT_BUMP:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_BUMP);
        }
        else
        {
        }
        break;
    case KEY_EVENT_LOOP:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_LOOP);
        }
        else
        {
        }
        break;
    case KEY_EVENT_DESLAG:
        if (current_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_DESLAG);
        }
        else
        {
        }
        break;
    }
}
