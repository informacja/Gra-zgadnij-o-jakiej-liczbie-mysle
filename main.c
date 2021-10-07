#include <stdio.h>     // pritnf
#include <windows.h>    // ststen
#include <stdlib.h>     // rand
#include <time.h>       // time

#define DIM 256

typedef char* string;

void green(string text);
void red(string comment);
void black(string comment);
void yellow(string comment);

int main()
{
    srand( time(0) );  /* ustawienie zarodka */

    unsigned a = 1;
    unsigned z = 1000;
    unsigned los, podana = 0;
    unsigned shot_couter = 0;
    char buff[DIM] = {0};

//  system("color 17");

    printf("Czesc, zagramy? . . . \n");
    system("pause > nul");
//  system("color 0a");

    los = rand() % (z - a) + a;

    printf("\nPodaj liczbe z zakresu %d - %d ", a , z);

    black("\nPodaj: ");
    gets(buff);
    podana = atoi(buff);

    do
    {
        system("cls");

        printf("%d\n", podana); // ostatnio podana

        printf("\nPodaj liczbe z zakresu %d - %d. Strzal nr %d.", a, z, shot_couter);

        if ( podana < los)
        {
            yellow("Za malo");
        }
        else
        {
            red("Za duza");
        }

        black("\nPodaj: ");
        gets(buff);
        podana = atoi(buff);

        shot_couter++;

    } while ( podana != los );

    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_INTENSITY );

    printf("Brawo, zgadles za %d razem, myslalem o %d.\n", shot_couter, los);

    system("pause");

    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

    return 0;
}


void green(string text) {

    HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
//	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );

    puts(text);

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}

void red(string comment) {

    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}

void black(string comment) {

    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}

void yellow(string comment) {

    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}
