/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __SETTING_PAGE_H__
#define __SETTING_PAGE_H__

/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include "watchx_page.h"
/* includes (local) ----------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/

typedef struct {
    const char *title;
    const void *icon;
    const lv_adv_page_class_t *page;
} setting_item_t;

typedef struct {
    const char *title;
    const void *icon;
} radio_item_t;

/* macro ---------------------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

WX_IMG_DECLARE(img_setting_desktop);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SETTING_PAGE_H__ */
