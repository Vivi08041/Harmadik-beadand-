#include "widget.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;

Widget::Widget() {}
Widget::Widget(int _x, int _y, int _sx, int _sy) : X(_x), Y(_y), sizeX(_sx), sizeY(_sy)
{
    infocus = false;
}

void Widget::rajzol() {}
bool Widget::selected(int mouseX,int mouseY) const
{
   return mouseX >= X && mouseX <= X+sizeX && mouseY >= Y && mouseY <= Y+sizeY;
}
void Widget::set_focus(bool focus)
{
    infocus = focus;
}
void Widget::handle(event ev) {}
