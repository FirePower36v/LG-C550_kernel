/*
 * leds-msm-pmic-key.c - MSM PMIC LEDs driver.
 *
 * Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/leds.h>
#include <linux/gpio.h>

#include <mach/pmic.h>


#if defined (CONFIG_LGE_UNIFIED_LED)
#include <mach/board_lge.h>

struct msm_pmic_leds_pdata *leds_pdata = 0;

#else
#include <mach/board_lge.h>

#endif


/*LED has 15 steps (10mA per step). LED's  max power capacity is 150mA. (0~255 level)*/
#define MAX_KEYPAD_BL_LEVEL		16	// 150mA
#define TUNED_MAX_KEYPAD_BL_LEVEL	80	// 30mA ==> 2400 / 30 = 80

static void msm_qwertykey_bl_led_set(struct led_classdev *led_cdev,
	enum led_brightness value)
{
	int ret;

#if defined (CONFIG_LGE_UNIFIED_LED)
	ret = leds_pdata->msm_keypad_led_set(value / TUNED_MAX_KEYPAD_BL_LEVEL);
#else	/* origin */
#ifdef CONFIG_MACH_MSM7X27_THUNDERA
	/* jinkyu.choi@lge.com
	 * P505, use the android led interface values, 255,127,0
	 * LED current is controlled by arm9 AMSS with the given values.
	 */
	ret = pmic_set_led_intensity(LED_KEYPAD, value);
#else
	ret = pmic_set_led_intensity(LED_KEYPAD, value / TUNED_MAX_KEYPAD_BL_LEVEL);
#endif /* end of CONFIG_MACH_MSM7X27_THUNDERA */
#endif
	if (ret)
		dev_err(led_cdev->dev, "can't set keypad backlight\n");
}

static struct led_classdev msm_qwertykp_bl_led = {
	.name			= "keyboard-backlight",
	.brightness_set		= msm_qwertykey_bl_led_set,
	.brightness		= LED_OFF,
};

static int msm_qwertykey_led_probe(struct platform_device *pdev)
{
	int rc;
#if defined (CONFIG_LGE_UNIFIED_LED)
	leds_pdata = pdev->dev.platform_data;
#endif

#ifndef CONFIG_LGE_UNIFIED_LED
	if (pdev->dev.platform_data)
		msm_qwertykp_bl_led.name = pdev->dev.platform_data;
#endif

	rc = led_classdev_register(&pdev->dev, &msm_qwertykp_bl_led);
	if (rc) {
		dev_err(&pdev->dev, "unable to register led class driver\n");
		return rc;
	}
	msm_qwertykey_bl_led_set(&msm_qwertykp_bl_led, LED_OFF);
#if defined (CONFIG_LGE_UNIFIED_LED)
	leds_pdata->register_custom_leds(pdev);
#endif
	return rc;
}

static int __devexit msm_qwertykey_led_remove(struct platform_device *pdev)
{
	led_classdev_unregister(&msm_qwertykp_bl_led);
#if defined (CONFIG_LGE_UNIFIED_LED)
	leds_pdata->unregister_custom_leds();
#endif

	return 0;
}

#ifdef CONFIG_PM
static int msm_qwertykey_led_suspend(struct platform_device *dev,
		pm_message_t state)
{
	led_classdev_suspend(&msm_qwertykp_bl_led);

#if defined (CONFIG_LGE_UNIFIED_LED)
	leds_pdata->suspend_custom_leds();
#endif
	return 0;
}

static int msm_qwertykey_led_resume(struct platform_device *dev)
{
	led_classdev_resume(&msm_qwertykp_bl_led);
#if defined (CONFIG_LGE_UNIFIED_LED)
	leds_pdata->resume_custom_leds();
#endif

	return 0;
}
#else
#define msm_qwertykey_led_suspend NULL
#define msm_qwertykey_led_resume NULL
#endif

static struct platform_driver msm_qwertykey_led_driver = {
	.probe		= msm_qwertykey_led_probe,
	.remove		= __devexit_p(msm_qwertykey_led_remove),
	.suspend	= msm_qwertykey_led_suspend,
	.resume		= msm_qwertykey_led_resume,
	.driver		= {
		.name	= "pmic-key-leds",
		.owner	= THIS_MODULE,
	},
};

static int __init msm_qwertykey_led_init(void)
{
	return platform_driver_register(&msm_qwertykey_led_driver);
}
module_init(msm_qwertykey_led_init);

static void __exit msm_qwertykey_led_exit(void)
{
	platform_driver_unregister(&msm_qwertykey_led_driver);
}
module_exit(msm_qwertykey_led_exit);

MODULE_DESCRIPTION("MSM qwertykey LEDs driver");
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("platform:pmic-key-leds");

