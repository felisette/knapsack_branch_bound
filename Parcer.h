#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Parcer{
protected:
    vector <int> v;
    vector <int> w;
    int N;
    long max_w;
public:
    Parcer (ifstream &f_in);
};
