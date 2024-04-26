#include <fstream>
#include <vector>
#include <sstream>
#include "Parcer.h"

using namespace std;

class DB;

struct item{
    int weight;
    int value;
    int num;
};

class DB:public Parcer{
protected:
    vector<int> knap;
    vector<item> it;
    int max_fit;
public:
    DB (ifstream &f_in);
    void write_file();
};
