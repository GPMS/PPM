#pragma once

#include "image.h"

int CheckRange(const Image* pic, const Color* color);
int ClearImage(Image* pic, const Color* clearColor);
void SetPixel(Image *pic, unsigned int x, unsigned int y, const Color *color);
