#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum komande {levo, desno, gore, dole, nista, pucanj_desno, pucanj_levo, pucanj_dole, pucanj_gore};
enum result {res_reaktor, res_medic, res_normal};
enum oruzja {nijedno, pistolj, laser, bazooka};
const int reaktor = -20;
const int medic = 30;
const int pocetna_energija = 200;
//const int kretanje = -5;
const int maks_broj_reaktora = 400;
const int maks_broj_medica = 400;
const int xmax = 20;
const int ymax = 20;
int pos_reaktor[maks_broj_reaktora * 2] = {1, 4};
int pos_medic[maks_broj_medica * 2] = {4, 1};
//int pos[2] = {0,0};
//int pos_m[2] = {xmax + 1, ymax + 1};
//int energija = 200;
//int energija2 = 100;
//int score = 0;
int brojac_medic = 1;
int brojac_reaktor = 1;
//int pos_o[2] = {0,0};
int krajigre_promenljiva = 0;
int level = 1;
int ukupno_usporenje = 150;
char matrix[xmax + 2][ymax + 2];
struct igrac
{
    char tip;
    int energija;
    int energija_kretanja;
    int poeni;
    int pozicija[2];
    int brzina;
    int stanje;
    int oruzje;
    int pozicija_metka[2];
};
igrac igrac_x;
igrac igrac_o;

void print_screen(void);

void beep_igrica (int frenkvencija, int vreme)
{
    if (krajigre_promenljiva == 1)
    {
        pthread_exit(NULL);
    }
    else
    {
        Beep(frenkvencija, vreme);
    }
    return;
}
void *Muzika(void *threadid)
 {
    while(1)
    {
            beep_igrica (330,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (392,100);Sleep(350);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (262,300);Sleep(150);
            beep_igrica (196,300);Sleep(150);
            beep_igrica (164,300);Sleep(150);
            beep_igrica (220,300);Sleep(50);
            beep_igrica (246,100);Sleep(150);
            beep_igrica (233,200);
            beep_igrica (220,100);Sleep(150);
            beep_igrica (196,100);Sleep(75);
            beep_igrica (330,100);Sleep(75);
            beep_igrica (392,100);Sleep(75);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (392,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (247,100);Sleep(250);
            beep_igrica (262,300);Sleep(150);
            beep_igrica (196,300);Sleep(150);
            beep_igrica (164,300);Sleep(150);
            beep_igrica (220,300);Sleep(50);
            beep_igrica (246,100);Sleep(150);
            beep_igrica (233,200);
            beep_igrica (220,100);Sleep(150);
            beep_igrica (196,100);Sleep(75);
            beep_igrica (330,100);Sleep(75);
            beep_igrica (392,100);Sleep(75);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (392,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (247,100);Sleep(450);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (207,100);Sleep(50);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(250);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (523,100);Sleep(150);
            beep_igrica (523,100);Sleep(50);
            beep_igrica (523,100);Sleep(550);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (207,100);Sleep(50);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(250);
            beep_igrica (311,300);Sleep(150);
            beep_igrica (296,300);Sleep(150);
            beep_igrica (262,300);Sleep(650);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(150);
            beep_igrica (330,200);Sleep(25);
            beep_igrica (262,200);Sleep(25);
            beep_igrica (220,200);Sleep(25);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (330,100);Sleep(350);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (392,100);Sleep(250);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(150);
            beep_igrica (330,200);Sleep(25);
            beep_igrica (262,200);Sleep(25);
            beep_igrica (220,200);Sleep(25);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (330,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (392,100);Sleep(350);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (196,100);Sleep(62);
            beep_igrica (262,100);Sleep(62);
            beep_igrica (330,100);Sleep(62);
            beep_igrica (392,100);Sleep(62);
            beep_igrica (523,100);Sleep(62);
            beep_igrica (660,100);Sleep(62);
            beep_igrica (784,100);Sleep(282);
            beep_igrica (660,100);Sleep(282);
            beep_igrica (207,100);Sleep(62);
            beep_igrica (262,100);Sleep(62);
            beep_igrica (311,100);Sleep(63);
            beep_igrica (415,100);Sleep(62);
            beep_igrica (523,100);Sleep(62);
            beep_igrica (622,100);Sleep(62);
            beep_igrica (830,100);Sleep(282);
            beep_igrica (622,100);Sleep(282);
            beep_igrica (233,100);Sleep(62);
            beep_igrica (294,100);Sleep(62);
            beep_igrica (349,100);Sleep(62);
            beep_igrica (466,100);Sleep(62);
            beep_igrica (587,100);Sleep(62);
            beep_igrica (698,100);Sleep(62);
            beep_igrica (932,100);Sleep(282);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (1046,675);
    }

    pthread_exit(NULL);
 }
void ludzvuk (void)
{
    Beep(300, 10);
}
void dobarzvuk (void)
{
    Beep(3000, 10);
}
void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void gameover (void)
{
    krajigre_promenljiva = 1;
    print_screen();
    gotoxy(xmax + 3, 4);
    cout << "Game over, your score is " << igrac_x.poeni << ".";
    Beep(420, 200);
    Beep(400, 200);
    Beep(420, 200);
    Beep(400, 200);
    Beep(420, 200);
    Beep(315, 200);
    Beep(370, 200);
    Beep(335, 200);
    Beep(282, 600);
    Beep(180, 200);
    Beep(215, 200);
    Beep(282, 200);
    Beep(315, 600);
    Beep(213, 200);
    Beep(262, 200);
    Beep(315, 200);
    Beep(335, 600);
    Beep(213, 200);
    Beep(420, 200);
    Beep(400, 200);
    Beep(420, 200);
    Beep(400, 200);
    Beep(420, 200);
    Beep(315, 200);
    Beep(370, 200);
    Beep(335, 200);
    Beep(282, 600);
    Beep(180, 200);
    Beep(215, 200);
    Beep(282, 200);
    Beep(315, 600);
    Beep(213, 200);
    Beep(330, 200);
    Beep(315, 200);
    Beep(282, 600);
    pthread_exit(NULL);
}
char tipka(void)
{
    if (kbhit()!=0)
        return getch();
    else
        return 0;
}
void clear_console(void)
{
    system("CLS");
}
void clear_matrix(void)
{
    for (int i = 0; i < xmax + 2; i++)
    {
        for (int j = 0; j < ymax + 2; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}
void print_border(void)
{
    for(int i = xmax + 1; i>=0; i--)
    {
        matrix[i][ymax + 1] = '-';
    }
    for(int i = ymax + 1; i >= 0; i--)
    {
        matrix[xmax + 1][i] = '|';
    }
}
void print_matrix(void)
{
    static char matrix_old[xmax + 2][ymax + 2];
    for (int i = 0; i < xmax + 2; i++)
    {
        for (int j = 0; j < ymax + 2; j++)
        {
            if (matrix_old[i][j] != matrix[i][j])
            {
                gotoxy(i, j);
                cout << matrix[i][j];
            }
        }

    }
    for (int i = 0; i < xmax + 2; i++)
    {
        for (int j = 0; j < ymax + 2; j++)
        {
            matrix_old[i][j] = matrix[i][j];
        }
    }
}
void print_screen(void)
{
    clear_matrix();
    print_border();
    for (int i = 0; i < brojac_reaktor; i++)
    {
        matrix[pos_reaktor[i]][pos_reaktor[i + 1]] = '!';
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        matrix[pos_medic[i]][pos_medic[i + 1]] = '+';
    }
    matrix[igrac_x.pozicija[0]][igrac_x.pozicija[1]] = 'X';
    if (igrac_x.energija < 0)
    {
        igrac_x.energija = 0;
    }
    matrix[igrac_o.pozicija[0]][igrac_o.pozicija[1]] = 'O';
    gotoxy(xmax + 3, 0);
    cout << "Tvoja energija je: " << igrac_x.energija << endl;
    gotoxy(xmax + 3, 1);
    cout << "Protivnikova energija je: " << igrac_o.energija << endl;
    gotoxy(xmax + 3, 2);
    cout << "Score: " << igrac_x.poeni << endl;
    gotoxy(xmax + 3, 3);
    cout << "Level: " << level << endl;
    if (igrac_x.pozicija_metka[0] <= xmax && igrac_x.pozicija_metka[1] <= ymax)
    {
        matrix[igrac_x.pozicija_metka[0]][igrac_x.pozicija_metka[1]] = '*';
    }
    print_matrix();
    return;
}

int igrica (int komanda)
{
    static int usporenje = 0;
    static int metak_ispaljen = 0;
    if (komanda == levo)
    {
        igrac_x.pozicija[0] -= 1;
        igrac_x.energija = igrac_x.energija + igrac_x.energija_kretanja;
        print_screen();
    }
    if (komanda == desno)
    {
        igrac_x.pozicija[0] += 1;
        igrac_x.energija = igrac_x.energija + igrac_x.energija_kretanja;
        print_screen();
    }
    if (komanda == gore)
    {
        igrac_x.pozicija[1] -= 1;
        igrac_x.energija = igrac_x.energija + igrac_x.energija_kretanja;
        print_screen();
    }
    if (komanda == dole)
    {
        igrac_x.pozicija[1] += 1;
        igrac_x.energija = igrac_x.energija + igrac_x.energija_kretanja;
        print_screen();
    }
    if (komanda == pucanj_desno)
    {
        metak_ispaljen = 1;
    }
    if (metak_ispaljen == 1)
    {
        if (igrac_x.pozicija_metka[0] < xmax + 1)
        {
            igrac_x.pozicija_metka[0]++;
        }
        else
        {
            metak_ispaljen = 0;
        }
    }
    if (komanda == pucanj_levo)
    {
        metak_ispaljen = 2;
    }
    if (metak_ispaljen == 2)
    {
        if (igrac_x.pozicija_metka[0] > 0)
        {
            igrac_x.pozicija_metka[0]--;
        }
        else
        {
            metak_ispaljen = 0;
            igrac_x.pozicija_metka[0] = xmax + 1;
        }
    }
    if (komanda == pucanj_gore)
    {
        metak_ispaljen = 3;
    }
    if (metak_ispaljen == 3)
    {
        if (igrac_x.pozicija_metka[1] > 0)
        {
            igrac_x.pozicija_metka[1]--;
        }
        else
        {
            metak_ispaljen = 0;
            igrac_x.pozicija_metka[1] = ymax + 1;
        }
    }
    if (komanda == pucanj_dole)
    {
        metak_ispaljen = 4;
    }
    if (metak_ispaljen == 4)
    {
        if (igrac_x.pozicija_metka[1] < ymax + 1)
        {
            igrac_x.pozicija_metka[1]++;
        }
        else
        {
            metak_ispaljen = 0;
        }
    }
    for (int i = 0; i < brojac_reaktor; i++)
    {
        if ((igrac_x.pozicija[0] == pos_reaktor[i]) && (igrac_x.pozicija[1] == pos_reaktor[i + 1]))
        {
            igrac_x.energija = igrac_x.energija + reaktor;
            for (int j = 0; j < brojac_reaktor; j++)
            {
                pos_reaktor[j] = rand() % xmax + 1;
                pos_reaktor[j + 1] = rand() % ymax + 1;
            }
            brojac_reaktor++;
            return res_reaktor;
        }
    }
    for (int i = 0; i < brojac_reaktor; i++)
    {
        if ((igrac_o.pozicija[0] == pos_reaktor[i]) && (igrac_o.pozicija[1] == pos_reaktor[i + 1]))
        {
            igrac_o.energija = igrac_o.energija + reaktor;
            if (igrac_o.energija < 0)
            {
                igrac_o.energija = 100;
                level++;
                ukupno_usporenje--;
            }
            for (int j = 0; j < brojac_reaktor; j++)
            {
                pos_reaktor[j] = rand() % xmax + 1;
                pos_reaktor[j + 1] = rand() % ymax + 1;
            }
            brojac_reaktor++;
            return res_reaktor;
        }
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        if ((igrac_x.pozicija[0] == pos_medic[i]) && (igrac_x.pozicija[1] == pos_medic[i + 1]))
        {
            igrac_x.energija = igrac_x.energija + medic;
            for (int j = 0; j < brojac_medic; j++)
            {
                pos_medic[j] = rand() % xmax + 1;
                pos_medic[j + 1] = rand() % ymax + 1;
            }
            brojac_medic++;
            return res_medic;
        }
    for (int i = 0; i < brojac_medic; i++)
    {
        if ((igrac_o.pozicija[0] == pos_medic[i]) && (igrac_o.pozicija[1] == pos_medic[i + 1]))
        {
            igrac_o.energija = igrac_o.energija + medic;
            for (int j = 0; j < brojac_medic; j++)
            {
                pos_medic[j] = rand() % xmax + 1;
                pos_medic[j + 1] = rand() % ymax + 1;
            }
            brojac_medic++;
            return res_medic;
        }
    }
    }
    if (igrac_x.pozicija[0] > xmax)
    {
        igrac_x.pozicija[0] = 0;
        print_screen();
    }
    if (igrac_x.pozicija[0] < 0)
    {
        igrac_x.pozicija[0] = xmax;
        print_screen();
    }
    if (igrac_x.pozicija[1] > ymax)
    {
        igrac_x.pozicija[1] = 0;
        print_screen();
    }
    if (igrac_x.pozicija[1] < 0)
    {
        igrac_x.pozicija[1] = ymax;
        print_screen();
    }
    if (igrac_x.pozicija_metka[0] == igrac_o.pozicija[0] && igrac_x.pozicija_metka[1] == igrac_o.pozicija[1])
    {
        usporenje = -20;
        metak_ispaljen = 0;
        igrac_x.pozicija_metka[0] = xmax + 1;
        igrac_x.pozicija_metka[1] = ymax + 1;
        igrac_x.poeni = igrac_x.poeni + 10;
    }
    if (igrac_x.pozicija[0] != igrac_o.pozicija[0])
    {
        usporenje++;
        if (usporenje >= ukupno_usporenje)
        {
            if (igrac_x.pozicija[0] < igrac_o.pozicija[0])
            {
                igrac_o.pozicija[0]--;
            }
            else if (igrac_x.pozicija[0] > igrac_o.pozicija[0])
            {
                igrac_o.pozicija[0]++;
            }
        }
        print_screen();
    }
    if (igrac_x.pozicija[1] != igrac_o.pozicija[1])
    {
        usporenje++;
        if (usporenje >= ukupno_usporenje)
        {
            if (igrac_x.pozicija[1] < igrac_o.pozicija[1])
            {
                igrac_o.pozicija[1]--;
            }
            else if (igrac_x.pozicija[1] > igrac_o.pozicija[1])
            {
                igrac_o.pozicija[1]++;
            }
        }
        print_screen();

    }
    if (usporenje >= ukupno_usporenje)
    {
        usporenje = 0;
    }
    if (igrac_x.pozicija[0] == igrac_o.pozicija[0] && igrac_x.pozicija[1] == igrac_o.pozicija[1])
    {
        gameover();
    }
    return res_normal;
}

int main (int argc, char *argv[])
{
    igrac_x.brzina = 0;
    igrac_x.energija = pocetna_energija;
    igrac_x.energija_kretanja = -5;
    igrac_x.oruzje = pistolj;
    igrac_x.poeni = 0;
    igrac_x.pozicija[0] = 0;
    igrac_x.pozicija[1] = 0;
    igrac_x.stanje = nista;
    igrac_x.pozicija_metka[0] = xmax + 1;
    igrac_x.pozicija_metka[1] = ymax + 1;
    igrac_x.stanje = 'X';

    igrac_o.brzina = 150;
    igrac_o.energija = 100;
    igrac_o.energija_kretanja = 0;
    igrac_o.oruzje = nijedno;
    igrac_o.poeni = 0;
    igrac_o.pozicija[0] = rand() % xmax + 1;
    igrac_o.pozicija[1] = rand() % ymax + 1;
    igrac_o.stanje = nista;
    igrac_o.stanje = 'O';

    srand(time(NULL));
    pos_reaktor[0] = rand() % xmax + 1;
    pos_reaktor[1] = rand() % ymax + 1;
    pos_medic[0] = rand() % xmax + 1;
    pos_medic[1] = rand() % ymax + 1;
    //pos_o[0] = rand() % xmax + 1;
    //pos_o[1] = rand() % ymax + 1;
    pthread_t threads;
    long t;
    pthread_create(&threads, NULL, Muzika, (void *)t);
    int stanje = 0;
    char c;
    print_screen();
    while(1)
    {
        c = tipka();
        if (c == 'w')
        {
            stanje = igrica(gore);
        }
        else if (c == 'a')
        {
            stanje = igrica(levo);
        }
        else if (c == 's')
        {
            stanje = igrica(dole);
        }
        else if (c == 'd')
        {
            stanje = igrica(desno);
        }
        else if (c == 'l')
        {
            igrac_x.pozicija_metka[0] = igrac_x.pozicija[0] + 1;
            igrac_x.pozicija_metka[1] = igrac_x.pozicija[1];
            stanje = igrica(pucanj_desno);
        }
        else if (c == 'j')
        {
            if (igrac_x.pozicija[0] > 0)
            {
                igrac_x.pozicija_metka[0] = igrac_x.pozicija[0] - 1;
                igrac_x.pozicija_metka[1] = igrac_x.pozicija[1];
                stanje = igrica(pucanj_levo);
            }
        }
        else if (c == 'i')
        {
            if (igrac_x.pozicija[0] > 0)
            {
                igrac_x.pozicija_metka[1] = igrac_x.pozicija[1] - 1;
                igrac_x.pozicija_metka[0] = igrac_x.pozicija[0];
                stanje = igrica(pucanj_gore);
            }
        }
        else if (c == 'k')
        {
            igrac_x.pozicija_metka[1] = igrac_x.pozicija[1] + 1;
            igrac_x.pozicija_metka[0] = igrac_x.pozicija[0];
            stanje = igrica(pucanj_dole);
        }
        else
        {
            stanje = igrica(nista);
            igrica(nista);
            c = 0;
        }
        if (c != 0)
        {
            if (stanje == res_normal)
            {
                Beep(1000, 20);
            }
            if (stanje == res_reaktor)
            {
                ludzvuk();
            }
            if (stanje == res_medic)
            {
                dobarzvuk();
            }
           igrac_x.poeni++;
        }
        if (igrac_x.energija <= 0)
        {
            break;
        }
    }
    gameover();
    pthread_exit(NULL);
}
