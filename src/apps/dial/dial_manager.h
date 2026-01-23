/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __DIAL_MANAGER_H__
#define __DIAL_MANAGER_H__

/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/
#include <watchx.h>
/* includes (local) ----------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines -------------------------------------------------------------------*/

#define DIAL_BUILTIN_NUM  2
#define DIAL_DOWNLOAD_NUM 1
#define DIAL_TOTAL_NUM    (DIAL_BUILTIN_NUM + DIAL_DOWNLOAD_NUM)

/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

lv_adv_app_t *dial_create_app(lv_obj_t *parent, int32_t dial_id, void *user_data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __DIAL_MANAGER_H__ */
