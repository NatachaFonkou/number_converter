#include "functions.h"

// Ensemble de fonctions qui vérifie les conditions pour pouvoir réaliser la division

// Verifie si un chiffre est bien dans une base
int valid_digit_in_base(int digit, int initial_base)
{
    int valid = (digit >= initial_base) ? 0 : 1;
    return valid;
}

int valid_number_in_base(char *initial_number, int base)
{
    char digit;
    for (int i = 0; i < strlen(initial_number); i++)
    {
        digit = initial_number[i];
        digit = char_to_int(digit);
        if (digit < 0)
        {
            return -1;
        }
        else if (valid_digit_in_base(digit, base))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int valid_base(int base)
{
    int valid = (base <= 1) ? 0 : 1;
    return valid;
}