#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int N,valori[1000000],v[1000000],I,c;

int main(){
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N;

    for(int i=0;i<N;i++)
        in>>valori[i];
    
    v[0]=1;
    I=1;
    while(v[I-1]<2){
        I=((I+valori[I-1])%N)+1;
        v[I-1]++;
        c++;
    }
    
    out<<N-c<<endl;
    for(int i=0;i<N;i++){
        if(v[i]==0)
            out<<i+1<<" ";
    }    
    in.close(); out.close();
    return 0;
}
