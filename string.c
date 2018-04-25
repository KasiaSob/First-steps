#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menu()
{
    int option;
    printf("MENU \n");
    printf("1. Zapamietaj napis     ------------- WYBIERZ  [1]\n");
    printf("2. Wyswietl napis     --------------- WYBIERZ  [2]\n");
    printf("3. Wyswietl dlugosc napisu     ------ WYBIERZ  [3]\n");
    printf("4. Policz kazda wybrana litere     -- WYBIERZ  [4]\n");
    printf("5. Zamien wybrany znak na inny     -- WYBIERZ  [5]\n");
    printf("6. Policz slowa     ----------------- WYBIERZ  [6]\n");
    printf("7. Kazde slowo w innej linii     ---- WYBIERZ  [7]\n");
    printf("0. Koniec     ----------------------- WYBIERZ  [0]\n\n");
    scanf("%d", &option);
    return option;
}

int menu_case3()
{
    int option;
    printf("1. Dlugosc calego napisu   --- WYBIERZ  [1]\n2. Ilosc liter w napisie   --- WYBIERZ  [2]\n");
    scanf("%d", &option);
    return option;
}

int menu_case5()
{
    int option;
    printf("1. Wielkosc liter nie ma znaczenia   - WYBIERZ  [1]\n2. Wielkosc liter ma znaczenie   ----- WYBIERZ  [2]\n");
    scanf("%d", &option);
    return option;
}

void info ()
{
    printf ("OPREACJE NA ZNAKACH ver: 2.1\n1. W punkcie 3 do wyboru opcja liczenia dlugosci calego lancucha znakow lub tylko znakow alfanumerycznych\n2. W punkcie 5 do wyboru 2 opcje\n3. W punkcie 4 i 5 (przy wybraniu wlasciwej opcji) nie zwraca uwagi na wielkosc liter.\n4. W punkcie 6 i 7 liczy(drukuje) osobno kazde slowo niezaleznie czy w tekscie wystepuja liczby, przecinki, kropki czy inne znaki interpunkcyjne oraz ignoruje wielokrotne spacje.\n\nDziekuje Tomkowi za pomoc i wsparcie przy szukaniu bledow.\nKasia");
}

void text(char str[])
{
    scanf(" %[^\n]s", str);
}

void show(char str[])
{
    printf("%s", str);
}

int lenght(char str[])
{
    int len;
    len = strlen(str);
    return len;
}

int letter(char str[])
{
    int len, letter=0, i;
    len = strlen(str);
    for (i=0; i< len; i++){
        if (isalnum(str[i]) != 0){
            letter++;
        }
        if (isalnum(str[i]) == 0){
            continue;
        }
    }
    return letter;
}

int number(char str[], char letter)
{
    int len, number, i;
    char text[100];
    strcpy(text,str);
    len = strlen(str);
    for (i = 0; i < len; i++){
        text[i] = toupper(text[i]);
    }
    letter = toupper(letter);
    number = 0;
    for(i = 0; i < len; i++){
        if (text[i] == letter){
            number++;
        }
    }
    return number;
}

void change_a(char str[], char letter1, char letter2)
 {
    int len, i;
    len = strlen(str);
    for (i = 0; i < len; i++){
        if ((str[i]==letter1) || (str[i]==letter1-32) || (str[i]==letter1+32)){
            if  ((isupper(str[i]) != 0) && (isupper(letter2)) != 0){
                 str[i] = letter2;
            }else if ((isupper(str[i]) == 0) && (isupper(letter2) != 0)){
                str[i] = letter2 + 32;
            }else if ((isupper(str[i]) != 0) && (isupper(letter2) == 0)){
                str[i] = letter2 - 32;
            }else if ((isupper(str[i]) == 0) && (isupper(letter2)) == 0){
                 str[i] = letter2;
            }
        }
    }
}

void change_b(char str[], char letter1, char letter2)
{

    int len, i;
    len = strlen(str);
    for (i = 0; i < len; i++){
        if (str[i] == letter1){
            str[i] = letter2;
        }
    }
}

int word(char str[])
{
    int len, i, words=0;
    len = strlen(str);
    for(i = 0; i < len; i ++){
        if ((isprint(str[i]) != 0) && (str[i] != ' ') && ((str[i+1] == ' ') || (str[i+1] == 0))) {
            words++;
        }else{
            continue;
        }
    }
    return words;
}

void new_line(char str[])
{
    int len, i;
    len = strlen(str);
    for(i = 0; i < len; i ++){
        if (str[i] != ' '){
            printf("%c", str[i]);
        }else if ((str[i-1] == ' ') &&(str[i]== ' ')){
            continue;
        }else if (str[i] == ' '){
            printf("\n");
        }

    }
}

int main()
{
    int opcja;
    char napis[100], znak, znak2;
    do{
        opcja=menu();
        switch(opcja){
            case 1:
                printf("Podaj napis: ");
                text(napis);

            break;
            case 2:
                show(napis);
            break;
            case 3:
                {
                int opcja;
                opcja = menu_case3();
                switch(opcja){
                case 1:
                    printf("Dlugosc napisu = %d", lenght(napis));
                break;
                case 2:
                    printf("Ilosc liter w napisie = %d", letter(napis));
                break;
                }
            break;
            }
            case 4:
                printf("Podaj szukana litere: ");
                scanf(" %c", &znak);
                printf("\n");
                if (number(napis,znak)== 0){
                    printf("Podana litera nie wystepuje w napisie");
                }else{
                    printf ("Litera %c wystepuje w napisie '%s' - %d raz(y)", znak, napis, number(napis,znak));
                }
            break;
            case 5:
                {
                int opcja;
                opcja = menu_case5();
                printf("Podaj jaka litere chcesz zamienic: ");
                scanf(" %c", &znak);
                if (number(napis,znak)== 0){
                    printf("Podana litera nie wystepuje w napisie");
                }else{
                    printf("Podaj na jaka chcesz zamienic: ");
                    scanf(" %c", &znak2);
                    switch(opcja){
                    case 1:
                        printf("\nNapis przed zmiana liter: %s\n", napis);
                        change_a(napis, znak, znak2);
                        printf("Napis po zamianie liter: %s", napis);
                    break;
                    case 2:
                        printf("\nNapis przed zmiana liter: %s\n", napis);
                        change_b(napis, znak, znak2);
                        printf("Napis po zamianie liter: %s", napis);
                    break;
                    }
                }
            break;
                }
            case 6:
                printf("\nNapis '%s' sklada sie z %d slow(a)", napis, word(napis));
            break;
            case 7:
                new_line(napis);
            break;
            case 8:
                info();
            break;
        }
    getchar();
    getchar();
    system("cls");
    }while (opcja!=0);
return 0;
}
