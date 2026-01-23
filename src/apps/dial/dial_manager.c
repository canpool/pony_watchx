/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "dial_manager.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/

LV_ADV_APP_DECLARE(dial_1);

/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/

static lv_adv_dial_t dial_items[DIAL_TOTAL_NUM] = {
    {
        "Digital Normal",
        LV_ADV_APP(dial_1),
        NULL,
        LV_ADV_DIAL_RESOURCE_BUILTIN,
        LV_ADV_DIAL_POWER_GRADE_2,
        false,
    },
};

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

lv_adv_app_t *dial_create_app(lv_obj_t *parent, int32_t dial_id, void *user_data)
{
    if (dial_id < 0) {
        dial_id = 0;
    } else if (dial_id >= DIAL_BUILTIN_NUM) {
        // TODO: create dynamic dial
        dial_id = 0;
    }
    const lv_adv_dial_t *dial = &dial_items[dial_id];
    lv_adv_app_t *app = lv_adv_app_create(parent, dial->src, user_data);
    return app;
}
