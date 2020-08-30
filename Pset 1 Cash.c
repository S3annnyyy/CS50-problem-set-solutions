#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //getting changed owed input from user
    float change_owed;
    do
    {
        change_owed = get_float("Changed owed in dollar: ");
    }
    while (change_owed < 0.00);

    // converting dollar to cents
    int cents;
    cents = round(change_owed * 100);

    // creating new variable coins used for change owed
    int coins;
    coins = 0;
    // body of "greedy" algorithm
    while (cents > 0)
    {
        if (cents >= 25)           //usage of while loop with if else
        {
            cents = cents - 25;
            coins++;
        }
        else if (cents >= 10)
        {
        cents = cents - 10;
            coins++;
        }
        else if (cents >= 5)
        {
        cents = cents - 5;
            coins++;
        }
        else
        {
            cents = cents - 1;
            coins++;
        }
    }
    // printing output of coins issued
    printf("%i\n", coins);
}

