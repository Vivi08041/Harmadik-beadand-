#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"
#include <functional>

using namespace std;
using namespace genv;

class Button : public Widget
{
protected:
    function<void()> fv;
    string felirat;

public:
    Button(int x, int y, int sx, int sy, string _felirat, function<void()> _fv);
    void rajzol();
    void handle(genv:: event ev);
    void ujfelirat(string s);
};

#endif // BUTTON_HPP_INCLUDED
