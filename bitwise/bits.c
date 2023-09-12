#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    printf("%d\n", 0b00000001);
    printf("%d\n", 0b00000010);
    printf("%d\n", 0b00000100);
    printf("%d\n", 0b00001000);
    printf("%d\n", 0b00010000);
    printf("%d\n", 0b00100000);
    printf("%d\n", 0b01000000);
    printf("%d\n", 0b10000000);
    printf("---------\n");
    printf("%d\n", 0b11111111);
    printf("%d\n", 0b1111111111111111);
    printf("%d\n", 0b111111111111111111111111);
    printf("%d\n", 0b01111111111111111111111111111111);
    printf("---------\n");

    printf("%d\n", 0x01);
    printf("%d\n", 0x02);
    printf("%d\n", 0x04);
    printf("%d\n", 0x08);
    printf("%d\n", 0x0f);
    printf("---------\n");

    printf("%d\n", 0x10);
    printf("%d\n", 0x20);
    printf("%d\n", 0x40);
    printf("%d\n", 0x80);
    printf("%d\n", 0xff);
    printf("---------\n");

    printf("%d\n", 0x100);
    printf("%d\n", 0x200);
    printf("%d\n", 0x400);
    printf("%d\n", 0x800);
    printf("%d\n", 0xfff);
    printf("---------\n");

    printf("%d\n", 0x1000);
    printf("%d\n", 0x2000);
    printf("%d\n", 0x4000);
    printf("%d\n", 0x8000);
    printf("%d\n", 0xffff);
    printf("---------\n");
    return EXIT_SUCCESS;
}

