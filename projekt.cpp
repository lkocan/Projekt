#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>              
#include <stdlib.h>
#include "funkcie.h"

void OnAdd() {
    int cislo;

    printf("\nCislo : ");
    scanf_s("%d", &cislo);
    while (getchar() != '\n');
    insertNode(, cislo);

}

void OnDel() {
    int cislo;

    printf("\nZmazat cislo : ");
    scanf_s("%d", &cislo);
    while (getchar() != '\n');
    deleteNode(, cislo);
}

void Tisk() {
    //funkcia na tisk do konzole + suboru
}

int main() {

    char  cmd;

    do
    {
        system("cls");		
        printf("A: Pridat     ");
        printf("D: Zmazat     ");
        printf("P: Tisk     ");
        printf("Q: Koniec\n\n");

        cmd = tolower(getchar());
        while (getchar() != '\n');

        switch (cmd)
        {
        case 'a':
            OnAdd();		
            break;
        case 'd':
            OnDel();			
            break;
        case 'p':
            Tisk();
            break;
        }
    } while (cmd != 'q');
    return 0;
}
