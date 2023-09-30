#include "functions.h"

// Fonction pour convertir un caractère en nombre (par ex., '0' -> 0, '1' -> 1, ..., 'A' -> 10, 'B' -> 11, ...)
int char_to_int(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 10;
    }
    else
    {
        return -1; // Erreur : le caractère n'est pas valide dans la base
    }
}

char int_to_char(int digit)
{
    if (digit >= 0 && digit <= 9)
    {
        return digit + '0';
    }
    else if (digit >= 10 && digit <= 35)
    {
        return digit - 10 + 'A';
    }
    else
    {
        return '\0'; // Fin chaine de caractere
    }
}

// Fonction pour convertir un nombre de la base initiale à la base décimale
int convert_to_decimal(int number, int initial_base)
{
    int decimal_number = 0;
    int multiplier = 1;

    while (number >= 1)
    {
        int digit = number % 10;
        decimal_number += digit * multiplier;
        multiplier *= initial_base;
        number /= 10;
    }

    return decimal_number;
}

// Fonction pour convertir un nombre de la base décimale à une base
char *convert_to_base(int decimal_number, int final_base)
{
    char *final_number = (char *)malloc(100 * sizeof(char));
    int index = 0;
    int remainder = 0;

    while (decimal_number >= 1)
    {
        remainder = decimal_number % final_base;
        if (remainder < 10)
        {
            final_number[index] = remainder + '0';
        }
        else
        {
            final_number[index] = remainder - 10 + 'A';
        }
        decimal_number /= final_base;
        index++;
    }

    final_number[index] = '\0';

    reverse_number(final_number);

    return final_number;
}

// Afficher le nombre final en ordre inverse
void reverse_number(char *tab)
{

    int length = strlen(tab);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = tab[i];
        tab[i] = tab[length - 1 - i];
        tab[length - 1 - i] = temp;
    }
}
