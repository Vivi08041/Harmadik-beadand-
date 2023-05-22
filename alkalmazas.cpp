#include "alkalmazas.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include "button.hpp"
#include "text.hpp"

#include <iostream>
#include <vector>

using namespace std;
using namespace genv;

const int open_width=700;
const int open_height=600;

Jatekmester::Jatekmester(vector<vector<int>> v) : app(v)
{
    gout.open (open_width,open_height);
    gout.set_title("Amőba");


    for(unsigned int i=0; i<30; i++)
    {
        for(unsigned j=0; j<30; j++)
        {
            Button *buttons = new Button(j*18+10,i*18+10,20,20, " ", [=](){matrix (i,j);});
            gombok.push_back(buttons);
        }
    }

    Text *texts = new Text(550,50,120,30);
    szoveg.push_back(texts);

}

void Jatekmester::matrix(int i, int j)
{
    string nyertel="O won";
    if(app[i][j]==0 && !gyozelem)
    {
        szamlalo++;
        string kiir= "X's turn";
        app[i][j]=jatekos;

        gyozelem=megvizsgal(i,j);

        if(szamlalo==30*30)
        {
            nyertel= "Draw";
            gyozelem=true;
        }

        if(jatekos==1)
        {
            gombok[i*30+j]->ujfelirat("X");
            jatekos=2;
            kiir= "O's turn";
        }
        else
        {
            gombok[i*30+j]->ujfelirat("O");
            jatekos=1;
        }
        if(gyozelem)
        {
            if(jatekos==2)
            {
                nyertel= "X won";
            }
            szoveg[0]->ujfelirat(nyertel);
            Button *buttons = new Button (550,100,120,30,"New game", [&](){ujra();});
            gombok.push_back(buttons);
            return;
        }
        szoveg[0]->ujfelirat(kiir);
    }
}

void Jatekmester::ujra()
{
    for(unsigned int i=0; i<30; i++)
    {
        for(unsigned int j=0; j<30; j++)
        {
            app[i][j]=0;
        }
    }
    gyozelem=false;
    gombok.pop_back();

    for(unsigned int i=0; i<gombok.size();i++)
    {
        gombok[i]->ujfelirat(" ");
    }
}

bool Jatekmester::megvizsgal(int _i, int _j)
{

    bool temp1=false;
    bool temp2=false;
    int i=_i;
    int j=_j;
    int szamlalo=1;

    while(!temp1)
    {
        i++;

        if(app[i][j]==jatekos)
            szamlalo++;

        else
            temp1=true;

    }

    i=_i;

    while(!temp2)
    {
        i--;

        if(app[i][j]==jatekos)
            szamlalo++;

        else
            temp2=true;

    }

    if (szamlalo>4)
        return true;


    temp1=false;
    temp2=false;
    i=_i;
    j=_j;
    szamlalo=1;

    while(!temp1)
    {
        j++;

        if(app[i][j]==jatekos)
            szamlalo++;

        else
            temp1=true;

    }

    j=_j;

    while(!temp2)
    {
        j--;

        if(app[i][j]==jatekos)
            szamlalo++;

        else
            temp2=true;

    }

    if(szamlalo>4)
        return true;


    temp1=false;
    temp2=false;
    i=_i;
    j=_j;
    szamlalo=1;

    while(!temp1)
    {
        i--;
        j++;

        if(app[i][j]==jatekos)
            szamlalo++;

        else
            temp1=true;
    }

    i=_i;
    j=_j;

    while(!temp2)
    {
        i++;
        j--;

        if(app[i][j]==jatekos)
            szamlalo ++;

        else
            temp2=true;
    }

    if(szamlalo>4)
        return true;


    temp1=false;
    temp2=false;
    i=_i;
    j=_j;
    szamlalo=1;

    while(!temp1)
    {
        i++;
        j++;

        if(app[i][j]==jatekos)
            szamlalo++;

        else
            temp1=true;
    }

    i=_i;
    j=_j;

    while(!temp2)
    {
        i--;
        j--;

        if(app[i][j]==jatekos)
            szamlalo++;

        else
            temp2=true;
    }

    if(szamlalo>4)
        return true;

    return false;

}

void Jatekmester::start()
{
    event ev;
    gin.timer(30);

    while(gin>>ev && ev.keycode !=key_escape)
    {
        gout << move_to(0,0) << color(255,255,255) << box(open_width,open_height);

        for(unsigned int i=0; i<gombok.size(); i++)
        {
            gombok[i]->handle(ev);
            gombok[i]->rajzol();
        }

        szoveg[0]->rajzol();

        gout << refresh;
    }
}
