#include "graphics.hpp"
#include "widget.hpp"
#include "text.hpp"
#include "fstream"

using namespace std;
using namespace genv;

Text::Text(int x, int y, int sx, int sy) : Widget (x, y, sx, sy) {}

void Text::rajzol()
{
    gout << color (40,40,40) << move_to (X,Y) << box (sizeX,sizeY) << move_to (X+2,Y+2)
         << color (255,255,128) << box (sizeX-4, sizeY-4);

    for(unsigned int i=0; i<tekszt.size(); i++)
    {
        if((i*gout.twidth("A")+2) < sizeX)
            gout << color(0,0,0) << move_to(X+i*gout.twidth("A")+10,Y+sizeY-10) << text(tekszt[i]);
    }
}

void Text::ujfelirat(string s)
{
    tekszt=s;
}

void Text::handle(event ev ){}
