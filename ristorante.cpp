#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int N,D,M,p[100005],s;

int main(){
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N>>D;
    
    for(int i=0;i<N;i++)
        in>>p[i];
    
    in>>M;
    sort(p,p+N);
    
    for(int i=0;i<M;i++){
        if(i<N)
            s+=p[i];
        else
            s-=D;
    }
    out<<s;

    in.close(); out.close();
    return 0;
}



