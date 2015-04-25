#include <vector>
#include <string>
#include <string.h>
#include <functional>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <assert.h>
using namespace std;

typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;

#define MAX_N 1000005
#define INF 9999999
#define MAXN 1000000

static FILE *fr, *fw;

static int N;
static int C[MAXN];

int colors[MAX_N];
vi av;

void Vernicia(int indice, int colore);

void Diversifica(int N, int colore[]) {
    for(int i=0;i<N;i++)
        colors[colore[i]-1]++;
    for(int i=0;i<N;i++)
        if(colors[i] == 0)
            av.push_back(i+1);
    memset(colors,0,sizeof colors);
    for(int i=0;i<N;i++){
        if(colors[colore[i]-1] == 1){
            Vernicia(i,av.back());
            av.pop_back();
        }
        else
            colors[colore[i]-1]++;
    }
}

/*void Vernicia(int i,int j){ cout<<i<<" "<<j<<endl; };

int main() {
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));

    int i;
    for (i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &(C[i])));

    Diversifica(N, C);

    fclose(fr);
    fclose(fw);
    return 0;
}
*/
