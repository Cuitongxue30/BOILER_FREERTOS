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
        }
        else
        {
        }
        break;
    case KEY_EVENT_DOWN_FUEL:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_CTRL_FUEL:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_FIRE_FUEL:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_GRATE:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_BLOW:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_INDUCE:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_SEBLOW:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_BUMP:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_LOOP:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    case KEY_EVENT_DESLAG:
        if (sys_mode == SYS_MODE_HANDLE)
        {
        }
        else
        {
        }
        break;
    }
}
