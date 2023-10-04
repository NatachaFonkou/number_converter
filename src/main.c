#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/functions.h"

int main()
{
    int initial_base, final_base;
    int length = 0, index, digit = 0, decimal_number = 0, multiplier = 1;
    int quotient, reste = 0;
    char *tab_quotient = (char *)malloc(100 * sizeof(char));
    char *initial_number = NULL;
    int character;

    // Allocation Mémoire pour stocker le nombre entré
    if (tab_quotient == NULL)
    {
        printf("Erreur d'allocation de mémoire.\n");
        return 1;
    }
    printf("Entrer le nombre à convertir dans la base initiale : ");
    while ((character = getchar()) != '\n' && character != EOF)
    {
        initial_number = (char *)realloc(initial_number, length + 1);
        if (initial_number == NULL)
        {
            printf("Erreur d'allocation de mémoire.\n");
            return 1;
        }
        initial_number[length] = character;
        length++;
    }
    initial_number[length] = '\0';
    printf("Entrer la base initiale : ");
    scanf("%d", &initial_base);
    printf("Entrer la base finale : ");
    scanf("%d", &final_base);

    char *initial_number_copy = (char *)malloc(length * sizeof(char));
    if (initial_number_copy == NULL)
    {
        printf("Erreur d'allocation de mémoire.\n");
        return 1;
    }
    strcpy(initial_number_copy, initial_number);

    if (valid_number_in_base(initial_number_copy, initial_base))
    {
        int interm_decimal = convert_to_decimal(initial_number_copy, initial_base);
        char *result = convert_to_base(interm_decimal, final_base);
        int length_reste = strlen(result);
        free(result);
        char *tab_reste = (char *)malloc(length_reste * sizeof(char));
        int k = 0;
        for (int cpt = 1; cpt <= length_reste; ++cpt)
        {
            index = length;
            int i = 0, j = 0;
            while (index > 0)
            {
                digit = char_to_int(initial_number_copy[length - index]);
                decimal_number = digit + reste * initial_base;

                if (i == 0)
                {
                    while (decimal_number < final_base)
                    {
                        initial_number_copy[length - index] = 0;
                        index--;
                        digit = char_to_int(initial_number_copy[length - index]);
                        decimal_number = decimal_number * initial_base + digit;
                        // Algorithme de Horner
                    }
                }

                quotient = decimal_number / final_base;
                reste = decimal_number % final_base;

                tab_quotient[i] = convert_to_base(quotient, initial_base)[0];
                initial_number_copy[length - index] = convert_to_base(reste, initial_base)[0];
                i++;
                index--;
            }

            tab_reste[k] = convert_to_base(reste, final_base)[0];
            tab_quotient[i++] = '\0';

            strcpy(initial_number_copy, tab_quotient);
            length = strlen(initial_number_copy);
            k++;
            ;
        }
        reverse_number(tab_reste);

        printf("Le resultat est : ");
        for (int i = 0; i < strlen(tab_reste); i++)
        {
            printf("%c", tab_reste[i]);
        }
        free(tab_reste);
    }
    else
    {
        printf("Le nombre entré n'est pas valide dans la base initiale %d \n", initial_base);
        free(initial_number); // Libérer la mémoire après utilisation
        return 1;
    }

    // Libération de la mémoire
    free(initial_number);
    free(tab_quotient);

    return 0;
}