#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Height{
float x, y, z;
};

struct Gift{
char name [50];
char city[50];
struct Height height;
float weight;
};



int menu()
{
    int option;
    printf("MENU\n");
    printf("1. Dodaj prezent\n");
    printf("2. Wyswietl prezenty\n");
    printf("3. Wyswietl prezenty z miasta\n");
    printf("4. Laczna waga\n");
    printf("5. Pakuj worek\n");
    printf("6. Koniec\n\n");
    scanf("%d", &option);
    return option;
}


int main()
{
    int option, i, how_many=0;
    char if_yes, city[50];
    struct Gift gift [1000];

    do{
        float weight=0;
        option=menu();
        switch(option){
        case 1:
            for(i=how_many; i<1000; i++){
                printf("Czy chcesz dodac nowy prezent T/N? ");
                scanf (" %c", &if_yes);
                if ((if_yes=='T')||(if_yes=='t')){
                    printf("Dla kogo: ");
                    scanf(" %[^\n]s", gift[i].name);
                    printf ("Miasto: ");
                    scanf(" %[^\n]s", gift[i].city);
                    printf("Podaj wymiary paczki w cm(dl szer wys): ");
                    scanf(" %f %f %f", &gift[i].height.x, &gift[i].height.y, &gift[i].height.z );
                    printf("Podaj wage paczki (w kilogramach): ");
                    scanf(" %f", &gift[i].weight);
                    how_many++;

                }else{
                    break;
                }
            }
        break;
        case 2:
            for (i=0; i<how_many; i++){
                printf("\nPrezent %d:\n", i+1);
                printf ("Imie: %s  \nMiasto: %s \n", gift[i].name, gift[i].city);
                printf ("Wymiary paczki: %.2f, %.2f, %.2f\n", gift[i].height.x, gift[i].height.y, gift[i].height.z);
                printf ("Waga paczki: %.3f\n",gift[i].weight );
            }
        break;
        case 3:
            {
            int number = 0;
            printf("Podaj miasto: ");
            scanf(" %[^\n]s", city);
            for (i=0; i<how_many; i++){
                if( strcmp( city, gift[i].city ) == 0 ){
                    printf("\nPrezent nr %d do miasta: %s\n", number+1, city);
                    printf ("Imie: %s\n", gift[i].name);
                    printf ("Wymiary paczki: %.2f, %.2f, %.2f\n", gift[i].height.x, gift[i].height.y, gift[i].height.z);
                    printf ("Waga paczki: %.3f\n",gift[i].weight );
                    number++;
                }
            }
            }
        break;
        case 4:
            for (i=0; i<how_many; i++){
                weight+=gift[i].weight;
            }
            printf("Waga wszystkich prezentow: %.2f\n", weight);
        break;
        case 5:
            printf("Segregowac liste prezentow ze wzgledu na miasto? T/N? ");
            scanf (" %c", &if_yes);
            if ((if_yes=='T')||(if_yes=='t')){
                int number = 0;
                printf("Podaj miasto: ");
                scanf(" %[^\n]s", city);
                printf("Lista prezentow dla miasta %s: \n" , city);
                for (i=0; i<how_many; i++){
                    if(((weight+gift[i].weight) <= 20)&&( strcmp( city, gift[i].city ) == 0 )){
                        printf("\nPrezent nr: %d\n", number+1);
                        printf ("Imie: %s  \nMiasto: %s \n", gift[i].name, gift[i].city);
                        printf ("Wymiary paczki: %.2f, %.2f, %.2f\n", gift[i].height.x, gift[i].height.y, gift[i].height.z);
                        printf ("Waga paczki: %.3f\n",gift[i].weight );
                        number++;
                        weight+=gift[i].weight;
                    }
                }
            }else{
                int number = 0;
                printf("Lista prezentow: \n");
                for (i=0; i<how_many; i++){
                    if((weight+gift[i].weight) <= 20){
                        printf("\nPrezent nr: %d\n", number+1);
                        printf ("Imie: %s  \nMiasto: %s \n", gift[i].name, gift[i].city);
                        printf ("Wymiary paczki: %.2f, %.2f, %.2f\n", gift[i].height.x, gift[i].height.y, gift[i].height.z);
                        printf ("Waga paczki: %.3f\n",gift[i].weight );
                        number++;
                        weight+=gift[i].weight;
                    }
                }
            }
        break;
        }
    getchar();
    getchar();
    system("cls");
    }while (option!=6);
    return 0;
}
