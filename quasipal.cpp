#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#define ii pair<string,int>

using namespace std;

int M, N;
string a[15];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cin>>M>>N;
    for(int i=0;i<M;i++)
        cin>>a[i];
    do{
        bool isSeqPal = true;
        for(int i=0;i<N;i++)
            for(int j=0;j<M/2;j++)
                if(a[num[j]][i] != a[num[M-1-j]][i] && a[num[j]][i] != '0' && a[num[M-1-j]][i] != '0')
                    isSeqPal = false;
        if(isSeqPal){
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++)
                    cout<<a[num[i]][j];
                cout<<endl;
            }
            break;
        }

    }while(next_permutation(num, num + M));
     
    return 0;        
}

