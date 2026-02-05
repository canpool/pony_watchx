/**
 * Copyright (C) 2026 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 */

/* includes (local) ----------------------------------------------------------*/
/* includes (standard library, system) ---------------------------------------*/
#include <rtthread.h>
#ifdef PKG_USING_FLASHDB
#include <string.h>
/* includes (other library) --------------------------------------------------*/
#include <fal.h>
#include <flashdb.h>
#include <lv_adv.h>
/* includes (project) --------------------------------------------------------*/
#include "ptab.h"

/* defines -------------------------------------------------------------------*/
/* typedefs ------------------------------------------------------------------*/
/* macro ---------------------------------------------------------------------*/
/* functions (prototype/declaration) -----------------------------------------*/
/* variables (extern) --------------------------------------------------------*/
/* variables (local) ---------------------------------------------------------*/

static lv_adv_kv_drv_t kvdb_drv;

#ifdef FDB_USING_KVDB

#define KVDB_NAME "app"
#define KVDB_PATH "app"
#define KVDB_MAX  (KVDB_APP_REGION_SIZE)

static struct fdb_kvdb g_kvdb_db;
static fdb_kvdb_t p_kvdb_db = &g_kvdb_db;
static struct rt_mutex g_kvdb_db_mutex;

#endif   // FDB_USING_KVDB

/* variables (global) --------------------------------------------------------*/
/* functions (inline) --------------------------------------------------------*/
/* functions (implementation) ------------------------------------------------*/

#ifdef FDB_USING_KVDB

static void lock(fdb_db_t db)
{
    rt_mutex_take(&g_kvdb_db_mutex, RT_WAITING_FOREVER);
}

static void unlock(fdb_db_t db)
{
    rt_mutex_release(&g_kvdb_db_mutex);
}

static int kvdb_init(void)
{
    int ret = -1;
    fdb_err_t err;

    /* mutex initialization. */
    rt_mutex_init(&g_kvdb_db_mutex, "kvdb_mtx", RT_IPC_FLAG_FIFO);

    memset(p_kvdb_db, 0, sizeof(*p_kvdb_db));

    /* set lock/unlock interface. */
    fdb_kvdb_control(p_kvdb_db, FDB_KVDB_CTRL_SET_LOCK, lock);
    fdb_kvdb_control(p_kvdb_db, FDB_KVDB_CTRL_SET_UNLOCK, unlock);

    err = fdb_kvdb_init(p_kvdb_db, KVDB_NAME, KVDB_PATH, NULL, NULL);
    if (err == FDB_NO_ERR) {
        ret = 0;
    }

    return ret;
}

lv_adv_kv_res_t kvdb_set(lv_adv_kv_drv_t *drv, const char *key, const char *value)
{
    LV_UNUSED(drv);
    fdb_err_t ret = fdb_kv_set(p_kvdb_db, key, value);
    if (ret != FDB_NO_ERR) {
        return LV_ADV_KV_RES_UNKNOWWN;
    }
    return LV_ADV_KV_RES_OK;
}

lv_adv_kv_res_t kvdb_get(lv_adv_kv_drv_t *drv, const char *key, char *value, uint32_t value_size)
{
    LV_UNUSED(drv);
    char *val = fdb_kv_get(p_kvdb_db, key);
    if (val == NULL) {
        return LV_ADV_KV_RES_UNKNOWWN;
    }
    lv_strlcpy(value, val, value_size);
    return LV_ADV_KV_RES_OK;
}

lv_adv_kv_res_t kvdb_del(lv_adv_kv_drv_t *drv, const char *key)
{
    LV_UNUSED(drv);
    fdb_err_t ret = fdb_kv_del(p_kvdb_db, key);
    if (ret != FDB_NO_ERR) {
        return LV_ADV_KV_RES_UNKNOWWN;
    }
    return LV_ADV_KV_RES_OK;
}

#endif   // FDB_USING_KVDB

void watchx_kvdb_init(void)
{
    if (kvdb_init() != 0) {
        return;
    }
    lv_adv_kv_drv_t *drv = &kvdb_drv;
    lv_adv_kv_drv_init(drv);

    drv->set = kvdb_set;
    drv->get = kvdb_get;
    drv->del = kvdb_del;

    lv_adv_kv_register_drv(drv);
}

#else
void watchx_kvdb_init(void)
{
}
#endif   // PKG_USING_FLASHDB
