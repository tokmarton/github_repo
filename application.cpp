#include "application.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Application::Application( int _SX, int _SY, std::string _name ) : SX(_SX), SY(_SY), name(_name) {
    isExiting = false;
    focused =2;
}

void Application::addWidget( Widget *w ) {
    widgets.push_back( w );
}

void Application::run() {
    gout.open( SX, SY );
    gout.set_title( name );
    gin.timer(40);
    event ev;
    while( gin>>ev && !isExiting ) {

        if( ev.keycode == key_escape )
            isExiting = true;
        for( size_t i=0; i<widgets.size(); ++i )
            widgets[i]->set_focus( focused == (int)i );

        /// Eseménykezelés

        for( size_t i=0; i<widgets.size(); ++i )
            widgets[i]->handle( ev );

       /// Fókusz kezelése
        if( ev.keycode == key_space && widgets.size() > 0 )
            focused = ( focused + 1 ) % widgets.size();

             if(focused == 0) focused =2;
        /// Vizualizálás

        if(ev.type == ev_timer){
            gout << move_to(0, 0) << color(0,0,0) << box(SX, SY);
            for( size_t i=0; i<widgets.size(); ++i )
                widgets[i]->draw();
        }
        gout << refresh;

    }
}

void Application::shutdown() {
    isExiting = true;
}
