#include <stdio.h>     // pritnf
#ifdef WIN32
    #include <windows.h>    // ststen
#endif
#include <stdlib.h>     // rand
#include <time.h>       // time

#define DIM 256

#define SIZE 256
typedef char* string;

void black(string text);
void red(string text);
void green(string text);
void yellow(string text);
void blue(string text);
void magenta(string text);
void cyan(string text);
void white(string text);

/*
void type(int *p)
{
    printf("Prosze podac 15 liczb calkowitych :");

    char buff[SIZE], txt[SIZE]; txt[0] = '3'; txt[1] = '\0';
    // gets_s(buff, SIZE);

    unsigned x = 0;

    for( unsigned n = 0; n < 15; n++ )
    {
        unsigned w = 0;

        for( x; buff[ x ] != ' ' && buff[ x ] != '\0'; x++ )
        {

            txt[ w ] = buff[ x ];
            w++;
        }
        txt[ w++ ] = '\0';
        x++;

        for( unsigned k = 0; txt[ k ] != '\0'; k++ )
        {
            if( '9' < txt[ k ] || txt[ k ] < '0' )
            {
                p[ n ] = 0;

                break;
            }
        }

        p[ n ] = atoi( txt );

        printf( "%4d", p[ n ] );
    }
}*/
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
#ifdef WIN32  
    system("pause > nul");
#endif
//  system("color 0a");

    los = rand() % (z - a) + a;

    printf("\nPodaj liczbe z zakresu %d - %d ", a , z);

    black("\nPodaj: ");
    fgets(buff,DIM,stdin);
    podana = atoi(buff);

    do
    {
#ifdef WIN32  
        system("cls"); 
#endif

        // printf("%d\n", podana); // ostatnio podana

        printf("\nPodaj liczbe z zakresu %d - %d. Strzal nr %d.", a, z, shot_couter);

        if ( podana < los)
        {
            red("Za malo");
        }
        else
        {
            blue("Za duzo");
        }

        printf("Podaj: ");

        fgets(buff,DIM,stdin);
        // type(podana);
        podana = atoi(buff);
        shot_couter++;

        if (podana == 0)
        {
            yellow("Łatwo się poddajesz, opuszczam program!");
            break;
        }        

    } while ( podana != los );

#ifdef WIN32  
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_INTENSITY );
#else
    printf("\x1b[32m");
#endif

    printf("Brawo, zgadles za %d razem, myslalem o %d.\n", shot_couter, los);
#ifdef WIN32  
        system("pause"); 
#endif

#ifdef WIN32  
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[0m");
#endif
   

  
    return 0;
}


void black(string text) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)    
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[30m%s\x1b[0m  \n", text);
#endif
}

void red(string text) {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[31m%s\x1b[0m  \n", text);
#endif
}

void green(string text) {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
    HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
//	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );

    puts(text);

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[32m%s\x1b[0m  \n", text);
#endif
}


void yellow(string text) {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[33m%s\x1b[0m  \n", text);
#endif
}


void blue(string text) {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
    todo
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[34m%s\x1b[0m  \n", text);
#endif
}

void magenta(string text) {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
    todo
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[35m%s\x1b[0m  \n", text);
#endif
}


void cyan(string text) {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
    todo
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[36m%s\x1b[0m  \n", text);
#endif
}

void white(string text) {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)  
    todo
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    puts(comment);
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
#else
    printf("\x1b[37m%s\x1b[0m  \n", text);
#endif
}

