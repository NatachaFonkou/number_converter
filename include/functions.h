#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int char_to_int(char c);
char int_to_char(int digit);
int convert_to_decimal(char* initial_number, int initial_base);
char *convert_to_base(int decimal_number, int final_base);
void reverse_number(char *tab);
void copy_table(char *tab1, char *tab2);
int parse_tab_to_int(char *tab, int initial_base);

// Fonctions de vérification
int valid_digit_in_base(int digit, int initial_base);
int valid_number_in_base(char *initial_number, int base);
int valid_base(int base);