#include "stdio.h"
#include "../drivers/vga.h"

printf(char* string_to_print)
{
    vga_print_string(string_to_print);
}
