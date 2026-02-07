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

#define WX_FONT_MIN_SIZE  8
#define WX_FONT_MAX_SIZE  48
#define WX_FONT_CACHE_NUM (((WX_FONT_MAX_SIZE - WX_FONT_MIN_SIZE) / 2) + 1)

/* typedefs ------------------------------------------------------------------*/

typedef struct {
    lv_font_t *font;
    int32_t refs;
} watchx_font_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/

#ifdef WX_USE_FILE_RESOURCE
#define TTF_PATH LV_ADV_FONT_RES("/DroidSansFallback")
#else
extern const unsigned char DroidSansFallback[];
extern const int DroidSansFallback_size;
#endif

/* variables (local) ---------------------------------------------------------*/

static watchx_font_t font_cache[WX_FONT_CACHE_NUM];

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

lv_font_t *watchx_font_create(uint16_t font_size)
{
    font_size = (font_size + 1) & ~1;
    if (font_size < WX_FONT_MIN_SIZE) {
        font_size = WX_FONT_MIN_SIZE;
    }
    if (font_size > WX_FONT_MAX_SIZE) {
        font_size = WX_FONT_MAX_SIZE;
    }
    uint16_t idx = (font_size - WX_FONT_MIN_SIZE) >> 1;
    if (font_cache[idx].font == NULL) {
#ifdef WX_USE_FILE_RESOURCE
        font_cache[idx].font =
            lv_freetype_font_create(TTF_PATH, LV_FREETYPE_FONT_RENDER_MODE_BITMAP, font_size,
                                    LV_FREETYPE_FONT_STYLE_NORMAL);
#else
        font_cache[idx].font =
            lv_tiny_ttf_create_data(DroidSansFallback, DroidSansFallback_size, font_size);
#endif
    }
    ++font_cache[idx].refs;
    return font_cache[idx].font;
}

void watchx_font_delete(lv_font_t *font)
{
    if (font == NULL) {
        return;
    }
    int i;
    for (i = 0; i < WX_FONT_CACHE_NUM; ++i) {
        if (font_cache[i].font == font) {
            break;
        }
    }
    if (i == WX_FONT_CACHE_NUM) {
        return;
    }
    if (font_cache[i].refs <= 0) {
        return;
    }
    if (--font_cache[i].refs != 0) {
        return;
    }
#ifdef WX_USE_FILE_RESOURCE
    lv_freetype_font_delete(font);
#else
    lv_tiny_ttf_destroy(font);
#endif
    font_cache[i].font = NULL;
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

void watchx_font_set(const char *font_name)
{

}
