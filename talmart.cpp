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
#include <bitset>

#define MAX_N 20000005

#define N_CHAR 130

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int N,P,sol=1,diff=-1,t,t2;

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N>>P>>t; N--;
    
    while(N--){
        in>>t2;
        if(diff<0){
            if(t2<t){
                diff=1;
                sol++;
            }
        }
        else
            if(t2>t){
                diff=-1;
                sol++;
            }
        t=t2;
    }
    
    out<<sol;

    in.close(); out.close(); 
    return 0;
}

//10 100 26 43 52 76 85 79 48 41 31 59
//10 100 95 99 76 84 34 13 37 89 78 92




