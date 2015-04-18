#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    int K,N,i,a,prezzo[2000],valMax=0,j;
    ifstream in;
    in.open("input.txt");
    in>>K;in>>N;
    for(i=0;i<N;i++){
        in>>prezzo[i];
    }
    for(i=0;i<=K;i++){
        prezzo[N+i]=prezzo[N-1];
    }
       for(i=0;i<(N-1);i++){
           for(j=1;j<=K;j++) {
               a=prezzo[i]-prezzo[i+j];
                 if(a<=0){
                    a*=(-1);
                   if(a>valMax) {
                         valMax=a; }
                      }
                 }
            }
    in.close();
    ofstream out;
    out.open("output.txt");
    out<<valMax<<endl;
    out.close();
    return EXIT_SUCCESS;
}
