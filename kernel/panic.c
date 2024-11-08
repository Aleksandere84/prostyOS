#include "../drivers/vga.h"

void panic(char* error) {
    vga_initialize();
    vga_color = 4;
    vga_print_string("Kernel panic!\n");
    vga_color = 15;
    vga_print_string("Error: ");
    vga_print_string(error);
    vga_print_string("\n");
}