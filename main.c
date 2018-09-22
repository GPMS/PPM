#include <stdio.h>

#include "image.h"
#include "draw.h"


// basic colors in a range of 255
const Color black = {  0,   0,   0};
const Color white = {255, 255, 255};
const Color red   = {255,   0,   0};
const Color green = {  0, 255,   0};
const Color blue  = {  0,   0, 255};

int main()
{
    Image *pic = CreateImage(5, 5, 255);

    //SetPixel(pic, 0, 0, &black);

    WriteToFile(pic, "image");

    DestroyImage(pic);
}
