#include "image.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Image* CreateImage(const int w, const int h, const int maxValue)
{
    Image* pic = (Image*) malloc(sizeof(Image));
    
    // Set properties
    pic->w = w;
    pic->h = h;
    pic->maxValue = maxValue;

    // Allocate pixels for a 'w x h' image
    // pixels[y][x]
    pic->colors = (Color**) malloc(sizeof(Color*) * h);

    if (!pic->colors)
    {
        printf("ERROR: malloc failed!\n");
        exit(1);
    }

    Color defaultColor = { maxValue, maxValue, maxValue };

    for (int y = 0; y < h; y++)
    {
        pic->colors[y] = (Color*) malloc(sizeof(Color*) * w);

        if (!pic->colors[y])
        {
            printf("ERROR: malloc failed!\n");
            exit(1);
        }

        // Set default color
        for (int x = 0; x < w; x++)
            pic->colors[y][x] = defaultColor;
    }

    return pic;
}

void DestroyImage(Image *pic)
{
    if (!pic)
    {
        printf("ERROR: no image to dealocate\n");
        return;
    }

    for (int i = 0; i < pic->h; i++)
    {
        free(pic->colors[i]);
    }
    free(pic->colors);

    free(pic);
}

void WriteToFile(const Image *pic, const char* fileName)
{
    FILE* fp = NULL;
    char fileNameExt[80];   // File name with extension

    if (!pic)
    {
        printf("ERROR: no image to write to file!");
        return;
    }

    sprintf(fileNameExt, "%s.ppm", fileName);

    // Can only open files for reading if they exist
    if ((fp = fopen(fileNameExt, "r")))
    {
        fclose(fp);

        printf("WARNING: file exists!\n");
        printf("Do you wish to overwrite it? (y/n): ");
        
        if (getchar() == 'n')
            return;
    }

    fp = fopen(fileNameExt, "w+");

    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", pic->w, pic->h);
    fprintf(fp, "%d\n", pic->maxValue);

    for (int y = 0; y < pic->h; y++)
    {
        for (int x = 0; x < pic->w; x++)
        {
            fprintf(fp, "%3d %3d %3d",
                    pic->colors[y][x].r, pic->colors[y][x].g, pic->colors[y][x].b
                   );
            if (x < pic->w-1)
                fputc(' ', fp);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
