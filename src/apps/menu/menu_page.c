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

enum {
    MENU_INDEX_LIST = 0,
    MENU_INDEX_CELLULAR,
    MENU_INDEX_NUM,
};

typedef struct {
    lv_adv_page_t base;
    lv_obj_t *sv;   // stacked view
    int32_t menu_idx;
} page_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/

WX_IMG_DECLARE(img_settings);
WX_IMG_DECLARE(img_flashlight);

/* variables (local) ---------------------------------------------------------*/
static const menu_item_t menu_items[] = {
    // clang-format off
    {"Settings", WX_IMG_GET(img_settings), LV_ADV_PAGE(setting)},
    {"Flashlight", WX_IMG_GET(img_flashlight), LV_ADV_PAGE(flashlight)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
    // clang-format on
};

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

void menu_item_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_SHORT_CLICKED) {
        const lv_adv_page_class_t *page = (const lv_adv_page_class_t *)lv_event_get_user_data(e);
        lv_adv_page_push(page, LV_SCR_LOAD_ANIM_MOVE_LEFT, NULL);
    }
}

static lv_obj_t *page_on_create(lv_adv_page_t *self)
{
    page_ctx_t *ctx = (page_ctx_t *)self;
    lv_obj_t *scr = lv_adv_create_screen();

    ctx->sv = lv_adv_stackedview_create(scr);
    ctx->menu_idx = MENU_INDEX_LIST;

    menu_create_f creators[] = {
        menu_list_create,
        menu_cellular_create,
    };

    for (size_t i = 0; i < LV_ADV_ARRAY_SIZE(creators); i++) {
        lv_obj_t *page = lv_adv_stackedview_add_page(ctx->sv);
        creators[i](page, menu_items, LV_ADV_ARRAY_SIZE(menu_items));
    }

    return scr;
}

static void page_on_show(lv_adv_page_t *self)
{
    page_ctx_t *ctx = (page_ctx_t *)self;
    lv_adv_kv_get_int(WX_KEY_DESKTOP, &ctx->menu_idx);
    lv_adv_stackedview_set_current(ctx->sv, ctx->menu_idx);
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
    page_ctx_t *ctx = (page_ctx_t *)self;
    if (ctx->menu_idx == MENU_INDEX_LIST) {
        lv_adv_page_back(NULL, LV_SCR_LOAD_ANIM_OUT_RIGHT, NULL);
    }
}

LV_ADV_PAGE_DEF(menu);
