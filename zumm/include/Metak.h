#ifndef METAK_H_INCLUDED
#define METAK_H_INCLUDED

#ifndef  METAK_H
#define  METAK_H
#include <main.h>


class Metak
{
    public:
         Metak();
         void kretanje();
         bool u_kretanju;
         int pozicija_x;
         int pozicija_y;
         int smer;
         int razorna_moc;
         void ispali (int x_igraca, int y_igraca, int komanda);
        virtual ~ Metak();

    protected:

    private:
};

#endif //  METAK_H


#endif // METAK_H_INCLUDED
