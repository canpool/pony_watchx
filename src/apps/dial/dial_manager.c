/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "dial_manager.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include "watchx_image.h"
#include "watchx_settings.h"
#include "watchx_tr.h"

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/

LV_ADV_APP_DECLARE(dial_1);
LV_ADV_APP_DECLARE(dial_2);

WX_IMG_DECLARE(img_dial1_pre);
WX_IMG_DECLARE(img_dial2_pre);

WX_IMG_DECLARE(img_power_grade_1);
WX_IMG_DECLARE(img_power_grade_2);
WX_IMG_DECLARE(img_power_grade_3);

/* variables (local) ---------------------------------------------------------*/

static lv_adv_dial_t dial_items[DIAL_TOTAL_NUM] = {
    {
        TR_DIAL_1,
        LV_ADV_APP(dial_1),
        WX_IMG_GET(img_dial1_pre),
        LV_ADV_DIAL_RESOURCE_BUILTIN,
        LV_ADV_DIAL_POWER_GRADE_2,
        false,
    },
    {
        TR_DIAL_2,
        LV_ADV_APP(dial_2),
        WX_IMG_GET(img_dial2_pre),
        LV_ADV_DIAL_RESOURCE_BUILTIN,
        LV_ADV_DIAL_POWER_GRADE_1,
        true,
    },
};

static const void *const grade_srcs[] = {
    WX_IMG_GET(img_power_grade_1),
    WX_IMG_GET(img_power_grade_2),
    WX_IMG_GET(img_power_grade_3),
};

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/

static inline bool id_is_invalid(int32_t id)
{
    return (id < 0 || id >= DIAL_BUILTIN_NUM);
}

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

lv_adv_dial_t *dial_get_item(int32_t dial_id)
{
    if (id_is_invalid(dial_id)) {
        return NULL;
    }
    return &dial_items[dial_id];
}

const void *dial_get_power_grade_src(lv_adv_dial_power_grade_t grade)
{
    return grade_srcs[grade];
}

int dial_set_id(int32_t id)
{
    if (id_is_invalid(id)) {
        return -1;
    }
    if (lv_adv_kv_set_int(WX_KEY_DIAL, id) != LV_ADV_KV_RES_OK) {
        return -1;
    }
    return 0;
}

int dial_get_id(int32_t *id)
{
    int32_t dial_id = 0;
    if (lv_adv_kv_get_int(WX_KEY_DIAL, &dial_id) != LV_ADV_KV_RES_OK) {
        return -1;
    }
    if (id_is_invalid(dial_id)) {
        return -1;
    }
    *id = dial_id;
    return 0;
}
