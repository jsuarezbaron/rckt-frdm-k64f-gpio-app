/* setup.c - FRDM-K64F GPIO demo setup routine */

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
 * Initialize GPIO for the on-board RGB LED: PTB21, PTB22 and PTE26 as output.
 */

#include <zephyr.h>
#include <gpio.h>
#include <pinmux.h>
#include <pinmux/pinmux_k64.h>

#include "frdm_k64fLED.h"


struct device *pinmux;
struct device *gpio_a;
struct device *gpio_b;
struct device *gpio_e;

/*
 * setup - Configure the RGB LED GPIO pins for the application
 *
 * Returns DEV_OK if the configuration succeeded, otherwise DEV_FAIL.
 */

int setup (void)
    {
    int status;

    /* Get the device bindings */

	pinmux = device_get_binding(PINMUX_NAME);

	gpio_a = device_get_binding(CONFIG_GPIO_K64_A_DEV_NAME);
	gpio_b = device_get_binding(CONFIG_GPIO_K64_B_DEV_NAME);
	gpio_e = device_get_binding(CONFIG_GPIO_K64_E_DEV_NAME);

    if (pinmux == NULL)
        {
        PRINT("Pinmux device not found!\n");
        }

    if (gpio_a == NULL)
        {
        PRINT("GPIO Port A device not found!\n");
        }

    if (gpio_b == NULL)
        {
        PRINT("GPIO Port B device not found!\n");
        }

    if (gpio_e == NULL)
        {
        PRINT("GPIO Port E device not found!\n");
        }

    if (!pinmux || !gpio_a || !gpio_b || !gpio_e)
        {
        return DEV_FAIL;
        }

    /* Configure the SW3 GPIO pin: pull-up is required */

    status = pinmux_pin_set(pinmux, K64_PIN_PTA4, K64_PINMUX_FUNC_GPIO);

    if (status == DEV_OK)
        {
		status = gpio_pin_configure(gpio_a, 4, GPIO_DIR_IN | GPIO_PUD_PULL_UP);
        }

    if (status != DEV_OK)
        {
        PRINT("Pin %d of GPIO Port A not configured!! Stopped.\n", SW3);
        return(DEV_FAIL);
        }
    else
        {
        PRINT("Pin %d of GPIO Port A configured\n", SW3);
        }

    /* Configure the RGB LED GPIO pins */

    status = pinmux_pin_set(pinmux, K64_PIN_PTB22, K64_PINMUX_FUNC_GPIO);

    if (status == DEV_OK)
        {
		status = gpio_pin_configure(gpio_b, 22, GPIO_DIR_OUT);
        }

    if (status != DEV_OK)
        {
        PRINT("Pin %d of GPIO Port B not configured!! Stopped.\n", LED_R);
        return(DEV_FAIL);
        }
    else
        {
        PRINT("Pin %d of GPIO Port B configured\n", LED_R);
        }

    status = pinmux_pin_set(pinmux, K64_PIN_PTB21, K64_PINMUX_FUNC_GPIO);

    if (status == DEV_OK)
        {
		status = gpio_pin_configure(gpio_b, 21, GPIO_DIR_OUT);
        }

    if (status != DEV_OK)
        {
        PRINT("Pin %d of GPIO Port B not configured!! Stopped.\n", LED_B);
        return(DEV_FAIL);
        }
    else
        {
        PRINT("Pin %d of GPIO Port B configured\n", LED_B);
        }

    status = pinmux_pin_set(pinmux, K64_PIN_PTE26, K64_PINMUX_FUNC_GPIO);

    if (status == DEV_OK)
        {
		status = gpio_pin_configure(gpio_e, 26, GPIO_DIR_OUT);
        }

    if (status != DEV_OK)
        {
        PRINT("Pin %d of GPIO Port E not configured!! Stopped.\n", LED_G);
        return(DEV_FAIL);
        }
    else
        {
        PRINT("Pin %d of GPIO Port E configured\n", LED_G);
        }

    /* Set the GPIO output pins to turn off the RGB LED */

    status = gpio_pin_write(gpio_b, LED_R, LED_OFF);

    if (status != DEV_OK)
        {
        PRINT("Write to pin %d of GPIO Port B failed!! Stopped.\n", LED_R);
        return(DEV_FAIL);
        }

    status = gpio_pin_write(gpio_b, LED_B, LED_OFF);

    if (status != DEV_OK)
        {
        PRINT("Write to pin %d of GPIO Port B failed!! Stopped.\n", LED_B);
        return(DEV_FAIL);
        }

    status = gpio_pin_write(gpio_e, LED_G, LED_OFF);

    if (status != DEV_OK)
        {
        PRINT("Write to pin %d of GPIO Port E failed!! Stopped.\n", LED_G);
        return(DEV_FAIL);
        }

    return(DEV_OK);
    }
