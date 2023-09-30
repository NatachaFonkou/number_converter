#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
    int initial_base, final_base;

    // Allocation Mémoire pour stocker le nombre entré
    char *initial_number = malloc(100 * sizeof(char));
    if (initial_number == NULL)
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

    if (valid_number_in_base(initial_number, initial_base))
    {
    }
    else
    {
        printf("Le nombre entré n'est pas valide dans la base initiale %d \n", initial_base);
    }
    free(initial_number); // Libérer la mémoire après utilisation

    return 0;
}