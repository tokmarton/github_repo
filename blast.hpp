#ifndef BALST_HPP
#define BLAST_HPP
#include <vector>
#include <iostream>
#include <cmath>
#include <time.h>
#include <cmath>

using namespace genv;
using namespace std;

struct parts{
private:
    float x;
    float y;

    float f_x;
    float f_y;

    int elet;

public:
    parts(int defx, int defy){
        set_default(defx,defy);

    }
    void set_default(int defx,int defy){
        x=defx;
        y=defy;

        f_x=float(rand()%21-10)/10;
        f_y=float(rand()%10-10)/10;

        elet=50;
    }

    int debrish(){
        //f_y+=g;

        x+=f_x;
        y+=f_y;

        gout << move_to(x,y) << color(rand()% 255,rand()% 255,rand()% 255) << box(2,2);
        elet--;
        return elet;
    }


};

#endif // BALST_HPP
