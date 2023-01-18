#include "types.h"

static inline void write32(virtual_addr_t addr, uint32_t value)
{
    *((volatile uint32_t *)(addr)) = value;
}

static inline uint32_t read32(virtual_addr_t addr)
{
    return( *((volatile uint32_t *)(addr)));
}

void sdelay(unsigned long us);