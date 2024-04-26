#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DB.h"

using namespace std;

DB::DB (ifstream &f_in): Parcer(f_in){
    max_fit=0;
    for (int i=0; i<N; i++)
        knap.push_back(0);
    for (int i=0; i<N; i++){
        item a;
        a.weight=w[i];
        a.value=v[i];
        a.num=i;
        it.push_back(a);
    }
}

void DB::write_file(){
    ofstream out;
    out.open("answer.txt");
    if (out.is_open()){
        out<<max_fit<<" ";
        int w_a=0;
        for (int i=0; i<N; i++){
           w_a=w_a+w[i]*knap[i];
        }
        out<<max_w-w_a<<"\n";
        for (int i=0; i<N; i++){
            out<<knap[i]<<" ";
        }
    }
    out.close();
}
