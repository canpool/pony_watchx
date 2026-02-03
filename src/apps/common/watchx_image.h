/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __WATCHX_IMAGE_H__
#define __WATCHX_IMAGE_H__

/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include <watchx.h>
/* includes (local) ----------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/

#ifdef WX_USE_FILE_RESOURCE
#define WX_IMG_GET(name) LV_ADV_IMG_RES("/" #name)
#else
#define WX_IMG_GET(name)     (const void *)&name
#endif

#define WX_IMG_DECLARE(name) LV_IMAGE_DECLARE(name)

/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

WX_IMG_DECLARE(img_logo);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WATCHX_IMAGE_H__ */
