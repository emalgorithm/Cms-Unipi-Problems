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
#include <math.h>
#include <string.h>

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
typedef vector<vi> vvi; 

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

#define INF 999999999
#define MAX_N 501000
#define MOD 1000000007

//FILE * in; FILE * out;
ifstream in; ofstream out;

int N, query;
deque<int> dq[1005];

int main() {
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d %d", &N, &query);
    int root = (int)sqrt(N);
    int j=-1;
    for(int i=0;i<N;i++){
        if((i+1) % (int)root == 1  || root == 1)
            j++;
        dq[j].push_back(i);
    }    
   
    
    int k = j;

    for(int i=0;i<query;i++){
        int firstQuery, secondQuery;
        char order;
        scanf(" %c %d", &order, &firstQuery);
        int currentRow = firstQuery / root;
        int currentColumn = firstQuery % root;
        
        if(order == 's'){
            scanf("%d", &secondQuery);
            int newRow = secondQuery / root;
            int newColumn = secondQuery % root;
            int shift = 0; bool cond = (newRow == currentRow);
            //cout<<currentRow<<" "<<newRow<<endl;
            deque<int> firstTempDeque, secondTempDeque;
            if(!cond){
                if(firstQuery < secondQuery){
                    int currentValue = dq[currentRow][currentColumn];
                    dq[currentRow].erase(dq[currentRow].begin()+currentColumn);
                    dq[newRow].insert(dq[newRow].begin()+newColumn+1, currentValue);
                    int temp = dq[newRow].front();
                    dq[newRow].pop_front();
                    
                    while(newRow-- > currentRow){
                        dq[newRow].push_back(temp);
                        if(newRow > currentRow){
                            temp = dq[newRow].front();
                            dq[newRow].pop_front();
                        }
                    }        
                
                /*
                  //Caso in cui devo spostare un'oggetto in una posizione piu grande della sua attuale
                    
                 * for(int j=0;j<currentColumn+1;j++){
                        firstTempDeque.push_back(dq[currentRow].front());
                        dq[currentRow].pop_front();
                    }

                    for(int j=0;j<newColumn+1;j++){
                        secondTempDeque.push_back(dq[newRow].front());
                        dq[newRow].pop_front();
                    }

                    dq[newRow].push_front(firstTempDeque.back());
                    firstTempDeque.pop_back();
                    while(secondTempDeque.size() > 1){
                        dq[newRow].push_front(secondTempDeque.back());
                        secondTempDeque.pop_back();
                    }

                    while(!firstTempDeque.empty()){
                        //cout<<f.back()<<endl;
                        dq[currentRow].push_front(firstTempDeque.back());
                        firstTempDeque.pop_back();
                    }
                    while(newRow-- > currentRow){
                        dq[newRow].push_back(secondTempDeque.back());
                        secondTempDeque.pop_back();
                        if(newRow > currentRow){
                            secondTempDeque.push_back(dq[newRow].front());
                            dq[newRow].pop_front();
                        }
                    }*/
                }
                

                if(firstQuery > secondQuery){
                    
                    int currentValue = dq[currentRow][currentColumn];
                    dq[currentRow].erase(dq[currentRow].begin()+currentColumn);
                    dq[newRow].insert(dq[newRow].begin()+newColumn, currentValue);
                    int temp = dq[newRow].back();
                    dq[newRow].pop_back();
                    while(newRow++ < currentRow){
                        dq[newRow].push_front(temp);
                        if(newRow < currentRow){
                            temp = dq[newRow].back();
                            dq[newRow].pop_back();
                        }
                    } 

                    /*for(int j=0;j<newColumn;j++){
                        firstTempDeque.push_back(dq[newRow].front());
                        dq[newRow].pop_front();
                    }
                    for(int j=0;j<currentColumn+1;j++){
                        secondTempDeque.push_back(dq[currentRow].front());
                        dq[currentRow].pop_front();
                    }
                    dq[newRow].push_front(secondTempDeque.back());
                    secondTempDeque.pop_back();
                    
                    while(!firstTempDeque.empty()){
                        dq[newRow].push_front(firstTempDeque.back());
                        firstTempDeque.pop_back();
                    }
                    firstTempDeque.push_back(dq[newRow].back());
                    dq[newRow].pop_back();
                    
                    while(!secondTempDeque.empty()){
                        //cout<<f.back()<<endl;
                        dq[currentRow].push_front(secondTempDeque.back());
                        secondTempDeque.pop_back();
                    }

                    while(newRow++ < currentRow){
                        dq[newRow].push_front(firstTempDeque.back());
                        firstTempDeque.pop_back();
                        if(newRow < currentRow){
                            firstTempDeque.push_back(dq[newRow].back());
                            dq[newRow].pop_back();
                        }
                    }*/
                }
            }
            
            
            if(cond){
                //shift = min(newColumn, currentColumn) + 1;
                if(firstQuery < secondQuery){  //Caso in cui devo spostare un'oggetto in una posizione piu grande della sua attuale
                    
                    int currentValue = dq[currentRow][currentColumn];
                    dq[currentRow].erase(dq[currentRow].begin()+currentColumn);
                    dq[newRow].insert(dq[newRow].begin()+newColumn, currentValue); 
                   
                    /*for(int j=0;j<currentColumn+1;j++){
                        firstTempDeque.push_back(dq[currentRow].front());
                        dq[currentRow].pop_front();
                    }

                    for(int j=0;j<newColumn+1-shift ;j++){
                        secondTempDeque.push_back(dq[newRow].front());
                        dq[newRow].pop_front();
                    }

                    dq[newRow].push_front(firstTempDeque.back());
                    firstTempDeque.pop_back();
                    while(secondTempDeque.size() > 0){
                        dq[newRow].push_front(secondTempDeque.back());
                        secondTempDeque.pop_back();
                    }

                    while(!firstTempDeque.empty()){
                        //cout<<f.back()<<endl;
                        dq[currentRow].push_front(firstTempDeque.back());
                        firstTempDeque.pop_back();
                    }
                    while(newRow-- > currentRow){
                        dq[newRow].push_back(secondTempDeque.back());
                        secondTempDeque.pop_back();
                        if(newRow > currentRow){
                            secondTempDeque.push_back(dq[newRow].front());
                            dq[newRow].pop_front();
                        }
                    }*/
                }
            
                if(firstQuery > secondQuery){
                    int currentValue = dq[currentRow][currentColumn];
                    dq[currentRow].erase(dq[currentRow].begin()+currentColumn);
                    dq[newRow].insert(dq[newRow].begin()+newColumn, currentValue);
                    
                    
                    
                    
                    

                    /*for(int j=0;j<newColumn+1;j++){
                        firstTempDeque.push_back(dq[newRow].front());
                        dq[newRow].pop_front();
                    }
                    for(int j=0;j<currentColumn+1-shift;j++){
                        secondTempDeque.push_back(dq[currentRow].front());
                        dq[currentRow].pop_front();
                    }

                    while(secondTempDeque.size() > 1){
                        //cout<<f.back()<<endl;
                        dq[currentRow].push_front(secondTempDeque.front());
                        secondTempDeque.pop_front();
                    }
                    dq[newRow].push_front(firstTempDeque.back());
                    firstTempDeque.pop_back();
                    
                    dq[newRow].push_front(secondTempDeque.back());
                    secondTempDeque.pop_back();
                    
                    while(!secondTempDeque.empty()){
                        //cout<<f.back()<<endl;
                        dq[currentRow].push_back(secondTempDeque.front());
                        secondTempDeque.pop_front();
                    }
                    
                    while(!firstTempDeque.empty()){
                        dq[newRow].push_front(firstTempDeque.back());
                        firstTempDeque.pop_back();
                    }

                    while(newRow++ < currentRow){
                        dq[newRow].push_front(firstTempDeque.back());
                        firstTempDeque.pop_back();
                        if(newRow < currentRow){
                            firstTempDeque.push_back(dq[newRow].back());
                            dq[newRow].pop_back();
                        }
                    }*/
                }
            }
        }
        if(order == 'c')
            printf("%d ", dq[currentRow][currentColumn]);
        /*for(int ind=0;ind<k+1;ind++){
                deque<int> myD;
                cout<<endl;
                 while(!dq[ind].empty()){
                     cout<<dq[ind].front()<<" ";
                     myD.push_back(dq[ind].front());
                     dq[ind].pop_front();
                 }
                while(!myD.empty()){
                    dq[ind].push_back(myD.front());
                    myD.pop_front();
                }
                
        }cout<<endl;  */
       
    }

    in.close(); out.close();
    //fclose(in); fclose(out);
    return 0;
}