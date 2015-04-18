#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

#define MAX_N 100005
#define INF 99999999

using namespace std;

int n, a[MAX_N];

int main(){
    freopen("input.txt","r",stdin);		    //L'idea generale è che se un numero è divisibile per 180, è divisibile anche per 10
    freopen("output.txt","w",stdout);		    //quindi finirà con uno 0, ed anche per 4, quindi la sua penultima cifra sarà pari
    ios_base::sync_with_stdio(false);		    //Il nostro numero deve essere divisibile anche per 3 e per 9 ma l'ordine delle cifre
    cin>>n;					    //non cambia questa proprietà
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i = 0; i < n; i++)			    //Trovo uno 0 e lo inserisco alla fine del numero
    	if(a[i] == 0){
    		swap(a[i], a[n-1]);
    		break;
    	}
    int minEven = INF, posMinEven = -1;		    //Qui trovo la più piccola cifra pari e la inserisco nella penultima posizione
    for(int i = 0; i < n - 1; i++)
    	if(a[i] % 2 == 0  &&  a[i] < minEven){
    		minEven = a[i];
    		posMinEven = i;
    	}
    swap(a[n-2], a[posMinEven]);

    sort(a, a + n - 2);			//Adesso che so che le ultime due cifre sono giuste, non mi resta che riordinare le restanti cifre
    reverse(a, a + n - 2);		//dalla piu grande alla più piccola usando sort e poi reverse.
    		
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
