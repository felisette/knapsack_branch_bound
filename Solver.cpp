#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Solver.h"

using namespace std;

Solver::Solver (ifstream &f_in): DB(f_in){
}

bool Solver::cmp(const item a, const item b){
    return (a.value/a.weight)>(b.value/b.weight);
}

int Solver::bound(Node u){
    if (u.weight>=max_w)
        return 0;
    int fit_bound=u.fit;
    int j=u.level+1;
    int a_w=u.weight;

    while ((j<N) && (a_w+it[j].weight<=max_w)){
        a_w=a_w+it[j].weight;
        fit_bound=fit_bound+it[j].value;
        j++;
    }
    if (j<N)
        fit_bound=fit_bound+(max_w-a_w)*it[j].value/it[j].weight;

    return fit_bound;
}
    
void Solver::solve(){
    sort(begin(it), end(it), [this](const item& a, const item& b) { return cmp(a, b); });
    vector<int> max_knap;
    
    queue<Node> Q;
    Node u, v;
    
    u.level=-1;
    u.fit=0;
    u.weight=0;
    Q.push(u);
    
    while (!Q.empty()) {
        u=Q.front();
        Q.pop();
        
        if (u.level!=N-1) {
            v.level=u.level+1;
            v.weight=u.weight+it[v.level].weight;
            v.fit=u.fit+it[v.level].value;
            v.knap=u.knap;
            v.knap.push_back(it[v.level].num);
            
            if ((v.weight<=max_w) && (v.fit>max_fit)){
                max_fit=v.fit;
                max_knap=v.knap;
            }
            v.bound=bound(v);
            
            if (v.bound>max_fit){
                Q.push(v);
            }

            v.weight=u.weight;
            v.fit=u.fit;
            v.knap=u.knap;
            v.bound=bound(v);
            if (v.bound>max_fit)
                Q.push(v);
        }
    }

    for (int i=0; i<max_knap.size(); i++)
        knap[max_knap[i]]=1;
    return;
}
