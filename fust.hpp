#ifndef FUST_HPP_INCLUDED
#define FUST_HPP_INCLUDED

#include <vector>

struct fust{
    int x;
    int y;
    int elettartam =0;
    fust(int _x, int _y): x(_x), y(_y){};
    int rajzol(){
        genv::gout << genv::color(155,155,155) << genv::move_to(x-elettartam/2, y-elettartam/2) << genv::box(elettartam,elettartam);
        elettartam++;
        return elettartam;
    }
};

#endif // FUST_HPP_INCLUDED
