#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/functions.h"

int main()
{
    int initial_base, final_base;
    int length, index, digit, decimal_number, multiplier = 1;
    int quotient, reste;
    char *tab_quotient = malloc(100 * sizeof(char)), *tab_reste = malloc(100 * sizeof(char));
    char *initial_number = malloc(100 * sizeof(char));

    // Allocation Mémoire pour stocker le nombre entré
    if (initial_number == NULL || tab_quotient == NULL || tab_reste == NULL)
    {
        printf("Erreur d'allocation de mémoire.\n");
        return 0;
    }

    printf("Entrer la base initiale : ");
    scanf("%d", &initial_base);
    printf("Entrer la base finale : ");
    scanf("%d", &final_base);
    printf("Entrer le nombre à convertir dans la base initiale : ");
    scanf("%s", initial_number);
    length = strlen(initial_number);

    if (valid_number_in_base(initial_number, initial_base))
    {
        int k = 0;
        while (length > 0 && initial_number[0] != 0)
        {   
            printf("Division %d : length : %d \n", k+1, length);
            index = length;
            int i = 0, j = 0;
            while (index >= 0)
            {
                digit = char_to_int(initial_number[length - index]);
                decimal_number = digit;
                if (i == 0)
                {
                    while (decimal_number < final_base)
                    {
                        initial_number[length - index] = 0;
                        index--;
                        digit = char_to_int(initial_number[length - index]);
                        decimal_number = decimal_number * initial_base + digit; // Algorithme de Horner
                    }
                }

                quotient = decimal_number / final_base;
                reste = decimal_number % final_base;
                printf("quotient : %d \n", quotient);

                tab_quotient[i] = convert_to_base(quotient, initial_base)[0];
                printf("tab_quotient[%d] : %d \n", i, tab_quotient[i]);
                reste = int_to_char(reste);
                initial_number[length - index + 1] = reste;
                i++;
                index--;
            }
            tab_reste[k] = convert_to_base(char_to_int(initial_number[length]), final_base)[0];
            printf("tab_reste[%d] : %d \n\n\n", k, tab_reste[k]);
            copy_table(initial_number, tab_quotient);
            length = strlen(initial_number);
            if (length == 1){
                length --;
            }
            k++;
            ;
        }
    }
    else
    {
        printf("Le nombre entré n'est pas valide dans la base initiale %d \n", initial_base);
        free(initial_number); // Libérer la mémoire après utilisation
        return 0;
    }
    reverse_number(tab_reste);

    printf("Le resultat est : ");
    for (int i = 0; i < strlen(tab_reste); i++)
    {
        printf("%c", tab_reste[i]);
    }

    // Libération de la mémoire
    free(initial_number);
    free(tab_quotient);
    free(tab_reste);

    return 0;
}