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
 
#define MAX_N 100005
 
#define N_CHAR 130
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
 
int n, k, num[MAX_N], sol;
 
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    in>>n>>k;
    for(int i=0;i<n;i++){
        int t; in>>t; num[t]++;
    }
    for(int i = 0;i <= MAX_N / k + 1;i++)
        if(i * k < MAX_N && num[i] && num[k*i]){
            num[i]++;
            num[k*i]++;
        }
    for(int i = 0;i <= MAX_N / k + 1;i++)
        if(i * k < MAX_N && num[i] && num[k*i]){
            if(num[i] < num[k*i])
                num[k*i] = 0;
            else
                num[i] = 0;
        }
    for(int i=0; i < MAX_N;i++)
        if(num[i])
            sol++;
    out<<sol; 
    
    in.close(); out.close();
    return 0;
}
//25 abcdbeababcdeebeedeedcacb
