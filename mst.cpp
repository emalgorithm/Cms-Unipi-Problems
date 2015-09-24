#include <utility>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

#define MAX_N (int)1e6+5

using namespace std;

typedef pair< long long, long long > ii;

long long p[MAX_N], ranking[MAX_N];

int findSet(int i){
	return (p[i] == i ? i : p[i] = findSet(p[i]));
}

void unionSet(int i, int j){
	int x = findSet(i), y = findSet(j);
	if(x != y){
		if(ranking[x] > ranking[y])
			p[y] = x;
		else{
			p[x] = y;
			if(ranking[x] == ranking[y])
				ranking[y]++;
		}
	}
}


pair< long long, ii > edge[10000005];
long long mstCost, N, M,c;
ii sol[10000005];
int solN;

int main(){
    ios::sync_with_stdio(false);
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
	//scanf("%d %d",&N,&M);
	in>>N>>M;
	for(int i=0;i<N;i++)
		p[i] = i;
	for(int i=0;i<M;i++){
		pair< int, ii > t;
		//scanf("%d %d %d",&t.second.first,&t.second.second,&t.first);
		int v1,v2,d;
		in>>v1>>v2>>d;
		edge[i].second.first=v1-1; edge[i].second.second=v2-1; edge[i].first=d;
	}

	sort(edge, edge + M);
	for(int i=0;i<M;i++){
		long long v1 = edge[i].second.first;
		long long v2 = edge[i].second.second;
		long long cost = edge[i].first;
		if(findSet(v1) != findSet(v2)){
			unionSet(v1,v2);
			mstCost += cost;
			sol[solN+1].first=v1;
			sol[solN++].second = v2;
			if(c == N - 1)
                break;
		}
	}
    //printf("%d",mstCost);
    out<<mstCost<<endl;
    for(int i=0;i<solN;i++)
        out<<sol[i].first+1<<" "<<sol[i].second+1<<endl;
    return 0;
}
