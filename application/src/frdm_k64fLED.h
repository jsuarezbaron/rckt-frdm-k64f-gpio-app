/* frdm_k64fLED.h - On-board RGB LED and switch definitions */

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

/* RGB LED states - inverse of logic value */
#define LED_ON   0
#define LED_OFF  1

/* RGB LED pins */
#define LED_R    22  /* Port B pin */
#define LED_B    21  /* Port B pin */
#define LED_G    26  /* Port E pin */

/* SW3 states- inverse of logic value */
#define SW_ON    0
#define SW_OFF   1

/* SW3 pin */
#define SW3       4  /* Port A pin */

/* device bindings */

extern struct device *gpio_a;
extern struct device *gpio_b;
extern struct device *gpio_e;

/* function declarations */

int setup (void);

