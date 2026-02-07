/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __WATCHX_SETTINGS_H__
#define __WATCHX_SETTINGS_H__

/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
/* includes (local) ----------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines -------------------------------------------------------------------*/

#define WX_KEY_DIAL                                  "ui.dial"
#define WX_KEY_DESKTOP                               "ui.desktop"
#define WX_KEY_LANGUAGE                              "ui.lang"
#define WX_KEY_ABCDEFGHIJKLMNOPQRSTUVWXYZ_1234567890 "format"

/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

void watchx_setting_language(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __WATCHX_SETTINGS_H__ */
