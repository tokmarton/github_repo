#ifndef TANKOS_JATEK_HPP_INCLUDED
#define TANKOS_JATEK_HPP_INCLUDED

#include "tankos_jatekos.hpp"
#include "application.hpp"
#include <vector>

class tankos_jatek: public Application{
protected:
    std::vector<int> palya;
    std::vector<tankos_jatekos> jatekosok;
    int szel_erosseg;
    tankos_jatekos* t1;
    tankos_jatekos* t2;
    Felho* f;
public:
    tankos_jatek( int _SX, int _SY, std::string _name );
    void palya_generalas();
};

#endif // TANKOS_JATEK_HPP_INCLUDED
