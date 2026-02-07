/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __WATCHX_FONT_H__
#define __WATCHX_FONT_H__

/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include <watchx.h>
/* includes (local) ----------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines -------------------------------------------------------------------*/

#define WX_FONT_NAME_DEFAULT "default"

/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/

#define WX_FONT(font_size) watchx_font_create(font_size)

/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

void watchx_font_init(void);
void watchx_font_deinit(void);

void watchx_font_set(const char *font_name);

lv_font_t *watchx_font_create(uint16_t font_size);
void watchx_font_delete(lv_font_t *font);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WATCHX_FONT_H__ */
