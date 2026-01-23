/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "watchx_font.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/

extern const unsigned char DroidSansFallback[];
extern const int DroidSansFallback_size;

/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

lv_font_t *watchx_font_create(uint16_t font_size)
{
    lv_font_t *font = lv_tiny_ttf_create_data(DroidSansFallback, DroidSansFallback_size, font_size);
    return font;
}

void watchx_font_delete(const lv_font_t *font)
{
    lv_tiny_ttf_destroy((lv_font_t *)font);
}

#if LV_ADV_FONT_CUSTOM

const lv_font_t *lv_adv_font(uint16_t font_size)
{
    return watchx_font_create(font_size);
}

#endif

void watchx_font_init(void)
{
}

void watchx_font_deinit(void)
{
}
