/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "dial_page.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/

typedef struct {
    lv_adv_subpage_t base;
    lv_adv_app_manager_t am;
    int32_t dial_id;
} subpage_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static lv_obj_t *subpage_on_create(lv_adv_subpage_t *self)
{
    subpage_ctx_t *ctx = (subpage_ctx_t *)self;
    lv_obj_t *root = lv_adv_create_container(self->parent);

    lv_adv_app_manager_init(&ctx->am);

    ctx->dial_id = 0;
    lv_adv_app_t *app = dial_create_app(root, ctx->dial_id, NULL);
    lv_adv_app_manager_load(&ctx->am, app);

    return root;
}

static void subpage_on_show(lv_adv_subpage_t *self)
{
    subpage_ctx_t *ctx = (subpage_ctx_t *)self;
    int32_t dial_id = ctx->dial_id;
    // TODO: get real dial id
    if (dial_id != ctx->dial_id) {
        ctx->dial_id = dial_id;
        lv_adv_app_t *app = dial_create_app(self->cont, dial_id, NULL);
        lv_adv_app_manager_load(&ctx->am, app);
    }
    lv_adv_app_manager_start(&ctx->am);
}

static void subpage_on_hide(lv_adv_subpage_t *self)
{
    subpage_ctx_t *ctx = (subpage_ctx_t *)self;
    lv_adv_app_manager_stop(&ctx->am);
}

static void subpage_on_destroy(lv_adv_subpage_t *self)
{
    subpage_ctx_t *ctx = (subpage_ctx_t *)self;
    lv_adv_app_manager_destroy(&ctx->am);
}

LV_ADV_SUBPAGE_DEF(dial);
