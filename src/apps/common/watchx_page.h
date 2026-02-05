/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __WATCHX_PAGE_H__
#define __WATCHX_PAGE_H__

/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include <watchx.h>
#include <watchx_font.h>
#include <watchx_image.h>
#include <watchx_icon.h>
#include <watchx_text.h>
#include <watchx_settings.h>
/* includes (local) ----------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

LV_ADV_PAGE_DECLARE(dummy);

LV_ADV_PAGE_DECLARE(home);
LV_ADV_SUBPAGE_DECLARE(dial);

LV_ADV_PAGE_DECLARE(dial_gallery);

LV_ADV_PAGE_DECLARE(menu);

LV_ADV_PAGE_DECLARE(setting);
LV_ADV_PAGE_DECLARE(setting_desktop);

LV_ADV_PAGE_DECLARE(flashlight);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WATCHX_PAGE_H__ */
