/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "dial_gallery_page.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/

typedef struct {
    lv_adv_page_t base;
    lv_obj_t *layout;
    lv_obj_t *title;
    lv_obj_t *power_img;
    lv_obj_t *custom_btn;
} page_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/
/* functions -----------------------------------------------------------------*/

static void event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *cont = lv_event_get_target(e);
    page_ctx_t *ctx = lv_event_get_user_data(e);

    switch (code) {
    case LV_EVENT_VALUE_CHANGED: {
        int32_t cur_idx = lv_adv_linear_layout_get_current_index(cont);
        const lv_adv_dial_t *item = dial_get_item(cur_idx);
        if (item == NULL) {
            break;
        }
        lv_label_set_text(ctx->title, item->name);
        lv_adv_image_set_src(ctx->power_img, dial_get_power_grade_src(item->power_grade));
        if (item->editable) {
            lv_obj_remove_flag(ctx->custom_btn, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(ctx->custom_btn, LV_OBJ_FLAG_HIDDEN);
        }
        lv_obj_t *child = lv_obj_get_child(cont, cur_idx);
        lv_adv_effect_set_glow_opa(child, LV_OPA_COVER);
        int32_t prev_idx = lv_adv_linear_layout_get_previous_index(cont);
        if (prev_idx != -1) {
            child = lv_obj_get_child(cont, prev_idx);
            lv_adv_effect_set_glow_opa(child, LV_OPA_20);
        }
        break;
    }
    default:
        break;
    }
}

static void preview_event_handler(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_current_target(e);
    int32_t index = lv_obj_get_index(obj);
    lv_adv_kv_set_int(WX_KEY_DIAL, index);
    LV_ADV_PAGE_BACK();
}

static lv_obj_t *page_on_create(lv_adv_page_t *self)
{
    page_ctx_t *ctx = (page_ctx_t *)self;
    lv_obj_t *scr = lv_adv_create_screen();

    lv_obj_t *layout = lv_adv_linear_layout_create(scr);
    lv_adv_linear_layout_set_dir(layout, LV_DIR_HOR);
    ctx->layout = layout;

    lv_obj_add_event_cb(layout, event_handler, LV_EVENT_VALUE_CHANGED, ctx);

    for (int32_t i = 0; i < DIAL_TOTAL_NUM; i++) {
        const lv_adv_dial_t *item = dial_get_item(i);
        if (item == NULL || item->preview_img_src == NULL) {
            continue;
        }
        lv_obj_t *img = lv_image_create(layout);
        lv_image_set_src(img, item->preview_img_src);
        lv_obj_set_style_radius(img, 50, 0);
        lv_obj_add_flag(img, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_remove_flag(img, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_add_flag(img, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
        lv_group_add_obj(lv_group_get_default(), img);
        lv_adv_effect_set_glow(img, 10, lv_palette_main(LV_PALETTE_BLUE));
        lv_adv_effect_set_glow_opa(img, LV_OPA_20);
        lv_obj_add_event_cb(img, preview_event_handler, LV_EVENT_SHORT_CLICKED, ctx);
    }

    lv_obj_t *title_cont = lv_obj_create(scr);
    lv_obj_remove_style_all(title_cont);
    lv_obj_set_size(title_cont, lv_pct(100), LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(title_cont, LV_FLEX_FLOW_COLUMN);
    lv_adv_layout_set_align(title_cont, LV_ALIGN_TOP_MID);
    lv_obj_remove_flag(title_cont, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *title_label = lv_label_create(title_cont);
    lv_obj_set_style_text_font(title_label, WX_FONT(32), 0);
    lv_obj_set_width(title_label, lv_pct(100));
    lv_obj_set_style_text_align(title_label, LV_TEXT_ALIGN_CENTER, 0);
    ctx->title = title_label;

    lv_obj_t *power_cont = lv_obj_create(title_cont);
    lv_obj_remove_style_all(power_cont);
    lv_obj_set_style_pad_gap(power_cont, 10, 0);
    lv_obj_set_flex_flow(power_cont, LV_FLEX_FLOW_ROW);
    lv_adv_layout_set_align(power_cont, LV_ALIGN_CENTER);
    lv_obj_set_size(power_cont, lv_pct(100), LV_SIZE_CONTENT);
    lv_obj_t *power_label = lv_label_create(power_cont);
    lv_label_set_text(power_label, "power grade");
    lv_obj_set_style_text_opa(power_label, LV_OPA_70, 0);
    lv_obj_t *power_img = lv_image_create(power_cont);
    lv_adv_image_set_src(power_img, dial_get_power_grade_src(LV_ADV_DIAL_POWER_GRADE_1));
    lv_adv_image_set_size(power_img, 22, 22);
    ctx->power_img = power_img;

    lv_obj_align(title_cont, LV_ALIGN_TOP_MID, 0, 30);

    lv_obj_t *btn = lv_button_create(scr);
    lv_obj_t *btn_label = lv_label_create(btn);
    lv_label_set_text(btn_label, "Custom");
    lv_obj_center(btn_label);
    lv_obj_set_width(btn, lv_pct(30));
    lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, 0);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -30);
    lv_group_remove_obj(btn);
    ctx->custom_btn = btn;

    return scr;
}

static void page_on_show(lv_adv_page_t *self)
{
    page_ctx_t *ctx = (page_ctx_t *)self;

    int32_t dial_id = 0;
    lv_adv_kv_get_int(WX_KEY_DIAL, &dial_id);
    lv_adv_linear_layout_select(ctx->layout, dial_id);
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
}

LV_ADV_PAGE_DEF(dial_gallery);
