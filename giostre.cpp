#include <cstdlib>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int A,B,vis[32000];

int visita(int diff){
    for(int i=0;i<A;i++)
        vis[i]=0;
    for(int i=0;;i+=diff){
        if(i>=A)
            i=i%A;
        vis[i]++;
        if(vis[i]>1)
            break;
    }
    for(int i=0;i<A;i++)
        if(vis[i]==0)
            return false;
    return true;
}

int visitaIniz(int diff){
    int sol=0;
    for(int i=0;;i+=diff){
        if(i>=A)
            i=i%A;
        vis[i]++;
        if(vis[i]>1)
            break;
        sol++;
    }
    return sol;
}
    
int main(){
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>A>>B;
    int i,diff=abs(A-B),sol;
    
    out<<visitaIniz(diff)<<" ";
    
    for(i=20;i<32000;i++)
        if(visita(abs(A-i))){
            sol=i;
            break;
        }
    out<<sol; 

    
    in.close(); out.close();
    return 0;
}
