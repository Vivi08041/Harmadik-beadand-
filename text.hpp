#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>

using namespace std;
using namespace genv;

class Text: public Widget
{
protected:
    string tekszt;

public:
    Text (int x, int y, int sx, int sy);
    void rajzol();
    void ujfelirat(string s);
    void handle(genv :: event ev);
};

#endif // TEXT_HPP_INCLUDED
