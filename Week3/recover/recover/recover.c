#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];
    int n = 0, m = 0;

//open card file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }


//repeat until end of the card
    uint8_t *buf = malloc(512);
    int k = fread(buf, 1, 512, inptr);
    FILE *img = NULL;

    while (k == 512)
    {
        // start of a new JPEG?(found JPEG header?)
        if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0)
        {
            char filename[30];
            if (n != 0)
            {
                //close file
                fclose(img);
            }
            //open a new file
            sprintf(filename, "%03i.jpg", n);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %03i.jpg.\n", n);
                return 3;
            }
            fwrite(buf, 1, 512, img);
            m = 1;
            n++;
        }
        //if already found a JPEG -> keep writing
        else if (m == 1)
        {
            fwrite(buf, 1, 512, img);
        }
        //if not found a JPEG -> empty buf
        else
        {
            memset(buf, (char)0, 512);
        }
        //read 512 bytes into a buffer
        k = fread(buf, 1, 512, inptr);
    }
    fwrite(buf, 1, k, img);
    fclose(img);
    fclose(inptr);
    free(buf);
}
