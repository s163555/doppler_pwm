/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Sample app to demonstrate PWM-based LED fade
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>

static const struct pwm_dt_spec pwm_t1 = PWM_DT_SPEC_GET(DT_ALIAS(pwmch1));
//static const struct pwm_dt_spec pwm_ch1n = PWM_DT_SPEC_GET(DT_ALIAS(pwmch1n));
static const struct pwm_dt_spec pwm_t2 = PWM_DT_SPEC_GET(DT_ALIAS(pwmch2));
#define SLEEP_MSEC	25U

void main(void)
{
	uint32_t pulse_width_t1 = 152U;
	uint32_t pulse_width_t2 = 1515U;
	int error = 0;

	printk("PWM-firmware API\n");
	if (!device_is_ready(pwm_t1.dev)) {
		printk("Error: PWM device %s is not ready\n",
		       pwm_t1.dev->name);
		return;
	}

	if (!device_is_ready(pwm_t2.dev)) {
		printk("Error: PWM device %s is not ready\n",
		       pwm_t2.dev->name);
		return;
	}

	while (1) {
		error = pwm_set_pulse_dt(&pwm_t1, pulse_width_t1);
		if (error) {
			printk("Error ch1 %d: failed to set pulse width\n", error);
			return;
		}
		error = pwm_set_pulse_dt(&pwm_t2, pulse_width_t2);
		if (error) {
			printk("Error ch1n %d: failed to set pulse width\n", error);
			return;
		}
		k_sleep(K_MSEC(SLEEP_MSEC));
	}
}
