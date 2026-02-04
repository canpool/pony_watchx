/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __WATCHX_ICON_H__
#define __WATCHX_ICON_H__

/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include "watchx_image.h"
/* includes (local) ----------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines -------------------------------------------------------------------*/

#define ICON_ARROW_RIGHT     WX_IMG_GET(img_arrow_right)
#define ICON_RADIO_UNCHECKED WX_IMG_GET(img_radio_unchecked)
#define ICON_RADIO_CHECKED   WX_IMG_GET(img_radio_checked)

/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

WX_IMG_DECLARE(img_arrow_right);
WX_IMG_DECLARE(img_radio_unchecked);
WX_IMG_DECLARE(img_radio_checked);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WATCHX_ICON_H__ */
