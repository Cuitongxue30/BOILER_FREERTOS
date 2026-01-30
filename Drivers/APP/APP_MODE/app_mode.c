#include "app_mode.h"

static SysMode_t sys_mode = SYS_MODE_HANDLE;
SysMode_t GetSysMode(void)
{
    return sys_mode;
}
void App_Mode_HandleEvent(uint8_t event)
{
    switch (event)
    {
    case KEY_EVENT_MODE:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            sys_mode = SYS_MODE_AUTO;
        }
        else
        {
            sys_mode = SYS_MODE_HANDLE;
        }
        break;
    case KEY_EVENT_UP_FUEL:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_UP_FUEL);
        }
        else
        {
        }
        break;
    case KEY_EVENT_DOWN_FUEL:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_DOWN_FUEL);
        }
        else
        {
        }
        break;
    case KEY_EVENT_CTRL_FUEL:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_CTRL_FUEL);
        }
        else
        {
        }
        break;
    case KEY_EVENT_FIRE_FUEL:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_FIRE_FUEL);
        }
        else
        {
        }
        break;
    case KEY_EVENT_GRATE:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_GRATE);
        }
        else
        {
        }
        break;
    case KEY_EVENT_BLOW:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_BLOW);
        }
        else
        {
        }
        break;
    case KEY_EVENT_INDUCE:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_INDUCE);
        }
        else
        {
        }
        break;
    case KEY_EVENT_SEBLOW:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_SEBLOW);
        }
        else
        {
        }
        break;
    case KEY_EVENT_BUMP:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_BUMP);
        }
        else
        {
        }
        break;
    case KEY_EVENT_LOOP:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_LOOP);
        }
        else
        {
        }
        break;
    case KEY_EVENT_DESLAG:
        if (sys_mode == SYS_MODE_HANDLE)
        {
            BSP_Relay_ToggleState(RELAY_ID_DESLAG);
        }
        else
        {
        }
        break;
    }
}
