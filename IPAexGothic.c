#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/
// 「テスト時分日月火水木金土年秒午前後無線今明昨」
// 「 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~」

#ifndef IPAEXGOTHIC
#define IPAEXGOTHIC 1
#endif

#if IPAEXGOTHIC

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */
    0x0,

    /* U+21 "!" */
    0xff, 0xb0,

    /* U+22 "\"" */
    0xb6, 0xd0,

    /* U+23 "#" */
    0x0, 0x12, 0x12, 0x12, 0xff, 0x24, 0x24, 0x24,
    0xff, 0x24, 0x44, 0x48, 0x48, 0x48,

    /* U+24 "$" */
    0x10, 0x73, 0x1c, 0x8, 0x18, 0x1c, 0xe, 0x6,
    0x6, 0xe, 0x37, 0xc2, 0x4, 0x0,

    /* U+25 "%" */
    0x70, 0x28, 0x84, 0x88, 0x88, 0x90, 0x89, 0x7,
    0x2e, 0x5, 0x30, 0x91, 0x9, 0x11, 0x11, 0x21,
    0xb4, 0xe,

    /* U+26 "&" */
    0x1c, 0x8, 0x82, 0x20, 0x88, 0x34, 0x6, 0x7,
    0x8b, 0x12, 0xc3, 0xb0, 0x4e, 0x3d, 0xf1,

    /* U+27 "'" */
    0xf0,

    /* U+28 "(" */
    0x2d, 0x29, 0x24, 0x92, 0x44, 0x89,

    /* U+29 ")" */
    0x91, 0x22, 0x49, 0x24, 0x94, 0xa4,

    /* U+2A "*" */
    0x4d, 0x6d, 0x40,

    /* U+2B "+" */
    0x8, 0x4, 0x2, 0x1, 0xf, 0xf8, 0x40, 0x20,
    0x10, 0x8, 0x0,

    /* U+2C "," */
    0x6d, 0x20,

    /* U+2D "-" */
    0xf0,

    /* U+2E "." */
    0xc0,

    /* U+2F "/" */
    0x4, 0x20, 0x82, 0x10, 0x41, 0x8, 0x20, 0x84,
    0x10, 0x42, 0x8, 0x0,

    /* U+30 "0" */
    0x3c, 0x66, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x42, 0x66, 0x3c,

    /* U+31 "1" */
    0x3f, 0x91, 0x11, 0x11, 0x11, 0x11, 0x10,

    /* U+32 "2" */
    0x3c, 0x62, 0xc1, 0x41, 0x1, 0x2, 0xc, 0x18,
    0x20, 0x40, 0xc0, 0xff,

    /* U+33 "3" */
    0x3c, 0x63, 0x41, 0x1, 0x3, 0x1c, 0x2, 0x1,
    0x1, 0x41, 0x63, 0x3c,

    /* U+34 "4" */
    0x6, 0x3, 0x2, 0x83, 0x43, 0x21, 0x11, 0x89,
    0x84, 0xff, 0x81, 0x0, 0x80, 0x40,

    /* U+35 "5" */
    0x7f, 0x60, 0x40, 0x40, 0x5c, 0x62, 0x1, 0x1,
    0x1, 0x41, 0x62, 0x3c,

    /* U+36 "6" */
    0x1e, 0x63, 0x40, 0x80, 0xbc, 0xc2, 0x81, 0x81,
    0x81, 0x81, 0x42, 0x3c,

    /* U+37 "7" */
    0xff, 0x3, 0x2, 0x4, 0x4, 0xc, 0x8, 0x18,
    0x10, 0x30, 0x30, 0x30,

    /* U+38 "8" */
    0x1e, 0x63, 0x41, 0x41, 0x41, 0x36, 0x2e, 0xc1,
    0x81, 0x81, 0xc3, 0x3c,

    /* U+39 "9" */
    0x3c, 0x42, 0x82, 0x81, 0x81, 0x43, 0x3d, 0x1,
    0x1, 0x2, 0xc6, 0x78,

    /* U+3A ":" */
    0xc1, 0x80,

    /* U+3B ";" */
    0x50, 0x1, 0x58,

    /* U+3C "<" */
    0x1, 0x83, 0x6, 0xc, 0x8, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80,

    /* U+3D "=" */
    0xff, 0x80, 0x0, 0x1f, 0xf0,

    /* U+3E ">" */
    0xc0, 0x18, 0x3, 0x0, 0x60, 0x8, 0x18, 0x30,
    0x60, 0xc0, 0x0,

    /* U+3F "?" */
    0x3c, 0x8f, 0x8, 0x10, 0x61, 0x86, 0x8, 0x10,
    0x0, 0x40, 0x80,

    /* U+40 "@" */
    0xf, 0x83, 0x6, 0x67, 0xa4, 0x99, 0x91, 0x99,
    0x11, 0x91, 0x19, 0x32, 0xcd, 0xc4, 0x0, 0x30,
    0x61, 0xf8,

    /* U+41 "A" */
    0xc, 0x3, 0x0, 0xe0, 0x48, 0x12, 0xc, 0xc2,
    0x10, 0xfc, 0x60, 0x90, 0x24, 0xf, 0x3,

    /* U+42 "B" */
    0xf8, 0x86, 0x82, 0x82, 0x86, 0xf8, 0x86, 0x81,
    0x81, 0x81, 0x82, 0xfc,

    /* U+43 "C" */
    0x1e, 0x10, 0xd0, 0x30, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x80, 0x20, 0x48, 0x63, 0xc0,

    /* U+44 "D" */
    0xfc, 0x41, 0x20, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xc0, 0xa0, 0x9f, 0x80,

    /* U+45 "E" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x2, 0x7, 0xf0,

    /* U+46 "F" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x2, 0x4, 0x0,

    /* U+47 "G" */
    0x1f, 0x8, 0x64, 0xe, 0x0, 0x80, 0x20, 0x8,
    0x3e, 0x1, 0x80, 0x50, 0x12, 0xc, 0x7c,

    /* U+48 "H" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xf, 0xfe, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x30, 0x10,

    /* U+49 "I" */
    0xff, 0xf0,

    /* U+4A "J" */
    0x11, 0x11, 0x11, 0x11, 0x11, 0x1e,

    /* U+4B "K" */
    0x82, 0x86, 0x8c, 0x98, 0xb0, 0xe0, 0xd0, 0x98,
    0x8c, 0x86, 0x82, 0x83,

    /* U+4C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82, 0x8,
    0x3f,

    /* U+4D "M" */
    0xc0, 0x78, 0xf, 0x83, 0xd0, 0x5a, 0xb, 0x62,
    0x64, 0x4c, 0xd9, 0x8a, 0x31, 0x46, 0x38, 0xc2,
    0x10,

    /* U+4E "N" */
    0xc0, 0xf0, 0x68, 0x36, 0x19, 0x8c, 0x46, 0x33,
    0xd, 0x82, 0xc1, 0xe0, 0x70, 0x10,

    /* U+4F "O" */
    0x1f, 0x4, 0x11, 0x1, 0x60, 0x38, 0x3, 0x0,
    0x60, 0xc, 0x1, 0xc0, 0x68, 0x8, 0x82, 0xf,
    0x80,

    /* U+50 "P" */
    0xf9, 0xe, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x2, 0x4, 0x0,

    /* U+51 "Q" */
    0x1f, 0x4, 0x11, 0x1, 0x60, 0x38, 0x3, 0x0,
    0x60, 0xc, 0x1, 0xc6, 0x28, 0x68, 0x83, 0xf,
    0xb0, 0x2,

    /* U+52 "R" */
    0xf8, 0x84, 0x82, 0x82, 0x82, 0x84, 0xf8, 0x8c,
    0x84, 0x86, 0x82, 0x83,

    /* U+53 "S" */
    0x79, 0x8e, 0x4, 0xc, 0xe, 0x7, 0x3, 0x3,
    0x7, 0x1b, 0xc0,

    /* U+54 "T" */
    0xff, 0xc2, 0x0, 0x80, 0x20, 0x8, 0x2, 0x0,
    0x80, 0x20, 0x8, 0x2, 0x0, 0x80, 0x20,

    /* U+55 "U" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xc0, 0x50, 0x47, 0xc0,

    /* U+56 "V" */
    0xc0, 0xd0, 0x34, 0x9, 0x86, 0x21, 0xc, 0x43,
    0x30, 0x48, 0x1a, 0x3, 0x80, 0xc0, 0x30,

    /* U+57 "W" */
    0xc1, 0x6, 0x86, 0x9, 0xe, 0x13, 0x14, 0x66,
    0x28, 0x84, 0xd9, 0x9, 0x16, 0x1a, 0x2c, 0x14,
    0x50, 0x30, 0xe0, 0x60, 0xc0, 0xc1, 0x0,

    /* U+58 "X" */
    0x60, 0xc4, 0x10, 0xc6, 0xd, 0x80, 0xa0, 0x1c,
    0x3, 0x80, 0xd0, 0x13, 0x6, 0x31, 0x82, 0x30,
    0x60,

    /* U+59 "Y" */
    0xc1, 0xa0, 0x98, 0xc6, 0x41, 0x40, 0xe0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0,

    /* U+5A "Z" */
    0x7f, 0x80, 0xc0, 0xc0, 0xc0, 0x60, 0x60, 0x60,
    0x30, 0x30, 0x30, 0x38, 0x1f, 0xf0,

    /* U+5B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0x27,

    /* U+5C "\\" */
    0x82, 0x4, 0x10, 0x20, 0x82, 0x4, 0x10, 0x40,
    0x82, 0x8, 0x10, 0x40,

    /* U+5D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x92, 0x4f,

    /* U+5E "^" */
    0x0, 0x18, 0x24, 0x66, 0x43,

    /* U+5F "_" */
    0xff,

    /* U+60 "`" */
    0xc9, 0x80,

    /* U+61 "a" */
    0x39, 0x30, 0x41, 0x7f, 0x18, 0x63, 0x74,

    /* U+62 "b" */
    0x81, 0x2, 0x4, 0xb, 0x98, 0xa0, 0xc1, 0x83,
    0x6, 0xe, 0x2b, 0x80,

    /* U+63 "c" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x20, 0x23, 0x3c,

    /* U+64 "d" */
    0x1, 0x1, 0x1, 0x1, 0x3d, 0x43, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x43, 0x3d,

    /* U+65 "e" */
    0x3c, 0x46, 0x82, 0x82, 0xfe, 0x80, 0x80, 0x42,
    0x3c,

    /* U+66 "f" */
    0x3d, 0x4, 0x10, 0xf9, 0x4, 0x10, 0x41, 0x4,
    0x10, 0x40,

    /* U+67 "g" */
    0x3e, 0xc9, 0xa, 0x16, 0x67, 0x90, 0x20, 0x3d,
    0x86, 0xb, 0xe0,

    /* U+68 "h" */
    0x81, 0x2, 0x4, 0xb, 0xd8, 0xe0, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+69 "i" */
    0x9f, 0xf0,

    /* U+6A "j" */
    0x20, 0x12, 0x49, 0x24, 0x92, 0xf0,

    /* U+6B "k" */
    0x82, 0x8, 0x20, 0x8e, 0x6b, 0x28, 0xe2, 0xc9,
    0xa2, 0x8c,

    /* U+6C "l" */
    0xff, 0xf8,

    /* U+6D "m" */
    0xb9, 0xd9, 0xce, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xc, 0x21, 0x84, 0x20,

    /* U+6E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x82,

    /* U+6F "o" */
    0x3c, 0x42, 0x83, 0x81, 0x81, 0x81, 0x81, 0x42,
    0x3c,

    /* U+70 "p" */
    0xb9, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xe2, 0xb9,
    0x2, 0x4, 0x0,

    /* U+71 "q" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x81, 0x43,
    0x3d, 0x1, 0x1, 0x1,

    /* U+72 "r" */
    0xbc, 0x88, 0x88, 0x88, 0x80,

    /* U+73 "s" */
    0x7a, 0x38, 0x30, 0x38, 0x30, 0x61, 0x78,

    /* U+74 "t" */
    0x2, 0x11, 0xf4, 0x21, 0x8, 0x42, 0x10, 0x70,

    /* U+75 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xe3, 0x7a,

    /* U+76 "v" */
    0xc3, 0x42, 0x46, 0x64, 0x24, 0x2c, 0x38, 0x18,
    0x18,

    /* U+77 "w" */
    0xc6, 0x34, 0x62, 0x46, 0x26, 0xf2, 0x69, 0x62,
    0x94, 0x29, 0xc3, 0xc, 0x10, 0x80,

    /* U+78 "x" */
    0x42, 0x66, 0x24, 0x18, 0x18, 0x38, 0x24, 0x66,
    0xc2,

    /* U+79 "y" */
    0xc3, 0x42, 0x66, 0x64, 0x24, 0x3c, 0x18, 0x18,
    0x18, 0x10, 0x30, 0x60,

    /* U+7A "z" */
    0xfc, 0x31, 0x84, 0x30, 0x84, 0x30, 0xfc,

    /* U+7B "{" */
    0x34, 0x44, 0x44, 0x48, 0xc4, 0x44, 0x44, 0x43,

    /* U+7C "|" */
    0xff, 0xff,

    /* U+7D "}" */
    0xc2, 0x22, 0x22, 0x23, 0x32, 0x22, 0x22, 0x2c,

    /* U+7E "~" */
    0x64, 0x60,

    /* U+30B9 "ス" */
    0x7f, 0xc0, 0x8, 0x0, 0x80, 0x10, 0x3, 0x0,
    0x20, 0x7, 0x0, 0x8c, 0x30, 0x66, 0x3, 0xc0,
    0x0,

    /* U+30C6 "テ" */
    0x3f, 0xe0, 0x0, 0x0, 0x1, 0xff, 0xf0, 0x30,
    0x1, 0x0, 0x8, 0x0, 0xc0, 0x4, 0x0, 0xe0,
    0xc, 0x0,

    /* U+30C8 "ト" */
    0x81, 0x2, 0x4, 0x8, 0x1c, 0x2e, 0x47, 0x87,
    0x2, 0x4, 0x8, 0x0,

    /* U+4ECA "今" */
    0x3, 0x0, 0x5, 0x0, 0x13, 0x0, 0x61, 0x1,
    0x81, 0x8d, 0xfd, 0xa0, 0x0, 0x1f, 0xfc, 0x0,
    0x10, 0x0, 0x60, 0x1, 0x80, 0x6, 0x0, 0x18,
    0x0, 0x0, 0x0,

    /* U+5206 "分" */
    0x8, 0x80, 0x22, 0x0, 0x84, 0x4, 0x18, 0x30,
    0x31, 0x80, 0x6f, 0xfe, 0xe1, 0x8, 0x4, 0x20,
    0x10, 0x80, 0xc2, 0x2, 0x8, 0x30, 0x21, 0x8f,
    0x0,

    /* U+524D "前" */
    0x0, 0x40, 0x21, 0x0, 0x8c, 0x3f, 0xff, 0x0,
    0x0, 0x0, 0x7, 0xe4, 0x91, 0x92, 0x7e, 0x49,
    0x19, 0x27, 0xe4, 0x91, 0x92, 0x46, 0x9, 0x18,
    0x24, 0xc7, 0x80,

    /* U+5348 "午" */
    0x10, 0x0, 0x40, 0x3, 0xff, 0x88, 0xc0, 0x63,
    0x3, 0xc, 0x0, 0x30, 0x3f, 0xff, 0x3, 0x0,
    0xc, 0x0, 0x30, 0x0, 0xc0, 0x3, 0x0, 0xc,
    0x0,

    /* U+571F "土" */
    0x3, 0x0, 0xc, 0x0, 0x30, 0x0, 0xc0, 0x7f,
    0xf8, 0xc, 0x0, 0x30, 0x0, 0xc0, 0x3, 0x0,
    0xc, 0x0, 0x30, 0x0, 0xc0, 0xff, 0xfc,

    /* U+5E74 "年" */
    0x10, 0x0, 0x40, 0x3, 0xff, 0x98, 0x40, 0x41,
    0x0, 0x7f, 0xe1, 0x10, 0x4, 0x40, 0x11, 0x3,
    0xff, 0xf0, 0x10, 0x0, 0x40, 0x1, 0x0, 0x4,
    0x0,

    /* U+5F8C "後" */
    0x10, 0xc0, 0xc2, 0x6, 0x73, 0x34, 0xd8, 0x91,
    0xd0, 0xc6, 0x26, 0x7f, 0xd8, 0x40, 0xa3, 0xf0,
    0x9c, 0x42, 0xda, 0x8, 0x30, 0x21, 0xb8, 0xb8,
    0x30,

    /* U+65E5 "日" */
    0xff, 0xe0, 0x18, 0x6, 0x1, 0x80, 0x7f, 0xf8,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x7, 0xff, 0x80,
    0x40,

    /* U+660E "明" */
    0x1, 0xff, 0xc8, 0x62, 0x43, 0x12, 0x18, 0x9f,
    0xfc, 0x86, 0x24, 0x31, 0x21, 0x89, 0xff, 0xc8,
    0x60, 0x42, 0x4, 0x10, 0x60, 0x86, 0x3c,

    /* U+6628 "昨" */
    0x0, 0x0, 0x4, 0xf, 0x90, 0x22, 0xff, 0x8a,
    0x82, 0x2a, 0x8, 0xa8, 0x3f, 0x3e, 0x8c, 0x82,
    0x22, 0x8, 0x8f, 0xa2, 0x20, 0xf8, 0x82, 0x2,
    0x0, 0x8, 0x0,

    /* U+6642 "時" */
    0x0, 0x43, 0xc1, 0x9, 0x7f, 0xa4, 0x10, 0x90,
    0x42, 0x5f, 0xff, 0x1, 0x24, 0x4, 0x97, 0xfe,
    0x40, 0x49, 0x11, 0x3c, 0x64, 0x80, 0x10, 0x3,
    0xc0,

    /* U+6708 "月" */
    0x3f, 0xe4, 0x4, 0x80, 0x90, 0x13, 0xfe, 0x40,
    0x48, 0x9, 0x1, 0x3f, 0xe4, 0x4, 0x80, 0xb0,
    0x14, 0x3, 0x87, 0xc0,

    /* U+6728 "木" */
    0x3, 0x0, 0xc, 0x0, 0x30, 0x0, 0xc0, 0xff,
    0xfc, 0xc, 0x0, 0x78, 0x3, 0xf0, 0xb, 0x60,
    0x4c, 0xc6, 0x31, 0xb0, 0xc3, 0x3, 0x0, 0xc,
    0x0,

    /* U+6C34 "水" */
    0x1, 0x0, 0x4, 0x0, 0x10, 0x0, 0x46, 0x7d,
    0x30, 0x17, 0x80, 0xdc, 0x2, 0x50, 0x9, 0x60,
    0x44, 0xc3, 0x11, 0x98, 0x43, 0x41, 0x0, 0x1c,
    0x0,

    /* U+706B "火" */
    0x2, 0x0, 0x10, 0x0, 0x80, 0x64, 0x22, 0x23,
    0x11, 0x11, 0x8d, 0x88, 0xa0, 0x5, 0x80, 0x24,
    0x2, 0x10, 0x20, 0x66, 0x1, 0xe0, 0x0,

    /* U+7121 "無" */
    0x10, 0x0, 0x40, 0x3, 0xff, 0x9d, 0x24, 0x54,
    0x90, 0x52, 0x4f, 0xff, 0xc5, 0x24, 0x14, 0x90,
    0x52, 0x4f, 0xff, 0xc0, 0x4, 0x24, 0x99, 0x92,
    0x24, 0x4c, 0xc0, 0x0,

    /* U+79D2 "秒" */
    0x0, 0x43, 0xe1, 0x1, 0x15, 0x4, 0x54, 0xfd,
    0x48, 0xcd, 0x33, 0x24, 0x56, 0x90, 0x5c, 0x5b,
    0x57, 0x49, 0x3, 0x4, 0x18, 0x11, 0xc0, 0x4c,
    0x0,

    /* U+7DDA "線" */
    0x10, 0x20, 0x20, 0xc0, 0xc7, 0xf3, 0x48, 0x26,
    0x90, 0x46, 0x3f, 0x84, 0x41, 0x12, 0xfe, 0x7c,
    0x24, 0xa7, 0xf9, 0x52, 0xe2, 0xa5, 0x45, 0x52,
    0x5a, 0x64, 0xc4, 0xb8, 0x0,

    /* U+91D1 "金" */
    0x3, 0x0, 0x1e, 0x0, 0xcc, 0x6, 0x18, 0x30,
    0x31, 0xff, 0xf8, 0x30, 0x1f, 0xfe, 0x3, 0x0,
    0xcc, 0xc1, 0x32, 0x6, 0xc8, 0x13, 0x3, 0xff,
    0xf0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 69, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 76, .box_w = 1, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 87, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 5, .adv_w = 161, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 19, .adv_w = 161, .box_w = 7, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 33, .adv_w = 218, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 178, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 49, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 67, .adv_w = 85, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 73, .adv_w = 85, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 79, .adv_w = 95, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 82, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 93, .adv_w = 68, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 95, .adv_w = 92, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 96, .adv_w = 68, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 109, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 161, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 161, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 82, .box_w = 1, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 228, .adv_w = 82, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 231, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 242, .adv_w = 174, .box_w = 9, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 247, .adv_w = 174, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 258, .adv_w = 141, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 229, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 163, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 169, .box_w = 8, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 186, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 194, .box_w = 9, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 152, .box_w = 7, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 353, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 193, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 192, .box_w = 9, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 74, .box_w = 1, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 97, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 165, .box_w = 8, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 135, .box_w = 6, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 231, .box_w = 11, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 195, .box_w = 9, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 204, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 159, .box_w = 7, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 204, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 499, .adv_w = 166, .box_w = 8, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 150, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 153, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 537, .adv_w = 191, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 163, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 566, .adv_w = 238, .box_w = 15, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 176, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 159, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 620, .adv_w = 164, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 77, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 640, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 652, .adv_w = 77, .box_w = 3, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 658, .adv_w = 128, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 663, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 664, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 666, .adv_w = 141, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 160, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 685, .adv_w = 139, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 146, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 715, .adv_w = 78, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 142, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 736, .adv_w = 155, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 69, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 750, .adv_w = 69, .box_w = 3, .box_h = 15, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 756, .adv_w = 133, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 766, .adv_w = 69, .box_w = 1, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 768, .adv_w = 223, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 781, .adv_w = 155, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 789, .adv_w = 155, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 798, .adv_w = 159, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 809, .adv_w = 159, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 821, .adv_w = 95, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 826, .adv_w = 118, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 89, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 841, .adv_w = 155, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 849, .adv_w = 124, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 858, .adv_w = 193, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 872, .adv_w = 125, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 126, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 893, .adv_w = 121, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 900, .adv_w = 84, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 908, .adv_w = 51, .box_w = 1, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 910, .adv_w = 84, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 918, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 920, .adv_w = 256, .box_w = 12, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 937, .adv_w = 256, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 955, .adv_w = 256, .box_w = 7, .box_h = 13, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 967, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 994, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1019, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1046, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1071, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1094, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1119, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1144, .adv_w = 256, .box_w = 10, .box_h = 13, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 1161, .adv_w = 256, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1184, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1211, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1236, .adv_w = 256, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1256, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1281, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1306, .adv_w = 256, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1329, .adv_w = 256, .box_w = 14, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1357, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1382, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1411, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0xd, 0xf, 0x1e11, 0x214d, 0x2194, 0x228f, 0x2666,
    0x2dbb, 0x2ed3, 0x352c, 0x3555, 0x356f, 0x3589, 0x364f, 0x366f,
    0x3b7b, 0x3fb2, 0x4068, 0x4919, 0x4d21, 0x6118
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 12473, .range_length = 24857, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 22, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t IPAexGothic = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};

#endif /*#if IPAEXGOTHIC*/
