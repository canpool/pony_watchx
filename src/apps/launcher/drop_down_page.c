/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "watchx_page.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/

typedef struct {
    lv_adv_subpage_t base;
} subpage_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/

WX_IMG_DECLARE(img_quick_setting);
WX_IMG_DECLARE(img_quick_flashlight);

/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void quick_setting_event_handler(lv_event_t *e)
{
    LV_ADV_PAGE_PUSH_ANIM(setting, LV_SCR_LOAD_ANIM_MOVE_LEFT);
}

static void quick_flashlight_event_handler(lv_event_t *e)
{
    LV_ADV_PAGE_PUSH_ANIM(flashlight, LV_SCR_LOAD_ANIM_MOVE_LEFT);
}

static lv_obj_t *subpage_on_create(lv_adv_subpage_t *self)
{
    subpage_ctx_t *ctx = (subpage_ctx_t *)self;
    lv_obj_t *root = lv_adv_create_container(self->parent);

    lv_obj_t *layout = lv_adv_flow_layout_create(root);
    lv_obj_set_size(layout, lv_pct(90), lv_pct(90));
    lv_obj_center(layout);

    lv_adv_flow_layout_set_item_mode(layout, LV_ADV_FLOW_LAYOUT_ITEM_SQUARE);
    lv_adv_flow_layout_set_cols(layout, 4);

    lv_obj_t *btn = lv_adv_control_button_create(layout);
    lv_adv_control_button_set_icon(btn, WX_IMG_GET(img_quick_setting));
    lv_obj_add_event_cb(btn, quick_setting_event_handler, LV_EVENT_SHORT_CLICKED, NULL);

    btn = lv_adv_control_button_create(layout);
    lv_adv_control_button_set_icon(btn, WX_IMG_GET(img_quick_flashlight));
    lv_obj_add_event_cb(btn, quick_flashlight_event_handler, LV_EVENT_SHORT_CLICKED, NULL);

    return root;
}

static void subpage_on_show(lv_adv_subpage_t *self)
{
    // subpage_ctx_t *ctx = (subpage_ctx_t *)self;
}

static void subpage_on_hide(lv_adv_subpage_t *self)
{
    // subpage_ctx_t *ctx = (subpage_ctx_t *)self;
}

static void subpage_on_destroy(lv_adv_subpage_t *self)
{
    // subpage_ctx_t *ctx = (subpage_ctx_t *)self;
}

LV_ADV_SUBPAGE_DEF(drop_down);
