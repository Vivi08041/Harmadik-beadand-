#ifndef ALKALMAZAS_HPP_INCLUDED
#define ALKALMAZAS_HPP_INCLUDED


#include "graphics.hpp"
#include "widget.hpp"
#include "button.hpp"
#include "text.hpp"

#include <vector>

using namespace std;
using namespace genv;

struct Jatekmester
{
protected:
    vector<Button*> gombok;
    vector<Text*> szoveg;
    bool gyozelem=false;
    int szamlalo=0;
    vector<vector<int>> app;
    int jatekos=1; /// x=1; o=2 jön

public:
    Jatekmester (vector<vector<int>> v);
    void matrix(int i, int j);
    bool megvizsgal (int _i, int _j);
    void ujra();
    void start();
};


#endif // ALKALMAZAS_HPP_INCLUDED
