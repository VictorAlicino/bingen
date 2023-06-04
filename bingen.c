/* ==========================================================================
 * bingen.c - Binary file generator
 * --------------------------------------------------------------------------
 * Copyright (c) 2023 Victor Alicino
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "1.0"

void print_version() {
    printf("bingen 1.0 (Jun 04 2023)\n");
    printf("Written by: Victor Alicino <victor.alicino@gmail.com>\n\n");
    printf("This is free software: you are free to change and redistribute it.\n");
    printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
}

void print_help() {
    printf("Usage: bingen [FILE] [SIZE]\n");
    printf("Generates a binary file of size SIZE filled with 0xFF in each byte\n");
    printf("Example: bingen test.bin 1024\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-V") == 0) {
            print_version();
            return 0;
        } else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            print_help();
            return 0;
        }
    }

    if (argc != 3) {
        printf("Usage: bingen [FILE] [SIZE]\n");
        printf("Try 'bingen --help' for more information.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "wb");
    if (fp == NULL){
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int size = atoi(argv[2]);
    for (int i = 0; i < size; i++){
        fputc(255, fp);
    }

    return 0;
}