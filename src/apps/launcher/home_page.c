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

extern const unsigned char DroidSansFallback[];
extern const int DroidSansFallback_size;

/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static lv_obj_t *page_on_create(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
    lv_obj_t *scr = lv_adv_create_screen();

    lv_obj_t *img = lv_image_create(scr);
    lv_image_set_src(img, &img_logo);
    // lv_obj_set_size(img, 100, 100);
    lv_adv_image_set_size(img, 200, 200);
    lv_obj_center(img);

    lv_font_t *font = lv_tiny_ttf_create_data(DroidSansFallback, DroidSansFallback_size, 48);

    lv_obj_t *title = lv_label_create(scr);
    lv_label_set_text(title, "Watchx");
    lv_obj_set_style_text_font(title, font, LV_PART_MAIN);
    lv_obj_align_to(title, img, LV_ALIGN_BOTTOM_MID, 0, 50);

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
