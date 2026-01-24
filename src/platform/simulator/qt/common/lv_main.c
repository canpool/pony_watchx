/**
 * Copyright (C) 2025 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "lv_main.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include "watchx.h"

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void lv_adv_ctx_init(void)
{
    LV_LOG_USER("init");

    watchx_init();
}

static void lv_adv_ctx_destroy(void)
{
    LV_LOG_USER("destory");

    watchx_deinit();
}

void lv_adv_setup(void)
{
    lv_adv_ctx_t ctx = {
        .init = lv_adv_ctx_init,
        .destroy = lv_adv_ctx_destroy,
    };
    lv_adv_register_ctx(&ctx);
}
