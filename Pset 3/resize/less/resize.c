// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize multiplier infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // check for multiplier positive and equal or below 100
    if (n<1 || n>100)
    {
        fprintf (stderr, "Usage: resize multiplier infile outfile. For multiplier enter an integer between 0 and 100.\n");
        return 2;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_new;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_new = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_new;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_new = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // define the new dimensions of the outfile
    bi_new.biWidth = bi.biWidth * n;
    bi_new.biHeight = bi.biHeight * n;

    // determine padding for scanlines - for the infile and for the outfile
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //new image dimensions
    bi_new.biSizeImage = (( sizeof(RGBTRIPLE) * bi_new.biWidth) + new_padding ) * abs(bi_new.biHeight);
    bf_new.bfSize = bi_new.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

            // read n times
            for (int j = 0; j < n; j++)
            {

                 // iterate over pixels in scanline
                for (int m = 0; m < bi.biWidth; m++)
                    {
                         // temporary storage
                        RGBTRIPLE triple;

                        // read RGB triple from infile
                        fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                        // write RGB triple to outfile n times
                        for (int l = 0; l < n; l++)
                        {
                            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                        }
                    }

                //add padding
                for (int k=0; k < new_padding; k++)
                {
                     fputc(0x00, outptr);
                }
                if (j < (n - 1))
                {
                     fseek (inptr, -(bi.biWidth * (int)sizeof(RGBTRIPLE)), SEEK_CUR);
                }

            }

        // skip over infile padding, if any
        fseek(inptr, padding, SEEK_CUR);
        }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
