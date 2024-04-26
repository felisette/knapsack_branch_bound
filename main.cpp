#include <iostream>
#include "Solver.h"
#include <locale.h>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream f_in;
    f_in.open("tsp.txt");
    Solver New_Report(f_in);
    New_Report.solve();
    New_Report.write_file();
    return 0;
}
