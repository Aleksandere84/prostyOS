#include "../include/stddef.h"
#include "../drivers/vga.h"
#include "main.h"

void kernel_main(void)
{
	/* Initialize terminal interface */
	vga_initialize();

	/* Newline support is left as an exercise. */
	vga_print_string("Hello, kernel World!\n");
}