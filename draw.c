#include "draw.h"

#include <stdio.h>

int CheckRange(const Image* pic, const Color* color)
{
    if (color->r <= 0 || color->r >= pic->range)
        return 1;

    if (color->g <= 0 || color->g >= pic->range)
        return 1;

    if (color->b <= 0 || color->b >= pic->range)
        return 1;

    return 0;
}

int ClearImage(Image* pic, const Color* clearColor)
{
    if (!CheckRange(pic, clearColor))
    {
        printf("ERROR: couldn't clear image to color (%d, %d, %d)\n",
               clearColor->r, clearColor->g, clearColor->b
              );
        return 1;
    }

    for (int y = 0; y < pic->h; y++)
        for (int x = 0; x < pic->w; x++)
            pic->colors[y][x] = *clearColor;
    return 0;
}

void SetPixel(Image *pic, unsigned int x, unsigned int y, const Color *color)
{
    unsigned int range = pic->range;

    if (!CheckRange(pic, color))
    {
        printf("ERROR: couldn't set color of pixel(%d,%d) to (%d, %d, %d)!\n",
               x, y, color->r, color->g, color->b
              );
        return;
    }
    pic->colors[y][x] = *color;
}
