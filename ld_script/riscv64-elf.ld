OUTPUT_FORMAT("elf64-littleriscv")
OUTPUT_ARCH(riscv)
ENTRY(_start)

STACK_SIZE = 0x100000;

MEMORY
{
	ram  : org = 0x40000000, len = 64M
}
SECTIONS
{
	.text :
	{
		*(.init)
		*(.text*)
	} > ram

	.rodata ALIGN(16) :
	{
		*(.rodata*)
		*(.srodata*)
	} > ram

	.data ALIGN(16) :
	{
		PROVIDE(__global_pointer$ = . + 0x800);
		*(.sdata*)
		*(.data*)
		. = ALIGN(8);
	} > ram

	.bss ALIGN(16) (NOLOAD) :
	{
		*(.bss*)
		*(.sbss*)
		. = ALIGN(8);
	} > ram

	.stack ALIGN(16) (NOLOAD) :
	{
		PROVIDE(__stack_start = .);
		. += STACK_SIZE;
		. = ALIGN(16);
		PROVIDE(__stack_end = .);
	} > ram
}