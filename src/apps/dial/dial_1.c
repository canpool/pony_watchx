/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "dial_page.h"
/* includes (standard library, system) ---------------------------------------*/
#include <time.h>
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/

typedef struct {
    lv_adv_app_t base;
    lv_adv_clock_digi_t digi;
    lv_obj_t *step_label;
    lv_obj_t *heart_rate_label;
    lv_timer_t *timer;
} app_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/

WX_IMG_DECLARE(img_dial1_bg_1);
WX_IMG_DECLARE(img_dial1_bg_2);
WX_IMG_DECLARE(img_dial1_bg_3);
WX_IMG_DECLARE(img_dial1_bg_4);
WX_IMG_DECLARE(img_dial1_bg_5);
WX_IMG_DECLARE(img_dial1_bg_6);
WX_IMG_DECLARE(img_dial1_bg_7);
WX_IMG_DECLARE(img_dial1_bg_8);
WX_IMG_DECLARE(img_dial1_bg_9);
WX_IMG_DECLARE(img_dial1_bg_10);
WX_IMG_DECLARE(img_dial1_bg_11);
WX_IMG_DECLARE(img_dial1_bg_12);
WX_IMG_DECLARE(img_dial1_bg_13);
WX_IMG_DECLARE(img_dial1_bg_14);
WX_IMG_DECLARE(img_dial1_bg_15);
WX_IMG_DECLARE(img_dial1_bg_16);
WX_IMG_DECLARE(img_dial1_bg_17);
WX_IMG_DECLARE(img_dial1_bg_18);
WX_IMG_DECLARE(img_dial1_bg_19);
WX_IMG_DECLARE(img_dial1_bg_20);
WX_IMG_DECLARE(img_dial1_bg_21);
WX_IMG_DECLARE(img_dial1_bg_22);
WX_IMG_DECLARE(img_dial1_bg_23);
WX_IMG_DECLARE(img_dial1_bg_24);
WX_IMG_DECLARE(img_dial1_bg_25);

WX_IMG_DECLARE(img_dial1_hour_0);
WX_IMG_DECLARE(img_dial1_hour_1);
WX_IMG_DECLARE(img_dial1_hour_2);
WX_IMG_DECLARE(img_dial1_hour_3);
WX_IMG_DECLARE(img_dial1_hour_4);
WX_IMG_DECLARE(img_dial1_hour_5);
WX_IMG_DECLARE(img_dial1_hour_6);
WX_IMG_DECLARE(img_dial1_hour_7);
WX_IMG_DECLARE(img_dial1_hour_8);
WX_IMG_DECLARE(img_dial1_hour_9);

WX_IMG_DECLARE(img_dial1_minute_0);
WX_IMG_DECLARE(img_dial1_minute_1);
WX_IMG_DECLARE(img_dial1_minute_2);
WX_IMG_DECLARE(img_dial1_minute_3);
WX_IMG_DECLARE(img_dial1_minute_4);
WX_IMG_DECLARE(img_dial1_minute_5);
WX_IMG_DECLARE(img_dial1_minute_6);
WX_IMG_DECLARE(img_dial1_minute_7);
WX_IMG_DECLARE(img_dial1_minute_8);
WX_IMG_DECLARE(img_dial1_minute_9);

WX_IMG_DECLARE(img_dial1_line_bottom);
WX_IMG_DECLARE(img_dial1_line_top);
WX_IMG_DECLARE(img_dial1_step);
WX_IMG_DECLARE(img_dial1_heart);

/* variables (local) ---------------------------------------------------------*/

static const void *const bg_imgs[] = {
    // clang-format off
    WX_IMG_GET(img_dial1_bg_1),
    WX_IMG_GET(img_dial1_bg_2),
    WX_IMG_GET(img_dial1_bg_3),
    WX_IMG_GET(img_dial1_bg_4),
    WX_IMG_GET(img_dial1_bg_5),
    WX_IMG_GET(img_dial1_bg_6),
    WX_IMG_GET(img_dial1_bg_7),
    WX_IMG_GET(img_dial1_bg_8),
    WX_IMG_GET(img_dial1_bg_9),
    WX_IMG_GET(img_dial1_bg_10),
    WX_IMG_GET(img_dial1_bg_11),
    WX_IMG_GET(img_dial1_bg_12),
    WX_IMG_GET(img_dial1_bg_13),
    WX_IMG_GET(img_dial1_bg_14),
    WX_IMG_GET(img_dial1_bg_15),
    WX_IMG_GET(img_dial1_bg_16),
    WX_IMG_GET(img_dial1_bg_17),
    WX_IMG_GET(img_dial1_bg_18),
    WX_IMG_GET(img_dial1_bg_19),
    WX_IMG_GET(img_dial1_bg_20),
    WX_IMG_GET(img_dial1_bg_21),
    WX_IMG_GET(img_dial1_bg_22),
    WX_IMG_GET(img_dial1_bg_23),
    WX_IMG_GET(img_dial1_bg_24),
    WX_IMG_GET(img_dial1_bg_25),
    // clang-format on
};

static const void *const hour_imgs[] = {
    // clang-format off
    WX_IMG_GET(img_dial1_hour_0),
    WX_IMG_GET(img_dial1_hour_1),
    WX_IMG_GET(img_dial1_hour_2),
    WX_IMG_GET(img_dial1_hour_3),
    WX_IMG_GET(img_dial1_hour_4),
    WX_IMG_GET(img_dial1_hour_5),
    WX_IMG_GET(img_dial1_hour_6),
    WX_IMG_GET(img_dial1_hour_7),
    WX_IMG_GET(img_dial1_hour_8),
    WX_IMG_GET(img_dial1_hour_9),
    // clang-format on
};

static const void *const minute_imgs[] = {
    // clang-format off
    WX_IMG_GET(img_dial1_minute_0),
    WX_IMG_GET(img_dial1_minute_1),
    WX_IMG_GET(img_dial1_minute_2),
    WX_IMG_GET(img_dial1_minute_3),
    WX_IMG_GET(img_dial1_minute_4),
    WX_IMG_GET(img_dial1_minute_5),
    WX_IMG_GET(img_dial1_minute_6),
    WX_IMG_GET(img_dial1_minute_7),
    WX_IMG_GET(img_dial1_minute_8),
    WX_IMG_GET(img_dial1_minute_9),
    // clang-format on
};

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void clock_update(app_ctx_t *ctx)
{
    time_t now;
    struct tm *t;

    time(&now);
    t = localtime(&now);
    if (t) {
        lv_adv_clock_digi_update(&ctx->digi, t->tm_hour, (const void **)hour_imgs, t->tm_min,
                                 (const void **)minute_imgs);
    }
}

static void clock_timer_cb(lv_timer_t *timer)
{
    app_ctx_t *ctx = lv_timer_get_user_data(timer);
    clock_update(ctx);
}

static void image_create(lv_obj_t *parent, app_ctx_t *ctx)
{
    lv_adv_class_image_t img_items[] = {
        {.pos = {30, 284}, .src = WX_IMG_GET(img_dial1_line_bottom)},
        {.pos = {254, 60}, .src = WX_IMG_GET(img_dial1_line_top)},
        {.pos = {290, 55}, .src = WX_IMG_GET(img_dial1_step)},
        {.pos = {60, 375}, .src = WX_IMG_GET(img_dial1_heart)},
    };

    for (size_t i = 0; i < LV_ADV_ARRAY_SIZE(img_items); ++i) {
        lv_adv_class_image_create(parent, &img_items[i]);
    }
}

static void clock_create(lv_obj_t *parent, app_ctx_t *ctx)
{
    lv_adv_class_image_t img_items[] = {
        {.pos = {18, 90}, .src = WX_IMG_GET(img_dial1_hour_0)},
        {.pos = {136, 30}, .src = WX_IMG_GET(img_dial1_hour_8)},
        {.pos = {136, 247}, .src = WX_IMG_GET(img_dial1_minute_2)},
        {.pos = {254, 183}, .src = WX_IMG_GET(img_dial1_minute_6)},
    };

    lv_obj_t **digi = (lv_obj_t **)&ctx->digi;
    for (size_t i = 0; i < LV_ADV_ARRAY_SIZE(img_items); ++i) {
        digi[i] = lv_adv_class_image_create(parent, &img_items[i]);
    }
}

static void step_create(lv_obj_t *parent, app_ctx_t *ctx)
{
    lv_adv_class_text_t c_t = {
        .pos = {300, 110},
        .w = 85,
        .font = WX_FONT(24),
        .align = LV_TEXT_ALIGN_CENTER,
    };
    ctx->step_label = lv_adv_class_text_create(parent, &c_t);
    lv_label_set_text_fmt(ctx->step_label, "step\n%d", 8000);
}

static void heart_rate_create(lv_obj_t *parent, app_ctx_t *ctx)
{
    lv_adv_class_text_t c_t = {
        .pos = {15, 280},
        .w = 60,
        .font = WX_FONT(24),
        .align = LV_TEXT_ALIGN_CENTER,
    };
    ctx->heart_rate_label = lv_adv_class_text_create(parent, &c_t);
    lv_label_set_text_fmt(ctx->heart_rate_label, "%d\nbpm", 102);
}

static lv_obj_t *app_on_create(lv_adv_app_t *self)
{
    app_ctx_t *ctx = (app_ctx_t *)self;
    lv_obj_t *root = lv_adv_create_container(self->parent);

    lv_obj_t *bg = lv_animimg_create(root);
    lv_animimg_set_src(bg, (const void **)bg_imgs, LV_ADV_ARRAY_SIZE(bg_imgs));
    lv_animimg_set_duration(bg, 1000);
    lv_animimg_set_repeat_count(bg, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(bg);

    image_create(root, ctx);
    clock_create(root, ctx);
    step_create(root, ctx);
    heart_rate_create(root, ctx);

    return root;
}

static void app_on_resume(lv_adv_app_t *self)
{
    app_ctx_t *ctx = (app_ctx_t *)self;

    clock_update(ctx);
    if (ctx->timer == NULL) {
        ctx->timer = lv_timer_create(clock_timer_cb, 1000, ctx);
    }
}

static void app_on_pause(lv_adv_app_t *self)
{
    app_ctx_t *ctx = (app_ctx_t *)self;

    if (ctx->timer != NULL) {
        lv_timer_delete(ctx->timer);
        ctx->timer = NULL;
    }
}

static void app_on_destroy(lv_adv_app_t *self)
{
    // app_ctx_t *ctx = (app_ctx_t *)self;
}

LV_ADV_APP_DEF(dial_1);
