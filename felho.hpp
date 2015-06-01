#ifndef FELHO_HPP_INCLUDED
#define FELHO_HPP_INCLUDED

#include "widgets.hpp"

class Felho: public Widget{
public:
    int ox;
    int bx, oy;
    Felho( int _ox);
    void draw();
    void set_irany(int irany);
};

#endif // FELHO_HPP_INCLUDED
