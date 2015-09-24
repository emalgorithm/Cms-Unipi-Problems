#include <cstdlib>
#include <iostream>
#include <fstream>

#define PP pair<int,int>

using namespace std;

int statoSucc[10000000],spost[10000000],din[10000000],nastro[1000000],N,nStati,valoriPoss;

bool DFS(int pos,int statoCorr){
    if(pos==0)
        return true;
    if(din[pos*nStati+statoCorr]!=0){
        if(din[pos*nStati+statoCorr]==1)
            return true;
        else
            return false;
    }
    din[pos*nStati+statoCorr]=2;
    
    if(DFS(pos+spost[nastro[pos]*nStati+statoCorr],statoSucc[nastro[pos]*nStati+statoCorr])){
        din[pos*nStati+statoCorr]=1;
        return true;
    }
    return false;
}
    

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    int i,j,count=0;
    
    in>>N>>nStati>>valoriPoss;
    
    for(i=0;i<nStati;i++)
        for(j=0;j<valoriPoss;j++){
            int statoCorr,valoreCorr;
            in>>statoCorr>>valoreCorr;
            in>>statoSucc[valoreCorr*nStati+statoCorr]>>spost[valoreCorr*nStati+statoCorr];
        }
            
    for(i=0;i<N;i++)
        in>>nastro[i];
    
    din[0]=1;    
    for(i=0;i<N;i++){
        /*for(int j=0;j<N*nStati+nStati;j++)
            if(din[j]==2)
                din[j]=0;*/
        if(DFS(i,0))
            count++;
    }
    out<<count<<endl;
    
    for(i=0;i<N;i++)
        if(din[i*nStati]==1)
         out<<i<<endl;

        
    return 0;
}

//5 2 3 0 0 1 -2 0 1 0 -2 0 2 0 1 1 0 1 -1 1 1 0 -1 1 2 0 2 0 2 1 0 1
