#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include <vector>
#include "graphics.hpp"
#include <iostream>
#include "szel.hpp"

class palyarajz : public Widget{
    public:
        std::vector<int>* palya;
        palyarajz(std::vector<int>* _palya): Widget(0,0,0,0), palya(_palya){


        };
        void draw(){

            for(int i =0; i < (*palya).size()-1; i++){

                genv::gout << genv::move_to(i, (*palya)[i]) << genv::color(255,255,255) << genv::line_to(i+1,(*palya)[i+1] );
                genv::gout << genv::move_to(20,20) << genv::color(255,255,255) << genv::box(40,10);
                genv::gout << genv::move_to(21,21) << genv::color(0,0,0) << genv::box(18,8);
                genv::gout << genv::move_to(41,21) << genv::color(0,0,0) << genv::box(18,8);

            }

            gout << color(255,255,255) << move_to (250, 450) << text("Press F12 for Help");




        }

};

#endif // PALYA_HPP_INCLUDED
