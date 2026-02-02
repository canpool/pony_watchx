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
    lv_adv_clock_hand_t clock_hand;
    lv_timer_t *timer;
} app_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/

WX_IMG_DECLARE(img_dial2_bg);
WX_IMG_DECLARE(img_dial2_point_h);
WX_IMG_DECLARE(img_dial2_point_m);
WX_IMG_DECLARE(img_dial2_point_s);

/* variables (local) ---------------------------------------------------------*/
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
        lv_adv_clock_hand_update(&ctx->clock_hand, t->tm_hour, t->tm_min, t->tm_sec);
    }
}

static void clock_timer_cb(lv_timer_t *timer)
{
    app_ctx_t *ctx = lv_timer_get_user_data(timer);
    clock_update(ctx);
}

static void clock_create(lv_obj_t *parent, app_ctx_t *ctx)
{
    lv_adv_clock_hand_t *hand = &ctx->clock_hand;

    lv_adv_class_hand_t c = {
        .center = {195, 225},
        .pivot = {17, 108},
        .start_angle = 0,
        .end_angle = 360,
        .img_src = WX_IMG_GET(img_dial2_point_h),
    };
    hand->hour = lv_adv_class_hand_create(parent, &c);

    c.pivot.x = 20;
    c.pivot.y = 140;
    c.img_src = WX_IMG_GET(img_dial2_point_m);
    hand->minute = lv_adv_class_hand_create(parent, &c);

    c.pivot.x = 8;
    c.pivot.y = 160;
    c.img_src = WX_IMG_GET(img_dial2_point_s);
    hand->second = lv_adv_class_hand_create(parent, &c);

    lv_img_set_angle(hand->hour, 0);
    lv_img_set_angle(hand->minute, 0);
    lv_img_set_angle(hand->second, 0);
}

static lv_obj_t *app_on_create(lv_adv_app_t *self)
{
    app_ctx_t *ctx = (app_ctx_t *)self;
    lv_obj_t *root = lv_adv_create_container(self->parent);

    lv_obj_t *bg = lv_image_create(root);
    lv_image_set_src(bg, WX_IMG_GET(img_dial2_bg));
    lv_obj_center(bg);

    clock_create(root, ctx);

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

LV_ADV_APP_DEF(dial_2);
