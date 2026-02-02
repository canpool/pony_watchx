/**
 * Copyright (C) 2025 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "lv_main.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include "watchx.h"
#include "watchx_page.h"

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void keypad_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    uint32_t key = lv_indev_get_key(lv_indev_active());

    switch (key) {
    case LV_KEY_ENTER:
        if (code == LV_EVENT_SHORT_CLICKED) {
            if (lv_adv_page_is_current(LV_ADV_PAGE(home))) {
                LV_ADV_PAGE_PUSH_ANIM(menu, LV_SCR_LOAD_ANIM_OUT_LEFT);
            } else {
                LV_ADV_PAGE_BACK_TO_ANIM(home, LV_SCR_LOAD_ANIM_OUT_RIGHT);
            }
        } else if (code == LV_EVENT_LONG_PRESSED_REPEAT) {
            // TODO
            LV_LOG_USER("ENTER long pressed repeat");
        }
        break;
    }
}

static void lv_adv_ctx_init(void)
{
    LV_LOG_USER("init");

    watchx_init();

    lv_adv_page_t *home = lv_adv_page_get(LV_ADV_PAGE(home));
    if (home) {
        lv_group_add_obj(lv_adv_group_get_keypad(), home->scr);
        lv_obj_add_event_cb(home->scr, keypad_event_cb, LV_EVENT_SHORT_CLICKED, NULL);
        lv_obj_add_event_cb(home->scr, keypad_event_cb, LV_EVENT_LONG_PRESSED_REPEAT, NULL);
    }
}

static void lv_adv_ctx_destroy(void)
{
    LV_LOG_USER("destory");

    watchx_deinit();
}

void lv_adv_setup(void)
{
    lv_adv_ctx_t ctx = {
        .init = lv_adv_ctx_init,
        .destroy = lv_adv_ctx_destroy,
    };
    lv_adv_register_ctx(&ctx);
}
