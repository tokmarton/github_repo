#ifndef LOVEDEK_HPP_INCLUDED
#define LOVEDEK_HPP_INCLUDED

#include "graphics.hpp"

struct lovedek{
    float x;
    float y;
    float vx;
    float vy;
    float ay;
    float ax;
    int time =0;
    lovedek(float _x, float _y,float _vx, float _vy, float _ax, float _ay) : x(_x), y(_y), vx(_vx), vy(_vy), ax(_ax), ay(_ay){};
    int mozog (){

        for(int i = 0; i < 10; i++){
        if(y>0){genv::gout << genv::color(255,0,0) << genv::move_to(x-1, y-1) << genv::box(3,3);}
        x += vx/10;
        y += vy/10;
        vx += ax/10;
        vy += ay/10;
        }


        if(time > 1){

            time = 0;
        }else{
        time++;
        }
        //a gyorsulo mozgas fizikaja
        return time;
    }
};


#endif // LOVEDEK_HPP_INCLUDED
