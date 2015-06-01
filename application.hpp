#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widgets.hpp"
#include <vector>

class Application {
    protected:
        std::vector<Widget*> widgets;
        int focused;
        bool isExiting;
        int SX, SY;
        std::string name;

    public:
        Application( int _SX, int _SY, std::string _name );
        void addWidget( Widget *w );
        void run();
        void shutdown();

        int width() const { return SX; }
        int height() const { return SY; }

};

#endif // APPLICATION_HPP
