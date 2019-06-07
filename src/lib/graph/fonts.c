/**
 * @file 	fonts.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include <stdint.h>

const uint16_t pixfont8x16[256][8] = {
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x07F0, 0x0C18, 0x0948, 0x0B08, 0x0B08, 0x0948, 0x0C18, 0x07F0},
	{0x07F0, 0x0FF8, 0x0EB8, 0x0CF8, 0x0CF8, 0x0EB8, 0x0FF8, 0x07F0},
	{0x01E0, 0x03F0, 0x07E0, 0x0FC0, 0x07E0, 0x03F0, 0x01E0, 0x0000},
	{0x00C0, 0x01E0, 0x03F0, 0x07F8, 0x03F0, 0x01E0, 0x00C0, 0x0000},
	{0x01C0, 0x09C0, 0x09F0, 0x0E78, 0x0E78, 0x09F0, 0x09C0, 0x01C0},
	{0x00C0, 0x09E0, 0x09F0, 0x0FF8, 0x0FF8, 0x09F0, 0x09E0, 0x00C0},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x1800, 0x1FF8, 0x0FF8, 0x0028, 0x0028, 0x0E28, 0x0FF8, 0x07F8},
	{0x05A0, 0x07E0, 0x03C0, 0x0E70, 0x0E70, 0x03C0, 0x07E0, 0x05A0},
	{0x0FF8, 0x07F0, 0x03E0, 0x01C0, 0x01C0, 0x0080, 0x0080, 0x0000},
	{0x0080, 0x0080, 0x01C0, 0x01C0, 0x03E0, 0x07F0, 0x0FF8, 0x0000},
	{0x0000, 0x0220, 0x0630, 0x0FF8, 0x0FF8, 0x0630, 0x0220, 0x0000},
	{0x0000, 0x0CF8, 0x0CF8, 0x0000, 0x0000, 0x0CF8, 0x0CF8, 0x0000},
	{0x0070, 0x00F8, 0x0088, 0x0FF8, 0x0FF8, 0x0008, 0x0FF8, 0x0FF8},
	{0x0800, 0x1998, 0x13F8, 0x1268, 0x1648, 0x1FC8, 0x1998, 0x0010},
	{0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0000},
	{0x0000, 0x1220, 0x1630, 0x1FF8, 0x1FF8, 0x1630, 0x1220, 0x0000},
	{0x0000, 0x0020, 0x0030, 0x0FF8, 0x0FF8, 0x0030, 0x0020, 0x0000},
	{0x0000, 0x0200, 0x0600, 0x0FF8, 0x0FF8, 0x0600, 0x0200, 0x0000},
	{0x0080, 0x0080, 0x0080, 0x02A0, 0x03E0, 0x01C0, 0x0080, 0x0000},
	{0x0080, 0x01C0, 0x03E0, 0x02A0, 0x0080, 0x0080, 0x0080, 0x0000},
	{0x01E0, 0x01E0, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0000},
	{0x0080, 0x01C0, 0x03E0, 0x0080, 0x0080, 0x03E0, 0x01C0, 0x0080},
	{0x0C00, 0x0F00, 0x0FC0, 0x0FF0, 0x0FC0, 0x0F00, 0x0C00, 0x0000},
	{0x0030, 0x00F0, 0x03F0, 0x0FF0, 0x03F0, 0x00F0, 0x0030, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0070, 0x0DF8, 0x0DF8, 0x0070, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0038, 0x0078, 0x0000, 0x0000, 0x0078, 0x0038, 0x0000},
	{0x0220, 0x0FF8, 0x0FF8, 0x0220, 0x0FF8, 0x0FF8, 0x0220, 0x0000},
	{0x0460, 0x04F0, 0x1C9C, 0x1C9C, 0x0790, 0x0310, 0x0000, 0x0000},
	{0x0000, 0x0C60, 0x0660, 0x0300, 0x0180, 0x0CC0, 0x0C60, 0x0000},
	{0x07B0, 0x0FF8, 0x08C8, 0x0DF8, 0x07B0, 0x0F00, 0x0980, 0x0000},
	{0x0000, 0x0040, 0x0078, 0x0038, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x01C0, 0x03E0, 0x0630, 0x0C18, 0x0808, 0x0000, 0x0000},
	{0x0000, 0x0808, 0x0C18, 0x0630, 0x03E0, 0x01C0, 0x0000, 0x0000},
	{0x0080, 0x02A0, 0x03E0, 0x01C0, 0x01C0, 0x03E0, 0x02A0, 0x0080},
	{0x0000, 0x0080, 0x0080, 0x03E0, 0x03E0, 0x0080, 0x0080, 0x0000},
	{0x0000, 0x0000, 0x1000, 0x1C00, 0x0C00, 0x0C00, 0x0000, 0x0000},
	{0x0000, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0000},
	{0x0000, 0x0000, 0x0C00, 0x0C00, 0x0C00, 0x0000, 0x0000, 0x0000},
	{0x0C00, 0x0600, 0x0300, 0x0180, 0x00C0, 0x0060, 0x0030, 0x0000},
	{0x07F0, 0x0FF8, 0x0B08, 0x09C8, 0x0868, 0x0FF8, 0x07F0, 0x0000},
	{0x0820, 0x0820, 0x0FF0, 0x0FF8, 0x0800, 0x0800, 0x0000, 0x0000},
	{0x0C30, 0x0E38, 0x0B08, 0x0988, 0x08F8, 0x0C70, 0x0000, 0x0000},
	{0x0410, 0x0C18, 0x0888, 0x0888, 0x0FF8, 0x0770, 0x0000, 0x0000},
	{0x0180, 0x01C0, 0x0160, 0x0930, 0x0FF8, 0x0FF8, 0x0900, 0x0000},
	{0x04F8, 0x0CF8, 0x0888, 0x0888, 0x0F88, 0x0708, 0x0000, 0x0000},
	{0x07E0, 0x0FF0, 0x0898, 0x0888, 0x0F88, 0x0700, 0x0000, 0x0000},
	{0x0038, 0x0038, 0x0E08, 0x0F08, 0x0188, 0x00F8, 0x0078, 0x0000},
	{0x0770, 0x0FF8, 0x08C8, 0x0988, 0x0FF8, 0x0770, 0x0000, 0x0000},
	{0x0070, 0x08F8, 0x0888, 0x0C88, 0x07F8, 0x03F0, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0660, 0x0660, 0x0660, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x1660, 0x1E60, 0x0E60, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0080, 0x01C0, 0x0360, 0x0630, 0x0C18, 0x0808, 0x0000},
	{0x0000, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0000},
	{0x0000, 0x0808, 0x0C18, 0x0630, 0x0360, 0x01C0, 0x0080, 0x0000},
	{0x0000, 0x0010, 0x0018, 0x0D88, 0x0DC8, 0x0078, 0x0030, 0x0000},
	{0x07F0, 0x0FF8, 0x0808, 0x09C8, 0x09C8, 0x09F8, 0x01F0, 0x0000},
	{0x0FE0, 0x0FF0, 0x0118, 0x0118, 0x0FF0, 0x0FE0, 0x0000, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0888, 0x0888, 0x0FF8, 0x0770, 0x0000},
	{0x03E0, 0x07F0, 0x0C18, 0x0808, 0x0808, 0x0E38, 0x0630, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0808, 0x0C18, 0x07F0, 0x03E0, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0888, 0x0888, 0x09C8, 0x0C18, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0888, 0x0088, 0x0018, 0x0038, 0x0000},
	{0x03E0, 0x07F0, 0x0C18, 0x0808, 0x0908, 0x0F38, 0x0F30, 0x0000},
	{0x0000, 0x0FF8, 0x0FF8, 0x0080, 0x0080, 0x0FF8, 0x0FF8, 0x0000},
	{0x0000, 0x0808, 0x0FF8, 0x0FF8, 0x0808, 0x0000, 0x0000, 0x0000},
	{0x0700, 0x0F00, 0x0800, 0x0808, 0x0FF8, 0x07F8, 0x0008, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0080, 0x03E0, 0x0F78, 0x0C18, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0808, 0x0800, 0x0E00, 0x0F00, 0x0000},
	{0x0FF8, 0x0FF8, 0x0030, 0x0060, 0x0030, 0x0FF8, 0x0FF8, 0x0000},
	{0x0FF8, 0x0FF8, 0x00E0, 0x01C0, 0x0380, 0x0FF8, 0x0FF8, 0x0000},
	{0x03E0, 0x07F0, 0x0C18, 0x0808, 0x0C18, 0x07F0, 0x03E0, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0888, 0x0088, 0x00F8, 0x0070, 0x0000},
	{0x03E0, 0x07F0, 0x0418, 0x1608, 0x1F18, 0x1FF0, 0x13E0, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0088, 0x0188, 0x0FF8, 0x0E70, 0x0000},
	{0x0670, 0x0EF8, 0x0888, 0x0988, 0x0F38, 0x0630, 0x0000, 0x0000},
	{0x0018, 0x0808, 0x0FF8, 0x0FF8, 0x0808, 0x0018, 0x0000, 0x0000},
	{0x07F8, 0x0FF8, 0x0800, 0x0800, 0x0FF8, 0x07F8, 0x0000, 0x0000},
	{0x03F8, 0x07F8, 0x0C00, 0x0C00, 0x07F8, 0x03F8, 0x0000, 0x0000},
	{0x01F8, 0x0FF8, 0x0E00, 0x0180, 0x0E00, 0x0FF8, 0x01F8, 0x0000},
	{0x0E38, 0x0F78, 0x01C0, 0x01C0, 0x0F78, 0x0E38, 0x0000, 0x0000},
	{0x0078, 0x08F8, 0x0F80, 0x0F80, 0x08F8, 0x0078, 0x0000, 0x0000},
	{0x0C38, 0x0F18, 0x0B88, 0x08E8, 0x0878, 0x0818, 0x0C18, 0x0000},
	{0x0000, 0x0000, 0x0FF8, 0x0FF8, 0x0808, 0x0000, 0x0000, 0x0000},
	{0x0030, 0x0060, 0x00C0, 0x0180, 0x0300, 0x0600, 0x0C00, 0x0000},
	{0x0000, 0x0000, 0x0808, 0x0808, 0x0FF8, 0x0FF8, 0x0000, 0x0000},
	{0x0020, 0x0030, 0x0018, 0x000C, 0x0018, 0x0030, 0x0020, 0x0000},
	{0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000},
	{0x0000, 0x0000, 0x000C, 0x001C, 0x0010, 0x0000, 0x0000, 0x0000},
	{0x0600, 0x0F40, 0x0940, 0x0940, 0x07C0, 0x0F80, 0x0800, 0x0000},
	{0x0808, 0x0FF8, 0x07F8, 0x0840, 0x0840, 0x0FC0, 0x0780, 0x0000},
	{0x0780, 0x0FC0, 0x0840, 0x0840, 0x0CC0, 0x0480, 0x0000, 0x0000},
	{0x0780, 0x0FC0, 0x0840, 0x0848, 0x07F8, 0x0FF8, 0x0800, 0x0000},
	{0x0780, 0x0FC0, 0x0940, 0x0940, 0x0DC0, 0x0580, 0x0000, 0x0000},
	{0x0880, 0x0FF0, 0x0FF8, 0x0888, 0x0098, 0x0010, 0x0000, 0x0000},
	{0x1380, 0x37C0, 0x2440, 0x2440, 0x3F80, 0x1FC0, 0x0040, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0080, 0x0040, 0x0FC0, 0x0F80, 0x0000},
	{0x0840, 0x0840, 0x0FD8, 0x0FD8, 0x0800, 0x0800, 0x0000, 0x0000},
	{0x1800, 0x3800, 0x2040, 0x2040, 0x3FD8, 0x1FD8, 0x0000, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0100, 0x0380, 0x0EC0, 0x0C40, 0x0000},
	{0x0808, 0x0808, 0x0FF8, 0x0FF8, 0x0800, 0x0800, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0040, 0x07C0, 0x0040, 0x0FC0, 0x0F80, 0x0000},
	{0x0FC0, 0x0FC0, 0x0040, 0x0040, 0x0FC0, 0x0F80, 0x0000, 0x0000},
	{0x0780, 0x0FC0, 0x0840, 0x0840, 0x0FC0, 0x0780, 0x0000, 0x0000},
	{0x2040, 0x3FC0, 0x3F80, 0x2840, 0x0840, 0x0FC0, 0x0780, 0x0000},
	{0x0780, 0x0FC0, 0x0840, 0x2840, 0x3F80, 0x3FC0, 0x2040, 0x0000},
	{0x0840, 0x0FC0, 0x0FC0, 0x0900, 0x00C0, 0x01C0, 0x0180, 0x0000},
	{0x0480, 0x0DC0, 0x0940, 0x0A40, 0x0EC0, 0x0480, 0x0000, 0x0000},
	{0x0040, 0x07E0, 0x0FF0, 0x0840, 0x0C40, 0x0440, 0x0000, 0x0000},
	{0x07C0, 0x0FC0, 0x0800, 0x0800, 0x07C0, 0x0FC0, 0x0800, 0x0000},
	{0x03C0, 0x07C0, 0x0C00, 0x0C00, 0x07C0, 0x03C0, 0x0000, 0x0000},
	{0x03C0, 0x0FC0, 0x0C00, 0x0300, 0x0C00, 0x0FC0, 0x03C0, 0x0000},
	{0x0840, 0x0CC0, 0x0780, 0x0300, 0x0780, 0x0CC0, 0x0840, 0x0000},
	{0x2000, 0x23C0, 0x27C0, 0x3400, 0x1C00, 0x0FC0, 0x03C0, 0x0000},
	{0x0CC0, 0x0E40, 0x0A40, 0x0940, 0x09C0, 0x0CC0, 0x0000, 0x0000},
	{0x0080, 0x01C0, 0x0770, 0x0E38, 0x0808, 0x0808, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0F78, 0x0F78, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0808, 0x0808, 0x0E38, 0x0770, 0x01C0, 0x0080, 0x0000},
	{0x0018, 0x001C, 0x0004, 0x000C, 0x0018, 0x0010, 0x001C, 0x0004},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0FE0, 0x0FF0, 0x0118, 0x0118, 0x0FF0, 0x0FE0, 0x0000, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0848, 0x0848, 0x0FC8, 0x0798, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0888, 0x0888, 0x0FF8, 0x0770, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0808, 0x0008, 0x0008, 0x0038, 0x0000},
	{0x1800, 0x1FF0, 0x0FF8, 0x0808, 0x0808, 0x0FF8, 0x1FF8, 0x1800},
	{0x0808, 0x0FF8, 0x0FF8, 0x0888, 0x0888, 0x09C8, 0x0C18, 0x0000},
	{0x0C18, 0x0770, 0x01C0, 0x0FF8, 0x0FF8, 0x01C0, 0x0770, 0x0C18},
	{0x0000, 0x0630, 0x0C18, 0x0888, 0x0888, 0x0FF8, 0x0770, 0x0000},
	{0x0FF8, 0x0FF8, 0x0380, 0x01C0, 0x00E0, 0x0FF8, 0x0FF8, 0x0000},
	{0x0FF8, 0x0FF8, 0x0390, 0x01DC, 0x00E4, 0x0FF8, 0x0FF8, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0080, 0x03E0, 0x0F78, 0x0C18, 0x0000},
	{0x0800, 0x0FE0, 0x07F0, 0x0018, 0x0018, 0x0FF8, 0x0FF8, 0x0000},
	{0x0FF8, 0x0FF8, 0x0070, 0x00E0, 0x0070, 0x0FF8, 0x0FF8, 0x0000},
	{0x0FF8, 0x0FF8, 0x0080, 0x0080, 0x0080, 0x0FF8, 0x0FF8, 0x0000},
	{0x03E0, 0x07F0, 0x0C18, 0x0808, 0x0C18, 0x07F0, 0x03E0, 0x0000},
	{0x0FF8, 0x0FF8, 0x0008, 0x0008, 0x0008, 0x0FF8, 0x0FF8, 0x0000},
	{0x0808, 0x0FF8, 0x0FF8, 0x0888, 0x0088, 0x00F8, 0x0070, 0x0000},
	{0x03E0, 0x07F0, 0x0C18, 0x0808, 0x0808, 0x0E38, 0x0630, 0x0000},
	{0x0000, 0x0018, 0x0808, 0x0FF8, 0x0FF8, 0x0808, 0x0018, 0x0000},
	{0x0000, 0x04F8, 0x0DF8, 0x0900, 0x0900, 0x0FF8, 0x07F8, 0x0000},
	{0x01E0, 0x03F0, 0x0210, 0x0FF8, 0x0FF8, 0x0210, 0x03F0, 0x01E0},
	{0x0E38, 0x0F78, 0x01C0, 0x01C0, 0x0F78, 0x0E38, 0x0000, 0x0000},
	{0x0FF8, 0x0FF8, 0x0800, 0x0800, 0x0FF8, 0x1FF8, 0x1800, 0x0000},
	{0x00F8, 0x01F8, 0x0100, 0x0100, 0x0100, 0x0FF8, 0x0FF8, 0x0000},
	{0x0FF8, 0x0FF8, 0x0800, 0x0FF8, 0x0800, 0x0FF8, 0x0FF8, 0x0000},
	{0x0FF8, 0x0FF8, 0x0800, 0x0FF8, 0x0800, 0x0FF8, 0x1FF8, 0x1800},
	{0x0018, 0x0FF8, 0x0FF8, 0x0880, 0x0880, 0x0F80, 0x0700, 0x0000},
	{0x0FF8, 0x0FF8, 0x0880, 0x0F80, 0x0700, 0x0FF8, 0x0FF8, 0x0000},
	{0x0FF0, 0x0FF0, 0x0880, 0x0880, 0x0880, 0x0F80, 0x0700, 0x0000},
	{0x0630, 0x0E38, 0x0808, 0x0888, 0x0C98, 0x07F0, 0x03E0, 0x0000},
	{0x0FF8, 0x0FF8, 0x00C0, 0x07F0, 0x0FF8, 0x0808, 0x0FF8, 0x07F0},
	{0x0800, 0x0E70, 0x0FF8, 0x0188, 0x0088, 0x0FF8, 0x0FF8, 0x0808},
	{0x0600, 0x0F40, 0x0940, 0x0940, 0x07C0, 0x0F80, 0x0800, 0x0000},
	{0x07C0, 0x0F40, 0x0940, 0x0940, 0x0F40, 0x0660, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0940, 0x0940, 0x0FC0, 0x0680, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0040, 0x0040, 0x0040, 0x0040, 0x0000, 0x0000},
	{0x1800, 0x1FC0, 0x0FC0, 0x0840, 0x0FC0, 0x1FC0, 0x1800, 0x0000},
	{0x0780, 0x0FC0, 0x0940, 0x0940, 0x0DC0, 0x0580, 0x0000, 0x0000},
	{0x0CC0, 0x0780, 0x0300, 0x0FC0, 0x0300, 0x0780, 0x0CC0, 0x0000},
	{0x0480, 0x0840, 0x0940, 0x0940, 0x0FC0, 0x0680, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0600, 0x0300, 0x0FC0, 0x0FC0, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0600, 0x0330, 0x0FD8, 0x0FC0, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0100, 0x0380, 0x0EC0, 0x0840, 0x0000, 0x0000},
	{0x0800, 0x0E00, 0x0380, 0x00C0, 0x0FC0, 0x0FC0, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0080, 0x0300, 0x0080, 0x0FC0, 0x0FC0, 0x0000},
	{0x0FC0, 0x0FC0, 0x0100, 0x0100, 0x0FC0, 0x0FC0, 0x0000, 0x0000},
	{0x0780, 0x0FC0, 0x0840, 0x0840, 0x0FC0, 0x0780, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0040, 0x0040, 0x0FC0, 0x0FC0, 0x0000, 0x0000},
	{0x1248, 0x2490, 0x0924, 0x1248, 0x2490, 0x0924, 0x1248, 0x2490},
	{0x2AA8, 0x1554, 0x2AA8, 0x1554, 0x2AA8, 0x1554, 0x2AA8, 0x1554},
	{0x36D8, 0x1B6C, 0x2DB4, 0x36D8, 0x1B6C, 0x2DB4, 0x36D8, 0x1B6C},
	{0x0000, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x0000},
	{0x0080, 0x0080, 0x0080, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x0000},
	{0x0240, 0x0240, 0x0240, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x0000},
	{0x0080, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0000},
	{0x0080, 0x3F80, 0x3F80, 0x0080, 0x0080, 0x3F80, 0x3F80, 0x0000},
	{0x0240, 0x0240, 0x0240, 0x3FC0, 0x3FC0, 0x0000, 0x0000, 0x0000},
	{0x0240, 0x3E7C, 0x3E7C, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0000},
	{0x0000, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0000},
	{0x0240, 0x3E40, 0x3E40, 0x0040, 0x0040, 0x3FC0, 0x3FC0, 0x0000},
	{0x0240, 0x027C, 0x027C, 0x0200, 0x0200, 0x03FC, 0x03FC, 0x0000},
	{0x0080, 0x00FC, 0x00FC, 0x0080, 0x0080, 0x00FC, 0x00FC, 0x0000},
	{0x0240, 0x0240, 0x0240, 0x03FC, 0x03FC, 0x0000, 0x0000, 0x0000},
	{0x0080, 0x0080, 0x0080, 0x3F80, 0x3F80, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x00FC, 0x00FC, 0x0080, 0x0080, 0x0080},
	{0x0080, 0x0080, 0x0080, 0x00FC, 0x00FC, 0x0080, 0x0080, 0x0080},
	{0x0080, 0x0080, 0x0080, 0x3F80, 0x3F80, 0x0080, 0x0080, 0x0080},
	{0x0000, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0080, 0x0080, 0x0080},
	{0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080},
	{0x0080, 0x0080, 0x0080, 0x3FFC, 0x3FFC, 0x0080, 0x0080, 0x0080},
	{0x0000, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0240, 0x0240, 0x0240},
	{0x0000, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0080},
	{0x0000, 0x03FC, 0x03FC, 0x0200, 0x0200, 0x027C, 0x027C, 0x0240},
	{0x0000, 0x3FC0, 0x3FC0, 0x0040, 0x0040, 0x3E40, 0x3E40, 0x0240},
	{0x0240, 0x027C, 0x027C, 0x0200, 0x0200, 0x027C, 0x027C, 0x0240},
	{0x0240, 0x3E40, 0x3E40, 0x0040, 0x0040, 0x3E40, 0x3E40, 0x0240},
	{0x0000, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x3E7C, 0x3E7C, 0x0240},
	{0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240},
	{0x0240, 0x3E7C, 0x3E7C, 0x0000, 0x0000, 0x3E7C, 0x3E7C, 0x0240},
	{0x0240, 0x0240, 0x0240, 0x027C, 0x027C, 0x0240, 0x0240, 0x0240},
	{0x0080, 0x00FC, 0x00FC, 0x0080, 0x0080, 0x00FC, 0x00FC, 0x0080},
	{0x0240, 0x0240, 0x0240, 0x3E40, 0x3E40, 0x0240, 0x0240, 0x0240},
	{0x0080, 0x3F80, 0x3F80, 0x0080, 0x0080, 0x3F80, 0x3F80, 0x0080},
	{0x0000, 0x00FC, 0x00FC, 0x0080, 0x0080, 0x00FC, 0x00FC, 0x0080},
	{0x0000, 0x0000, 0x0000, 0x03FC, 0x03FC, 0x0240, 0x0240, 0x0240},
	{0x0000, 0x0000, 0x0000, 0x3FC0, 0x3FC0, 0x0240, 0x0240, 0x0240},
	{0x0000, 0x3F80, 0x3F80, 0x0080, 0x0080, 0x3F80, 0x3F80, 0x0080},
	{0x0080, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0080},
	{0x0240, 0x0240, 0x0240, 0x3E7C, 0x3E7C, 0x0240, 0x0240, 0x0240},
	{0x0080, 0x0080, 0x0080, 0x00FC, 0x00FC, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x3F80, 0x3F80, 0x0080, 0x0080, 0x0080},
	{0x3FFC, 0x3FFC, 0x3FFC, 0x3FFC, 0x3FFC, 0x3FFC, 0x3FFC, 0x3FFC},
	{0x3F00, 0x3F00, 0x3F00, 0x3F00, 0x3F00, 0x3F00, 0x3F00, 0x3F00},
	{0x3FFC, 0x3FFC, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x3FFC, 0x3FFC},
	{0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x00FC},
	{0x3FC0, 0x3FC0, 0x0840, 0x0840, 0x0FC0, 0x0780, 0x0000, 0x0000},
	{0x0780, 0x0FC0, 0x0840, 0x0840, 0x0CC0, 0x0480, 0x0000, 0x0000},
	{0x0040, 0x0040, 0x0FC0, 0x0FC0, 0x0040, 0x0040, 0x0000, 0x0000},
	{0x0000, 0x13C0, 0x37C0, 0x2400, 0x2400, 0x3FC0, 0x1FC0, 0x0000},
	{0x0380, 0x07C0, 0x0440, 0x1FE0, 0x0440, 0x07C0, 0x0380, 0x0000},
	{0x0840, 0x0CC0, 0x0780, 0x0300, 0x0780, 0x0CC0, 0x0840, 0x0000},
	{0x0FC0, 0x0FC0, 0x0800, 0x0800, 0x0FC0, 0x1FC0, 0x1800, 0x0000},
	{0x01C0, 0x03C0, 0x0200, 0x0200, 0x0FC0, 0x0FC0, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0800, 0x0FC0, 0x0800, 0x0FC0, 0x0FC0, 0x0000},
	{0x0FC0, 0x0FC0, 0x0800, 0x0FC0, 0x0800, 0x0FC0, 0x1FC0, 0x1800},
	{0x00C0, 0x0FC0, 0x0FC0, 0x0900, 0x0900, 0x0F00, 0x0600, 0x0000},
	{0x0FC0, 0x0FC0, 0x0900, 0x0600, 0x0FC0, 0x0FC0, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0900, 0x0900, 0x0F00, 0x0600, 0x0000, 0x0000},
	{0x0480, 0x0CC0, 0x0940, 0x0940, 0x0FC0, 0x0780, 0x0000, 0x0000},
	{0x0FC0, 0x0FC0, 0x0780, 0x0FC0, 0x0840, 0x0FC0, 0x0780, 0x0000},
	{0x0980, 0x0FC0, 0x0640, 0x0240, 0x0FC0, 0x0FC0, 0x0000, 0x0000},
	{0x0808, 0x0FFC, 0x0FFC, 0x0888, 0x088C, 0x09CC, 0x0C18, 0x0000},
	{0x0780, 0x0FD8, 0x0940, 0x0940, 0x0DD8, 0x0580, 0x0000, 0x0000},
	{0x03E0, 0x07F0, 0x0C98, 0x0888, 0x0808, 0x0E38, 0x0630, 0x0000},
	{0x0780, 0x0FC0, 0x0940, 0x0940, 0x0CC0, 0x0480, 0x0000, 0x0000},
	{0x000C, 0x080C, 0x0FF0, 0x0FF0, 0x080C, 0x000C, 0x0000, 0x0000},
	{0x0000, 0x0018, 0x1018, 0x1FC0, 0x1FC0, 0x1018, 0x0018, 0x0000},
	{0x0000, 0x04F4, 0x0DF4, 0x0908, 0x0908, 0x0FF4, 0x07F4, 0x0000},
	{0x2000, 0x23D0, 0x27D0, 0x3420, 0x1C20, 0x0FD0, 0x03D0, 0x0000},
	{0x0000, 0x0070, 0x00F8, 0x0088, 0x0088, 0x00F8, 0x0070, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x00C0, 0x00C0, 0x00C0, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0080, 0x0080, 0x0000, 0x0000, 0x0000},
	{0x0000, 0x00C0, 0x0180, 0x0300, 0x0600, 0x0C00, 0x0FF8, 0x0000},
	{0x0FF8, 0x0FF8, 0x00C0, 0x0180, 0x0FF8, 0x0FF8, 0x0170, 0x0170},
	{0x0000, 0x0110, 0x01F0, 0x00A0, 0x00A0, 0x01F0, 0x0110, 0x0000},
	{0x0000, 0x0000, 0x0FF0, 0x0FF0, 0x0FF0, 0x0FF0, 0x0000, 0x0000},
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
};


const uint8_t pixfont5x8[128][5] =
{
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 00 /-/
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 01 /-/O
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 02 /-/O
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 03 /-/¶
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 04 /-/¶
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 05 /-/¶
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 06 /-/¶
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 07 /-/Х
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 08 /-/Х
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 09 /-/0
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 0A /-/0
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 0B /-/>
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 0C /-/+
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 0D /-/d
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 0E /-/d
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 0F /-/0
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 10 /-/>
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 11 /-/<
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 12 /-/¶
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 13 /-/!
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 14 /-/∂
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 15 /-/І
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 16 /-/-
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 17 /-/¶
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 18 /-/^
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 19 /-/v
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 1A /-/>
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 1B /-/<
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 1C /-/L
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 1D /-/-
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 1E /-/^
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 1F /-/°
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 20 'пробел'
	{ 0x00, 0x00, 0x5F, 0x00, 0x00 }, // 21 !
	{ 0x00, 0x07, 0x00, 0x07, 0x00 }, // 22 "
	{ 0x14, 0x7F, 0x14, 0x7F, 0x14 }, // 23 #
	{ 0x24, 0x2A, 0x7F, 0x2A, 0x12 }, // 24 $
	{ 0x23, 0x13, 0x08, 0x64, 0x62 }, // 25 %
	{ 0x36, 0x49, 0x55, 0x22, 0x50 }, // 26 &
	{ 0x00, 0x05, 0x03, 0x00, 0x00 }, // 27 '
	{ 0x00, 0x1C, 0x22, 0x41, 0x00 }, // 28 (
	{ 0x00, 0x41, 0x22, 0x1C, 0x00 }, // 29 )
	{ 0x14, 0x08, 0x3E, 0x08, 0x14 }, // 2A *
	{ 0x08, 0x08, 0x3E, 0x08, 0x08 }, // 2B +
	{ 0x00, 0x50, 0x30, 0x00, 0x00 }, // 2C ,
	{ 0x08, 0x08, 0x08, 0x08, 0x08 }, // 2D -
	{ 0x00, 0x60, 0x60, 0x00, 0x00 }, // 2E .
	{ 0x20, 0x10, 0x08, 0x04, 0x02 }, // 2F /
	{ 0x3E, 0x51, 0x49, 0x45, 0x3E }, // 30 0
	{ 0x00, 0x42, 0x7F, 0x40, 0x00 }, // 31 1
	{ 0x42, 0x61, 0x51, 0x49, 0x46 }, // 32 2
	{ 0x21, 0x41, 0x45, 0x4B, 0x31 }, // 33 3
	{ 0x18, 0x14, 0x12, 0x7F, 0x10 }, // 34 4
	{ 0x27, 0x45, 0x45, 0x45, 0x39 }, // 35 5
	{ 0x3C, 0x4A, 0x49, 0x49, 0x30 }, // 36 6
	{ 0x03, 0x01, 0x71, 0x09, 0x07 }, // 37 7
	{ 0x36, 0x49, 0x49, 0x49, 0x36 }, // 38 8
	{ 0x06, 0x49, 0x49, 0x29, 0x1E }, // 39 9
	{ 0x00, 0x36, 0x36, 0x00, 0x00 }, // 3A :
	{ 0x00, 0x56, 0x36, 0x00, 0x00 }, // 3B ;
	{ 0x08, 0x14, 0x22, 0x41, 0x00 }, // 3C <
	{ 0x14, 0x14, 0x14, 0x14, 0x14 }, // 3D =
	{ 0x00, 0x41, 0x22, 0x14, 0x08 }, // 3E >
	{ 0x02, 0x01, 0x51, 0x09, 0x06 }, // 3F ?
	{ 0x32, 0x49, 0x79, 0x41, 0x3E }, // 40 @
	{ 0x7C, 0x12, 0x11, 0x12, 0x7C }, // 41 A
	{ 0x7F, 0x49, 0x49, 0x49, 0x36 }, // 42 B
	{ 0x3E, 0x41, 0x41, 0x41, 0x22 }, // 43 C
	{ 0x7F, 0x41, 0x41, 0x41, 0x3E }, // 44 D
	{ 0x7F, 0x49, 0x49, 0x49, 0x41 }, // 45 E
	{ 0x7F, 0x09, 0x09, 0x09, 0x01 }, // 46 F
	{ 0x3E, 0x41, 0x51, 0x51, 0x32 }, // 47 G
	{ 0x7F, 0x08, 0x08, 0x08, 0x7F }, // 48 H
	{ 0x00, 0x41, 0x7F, 0x41, 0x00 }, // 49 I
	{ 0x20, 0x40, 0x41, 0x3F, 0x01 }, // 4A J
	{ 0x7F, 0x08, 0x14, 0x22, 0x41 }, // 4B K
	{ 0x7F, 0x40, 0x40, 0x40, 0x40 }, // 4C L
	{ 0x7F, 0x02, 0x04, 0x02, 0x7F }, // 4D M
	{ 0x7F, 0x04, 0x08, 0x10, 0x7F }, // 4E N
	{ 0x3E, 0x41, 0x41, 0x41, 0x3E }, // 4F O
	{ 0x7F, 0x11, 0x11, 0x11, 0x0E }, // 50 P
	{ 0x3E, 0x41, 0x51, 0x21, 0x5E }, // 51 Q
	{ 0x7F, 0x09, 0x19, 0x29, 0x46 }, // 52 R
	{ 0x46, 0x49, 0x49, 0x49, 0x31 }, // 53 S
	{ 0x01, 0x01, 0x7F, 0x01, 0x01 }, // 54 T
	{ 0x3F, 0x40, 0x40, 0x40, 0x3F }, // 55 U
	{ 0x1F, 0x20, 0x40, 0x20, 0x1F }, // 56 V
	{ 0x3F, 0x40, 0x30, 0x40, 0x3F }, // 57 W
	{ 0x63, 0x14, 0x08, 0x14, 0x63 }, // 58 X
	{ 0x07, 0x08, 0x70, 0x08, 0x07 }, // 59 Y
	{ 0x61, 0x51, 0x49, 0x45, 0x43 }, // 5A Z
	{ 0x00, 0x7F, 0x41, 0x00, 0x00 }, // 5B [
	{ 0x02, 0x04, 0x08, 0x10, 0x20 }, // 5C
	{ 0x00, 0x00, 0x41, 0x7F, 0x00 }, // 5D ]
	{ 0x04, 0x02, 0x01, 0x02, 0x04 }, // 5E ^
	{ 0x40, 0x40, 0x40, 0x40, 0x40 }, // 5F _
	{ 0x00, 0x01, 0x02, 0x04, 0x00 }, // 60 `
	{ 0x20, 0x54, 0x54, 0x54, 0x78 }, // 61 a
	{ 0x7F, 0x48, 0x44, 0x44, 0x38 }, // 62 b
	{ 0x38, 0x44, 0x44, 0x44, 0x28 }, // 63 c
	{ 0x38, 0x44, 0x44, 0x48, 0x7F }, // 64 d
	{ 0x38, 0x54, 0x54, 0x54, 0x58 }, // 65 e
	{ 0x08, 0x7E, 0x09, 0x01, 0x02 }, // 66 f
	{ 0x0C, 0x52, 0x52, 0x52, 0x3E }, // 67 g
	{ 0x7F, 0x08, 0x04, 0x04, 0x78 }, // 68 h
	{ 0x00, 0x44, 0x7D, 0x40, 0x00 }, // 69 i
	{ 0x20, 0x40, 0x44, 0x3D, 0x00 }, // 6A j
	{ 0x7F, 0x10, 0x28, 0x44, 0x00 }, // 6B k
	{ 0x00, 0x41, 0x7f, 0x40, 0x00 }, // 6C l
	{ 0x7C, 0x04, 0x18, 0x04, 0x78 }, // 6D m
	{ 0x7C, 0x08, 0x04, 0x04, 0x78 }, // 6E n
	{ 0x38, 0x44, 0x44, 0x44, 0x38 }, // 6F o
	{ 0x7C, 0x14, 0x14, 0x14, 0x08 }, // 70 p
	{ 0x08, 0x14, 0x14, 0x18, 0x7C }, // 71 q
	{ 0x7C, 0x08, 0x04, 0x04, 0x08 }, // 72 r
	{ 0x48, 0x54, 0x54, 0x54, 0x24 }, // 73 s
	{ 0x04, 0x3F, 0x44, 0x40, 0x20 }, // 74 t
	{ 0x3C, 0x40, 0x40, 0x20, 0x7C }, // 75 u
	{ 0x1C, 0x20, 0x40, 0x20, 0x1C }, // 76 v
	{ 0x3C, 0x40, 0x30, 0x40, 0x3C }, // 77 w
	{ 0x44, 0x28, 0x10, 0x28, 0x44 }, // 78 x
	{ 0x0C, 0x50, 0x50, 0x50, 0x3C }, // 79 y
	{ 0x44, 0x64, 0x54, 0x4C, 0x44 }, // 7A z
	{ 0x00, 0x08, 0x36, 0x41, 0x00 }, // 7B {
	{ 0x00, 0x00, 0x7F, 0x00, 0x00 }, // 7C |
	{ 0x00, 0x41, 0x36, 0x08, 0x00 }, // 7D }
	{ 0x04, 0x02, 0x06, 0x04, 0x02 }, // 7E ~
	{ 0x78, 0x44, 0x42, 0x44, 0x78 }, // 7F ¶
};