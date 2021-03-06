#ifndef IMG_H
#define IMG_H
#ifdef __cplusplus
extern "C" {
#endif

#include <avr/pgmspace.h>

// belt1_1.bmp / 24x4
PROGMEM const unsigned char bitmapBelt1_1[] = {
	24, 4,
	0x49,0x24,0x92,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x49,0x24,0x92
};

// belt1_2.bmp / 24x4
PROGMEM const unsigned char bitmapBelt1_2[] = {
	24, 4,
	0x24,0x92,0x48,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0x12,0x49,0x24
};

// belt1_3.bmp / 24x4
PROGMEM const unsigned char bitmapBelt1_3[] = {
	24, 4,
	0x12,0x49,0x24,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x24,0x92,0x48
};

// belt2_1.bmp / 24x4
PROGMEM const unsigned char bitmapBelt2_1[] = {
	24, 4,
	0x49,0x24,0x92,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x49,0x24,0x92
};

// belt2_2.bmp / 24x4
PROGMEM const unsigned char bitmapBelt2_2[] = {
	24, 4,
	0x12,0x49,0x24,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x24,0x92,0x48
};

// belt2_3.bmp / 24x4
PROGMEM const unsigned char bitmapBelt2_3[] = {
	24, 4,
	0x24,0x92,0x48,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0x12,0x49,0x24
};

// chr1_1.bmp / 8x8
PROGMEM const unsigned char bitmapChr1_1[] = {
	8, 8,
	0x1C,0x1C,0x10,0x7C,0xDB,0x18,0x1C,0x76
};

// chr1_2.bmp / 8x8
PROGMEM const unsigned char bitmapChr1_2[] = {
	8, 8,
	0x1C,0x1C,0x18,0x38,0x7C,0x1B,0x3C,0x30
};

// chr1_3.bmp / 8x8
PROGMEM const unsigned char bitmapChr1_3[] = {
	8, 8,
	0x1C,0x1C,0x18,0x7A,0xDE,0x18,0x3E,0x66
};

// chr2_1.bmp / 8x8
PROGMEM const unsigned char bitmapChr2_1[] = {
	8, 8,
	0x38,0x38,0x08,0x3E,0xDB,0x18,0x38,0x6E
};

// chr2_2.bmp / 8x8
PROGMEM const unsigned char bitmapChr2_2[] = {
	8, 8,
	0x38,0x38,0x18,0x1C,0x3E,0xD8,0x3C,0x0C
};

// chr2_3.bmp / 8x8
PROGMEM const unsigned char bitmapChr2_3[] = {
	8, 8,
	0x38,0x38,0x18,0x5E,0x7B,0x18,0x7C,0x66
};

// gauge1_1.bmp / 24x8
PROGMEM const unsigned char bitmapGauge1_1[] = {
	24, 8,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDB,0x6D,0x80,0xDB,0x6D,0x80
};

// gauge1_2.bmp / 24x8
PROGMEM const unsigned char bitmapGauge1_2[] = {
	24, 8,
	0x00,0x00,0x00,0xC0,0x00,0x00,0xC0,0x00,0x00,0xC0,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0xDB,0x6D,0x80,0xDB,0x6D,0x80
};

// gauge1_3.bmp / 24x8
PROGMEM const unsigned char bitmapGauge1_3[] = {
	24, 8,
	0x00,0x00,0x00,0xD8,0x00,0x00,0xD8,0x00,0x00,0xD8,0x00,0x00,0xD8,0x00,0x00,0x00,0x00,0x00,0xDB,0x6D,0x80,0xDB,0x6D,0x80
};

// gauge1_4.bmp / 24x8
PROGMEM const unsigned char bitmapGauge1_4[] = {
	24, 8,
	0x00,0x00,0x00,0xDB,0x00,0x00,0xDB,0x00,0x00,0xDB,0x00,0x00,0xDB,0x00,0x00,0x00,0x00,0x00,0xDB,0x6D,0x80,0xDB,0x6D,0x80
};

// gauge1_5.bmp / 24x8
PROGMEM const unsigned char bitmapGauge1_5[] = {
	24, 8,
	0x00,0x00,0x00,0xDB,0x60,0x00,0xDB,0x60,0x00,0xDB,0x60,0x00,0xDB,0x60,0x00,0x00,0x00,0x00,0xDB,0x6D,0x80,0xDB,0x6D,0x80
};

// gauge1_6.bmp / 24x8
PROGMEM const unsigned char bitmapGauge1_6[] = {
	24, 8,
	0x00,0x00,0x00,0xDB,0x6C,0x00,0xDB,0x6C,0x00,0xDB,0x6C,0x00,0xDB,0x6C,0x00,0x00,0x00,0x00,0xDB,0x6D,0x80,0xDB,0x6D,0x80
};

// gauge1_7.bmp / 24x8
PROGMEM const unsigned char bitmapGauge1_7[] = {
	24, 8,
	0x00,0x00,0x00,0xDB,0x6D,0x80,0xDB,0x6D,0x80,0xDB,0x6D,0x80,0xDB,0x6D,0x80,0x00,0x00,0x00,0xDB,0x6D,0x80,0xDB,0x6D,0x80
};

// plate.bmp / 24x4
PROGMEM const unsigned char bitmapPlate[] = {
	24, 4,
	0xFF,0xFF,0xFF,0x80,0x00,0x01,0x80,0x00,0x01,0xFF,0xFF,0xFF
};

// spring1_1.bmp / 24x4
PROGMEM const unsigned char bitmapSpring1_1[] = {
	24, 4,
	0xFF,0xFF,0xFF,0x49,0x24,0x92,0x49,0x24,0x92,0xFF,0xFF,0xFF
};

// spring1_2.bmp / 24x4
PROGMEM const unsigned char bitmapSpring1_2[] = {
	24, 4,
	0x00,0x00,0x00,0xFF,0xFF,0xFF,0x49,0x24,0x92,0xFF,0xFF,0xFF
};

// spring1_3.bmp / 24x5
PROGMEM const unsigned char bitmapSpring1_3[] = {
	24, 5,
	0xFF,0xFF,0xFF,0x49,0x24,0x92,0x49,0x24,0x92,0x49,0x24,0x92,0xFF,0xFF,0xFF
};

// wall.bmp / 8x8
PROGMEM const unsigned char bitmapWall[] = {
	8, 8,
	0xF0,0x90,0x90,0x90,0x90,0x90,0x90,0xF0
};


#ifdef __cplusplus
}
#endif
#endif
