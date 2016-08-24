#ifndef METAK_H_INCLUDED
#define METAK_H_INCLUDED

#ifndef  METAK_H
#define  METAK_H
#include <main.h>


class Metak
{
    public:
         Metak();
         kretanje();
         int pozicija_x;
         int pozicija_y;
         int razorna_moc;
         void ispali (int);
        virtual ~ Metak();

    protected:

    private:
};

#endif //  METAK_H


#endif // METAK_H_INCLUDED
