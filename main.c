/*
    project : Matrix and Determinant calculator
    language used: C programming
    programmer: Siddhanta Choudhury
*/

#include"matrix.h"

int main() {


    int choice;
    char ch;

    do {
            welcome();

            choice = menu();

            ChoiceyourOperation( choice );

            usleep(200000);
            printf("\n\n\t\t\t\tPress Y to go to the menu page......: ");
            fflush(stdin);
            ch = getchar();

            system("cls");
            usleep(1000000);

    } while ( ch == 'y' || ch == 'Y' );

    return 0;
}
