#include "../include/stddef.h"
#include "../drivers/vga.h"
#include "main.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void)
{
	/* Initialize terminal interface */
	vga_initialize();

	/* Newline support is left as an exercise. */
	vga_print_string("Hello, kernel World!\n");
}