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

int n,h[1005],c[1005],s[1005],sum;

int find(int n){
    int m=sum;
    for(int i=n-1;i>=0;i--)
        if(h[i]>h[n] && s[i]<m)
            m=s[i];
    return m;
}

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>n;
    
    for(int i=0;i<n;i++){
        in>>h[i]>>c[i];
        sum+=c[i];
    }
    
    s[0]=sum-c[0];
    
    for(int i=1;i<n;i++)
        s[i]=find(i)-c[i];
    
    int sol=sum;
    
    for(int i=0;i<n;i++)
        if(s[i]<sol)
            sol=s[i];
    
    out<<sol;
           
    in.close(); out.close(); 
    return 0;
}


//8 6 6 8 5 7 3 3 7 4 6 2 2 5 9 1 1










