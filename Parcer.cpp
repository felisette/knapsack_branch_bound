#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "Parcer.h"
 
using namespace std;
 
Parcer::Parcer (ifstream &f_in){
    string s;
    f_in>>s;
    int n1{stoi(s)};
    N=n1;
    f_in>>s;
    long n2{stoi(s)};
    max_w=n2;
    while (!f_in.eof ())
    {
      f_in >> s;
      double V{stod (s)};
      v.push_back(V);
      f_in >> s;
      double W{stod (s)};
      w.push_back(W);
    }
}
