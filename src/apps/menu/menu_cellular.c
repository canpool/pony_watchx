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
    lv_obj_t *menu = lv_adv_menu_cellular_create(parent);
    lv_adv_menu_cellular_set_type(menu, LV_ADV_MENU_CELLULAR_SCALE);

    for (size_t i = 0; i < item_cnt; i++) {
        const menu_item_t *item = items + i;
        lv_obj_t *btn = lv_adv_toolbutton_create(menu, item->icon, "");
        lv_adv_toolbutton_set_style(btn, LV_ADV_TOOLBUTTON_ICON_ONLY);
        lv_obj_set_size(btn, 80, 80);
        lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, 0);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x272727), 0);
        lv_obj_t *title = lv_adv_button_get_label(btn);
        lv_label_set_text(title, item->title);
        lv_obj_t *icon = lv_adv_button_get_icon(btn);
        lv_adv_image_set_size(icon, 72, 72);
        if (item->page != NULL) {
            lv_obj_add_event_cb(btn, menu_item_event_handler, LV_EVENT_SHORT_CLICKED, (void *)item->page);
        }
    }
    lv_adv_menu_cellular_update_layout(menu);

    return menu;
}
