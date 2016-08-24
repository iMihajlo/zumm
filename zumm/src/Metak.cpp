#include "Metak.h"
#include "main.h"

Metak::Metak()
{
    razorna_moc = 10;
    pozicija_x = xmax + 1;
    pozicija_y = ymax + 1;
}
void Metak::kretanje()
{
    if (smer == pucanj_desno)
    {
        if (pozicija_x < xmax)
        {
            pozicija_x++;
        }
    }
    if (smer == pucanj_levo)
    {
        if (pozicija_x > 0)
        {
            pozicija_x--;
        }
    }
    if (smer == pucanj_gore)
    {
        if (pozicija_y > 0)
        {
            pozicija_y--;
        }
    }
    if (smer == pucanj_dole)
    {
        if (pozicija_y < ymax)
        {
            pozicija_y++;
        }
    }
}
void Metak::ispali(int x_igraca, int y_igraca, int komanda)
{
    pozicija_x = x_igraca;
    pozicija_y = y_igraca;
    smer = komanda;
}

Metak::~Metak()
{
    //dtor
}
