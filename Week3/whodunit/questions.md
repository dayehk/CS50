# Questions

## What's `stdint.h`?

The <stdint.h> header shall declare sets of integer types having specified widths, and shall define corresponding sets of macros. It shall also define macros that specify limits of integer types corresponding to types defined in other standard headers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Usually, size of int is 2 or 4 bytes. When we use uint8_t, uint16_t, uint32_t, we can define 8, 16, or 32 byte-size int variable without sign. Using int32_t, we can define 32 byte-size int with sign.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2 bytes each.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM in ASCII

## What's the difference between `bfSize` and `biSize`?

biSize: The number of bytes required by the structure.
bfSize: The size, in bytes, of the bitmap file.

## What does it mean if `biHeight` is negative?

If it is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

Because input file is not available to open.

## Why is the third argument to `fread` always `1` in our code?

Since we need to get data pixel by pixel.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

It can move file pointer associated with a given file to a specific position

## What is `SEEK_CUR`?

TODO
