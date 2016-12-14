#include <iostream>     // cout, cin
#include <windows.h>    // ststen
#include <stdlib.h>     // rand
#include <time.h>       // time

using namespace std;

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

//  system("color 17");

    cout << "Czesc, zagramy? . . . \n";
    system("pause > nul");
//  system("color 0a");

    los = rand() % (z - a) + a;
///   Matrix
//    for (;;)
//        cout << rand() << "    ";

    cout << "\nPodaj liczbe z zakresu " << a << "-" << z << " " << endl;
//cout << los;      /// co wylosowano

    black("\nPodaj: ");
    cin >> podana;

    do
    {
        system("cls");

        cout << podana << endl; // ostatnio podana

        cout << "\nPodaj liczbe z zakresu " << a << "-" << z << " " << endl;

        if ( podana < los)
        {
            yellow("Za malo");
        }
        else
        {
            red("Za duza");
        }

        black("\nPodaj: ");
        cin >> podana;
    }while ( podana != los );

    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_INTENSITY );

    cout << "Brawo, zgadles myslalem o " << los << "." << endl;

    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

    return 0;
}


void green(string text) {

	HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
//	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );

	cout << text;
//	printf( "%s", &text);

	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}

void red(string comment) {

	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY );
	cout << comment << endl;
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}

void black(string comment) {

	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY );
    cout << comment << endl;
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}

void yellow(string comment) {

	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	cout << comment << endl;
   	 SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}
