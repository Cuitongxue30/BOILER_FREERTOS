#include "app_freertos.h"

TaskHandle_t KeyTaskHandle;

void App_FreeRTOS_Start(void)
{
    // 创建按键任务
    xTaskCreate(
        vTask_KeyScan,        // 任务函数
        "KeyTask",            // 任务名称
        256,                  // 任务堆栈大小
        NULL,                 // 任务参数
        tskIDLE_PRIORITY + 1, // 任务优先级
        &KeyTaskHandle        // 任务句柄
    );

    // 启动调度器
    vTaskStartScheduler();
}

void vTask_KeyScan(void *pvParameters)
{
    for (;;)
    {
        uint8_t event = Key_Scan_All();
        if (event != 0)
        {
            App_Mode_HandleEvent(event);
            DEBUG_PRINT("Key Event: %d\n", event);
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}



/* --------------------------------------------------------------------------
 * 1. 空闲任务内存分配 (configSUPPORT_STATIC_ALLOCATION == 1)
 * -------------------------------------------------------------------------- */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                   StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize)
{
    /* 静态分配空闲任务的 TCB 和 栈空间 */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/* --------------------------------------------------------------------------
 * 2. 定时器任务内存分配 (configSUPPORT_STATIC_ALLOCATION == 1 && configUSE_TIMERS == 1)
 * -------------------------------------------------------------------------- */
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
                                    StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize)
{
    /* 静态分配定时器任务的 TCB 和 栈空间 */
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

/* --------------------------------------------------------------------------
 * 3. 内存申请失败钩子 (configUSE_MALLOC_FAILED_HOOK == 1)
 * -------------------------------------------------------------------------- */
void vApplicationMallocFailedHook(void)
{
    /* 内存不足！在此处打断点或死循环。
       实战建议：闪烁故障灯或通过看门狗复位 */
    taskDISABLE_INTERRUPTS();
    for (;;)
        ;
}

/* --------------------------------------------------------------------------
 * 4. 栈溢出检测钩子 (configCHECK_FOR_STACK_OVERFLOW > 0)
 * -------------------------------------------------------------------------- */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    /* 发生栈溢出！xTask 是溢出的任务句柄，pcTaskName 是任务名。
       实战建议：打印任务名并复位 */

    // 可以在这里加个断点查看 pcTaskName 是哪个任务炸了
    (void)pcTaskName;
    (void)xTask;

    taskDISABLE_INTERRUPTS();
    for (;;)
        ;
}
