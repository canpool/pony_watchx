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
    lv_obj_t *lst;
} page_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/

static const radio_item_t desktop_items[] = {
    {"List", WX_IMG_GET(img_setting_desktop)},
    {"Cellular", WX_IMG_GET(img_setting_desktop)},
};

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void value_changed_event_handler(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);

    lv_obj_t *pre_child = lv_adv_radio_applist_get_previous_child(obj);
    lv_obj_t *cur_child = lv_adv_radio_applist_get_current_child(obj);

    if (pre_child) {
        lv_obj_t *img = lv_adv_item_get_right(pre_child);
        lv_img_set_src(img, ICON_RADIO_UNCHECKED);
    }
    if (cur_child) {
        lv_obj_t *img = lv_adv_item_get_right(cur_child);
        lv_img_set_src(img, ICON_RADIO_CHECKED);

        int32_t idx = lv_obj_get_index(cur_child);
        lv_adv_kv_set_int(WX_KEY_DESKTOP, idx);
    }
}

static void applist_add_item(lv_obj_t *parent, void *user_data)
{
    for (size_t i = 0; i < LV_ADV_ARRAY_SIZE(desktop_items); i++) {
        const radio_item_t *item = desktop_items + i;
        lv_obj_t *obj = lv_adv_item_create(parent, LV_ADV_ITEM_ICON_TEXT_SINGLE);
        lv_obj_set_width(obj, lv_pct(90));
        lv_obj_set_height(obj, 112);
        lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, 0);
        lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x272727), 0);
        lv_adv_item_set_icon(obj, item->icon);
        lv_obj_t *label = lv_adv_item_get_label(obj);
        watchx_text_set(label, item->title, 32);
        lv_obj_t *img = lv_adv_item_set_right(obj, LV_ADV_ITEM_RIGHT_IMAGE);
        lv_img_set_src(img, ICON_RADIO_UNCHECKED);
    }
}

static lv_obj_t *page_on_create(lv_adv_page_t *self)
{
    page_ctx_t *ctx = (page_ctx_t *)self;
    lv_obj_t *scr = lv_adv_create_screen();

    lv_obj_t *lst = lv_adv_radio_applist_create(scr);
    lv_obj_add_event_cb(lst, value_changed_event_handler, LV_EVENT_VALUE_CHANGED, ctx);
    lv_obj_t *menu = lv_adv_applist_get_menu_list(lst);
    lv_adv_menu_list_set_type(menu, LV_ADV_MENU_LIST_NORMAL);
    lv_adv_layout_set_align(menu, LV_ALIGN_TOP_MID);

    lv_obj_t *title = lv_adv_applist_add_title(lst, "Desktop");
    lv_obj_set_style_text_font(title, WX_FONT(32), 0);
    lv_adv_radio_applist_add_item(lst, applist_add_item, ctx);
    ctx->lst = lst;

    return scr;
}

static void page_on_show(lv_adv_page_t *self)
{
    page_ctx_t *ctx = (page_ctx_t *)self;

    int32_t desktop_type = 0;
    lv_adv_kv_get_int(WX_KEY_DESKTOP, &desktop_type);
    lv_adv_radio_applist_set_current_index(ctx->lst, desktop_type);
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

LV_ADV_PAGE_DEF(setting_desktop);
