/**
 * Copyright (C) 2025 maminjie <canpool@163.com>
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

typedef struct language_item {
    const char *code;
    const char *font_name;
} language_item_t;

/* macro ---------------------------------------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/

static const language_item_t language_items[] = {
    {TR_LANGUAGE_EN_US, WX_FONT_NAME_DEFAULT},
    {TR_LANGUAGE_ZH_CN, WX_FONT_NAME_DEFAULT},
};

/* variables (global) --------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/

static inline bool id_is_invalid(int32_t id)
{
    return (id < 0 || id >= LV_ADV_ARRAY_SIZE(language_items));
}

/* functions -----------------------------------------------------------------*/

static int language_set_id(int32_t id)
{
    if (id_is_invalid(id)) {
        return -1;
    }
    if (lv_adv_kv_set_int(WX_KEY_LANGUAGE, id) != LV_ADV_KV_RES_OK) {
        return -1;
    }
    return 0;
}

static int language_get_id(int32_t *id)
{
    int32_t lang_id = 0;
    if (lv_adv_kv_get_int(WX_KEY_LANGUAGE, &lang_id) != LV_ADV_KV_RES_OK) {
        return -1;
    }
    if (id_is_invalid(lang_id)) {
        return -1;
    }
    *id = lang_id;
    return 0;
}

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
        language_set_id(idx);

        if (strcmp(lv_i18n_get_current_locale(), language_items[idx].code) != 0) {
            lv_i18n_set_locale(language_items[idx].code);
            watchx_font_set(language_items[idx].font_name);
            lv_adv_page_manager_lang_invalidate();
        }
    }
}

static void applist_add_item(lv_obj_t *parent, void *user_data)
{
    for (size_t i = 0; i < LV_ADV_ARRAY_SIZE(language_items); i++) {
        const language_item_t *item = language_items + i;
        lv_obj_t *obj = lv_adv_item_create(parent, LV_ADV_ITEM_ONLY_TEXT_SIGNLE);
        lv_obj_set_width(obj, lv_pct(100));
        lv_obj_set_height(obj, 112);
        lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, 0);
        lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x272727), 0);
        lv_obj_t *label = lv_adv_item_get_label(obj);
        watchx_text_set(label, item->code, 28);
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
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

    lv_obj_t *title = lv_adv_applist_add_title(lst, "");
    watchx_text_set(title, TR_LANGUAGE, 32);
    lv_adv_radio_applist_add_item(lst, applist_add_item, ctx);
    ctx->lst = lst;

    return scr;
}

static void page_on_show(lv_adv_page_t *self)
{
    page_ctx_t *ctx = (page_ctx_t *)self;

    int32_t lang_id = 0;
    language_get_id(&lang_id);
    lv_adv_radio_applist_set_current_index(ctx->lst, lang_id);
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

LV_ADV_PAGE_DEF(setting_language);

void watchx_setting_language(void)
{
    int32_t id = 0;
    language_get_id(&id);
    lv_i18n_set_locale(language_items[id].code);
    watchx_font_set(language_items[id].font_name);
}
