/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include <watchx.h>
#include <watchx_page.h>

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void watchx_theme_init(void)
{
    lv_display_t *disp = lv_display_get_default();
    lv_theme_t *theme =
        lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE),
                              lv_palette_main(LV_PALETTE_RED), true, lv_adv_font(14));
    lv_display_set_theme(disp, theme);
}

int watchx_init(void)
{
    watchx_theme_init();

    lv_adv_page_manager_init();

    LV_ADV_PAGE_PUSH(home);

    return 0;
}

int watchx_deinit(void)
{
    return 0;
}
