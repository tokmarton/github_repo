#ifndef TANKOS_JATEKOS_HPP_INCLUDED
#define TANKOS_JATEKOS_HPP_INCLUDED

#include <vector>
#include "widgets.hpp"
#include "lovedek.hpp"
#include "fust.hpp"
#include "szel.hpp"
#include "felho.hpp"
#include "blast.hpp"

class tankos_jatekos: public Widget{
public:
    std::vector<int> szin;
    int hp;
    float cso_szog;
    std::vector<lovedek*> lovedekek;
    std::vector<fust*> fustok;
    std::vector<int>* palya;
    vector<parts*> t;
    int SX, SY;
    int irany;
    float ero;
    int ox;
    int bx;
    int oy;
    tankos_jatekos** tank;
    Felho* f;
    int mx, my, size_mx, size_my;
    bool segitseg;
    bool retry;
    tankos_jatekos( int _x, int _y, int _size_x, int _size_y, int _SX, int _SY, std::vector<int>* _palya, tankos_jatekos** _tank, int _mx, int _my, int _size_mx, int _size_my, Felho* _f );
    void draw();
    void handle(genv::event ev);
    void talalat();
    void set_hp();
};

#endif // TANKOS_JATEKOS_HPP_INCLUDED
