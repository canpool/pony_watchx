/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */


/* includes (local) ----------------------------------------------------------*/
/* includes (standard library, system) ---------------------------------------*/
#include <rtthread.h>
#ifdef USING_BUTTON_LIB
/* includes (other library) --------------------------------------------------*/
#include "littlevgl2rtt.h"
#include "button.h"
/* includes (project) --------------------------------------------------------*/

/* defines -------------------------------------------------------------------*/
#ifdef BSP_KEY1_ACTIVE_HIGH
#define BUTTON_ACTIVE_POL BUTTON_ACTIVE_HIGH
#else
#define BUTTON_ACTIVE_POL BUTTON_ACTIVE_LOW
#endif

#define SLEEP_CTRL_PIN (BSP_KEY1_PIN)

/* typedefs ------------------------------------------------------------------*/

typedef enum {
    KEYPAD_KEY_HOME = 2,
} keypad_key_code_t;

typedef enum {
    KEYPAD_KEY_STATE_REL,
    KEYPAD_KEY_STATE_PRESSED,
} keypad_key_state_t;

typedef struct {
    keypad_key_code_t last_key;
    keypad_key_state_t last_key_state;
} keypad_status_t;

/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/

static int32_t key1_button_handle = -1;
static keypad_status_t keypad_status;

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

void button_key_read(uint32_t *last_key, lv_indev_state_t *state)
{
    if (last_key && state) {
        *last_key = keypad_status.last_key;
        if (KEYPAD_KEY_STATE_REL == keypad_status.last_key_state) {
            *state = LV_INDEV_STATE_REL;
        } else {
            *state = LV_INDEV_STATE_PR;
            keypad_status.last_key_state = KEYPAD_KEY_STATE_REL;
        }
    }
}

/* button event handler in UI inactive state */
static void button_event_handler(int32_t pin, button_action_t action)
{
    lv_disp_trig_activity(NULL);
    switch (action) {
    case BUTTON_CLICKED: {
        keypad_status.last_key = KEYPAD_KEY_HOME;
        keypad_status.last_key_state = KEYPAD_KEY_STATE_PRESSED;   // value is 1
        break;
    }
    default:
        break;
    }
}

#endif /* USING_BUTTON_LIB */

void watchx_input_keypad_init(void)
{
#ifdef USING_BUTTON_LIB
    button_cfg_t cfg;

    cfg.pin = SLEEP_CTRL_PIN;
    cfg.active_state = BUTTON_ACTIVE_POL;
    cfg.mode = PIN_MODE_INPUT;
    cfg.button_handler = button_event_handler;
    int32_t id = button_init(&cfg);
    RT_ASSERT(id >= 0);
    RT_ASSERT(SF_EOK == button_enable(id));
    key1_button_handle = id;
#endif /* USING_BUTTON_LIB */
}
