#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height between 1 and 8: ");
    }
    while (h < 1 || h > 8);

    for (int j = 0; j < h; j++)
    {
        for (int i = 1; i <= h; i++)
        {
            if (i + j < (h))
            printf(" ");
            else
            printf("#");
        }
     printf("\n");
    }
}
