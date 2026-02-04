/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "menu_page.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

lv_obj_t *menu_cellular_create(lv_obj_t *parent, const menu_item_t *items, uint16_t item_cnt)
{
    lv_obj_t *menu = lv_adv_menu_cell_create(parent);

    for (size_t i = 0; i < item_cnt; i++) {
        const menu_item_t *item = items + i;
        lv_obj_t *img = lv_image_create(menu);
        lv_image_set_src(img, item->icon);
        if (item->page != NULL) {
            lv_obj_add_event_cb(img, menu_item_event_handler, LV_EVENT_SHORT_CLICKED,
                                (void *)item->page);
        }
    }
    lv_adv_menu_cell_update_layout(menu);

    return menu;
}
