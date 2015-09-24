#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

#define PP pair<int,int>

using namespace std;

vector<PP> sol;
int N;

void ric(int n){
    if(n==3){
        sol.push_back(PP(2,7));
        sol.push_back(PP(6,2));
        sol.push_back(PP(4,6));
        sol.push_back(PP(7,4));
        return;
    }
    sol.push_back(PP(n,2*n+1));
    sol.push_back(PP(2*n-1,n));
    ric(n-1);

}


int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N;
    
    ric(N);
    
    if(N>3)
        sol.push_back(PP(2*N+1,7));
    
    out<<sol.size()<<" "<<N<<endl;
    
    for(int i=0;i<sol.size();i++)
        out<<sol[i].first<<" "<<sol[i].second<<endl;
   
    in.close(); out.close();
  
    return 0;
}

