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

int N,L;
char s[200005],p[]="***************";

int main(){
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    in>>N>>L;
    for(int i=0;i<L;i++)
        in>>s[i];

    for(int i=0,j=L-1;i<L/2,j>=L/2;i++,j--){
        if(s[i]<='9' && s[j]!=s[i]){
            if(p[(s[i]-'0')]!='*' && p[(s[i]-'0')]!=s[j]){
                out<<"impossibile";
                return 0;
            }
            p[(s[i]-'0')]=s[j];
        }
        if(s[j]<='9' && s[j]!=s[i]){
            if(p[(s[j]-'0')]!='*' && p[(s[j]-'0')]!=s[i]){
                out<<"impossibile";
                return 0;
            }
            p[(s[j]-'0')]=s[i];
        }
    }
    for(int i=0;i<N;i++)
        if(p[i]=='*'){
            out<<"impossibile";
            return 0;
        }
    for(int i=0;i<N;i++)
        out<<p[i];
    in.close(); out.close();
    
    return 0;
}



