#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int option;
    printf("MENU \n");
    printf("1. Pole prostokata\n2. N-ta potega liczby rzeczywistej\n3. Pole powierzchni  prostopadloscianu\n");
    printf("4. Objetosc szescianu\n5. Czy liczba jest parzysta\n6. Samogloska o podanym numerze\n7. Koniec\n\n");
    scanf("%d", &option);
    return option;
}

float rectangle(float side1, float side2)
{
    float area;
    area = side1 * side2;
    return area;
}

int power(int degree, int number)
{
    int i;
    float power = 1;
    for(i = 0; i < degree; i++){
        power *= number;
    }
    return power;
}

float cuboid(float side1, float side2, float side3)
{
    float area;
    area = (rectangle(side1, side2) + rectangle(side1, side3) + rectangle(side2, side3)) * 2;
    return area;
}

float cube (float side)
{
   return  power(3, side);
}

int even(int number)
{
    if(number%2==0){
        return 1;
    }
    return 0;
}

char volwel(int number)
{
    char letter[] = "AEIOU";
    char vowel;
    vowel = letter[number-1];
    return vowel;
}

int main()
{
    int opcja, liczba, stopien;
    float bok1, bok2, bok3;
    do{
        opcja=menu();
        switch(opcja)
        {
            case 1:
                printf("Podaj dlugosc pierwszego boku prostokata: ");
                scanf("%f", &bok1);
                printf("Podaj dlugosc drugiego boku prostokata: ");
                scanf(" %f", &bok2);
                printf("\n");
                printf("Pole prostokata: %.2f", rectangle(bok1, bok2));
            break;
            case 2:
                printf("Podaj liczbe: ");
                scanf("%d", &liczba);
                printf("Podaj potege, do ktorej chcesz podniesc liczbe: ");
                scanf("%d", &stopien);
                printf("\n");
                printf("Liczba %d, podniesiona do potegi %d wynosi: %d", liczba, stopien, power(stopien, liczba));
            break;
            case 3:
                printf("Podaj dlugosc pierwszej krawedzi prostopadloscianu: ");
                scanf("%f", &bok1);
                printf("Podaj dlugosc drugiej krawedzi prostopadloscianu: ");
                scanf(" %f", &bok2);
                printf("Podaj dlugosc trzeciej krawedzi prostopadloscianu: ");
                scanf(" %f", &bok3);
                printf("\n");
                printf("Pole powierzchni prostopadloscianu: %.2f", cuboid(bok1, bok2, bok3));
            break;
            case 4:
                printf("Podaj krawedz szescianu: ");
                scanf("%f", &bok1);
                printf("\n");
                printf("Objetosc szescianu: %.2f", cube (bok1));
            break;
            case 5:
                printf("Podaj liczbe: ");
                scanf("%d", &liczba);
                printf("\n");
                if (even(liczba)){
                    printf("Podana liczba jest parzysta");
                }else {
                    printf("Podana liczba jest nieparzysta");
                }
            break;
            case 6:
                do{
                    printf("Podaj numer samogloski (od 1 do 5): ");
                    scanf("%d", &liczba);
                    if (liczba > 5){
                        printf ("Podales zly numer. \n");
                        printf( "Mozesz wybrac jedna z pieciu samoglosek.\n");
                    }
                }while (liczba >5);
                printf("\n");
                printf("Wybrana samogloska, to: %c", volwel(liczba));
            break;
            case 7:
            return 0;
            break;
        }
        getchar();
        getchar();
        system("cls");
    }while(opcja!=1);

return 0;
}
