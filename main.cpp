#include "alkalmazas.hpp"
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> app(30,vector<int>(30));
    Jatekmester mester(app);
    mester.start();


    return 0;
}
