#include "tankos_jatek.hpp"
#include "tankos_jatekos.hpp"
#include "fust.hpp"
#include "lovedek.hpp"
#include "szel.hpp"

#include <cmath>
#include "palya.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "graphics.hpp"


using namespace std;
using namespace genv;

tankos_jatek::tankos_jatek( int _SX, int _SY, std::string _name ): Application(_SX, _SY, _name){
    addWidget(new palyarajz(&palya));
    palya_generalas();
    f = new Felho(50);
    addWidget(f);
    t1 = new tankos_jatekos(200, 240, 25,15, SX, SY, &palya, &t2, 350, 240, 25,15,f);
    t2 = new tankos_jatekos(400, 240, 25,15, SX, SY, &palya, &t1, 300, 240, 25,15,f);
    addWidget(t1);
    addWidget(t2);
    //addWidget(new tankos_jatekos(300, 240, 25,15, SX, SY, &palya));
    szel_erosseg = rand() %10 -5;

};

void tankos_jatek::palya_generalas(){
    const double PI = atan(1.0)*4;
    double leptek =3*PI/(4*640);
    double kezdeti_ertek = PI/8;
    for(int i =0;  i < SX; i++){
    palya.push_back(SY + -200*sin(kezdeti_ertek+leptek*i));
    }



}




