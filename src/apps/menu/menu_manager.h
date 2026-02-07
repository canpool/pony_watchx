/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __MENU_MANAGER_H__
#define __MENU_MANAGER_H__

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

enum {
    MENU_ID_LIST,
    MENU_ID_CELLULAR,
    MENU_ID_NUM,
};

/* macro ---------------------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

int menu_set_id(int32_t id);
int menu_get_id(int32_t *id);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MENU_MANAGER_H__ */
