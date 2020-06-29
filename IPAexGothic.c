#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/
// テスト時分日月火水木金土年秒午前後無線今明昨

#ifndef IPAEXGOTHIC
#define IPAEXGOTHIC 1
#endif

#if IPAEXGOTHIC

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+30B9 "ス" */
    0x7f, 0x0, 0xc0, 0x20, 0x10, 0x4, 0x2, 0x83,
    0x11, 0x82, 0x0, 0x0,

    /* U+30C6 "テ" */
    0x3f, 0x0, 0x0, 0x3, 0xff, 0x4, 0x1, 0x0,
    0x80, 0x60, 0x30, 0x0,

    /* U+30C8 "ト" */
    0x82, 0x8, 0x30, 0xb2, 0x28, 0x20, 0x80,

    /* U+4ECA "今" */
    0xc, 0x1, 0x40, 0x46, 0x3f, 0xa8, 0x0, 0x7f,
    0x0, 0x20, 0x8, 0x2, 0x0, 0xc0,

    /* U+5206 "分" */
    0xb, 0x2, 0x20, 0xc2, 0x10, 0x27, 0xfa, 0x11,
    0x2, 0x20, 0x44, 0x10, 0x8c, 0xf0,

    /* U+524D "前" */
    0x11, 0x2, 0x23, 0xff, 0x80, 0x7, 0x94, 0x92,
    0x9e, 0x52, 0x4a, 0x79, 0x49, 0x9, 0x67, 0x0,

    /* U+5348 "午" */
    0x20, 0x8, 0x7, 0xf9, 0x10, 0x4, 0x3f, 0xf0,
    0x40, 0x10, 0x4, 0x1, 0x0, 0x40,

    /* U+571F "土" */
    0x8, 0x2, 0x7, 0xf8, 0x20, 0x8, 0x2, 0x0,
    0x80, 0x20, 0xff, 0xc0,

    /* U+5E74 "年" */
    0x20, 0x7, 0xf9, 0x10, 0x62, 0x3, 0xf8, 0x48,
    0x9, 0x7, 0xff, 0x4, 0x0, 0x80, 0x10, 0x0,

    /* U+5F8C "後" */
    0x11, 0x4, 0x49, 0x52, 0x9, 0xa2, 0xfe, 0xc4,
    0x69, 0xf1, 0x32, 0x29, 0x84, 0x70, 0xb1, 0x80,

    /* U+65E5 "日" */
    0xff, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81,
    0xff, 0x81,

    /* U+660E "明" */
    0xf7, 0xe5, 0x19, 0x7f, 0xd1, 0x94, 0x65, 0xff,
    0x46, 0x11, 0x8, 0x46, 0x70,

    /* U+6628 "昨" */
    0x4, 0x1e, 0x82, 0x5f, 0xcd, 0xf, 0xbd, 0x24,
    0x24, 0x84, 0x9e, 0xf2, 0x10, 0x40, 0x8, 0x0,

    /* U+6642 "時" */
    0x2, 0x3c, 0x89, 0xfe, 0x48, 0x9f, 0xfc, 0x29,
    0xfe, 0x42, 0xf4, 0xa0, 0x20, 0x30,

    /* U+6708 "月" */
    0x7f, 0x41, 0x7f, 0x41, 0x41, 0x7f, 0x41, 0x41,
    0xc1, 0x8f,

    /* U+6728 "木" */
    0x8, 0x2, 0xf, 0xfc, 0x30, 0x1a, 0x6, 0x82,
    0x91, 0x23, 0x88, 0x42, 0x0,

    /* U+6C34 "水" */
    0x4, 0x0, 0x80, 0x11, 0x7a, 0x41, 0x70, 0x2c,
    0x9, 0x41, 0x24, 0x44, 0x50, 0x80, 0x70, 0x0,

    /* U+706B "火" */
    0x4, 0x0, 0x80, 0x91, 0x12, 0x62, 0x48, 0x94,
    0x2, 0x80, 0x48, 0x10, 0x8c, 0xc,

    /* U+7121 "無" */
    0x20, 0x7, 0xf9, 0xaa, 0x15, 0x4f, 0xfe, 0x55,
    0xa, 0xa7, 0xff, 0x2, 0x89, 0x49, 0x24, 0x80,

    /* U+79D2 "秒" */
    0x11, 0x1c, 0x21, 0x15, 0x7a, 0xa4, 0x92, 0xd2,
    0x34, 0x56, 0xbc, 0xc1, 0x88, 0x61, 0x30, 0x0,

    /* U+7DDA "線" */
    0x21, 0xa, 0xfb, 0x51, 0x33, 0xe3, 0x44, 0xaf,
    0x8d, 0xd5, 0x9c, 0xb5, 0x54, 0xac, 0x8c, 0x0,

    /* U+91D1 "金" */
    0xc, 0x3, 0x1, 0x20, 0x84, 0x7f, 0xe2, 0x7,
    0xf8, 0xa4, 0x29, 0xa, 0x4f, 0xfc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 192, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 12, .adv_w = 192, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 24, .adv_w = 192, .box_w = 6, .box_h = 9, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 31, .adv_w = 192, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 45, .adv_w = 192, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 59, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 75, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 89, .adv_w = 192, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 117, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 133, .adv_w = 192, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 143, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 156, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 172, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 186, .adv_w = 192, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 196, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 209, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 225, .adv_w = 192, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 239, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 255, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 271, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 287, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xd, 0xf, 0x1e11, 0x214d, 0x2194, 0x228f, 0x2666,
    0x2dbb, 0x2ed3, 0x352c, 0x3555, 0x356f, 0x3589, 0x364f, 0x366f,
    0x3b7b, 0x3fb2, 0x4068, 0x4919, 0x4d21, 0x6118
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 12473, .range_length = 24857, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 22, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
    .cmap_num = 1,
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
    .line_height = 11,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};

#endif /*#if IPAEXGOTHIC*/
