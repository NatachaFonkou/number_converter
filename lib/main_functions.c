#include "../include/functions.h"

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
int parse_tab_to_int(char *tab, int initial_base)
{
    int length = strlen(tab);
    int *parse_tab = (int *)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        parse_tab[i] = char_to_int(tab[i]);
    }

    int decimal_number = parse_tab[0];

    for(int i = 1; i < length; ++i){
        decimal_number = decimal_number * initial_base + parse_tab[i];
    }

    free(parse_tab); 
    return decimal_number;
}




// Fonction pour convertir un nombre de la base initiale à la base décimale
int convert_to_decimal(char* initial_number, int initial_base)
{
    int decimal_number = 0;
    int length = strlen(initial_number);

    for (int i = 0; i < length; i++)
    {
        int digit_value = char_to_int(initial_number[i]);

        if (digit_value < 0 || digit_value >= initial_base)
        {
            // Le caractère n'est pas valide dans cette base
            return -1;
        }

        decimal_number = decimal_number * initial_base + digit_value;
    }

    // printf("decimal_number : %d", decimal_number);
    return decimal_number;

}
    

// Fonction pour convertir un nombre de la base décimale à une base
char* convert_to_base(int decimal_number, int final_base)
{
    if (final_base < 2 || final_base > 36) {
        return NULL; // La base doit être comprise entre 2 et 36 inclusivement.
    }

    char* final_number = (char *)malloc(100 * sizeof(char));
    int index = 0;
    int remainder = 0;

    while (decimal_number > 0)
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

    if (index == 0)
    {
        final_number[index] = '0';
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
    // printf("length : %d \n", length);
    for (int i = 0; i <= length / 2; i++)
    {
        char temp = tab[i];
        tab[i] = tab[length - 1 - i];
        tab[length - 1 - i] = temp;
    }
    tab[length] = '\0';
}

void copy_table(char *tab1, char *tab2)
{
    int i = 0;

    while (tab2[i] != '\0')
    {
        tab1[i] = tab2[i];
        i++;
    }

    tab1[i] = '\0';
}