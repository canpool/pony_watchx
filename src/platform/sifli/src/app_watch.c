/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
/* includes (standard library, system) ---------------------------------------*/
#include <rtdevice.h>
/* includes (other library) --------------------------------------------------*/
#include "littlevgl2rtt.h"
#include <lvsf.h>
#include <lv_adv.h>
/* includes (project) --------------------------------------------------------*/
#include <watchx.h>
#include <watchx_input.h>
#include <watchx_page.h>

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

static int32_t default_keypad_handler(lv_key_t key, lv_indev_state_t event)
{
    // LV_INDEV_STATE_REL == 0，LV_INDEV_STATE_PRESSED == 1
    static lv_indev_state_t last_event = LV_INDEV_STATE_REL;

    if (last_event != event) {   // Not execute repeatly.
        last_event = event;

        if ((LV_INDEV_STATE_PR == event) && (LV_KEY_HOME == key)) {
            if (lv_adv_page_is_current(LV_ADV_PAGE(home))) {
                LV_ADV_PAGE_PUSH_ANIM(menu, LV_SCR_LOAD_ANIM_OUT_LEFT);
            } else {
                LV_ADV_PAGE_BACK_TO_ANIM(home, LV_SCR_LOAD_ANIM_OUT_RIGHT);
            }
        } else if ((LV_INDEV_STATE_PR == event) && (LV_KEY_ESC == key)) {
            LV_ADV_PAGE_BACK_ANIM(LV_SCR_LOAD_ANIM_OUT_RIGHT);
        }
    }

    return LV_BLOCK_EVENT;
}

void app_watch_entry(void *parameter)
{
    rt_err_t ret = RT_EOK;
    rt_uint32_t ms;

    set_date(2026, 1, 23);
    set_time(13, 14, 0);

    lcd_device = rt_device_find(LCD_DEVICE_NAME);
    if (lcd_device == NULL) {
        return;
    }

    ret = littlevgl2rtt_init(LCD_DEVICE_NAME);
    if (ret != RT_EOK) {
        return;
    }
    lv_adv_screen_set_shape(LV_ADV_SCREEN_SHAPE_ROUND);

    if (watchx_init() != 0) {
        return;
    }

    watchx_input_keypad_init();
    keypad_default_handler_register(default_keypad_handler);

    while (1) {
        ms = lv_task_handler();
        rt_thread_mdelay(ms);
    }

    watchx_deinit();
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
