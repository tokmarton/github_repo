#include "tankos_jatekos.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace genv;
using namespace std;

tankos_jatekos::tankos_jatekos( int _x, int _y, int _size_x, int _size_y, int _SX, int _SY, std::vector<int>* _palya, tankos_jatekos** _tank, int _mx, int _my, int _size_mx, int _size_my, Felho* _f   ) : Widget( _x,  _y, _size_x, _size_y), SX(_SX), SY (_SY), palya(_palya), tank(_tank), mx(_mx), my(_my), size_mx(_size_mx), size_my(_size_my), f(_f){
 hp=10;
 srand(time(0));
 segitseg = false;
 retry = false;
 irany = rand()% 10 -5;
 cso_szog = atan(1.0)*-2;
 ero = 10;
 ox = 50;
 bx = 0;
};


void tankos_jatekos::draw(){
    y = (*palya)[x]- size_y;
    if (segitseg == false){
    if(hp>0){
    ///kijelölés
    if(inFocus){
        gout << move_to(x-3,y-3) << color(0,51,0) << box(size_x+6,size_y+6);
        gout << move_to(x-2,y-2) << color(0,102,0) << box(size_x+4,size_y+4);
        gout << move_to(x-1,y-1) << color(0,204,0) << box(size_x+2,size_y+2);
        gout << move_to(x-10, y-5) << color(153,0,0) << box(3,20);
        gout << color(255,0,0) << box(-3, -ero);
    }
    ///tank
    gout << move_to(x,y) << color(0,255,0) << box(size_x,size_y);
    gout << move_to(x + size_x/2, y+ size_y/2) << color(0,150,0) << line(cos(cso_szog)*20, sin(cso_szog)*20);
    gout << move_to (x-3, y-15 ) << color(204,0,0) << box_to(x+size_x+3, y-13);
    gout << move_to (x-3, y-15 ) << color(153,255,0) << box_to(x+((size_x+3)*hp)/100, y-13);
    gout << color(204,204,204);
    for(int k = -1; k < size_x+1; k++){
        for( int i=1; i<2*6; ++i ){
            for( int j=1; j<2*6; ++j ){
                if( x+k-6+i<SX && x+k-6+i>=0 && y+size_y-6+j<SY && y+size_y-6+j>=0 ){
                    gout << move_to(x+k-6+i,y+size_y-6+j);
                    if ( ((6-j)*(6-j)+(6-i)*(6-i)) <= 6*6 ) {
                        gout << dot;
                    }
                }
            }
        }
    }
    gout << color(153,153,153);
    for(int k = -1; k < size_x+1; k++){
        for( int i=1; i<2*4; ++i ){
            for( int j=1; j<2*4; ++j ){
                if( x+k-4+i<SX && x+k-4+i>=0 && y+size_y-4+j<SY && y+size_y-4+j>=0 ){
                    gout << move_to(x+k-4+i,y+size_y-4+j);
                    if ( ((4-j)*(4-j)+(4-i)*(4-i)) <= 4*4 ) {
                        gout << dot;
                    }
                }
            }
        }
    }
    for(int i = 0; i < fustok.size(); i++){
        if(fustok[i]-> rajzol()>=10){
            fustok[i] = fustok[fustok.size()-1];
            fustok.pop_back();
        }
    }
    for(int i = 0; i < lovedekek.size(); i++){
        if(lovedekek[i]->y >= (*palya)[lovedekek[i]->x]){
            for(int j = -10; j <=10; j++){
            (*palya)[lovedekek[i]->x +j] += sqrt(100 - j*j );

            }
            lovedekek[i]->x = SX+100;
        }
       if(lovedekek[i]->y >= SY-lovedekek[i]->vy || lovedekek[i]->x >= SX-lovedekek[i]->vx ||  lovedekek[i]->x <  abs(lovedekek[i]->vx)){
            lovedekek[i] = lovedekek[lovedekek.size()-1];
            lovedekek.pop_back();
        }
        else if(lovedekek[i]->mozog() == 1 && lovedekek[i]->y < SY-lovedekek[i]->vy && lovedekek[i]->x < SX-lovedekek[i]->vx && lovedekek[i]->y > abs(lovedekek[i]->vy) && lovedekek[i]->x > abs(lovedekek[i]->vx) ){
            fustok.push_back(new fust(lovedekek[i]->x, lovedekek[i]->y));
        }

    }

      if(inFocus){

    ///felhõk
       f->set_irany(irany);

    ///szél
    szel wind(irany);
    int a = wind.get_irany();
    genv::gout << genv::move_to(20,20) << genv::color(255,255,255) << genv::box(40,10);
        genv::gout << genv::move_to(21,21) << genv::color(0,0,0) << genv::box(18,8);
        genv::gout << genv::move_to(41,21) << genv::color(0,0,0) << genv::box(18,8);
        if (a < 0){
        genv::gout << genv::move_to(38,21) << genv::color(51,153,255) << genv::box((18/5)*a,8);
        }
        if (a > 0){
        genv::gout << genv::move_to(41,21) << genv::color(51,153,255) << genv::box((18/5)*a,8);
        }
      }

    }
    if(hp==0){
            gout << color(204,204,204);
            for(int k = -1; k < size_x+1; k++){
                for( int i=1; i<2*6; ++i ){
                    for( int j=1; j<2*6; ++j ){
                        if( x+k-6+i<SX && x+k-6+i>=0 && y+size_y-6+j<SY && y+size_y-6+j>=0 ){
                            gout << move_to(x+k-6+i,y+size_y-6+j);
                            if ( ((6-j)*(6-j)+(6-i)*(8-i)) <= 6*6 ) {
                                gout << dot;
                            }
                        }
                    }
                }
            }
            gout << color(153,153,153);
            for(int k = -1; k < size_x+1; k++){
                for( int i=1; i<2*4; ++i ){
                    for( int j=1; j<2*4; ++j ){
                        if( x+k-4+i<SX && x+k-4+i>=0 && y+size_y-4+j<SY && y+size_y-4+j>=0 ){
                            gout << move_to(x+k-4+i,y+size_y-4+j);
                            if ( ((4-j)*(4-j)+(4-i)*(4-i)) <= 4*4 ) {
                                gout << dot;
                            }
                        }
                    }
                }
            }
            for(unsigned int i=0;i<20;i++){
                t.push_back(new parts(x+size_x/2,y+size_y-5));
                cout << t.size() << endl;
                }
            for(unsigned int j=0;j<t.size();j++){
                        int error=t[j]->debrish();
                        if(error==0){
                            t[j]=t[t.size()-1];
                            t.pop_back();
                            j--;
                        }
                    }
        }
        if(retry == true){
         gout << move_to(150, 200) << color(255,255,255) << text("Szeretnél még egyet játszani? (Uj játék = Enter)");
         irany =0;
    }
    }
    if (segitseg == true){
        gout << color(0,0,0) <<move_to(0,0) << box(640,480);
        gout << move_to(30,30) << color(255,255,255) << text("Játékleirás \n \n A játékosok egy-egy tankot irányitanak. \n A tankok feletti zöld csik az életet, a mellettük megjelenö \n piros csik pedig a lövés erösségét jelzi. \n Az oldalra nyilakkal lehet a csö szögét állitani. A fel-le nyilakkal \n pedig a lövés erösségét. \n A space lenyomásával ad le lövést a tank. Utána rögtön a másik játékoson \n a sor. \n A szélirány és erösség minden lövés után változik, amit a  bal felsö \n sarokban lévö ikon jelez. A felhök is ennek megfelelöen mozognak. \n A pályát is szét lehet löni. \n Ha valamelyik tank élete elfogy, a másik játékos nyert. \n \n Jo szorakozást :)");
    }
}

void tankos_jatekos::handle(genv::event ev){

    if(ev.keycode== key_f12){
        segitseg = true;
        cout << "asd" << endl;
    }
    if(ev.keycode==-key_f12){
        segitseg = false;
    }

    if(hp ==0 ){
        retry = true;
    }
    if(hp != 0){
        retry = false;
    }
    if (retry== true){
        if(ev.keycode==key_enter){
            hp = 100;
            (*tank)->set_hp();
            irany = rand()% 10 -5;
        }
        if(ev.keycode== key_backspace){

        }


    }

    for(int i = 0; i < lovedekek.size(); i++){
        if(lovedekek[i]->x > mx && lovedekek[i]->x < mx + size_mx && lovedekek[i]->y < (*palya)[lovedekek[i]->x] && lovedekek[i]->y > (*palya)[lovedekek[i]->x] - size_my ){
            lovedekek[i] = lovedekek[lovedekek.size()-1];
            lovedekek.pop_back();
            (*tank)->talalat();
        }
    }

    if(inFocus){
    if (ev.keycode == key_up && ero < 20){
        ero++;

    }

    if (ev.keycode == key_down && ero >0){
        ero--;

    }

    if( ev.keycode == key_space){

        lovedekek.push_back(new lovedek(x + size_x/2+ cos(cso_szog)*20,y+ size_y/2 + sin(cso_szog)*20,(0.6+ero/10)*(cos(cso_szog)*20+ 2*irany),(0.6+ero/10)*(sin(cso_szog)*20), 0, 1.5));
        irany = rand()% 10 -5;

    }
    const double PI = atan(1.0)*4;
    if(ev.keycode == key_left && cso_szog > -PI){
        cso_szog -= PI/18.0;

    }else if(ev.keycode == key_right&& cso_szog < 0 ){
        cso_szog +=PI/18.0;
    }
}
}


void tankos_jatekos::talalat(){

    if (hp>0){
    hp -= 10;

    }


}

void tankos_jatekos::set_hp(){
    hp = 100;

}
