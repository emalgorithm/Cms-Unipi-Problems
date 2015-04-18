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

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int N,l=2;
vi s;

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N; 
    for(int i=0;i<N;i++){
        int t;
        in>>t;
        s.push_back(t);
    }
    
    for(int i=2;i<N;i++){
        if((s[i]-s[i-1])*(s[i-1]-s[i-2])<0)
            l++;
        else{
            s.erase(s.begin()+i-1);
            i--;
            N--;
        }
    }
    
    out<<l;
        
    in.close(); out.close(); 
    return 0;
}
//5 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5












