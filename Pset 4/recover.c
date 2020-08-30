#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //ensuring argv[1] exists
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //filename
    char *card = argv[1];
    //opening file card
    FILE* file = fopen(card, "r");

    //buffer array
    BYTE buffer[512];

    //counter for jpeg file
    int counter = 0;

    //file pointer to be written to
    FILE *img;

    //new array to store jpeg images
    char pictures[8];

    //while loop
    while (fread(buffer, sizeof(buffer), 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                //close already opened file
                fclose(img);

                //print picture using sprintf
                sprintf(pictures, "%03d.jpg", counter);
                counter += 1;

                //open new file for writing
                img = fopen(pictures, "w");

                //write to outfile
                fwrite(buffer, sizeof(buffer), 1, img);
            }
            if (counter == 0)
            {
                 //print picture using sprintf
                sprintf(pictures, "%03d.jpg", counter);
                counter += 1;
                //open new file for writing
                img = fopen(pictures, "w");
                //write to outfile
                fwrite(buffer, sizeof(buffer), 1, img);
            }
        }
        else if(counter > 0)
        {
            fwrite(buffer, sizeof(buffer), 1, img);
        }
    }
    fclose(img);
    fclose(file);
    return 0;
}
