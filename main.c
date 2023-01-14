typedef unsigned long uint64_t;
typedef unsigned int uint32_t;

typedef uint64_t virtual_addr_t;

static inline void write32(virtual_addr_t addr, uint32_t value) {
	*((volatile uint32_t *)(addr)) = value;
}

static inline uint32_t read32(virtual_addr_t addr) {
	return *((volatile uint32_t *)(addr));
}

static inline uint64_t counter(void)
{
	uint64_t cnt;
	 __asm__ __volatile__("csrr %0, time\n" : "=r"(cnt) :: "memory");
	return cnt;
}

static inline void sdelay(unsigned long us)
{
	uint64_t t = counter() + us * 24;
	while(counter() <= t);
}

static void sys_uart_putc(char c)
{
	virtual_addr_t addr = 0x02500000;

	while((read32(addr + 0x7c) & (0x1 << 1)) == 0);
	write32(addr, c);
}

void _start(void)
{
	while(1){
		sys_uart_putc('h');
		sys_uart_putc('e');
		sys_uart_putc('l');
		sys_uart_putc('l');
		sys_uart_putc('o');
		sys_uart_putc('\r');
		sys_uart_putc('\n');
		sdelay(1000*1000);
	}
}