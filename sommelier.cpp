/* 
 * File:   main.cpp
 * Author: emaros
 *
 * Created on August 19, 2014, 12:09 PM
 */
#include <iostream>
#include <cstdlib>

using namespace std;
int v[10000], memo[10000];
int n, ris;

int din(int pos){
    if(pos == 0)
        return memo[0] = 1;
    if(pos == 1)
        return memo[1] = 1;
    if(memo[pos] != 0)
        return memo[pos];
    int sol=1;
    for(int i=2;i<=pos;i++)
        if(v[pos-i] <= v[pos])
            sol = max(sol, din(pos-i)+1);
    ris = max(ris, sol);
    return memo[pos] = sol;
}

int main() {
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=n-1;i>=0;i--)
        int t = din(i);
    cout<<ris;
    return 0;
}

//9 11 13 10 16 12 12 13 11 13
//12 11 13 11 10 11 12 16 12 12 11 10 14