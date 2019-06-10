#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover file\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open card file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // define buffer for 512 bytes
    unsigned char buffer[512];

    // count of found JPEGs
    int counter = 0;

    // JPEG file and file name
    FILE *img = NULL;
    char filename[10];

    // repeat reading 512 bytes chunks until end of the card
    while ( fread(buffer, 512, 1, inptr) )
    {
        // check if first bytes correspond to JPEG file
        if ((buffer [0] == 0xff) &&
            (buffer [1] == 0xd8) &&
            (buffer [2] == 0xff) &&
            ((buffer [3] & 0xf0) == 0xe0))
            {
                // check if we already found JPEG
                if (counter>0)
                {
                    // if yes, close it
                    fclose(img);
                }

                // now point new file name and increase counter
                sprintf(filename,"%03i.jpg",counter);
                counter ++;

                // open new file to write to and write 512 chunks of bytes into it
                img = fopen(filename, "w");
                fwrite (buffer, 512, 1, img);
            }

        else if (img != NULL)
            {
            fwrite (buffer, 512, 1, img);
            }
    }

    // close infile
    fclose(inptr);

    // close any JPEG file
    fclose(img);

    // success
    return 0;
}
