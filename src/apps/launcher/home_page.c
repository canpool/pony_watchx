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
    lv_adv_page_t base;
    // TODO: add others
} page_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/

LV_IMAGE_DECLARE(img_logo);

/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static lv_obj_t *page_on_create(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
    lv_obj_t *scr = lv_adv_create_screen();

    lv_obj_t *tv = lv_adv_tileview_create(scr);

    lv_obj_t *ca = lv_adv_tileview_area(tv, LV_ADV_TV_CENTER_AREA);

    lv_obj_t *img = lv_image_create(ca);
    lv_image_set_src(img, &img_logo);
    // lv_obj_set_size(img, 100, 100);
    lv_adv_image_set_size(img, 200, 200);
    lv_obj_center(img);

    lv_font_t *font = watchx_font_create(48);

    lv_obj_t *title = lv_label_create(ca);
    lv_label_set_text(title, "Watchx");
    lv_obj_set_style_text_font(title, font, LV_PART_MAIN);
    lv_obj_align_to(title, img, LV_ALIGN_BOTTOM_MID, 0, 50);

    lv_obj_t *ta = lv_adv_tileview_area(tv, LV_ADV_TV_TOP_AREA);
    lv_obj_set_style_bg_opa(ta, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(ta, lv_color_hex(0xff0000), 0);

    lv_obj_t *ba = lv_adv_tileview_area(tv, LV_ADV_TV_BOTTOM_AREA);
    lv_obj_set_style_bg_opa(ba, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(ba, lv_color_hex(0x00ff00), 0);

    lv_obj_t *la = lv_adv_tileview_area(tv, LV_ADV_TV_LEFT_AREA);
    lv_obj_set_style_bg_opa(la, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(la, lv_color_hex(0xffff00), 0);

    lv_obj_t *ra = lv_adv_tileview_area(tv, LV_ADV_TV_RIGHT_AREA);
    lv_obj_set_style_bg_opa(ra, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(ra, lv_color_hex(0x00ffff), 0);

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
}

LV_ADV_PAGE_DEF(home);
