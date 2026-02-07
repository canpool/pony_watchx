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
#include <watchx_font.h>

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/

static const lv_adv_i18n_class_t i18n_class = {
    .get_text = lv_i18n_get_text,
    .create_font = watchx_font_create,
    .delete_font = watchx_font_delete,
};

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void lang_update_handler(lv_obj_t *obj)
{
    lv_adv_i18n_text_update_all(obj);
}

static void watchx_theme_init(void)
{
    lv_display_t *disp = lv_display_get_default();
    lv_theme_t *theme =
        lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE),
                              lv_palette_main(LV_PALETTE_RED), true, lv_adv_font(14));
    lv_display_set_theme(disp, theme);
}

static void watchx_language_init(void)
{
    lv_i18n_init(lv_i18n_language_pack);

    lv_adv_i18n_class_init(&i18n_class);
    lv_adv_page_lang_register_update_cb(lang_update_handler);

    watchx_setting_language();
}

int watchx_init(void)
{
    watchx_theme_init();

    watchx_font_init();
    watchx_language_init();

    lv_adv_page_manager_init();
    lv_adv_page_cache_add(LV_ADV_PAGE(menu), NULL);

    LV_ADV_PAGE_PUSH(home);

    return 0;
}

int watchx_deinit(void)
{
    watchx_font_deinit();

    return 0;
}
