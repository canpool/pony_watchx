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

lv_obj_t *menu_list_create(lv_obj_t *parent, const menu_item_t *items, uint16_t item_cnt)
{
    lv_obj_t *lst = lv_adv_menu_list_create(parent);
    lv_adv_menu_list_set_type(lst, LV_ADV_MENU_LIST_NORMAL);

    lv_obj_t *bar = lv_adv_menu_list_get_scrollbar(lst);
    lv_obj_set_style_arc_color(bar, lv_color_hex(0x505050), 0);

    for (size_t i = 0; i < item_cnt; i++) {
        const menu_item_t *item = items + i;
        lv_obj_t *btn = lv_adv_toolbutton_create(lst, item->icon, "");
        lv_obj_set_width(btn, lv_pct(100));
        lv_obj_set_height(btn, 112);
        lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, 0);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x272727), 0);
        lv_obj_t *title = lv_adv_button_get_label(btn);
        lv_label_set_text(title, item->title);
        lv_obj_set_style_text_font(title, WX_FONT(32), 0);
        lv_obj_t *icon = lv_adv_button_get_icon(btn);
        lv_adv_image_set_size(icon, 96, 96);
        if (item->page != NULL) {
            lv_obj_add_event_cb(btn, menu_item_event_handler, LV_EVENT_SHORT_CLICKED,
                                (void *)item->page);
        }
    }
    lv_adv_menu_list_update_layout(lst);

    return lst;
}
