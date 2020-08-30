#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // getting name input from user and printing it
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}
