#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool validity_of_key(string s);                        //creating function to determine if key is valid

int main(int argc, string argv[])                      //command line arguement
{
  if (argc == 2 && validity_of_key(argv[1]))
  {
    int k = atoi(argv[1]);                               // getting integer of key input from user
    string plaintext = get_string("plaintext: ");       //getting text
    int n = strlen(plaintext);
    printf("ciphertext: ");                             //printing out cipher

    for (int i = 0; i < n; i++)
    {
       if (isalpha(plaintext[i]))
       {
          if (islower(plaintext[i]))
          {
             printf("%c", ((((plaintext[i] - 97) + k) % 26) + 97));
          }
          else if (isupper(plaintext[i]))
          {
             printf("%c", ((((plaintext[i] - 65) +k) % 26) + 65));
          }
       }   
       else
       {
          printf("%c", plaintext[i]);
       }

    }
     printf("\n");
     return 0;
  }
  else
  {
     printf("Usage: %s\n", argv[0]);
     return 1;
  }
}

bool validity_of_key(string s)
{
 for (int y = 0, len = strlen(s); y < len; y++)
  if (!isdigit(s[y]))
   return false;
 return true;
}
