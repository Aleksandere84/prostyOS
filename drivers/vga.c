#include "vga.h"
#include "../include/stddef.h"

uint16_t* vga_buffer = (uint16_t*)VGA_ADDRESS;
uint8_t vga_color = (VGA_COLOR_BLACK << 4) | VGA_COLOR_LIGHT_GREY; // bit layout is 4bit background, then foreground
uint16_t vga_row = 0;
uint16_t vga_column = 0;

uint16_t vga_entry(unsigned char character, uint8_t color)
{
    return (uint16_t)(character | (color << 8));
}

void vga_initialize(void) {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            vga_buffer[y * VGA_WIDTH + x] = vga_entry(' ', vga_color);
        }
    }
}

void vga_set_color(uint8_t color) {
    vga_color = color;
}

void vga_put_char(char c) {
    if (c == '\n') {
        vga_row++;
        vga_column = 0;

        if (vga_row == VGA_HEIGHT) {
            vga_scroll();
        }
        return;
    }

    vga_buffer[vga_row * VGA_WIDTH + vga_column] = vga_entry(c, vga_color);

    if (++vga_column == VGA_WIDTH) {
        vga_column = 0;
        vga_row++;
        
        if (vga_row == VGA_HEIGHT) {
            vga_scroll();
        }
    }
}

void vga_print_string(const char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        vga_put_char(str[i]);
    }
}
void vga_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	vga_buffer[index] = vga_entry(c, color);
}