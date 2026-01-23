/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* define to prevent recursive inclusion -------------------------------------*/
#ifndef __MENU_PAGE_H__
#define __MENU_PAGE_H__

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
} menu_item_t;

typedef lv_obj_t *(*menu_create_f)(lv_obj_t *parent, const menu_item_t *items, uint16_t item_cnt);

/* macro ---------------------------------------------------------------------*/
/* inlines -------------------------------------------------------------------*/
/* externs -------------------------------------------------------------------*/

lv_obj_t *menu_list_create(lv_obj_t *parent, const menu_item_t *items, uint16_t item_cnt);
lv_obj_t *menu_cellular_create(lv_obj_t *parent, const menu_item_t *items, uint16_t item_cnt);
void menu_item_event_handler(lv_event_t *e);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MENU_PAGE_H__ */
