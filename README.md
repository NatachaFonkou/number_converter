# Convertisseur de Bases

## Description

Ce projet est un programme en C qui permet de convertir des nombres entre différentes bases numériques en utilisant les divisions successives. Il propose des fonctions de conversion et des fonctions de verifications pour s'assurer que la conversion est possible (**validité des données**)

## Principe
Il permet à l'utilisateur de convertir un nombre d'une base initiale vers une base finale en passant par la base décimale. Lorsque l'utlisateur entre un nombre, le programme se charge d'effectuer les verifications et si la division est possible, on effectue la division comme au primaire 😅. C'est à dire on compare le chiffre le plus à gauche 0 à la base finale, si la division est possible, on la fait; sinon on ajoute le digit suivant. La comparaison se fait dans la base 10. Le reste de cette division et le quotient sont gardés en basee initiale et on continue la division jusqu'a obtenir un dernier reste etant à la fin du nombre. Le quotient de la division est encore divisé par la base finale. Ainsi de suite jusqu'a obtenir un quotient nul.
## Fonctions incluses

Le projet comprend les fonctions les fonctions suivantes :

### Fonctions principales

- `int char_to_int(char c)` :  Convertit un caractère en un nombre. Par exemple, '0' devient 0, '1' devient 1, 'A' devient 10, et ainsi de suite.
- `char int_to_char(int digit)` : Fait l'inverse de la fonction précédente. Elle prend un nombre et le convertit en caractère.
- `int convert_to_decimal(int number, int initial_base)`: Convertit un nombre de la base initiale à la base décimale
- `char *convert_to_base(int decimal_number, int final_base)`: Convertit un nombre de la base décimale à la base finale. (Retourne un tableau dynamique qui doit être libéré après utilisation).
- `void reverse_number(char *tab)`: Inverse l'ordre des caractères dans un tableau de caractères.
### Fonctions de vérification

- `int valid_digit_in_base(int digit, int initial_base)`: 
- `int valid_number_in_base(char *initial_number, int base)` :
- `int valid_base(int base)` :

## Utilisation
Le programme principal se trouve dans le fichier _**main.c**_. Il demande à l'utilisateur de fournir la base initiale, la base finale et le nombre à convertir. Si le nombre est valide dans la base initiale, on effectue la conversion et on affiche le resultat à l'ecran.

## Compilation
Pour compiler le programme, il faut un compilateur du C tel que le GCC. Entrer la commande suivante : _**gcc lib/verifier.c lib/main_functions.c src/main.c -o bin/conversion_bases.exe**_ Ensuite _cd bin_ puis lancer l'exécutable _conversion_bases.exe_

## Auteur
[Natacha Fonkou, Computer Science Student]