/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "setting_page.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/

typedef struct {
    lv_adv_page_t base;
} page_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/

static const setting_item_t setting_items[] = {
    {"desktop", WX_IMG_GET(img_setting_desktop), LV_ADV_PAGE(menu_setting)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
};

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void item_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_SHORT_CLICKED) {
        const lv_adv_page_class_t *page = (const lv_adv_page_class_t *)lv_event_get_user_data(e);
        lv_adv_page_push(page, LV_SCR_LOAD_ANIM_MOVE_LEFT, NULL);
    }
}

static void applist_add_item(lv_obj_t *parent, void *user_data)
{
    for (size_t i = 0; i < LV_ADV_ARRAY_SIZE(setting_items); i++) {
        const setting_item_t *item = setting_items + i;
        lv_obj_t *btn = lv_adv_toolbutton_create(parent, item->icon, "");
        lv_obj_set_width(btn, lv_pct(100));
        lv_obj_set_height(btn, 112);
        lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, 0);
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x272727), 0);
        lv_obj_t *title = lv_adv_button_get_label(btn);
        watchx_text_set(title, item->title, 32);
        lv_obj_t *icon = lv_adv_button_get_icon(btn);
        lv_adv_image_set_size(icon, 96, 96);
        if (item->page != NULL) {
            lv_obj_add_event_cb(btn, item_event_handler, LV_EVENT_SHORT_CLICKED,
                                (void *)item->page);
        }
        lv_obj_t *arrow = lv_img_create(btn);
        lv_img_set_src(arrow, ICON_ARROW_RIGHT);
    }
}

static lv_obj_t *page_on_create(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
    lv_obj_t *scr = lv_adv_create_screen();

    lv_obj_t *lst = lv_adv_applist_create(scr);
    lv_obj_t *menu = lv_adv_applist_get_menu_list(lst);
    lv_adv_menu_list_set_type(menu, LV_ADV_MENU_LIST_NORMAL);
    lv_adv_layout_set_align(menu, LV_ALIGN_TOP_MID);

    lv_obj_t *title = lv_adv_applist_add_title(lst, "");
    watchx_text_set(title, "Settings", 32);
    lv_adv_applist_add_item(lst, applist_add_item, NULL);

    return scr;
}

static void page_on_show(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
}

static void page_on_hide(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
}

static void page_on_destroy(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
}

static void page_on_back(lv_adv_page_t *self)
{
    lv_adv_page_back(NULL, LV_SCR_LOAD_ANIM_OUT_RIGHT, NULL);
}

LV_ADV_PAGE_DEF(setting);
