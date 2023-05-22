#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>
#include "button.hpp"

using namespace std;
using namespace genv;

Button:: Button (int x, int y, int sx, int sy, string _felirat, function<void()> _fv)
: Widget (x, y, sx, sy), fv(_fv), felirat(_felirat) {}

void Button::rajzol()
{
    gout << color(209,31,73) << move_to(X,Y) << box(sizeX,sizeY) << move_to(X+2,Y+2) << color(0,0,0) << box (sizeX-4,sizeY-4);


    if(felirat=="O")
        gout << color(0,0,255);

    else
        gout << color (0,255,0);

    gout << move_to(X+4,Y+(sizeY/2)+5) << text(felirat);
}

void Button :: ujfelirat (string s)
{
    felirat=s;
}

void Button:: handle (event ev)
{
    if(ev.button == btn_left && ev.pos_x >= X && ev.pos_x <= X+sizeX && ev.pos_y >= Y && ev.pos_y <= Y+sizeY)
        fv();

}
