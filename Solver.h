#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "DB.h"

using namespace std;

struct Node{
    int level, fit, bound;
    float weight;
    vector <int> knap;
};

class Solver: public DB{
public:
    Solver (ifstream &f_in);
    bool cmp(item a, item b);
    int bound(Node u);
    void solve();
};
