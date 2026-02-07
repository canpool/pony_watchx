/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "watchx_text.h"
#include "watchx_font.h"
/* includes (standard library, system) ---------------------------------------*/
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

void watchx_text_set(lv_obj_t *obj, const char *txt, uint16_t font_size)
{
    lv_adv_i18n_text_set(obj, txt, font_size);
}

void watchx_text_update(lv_obj_t *obj, const char *txt)
{
    lv_adv_i18n_text_update_tr_id(obj, txt);
}
