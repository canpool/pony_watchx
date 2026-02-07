/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "menu_manager.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include "watchx_settings.h"

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/

static inline bool id_is_invalid(int32_t id)
{
    return (id < 0 || id >= MENU_ID_NUM);
}

/* functions (implementation) ------------------------------------------------*/

int menu_set_id(int32_t id)
{
    if (id_is_invalid(id)) {
        return -1;
    }
    if (lv_adv_kv_set_int(WX_KEY_DESKTOP, id) != LV_ADV_KV_RES_OK) {
        return -1;
    }
    return 0;
}

int menu_get_id(int32_t *id)
{
    int32_t menu_id = 0;
    if (lv_adv_kv_get_int(WX_KEY_DESKTOP, &menu_id) != LV_ADV_KV_RES_OK) {
        return -1;
    }
    if (id_is_invalid(menu_id)) {
        return -1;
    }
    *id = menu_id;
    return 0;
}
