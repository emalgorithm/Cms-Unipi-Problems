#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define PP pair<int,int>
#define MAX 2000000000

using namespace std;

int solve(int N, int M, int T, int* S, int* E) {
    vector<int> canali[N];
	int distanze[2][N],i,tempoCorrente=0,tempoMin=MAX;
	queue<PP> q;
	
	for(i=0;i<2;i++)
		for(int j=0;j<N;j++)
			distanze[i][j]=-1;
	
	for(i=0;i<M;i++)
		canali[S[i]].push_back(E[i]);
	
	for(int j=0;j<2;j++){
		if(j==0){
			q.push(PP(0,0));
			distanze[j][0]=0;
        }
		if(j==1){
			q.push(PP(N-1,0));
			distanze[j][N-1]=0;
        }
        while(!q.empty()){
		    PP corrente=q.front();
			q.pop();
			tempoCorrente=corrente.second;
			for(i=0;i<canali[corrente.first].size();i++)
				if(distanze[j][canali[corrente.first][i]]==-1){
                    distanze[j][canali[corrente.first][i]]=corrente.second+1;
					q.push(PP(canali[corrente.first][i],corrente.second+1));
                }
		}
	}

	for(i=0;i<N;i++)
		if(distanze[0][i]>-1 && distanze[0][i]<=T && distanze[1][i]>-1)
			if(T+distanze[1][i]<tempoMin)
				tempoMin=T+distanze[1][i];
	
	if(distanze[0][N-1]>-1 && distanze[0][N-1]<=T && distanze[0][N-1]<tempoMin)
		tempoMin=distanze[0][N-1];	
    
    if(tempoMin==MAX)
        tempoMin=-1;
    
    return tempoMin;	
}


/*int main(){
    int N,M,T;
    cin>>N>>M>>T;
    int S[M],E[M];
    for(int i=0; i<M;i++)
        cin>>S[i]>>E[i];
    cout<<solve(N,M,T,S,E);
    system("PAUSE");
    return 0;
}*/
