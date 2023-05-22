#ifndef WIDGET_HPP
#define WIDGET_HPP


#include "graphics.hpp"

using namespace std;
using namespace genv;

class Widget
{
protected:
    int X;
    int Y;
    int sizeX;
    int sizeY;
    bool infocus;

public:
    Widget();
    Widget (int _x, int _y, int _sx, int _sy);

    void set_focus (bool focus);
    bool selected (int mouseX, int mouseY) const;
    bool focused () const
        {
        return infocus;
        }
    int posX() const
    {
        return X;
    }
    int posY() const
    {
        return Y;
    }
    int width() const
    {
        return sizeX;
    }
    int height() const
    {
        return sizeY;
    }

    virtual void rajzol();
    virtual void handle(genv:: event ev);
};


#endif // WIDGET_HPP
