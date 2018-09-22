#pragma once

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    unsigned int w, h;
    unsigned int range;
    Color** colors;
} Image;

Image* CreateImage(const int w, const int h, const int range);
void DestroyImage(Image *pic);
void WriteToFile(const Image *pic, const char* fileName);
