#include "graphics.hpp"
#include "felho.hpp"
#include <cmath>

using namespace std;
using namespace genv;

Felho::Felho( int _ox): Widget(0,0, 0,0), ox(_ox){}

void Felho::draw(){

     gout  << color(255,255,255);
        for(int l =0; l < 6; l++){
                bx =  100*l;
                oy = 100 + 15*pow(-1,l) *l;
                bx = (ox + bx)%640;

     for(int k =0; k < 7; k++){
                int eltolas = pow(-1,k);
        for( int i=1; i<2*10; ++i ){
                for( int j=1; j<2*10; ++j ){
                    if( bx+8*k-10+i<640 && bx+8*k-10+i>=0 && oy+8*eltolas-8+j<480 && oy+8*eltolas-10+j>=0 ){
                        gout << move_to(bx+8*k-10+i,oy+8*eltolas-10+j);
                        if ( ((10-j)*(10-j)+(10-i)*(10-i)) <= 10*10 ) {
                            gout << dot;
                        }
                    }
                }
            }
        }
        }
}

void Felho::set_irany(int irany){
    ox = ox + irany;
    if(ox<0) ox = 640;
}
