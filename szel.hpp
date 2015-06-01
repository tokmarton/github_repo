#ifndef SZEL_HPP_INCLUDED
#define SZEL_HPP_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <iostream>

struct szel{
    int irany;

    szel (int _irany): irany(_irany){
    };
    void generate_irany(){
    srand(time(0));
    irany = rand()% 10 -5;
    }



    int get_irany(){

        return irany;
    }
};

#endif // SZEL_HPP_INCLUDED
