#include "types.h"
#include "common.h"
#include "gpio.h"

static void sys_uart_putc(char c)
{
	virtual_addr_t addr = 0x02500000;

	while((read32(addr + 0x7c) & (0x1 << 1)) == 0);
	write32(addr, c);
}

void main(void)
{
	sys_uart_putc('h');
	sys_uart_putc('e');
	sys_uart_putc('l');
	sys_uart_putc('l');
	sys_uart_putc('o');
	d1_set_gpio_mode(GPIO_PORT_D, GPIO_PIN_22, GPIO_OUTPUT);
	while(1){
		d1_set_gpio_val(GPIO_PORT_D, GPIO_PIN_22, 0);
		sdelay(1000*1000);
		d1_set_gpio_val(GPIO_PORT_D, GPIO_PIN_22, 1);
        sdelay(1000 * 1000);
	}
}