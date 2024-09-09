/*
 * heartbeat.c
 *
 * Change Logs:
 * Date           Author            Notes
 * 2024-09-09     chasel            first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "board.h"

#ifndef PKG_HEARTBEAT_LED_PIN
#error "Please define at least one PKG_HEARTBEAT_LED_PIN"
#endif

#ifndef PKG_HEARTBEAT_LED_ACTIVE_LOGIC
#define PKG_HEARTBEAT_LED_ACTIVE_LOGIC     PIN_LOW
#endif

static rt_timer_t heartbeat;
static rt_uint32_t timeout = 0;
static rt_uint8_t index = 0;
static rt_uint32_t beat_time_table[] = {70, 315, 70, 945};

static void heartbeat_cb(void *parameter)
{
    if (index % 2) {
        rt_pin_write(HEARTBEAT_LED_PIN, ~HEARTBEAT_LED_ACTIVE_LOGIC);
    } else {
        rt_pin_write(HEARTBEAT_LED_PIN, HEARTBEAT_LED_ACTIVE_LOGIC);
    }

    timeout = rt_tick_from_millisecond(beat_time_table[index]);
    rt_timer_control(heartbeat, RT_TIMER_CTRL_SET_TIME, &timeout);
    rt_timer_start(heartbeat);

    if (++index >= 4) {
        index = 0;
    }
}

int heartbeat_init(void)
{
    rt_pin_mode(HEARTBEAT_LED_PIN, PIN_MODE_INPUT_PULLUP);
    rt_pin_write(HEARTBEAT_LED_PIN, ~HEARTBEAT_LED_ACTIVE_LOGIC); /* close led */

    heartbeat = rt_timer_create("heartbeat", heartbeat_cb,
                                RT_NULL, 10,
                                RT_TIMER_FLAG_ONE_SHOT);
    if (heartbeat != RT_NULL)
        rt_timer_start(heartbeat);

    return 0;
}
INIT_APP_EXPORT(heartbeat_init);