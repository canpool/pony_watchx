/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
#include "watchx_page.h"
/* includes (standard library, system) ---------------------------------------*/
#include <time.h>
/* includes (other library) --------------------------------------------------*/
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/

#define CALENDAR_HEADER_H        70
#define CALENDAR_HEDAER_PAD_TOP  15
#define CALENDAR_HEDAER_PAD_LEFT 40
#define CALENDAR_HEDAER_PAD_GAP  5
#define CALENDAR_HEDAER_BUTTON_W 48
#define CALENDAR_HEDAER_BUTTON_H 48
#define CALENDAR_BODY_PAD_TOP    5
#define CALENDAR_BODY_PAD_BOTTOM 40

/* typedefs ------------------------------------------------------------------*/

typedef struct {
    lv_adv_page_t base;
    // TODO: add others
} page_ctx_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/
/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

static void calendar_init_date(lv_obj_t *obj)
{
    time_t now;
    struct tm *t;

    time(&now);
    t = localtime(&now);

    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int minute = t->tm_min;
    int second = t->tm_sec;

    lv_calendar_set_today_date(obj, year, month, day);
    lv_calendar_set_showed_date(obj, year, month);
}

static lv_obj_t *page_on_create(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
    lv_obj_t *scr = lv_adv_create_screen();

    lv_obj_t *calendar = lv_calendar_create(scr);
    lv_obj_set_size(calendar, lv_pct(100), lv_pct(100));
    lv_obj_center(calendar);

    lv_obj_t *body = lv_obj_get_child(calendar, 0);
    if (body) {
        lv_obj_set_style_pad_top(body, CALENDAR_BODY_PAD_TOP, LV_PART_MAIN);
        lv_obj_set_style_pad_bottom(body, CALENDAR_BODY_PAD_BOTTOM, LV_PART_MAIN);
        lv_obj_update_layout(body);
    }

#if LV_USE_CALENDAR_HEADER_ARROW
    lv_obj_t *header = lv_calendar_header_arrow_create(calendar);

    lv_obj_set_height(header, CALENDAR_HEADER_H);
    lv_obj_set_style_pad_left(header, CALENDAR_HEDAER_PAD_LEFT, LV_PART_MAIN);
    lv_obj_set_style_pad_top(header, CALENDAR_HEDAER_PAD_TOP, LV_PART_MAIN);
    lv_obj_set_style_pad_right(header, CALENDAR_HEDAER_PAD_LEFT, LV_PART_MAIN);
    lv_obj_set_style_pad_bottom(header, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_gap(header, CALENDAR_HEDAER_PAD_GAP, LV_PART_MAIN);

    lv_obj_t *mo_prev = lv_obj_get_child(header, 0);   // month previous button
    lv_obj_t *mo_next = lv_obj_get_child(header, 2);   // month next button
    lv_obj_set_size(mo_prev, CALENDAR_HEDAER_BUTTON_W, CALENDAR_HEDAER_BUTTON_H);
    lv_obj_set_size(mo_next, CALENDAR_HEDAER_BUTTON_W, CALENDAR_HEDAER_BUTTON_H);
    lv_obj_set_style_radius(mo_prev, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_radius(mo_next, LV_RADIUS_CIRCLE, 0);
#endif

    calendar_init_date(calendar);

    return scr;
}

static void page_on_show(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
}

static void page_on_hide(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
}

static void page_on_destroy(lv_adv_page_t *self)
{
    // page_ctx_t *ctx = (page_ctx_t *)self;
}

static void page_on_back(lv_adv_page_t *self)
{
    lv_adv_page_back(NULL, LV_SCR_LOAD_ANIM_OUT_RIGHT, NULL);
}

LV_ADV_PAGE_DEF(calendar);
