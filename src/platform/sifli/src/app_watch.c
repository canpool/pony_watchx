/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
/* includes (standard library, system) ---------------------------------------*/
#include <rtdevice.h>
/* includes (other library) --------------------------------------------------*/
#include "littlevgl2rtt.h"
#include <lv_adv.h>
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
#define APP_WATCH_GUI_TASK_STACK_SIZE (16 << 10)

#define LCD_DEVICE_NAME "lcd"
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
static struct rt_thread watch_thread;

ALIGN(RT_ALIGN_SIZE)
static uint8_t watch_thread_stack[APP_WATCH_GUI_TASK_STACK_SIZE];

static rt_device_t lcd_device;

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

void app_watch_entry(void *parameter)
{
    rt_err_t ret = RT_EOK;
    rt_uint32_t ms;

    lcd_device = rt_device_find(LCD_DEVICE_NAME);
    if (lcd_device == NULL) {
        return;
    }

    ret = littlevgl2rtt_init(LCD_DEVICE_NAME);
    if (ret != RT_EOK) {
        return;
    }

    lv_obj_t *btn = lv_adv_button_create(lv_screen_active(), "hello watchx on lvgl v9");
    lv_obj_set_size(btn, lv_pct(80), lv_pct(30));
    lv_obj_center(btn);

    while (1) {
        ms = lv_task_handler();
        rt_thread_mdelay(ms);
    }
}

int app_watch_init(void)
{
    rt_err_t ret = RT_EOK;
    rt_thread_t thread = RT_NULL;

    ret = rt_thread_init(&watch_thread, "app_watch", app_watch_entry, RT_NULL, watch_thread_stack,
                         APP_WATCH_GUI_TASK_STACK_SIZE, RT_THREAD_PRIORITY_MIDDLE,
                         RT_THREAD_TICK_DEFAULT);

    if (RT_EOK != ret) {
        return RT_ERROR;
    }
    rt_thread_startup(&watch_thread);
    return RT_EOK;
}

INIT_APP_EXPORT(app_watch_init);
