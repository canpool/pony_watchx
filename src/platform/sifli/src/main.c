#include "bf0_hal.h"
#include "drv_io.h"
#include "rtthread.h"
#include "stdio.h"
#include "string.h"

int main(void)
{
    rt_kprintf("Hello watchx!\n");

    while (1) {
        rt_thread_mdelay(1000);
    }
    return 0;
}
