#include <linux/init.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/regulator/machine.h>
#include <linux/i2c.h>
#include <mach/irqs.h>
#include <linux/power_supply.h>


#include "axp-cfg.h"
#include "axp-mfd.h"

static struct platform_device virt[]={
	{
			.name = "reg-virt-cs-ldo2",
			.id = -1,
			.dev		= {
				.platform_data = "axp20_analog/fm",
			}
 	},{
			.name = "reg-virt-cs-ldo3",
			.id = -1,
			.dev		= {
				.platform_data = "axp20_pll",
			}
 	},{
			.name = "reg-virt-cs-ldo4",
			.id = -1,
			.dev		= {
				.platform_data = "axp20_hdmi",
			}
 	},{
			.name = "reg-virt-cs-buck2",
			.id = -1,
			.dev		= {
				.platform_data = "axp20_core",
			}
 	},{
			.name = "reg-virt-cs-buck3",
			.id = -1,
			.dev		= {
				.platform_data = "axp20_ddr",
			}
	},{
			.name = "reg-virt-cs-ldoio0",
			.id = -1,
			.dev		= {
				.platform_data = "axp20_mic",
			}
	},
};



 static int __init virtual_init(void)
{
	int j,ret;
	for (j = 0; j < ARRAY_SIZE(virt); j++){ 
 		ret =  platform_device_register(&virt[j]);
  		if (ret)
				goto creat_devices_failed;
	}

	return ret;
	
creat_devices_failed:
	while (j--)
		platform_device_register(&virt[j]);
	return ret;

}
 
module_init(virtual_init);

static void __exit virtual_exit(void)
{
	int j;
	for (j = ARRAY_SIZE(virt) - 1; j >= 0; j--){ 
		platform_device_unregister(&virt[j]);
	}
}
module_exit(virtual_exit);

MODULE_DESCRIPTION("Krosspower axp regulator test");
MODULE_AUTHOR("Donglu Zhang Krosspower");
MODULE_LICENSE("GPL");