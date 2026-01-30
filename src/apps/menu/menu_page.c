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

typedef struct {
    lv_adv_page_t base;
    lv_obj_t *sv;   // stacked view
} page_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
static const menu_item_t menu_items[] = {
    // clang-format off
    {"dummy", WX_IMG_GET(img_logo), LV_ADV_PAGE(dummy)},
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
    int32_t idx = 0;   // TODO: get the real idx
    lv_adv_stackedview_set_current(ctx->sv, idx);
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

LV_ADV_PAGE_DEF(menu);
