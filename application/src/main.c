/* main.c - FRDM-K64F GPIO demo */

/*
 * Copyright (c) 2015-2016 Wind River Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#if defined(CONFIG_STDOUT_CONSOLE)
#include <stdio.h>
#define PRINT           printf
#else
#include <misc/printk.h>
#define PRINT           printk
#endif

/*
 * A GPIO demo that runs an endless loop that sets the
 * on-board RGB LED to display a sequence of color combinations.
 */

#include <zephyr.h>
#include <gpio.h>

#include "frdm_k64fLED.h"

/* specify delay between greetings (in ms); compute equivalent in ticks */

#define SLEEPTIME  1000
#define SLEEPTICKS (SLEEPTIME * sys_clock_ticks_per_sec / 1000)


/*
 * main - GPIO demo
 *
 */
void main(void)
    {
    uint32_t sw_value;
    uint32_t led_value = 0;

    if (setup() != DEV_OK)
        return;

    while (1)
        {
        /* set to next LED state if switch is not pressed */

        gpio_pin_read(gpio_a, SW3, &sw_value);

        if (sw_value == SW_OFF) {
            if (++led_value > 7)
                led_value = 0;
        }

        switch (led_value)
            {
            case 0: // OFF
                PRINT("LED is OFF\n");
                gpio_pin_write(gpio_b, LED_R, LED_OFF);
                gpio_pin_write(gpio_b, LED_B, LED_OFF);
                gpio_pin_write(gpio_e, LED_G, LED_OFF);
                break;
            case 1: // RED
                PRINT("LED is Red\n");
                gpio_pin_write(gpio_b, LED_R, LED_ON);
                break;
            case 2: // BLUE
                PRINT("LED is Blue\n");
                gpio_pin_write(gpio_b, LED_R, LED_OFF);
                gpio_pin_write(gpio_b, LED_B, LED_ON);
                break;
            case 3: // GREEN
                PRINT("LED is Green\n");
                gpio_pin_write(gpio_b, LED_B, LED_OFF);
                gpio_pin_write(gpio_e, LED_G, LED_ON);
                break;
            case 4: // RED+BLUE
                PRINT("LED is Red+Blue\n");
                gpio_pin_write(gpio_e, LED_G, LED_OFF);
                gpio_pin_write(gpio_b, LED_R, LED_ON);
                gpio_pin_write(gpio_b, LED_B, LED_ON);
                break;
            case 5: // RED+GREEN
                PRINT("LED is Red+Green\n");
                gpio_pin_write(gpio_b, LED_B, LED_OFF);
                gpio_pin_write(gpio_e, LED_G, LED_ON);
                break;
            case 6: // BLUE+GREEN
                PRINT("LED is Blue+Green\n");
                gpio_pin_write(gpio_b, LED_R, LED_OFF);
                gpio_pin_write(gpio_b, LED_B, LED_ON);
                break;
            case 7: // RED+BLUE+GREEN
                PRINT("LED is Red+Blue+Green\n");
                gpio_pin_write(gpio_b, LED_R, LED_ON);
                break;
            default:
                PRINT ("Error - Out of range value: %d\n", led_value);
                led_value=0;
                break;
            }

        /* wait a while, then loop again */
        task_sleep(SLEEPTICKS);
        }
    }


