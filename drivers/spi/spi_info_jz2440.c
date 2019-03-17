#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/list.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/syscore_ops.h>
#include <linux/platform_device.h>
#include <linux/spi/spi.h>
#include <linux/spi/spi_gpio.h>
#include <linux/module.h>


static struct spi_board_info __initdata spi_info_jz2440[] = {
	[0] = {
		.modalias	= "oled",
		.bus_num	= 1,
		.mode		= SPI_MODE_0,	/* CPOL=0, CPHA=0 */
		.max_speed_hz	= 10000000,
		.chip_select	= S3C2410_GPF(1), /* oled_cs */
		.platform_data	= (const void *)S3C2410_GPG(4), /* oled_dc */
	}, {
		.modalias	= "100ask_spi_flash",
		.bus_num	= 1,
		.mode		= SPI_MODE_0,	/* CPOL=0, CPHA=0 */
		.max_speed_hz	= 80000000,
		.chip_select	= S3C2410_GPG(2), /* flash_cs */
	},
};

static int __init spi_info_jz2440_init(void)
{
	return spi_register_board_info(spi_info_jz2440, ARRAY_SIZE(spi_info_jz2440));
}

module_init(spi_info_jz2440_init);
MODULE_DESCRIPTION("OLED SPI Info");
MODULE_AUTHOR("allen");
MODULE_LICENSE("GPL");

