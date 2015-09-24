#include <cstdlib>
#include <utility>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

#define PP pair<int,int>

int passati[15], maxim = 1, counter=1,N;
PP pezzi[15];

int control(int estremo, int pos) {
    if (estremo == pezzi[pos].first)
        return pezzi[pos].second;
    if (estremo == pezzi[pos].second)
        return pezzi[pos].first;
    return -1;
}

void ric(int estremo) {
    for (int i = 0; i < N; i++) {
        if (passati[i] != 1)
            if (control(estremo, i) != -1) {
                counter++;
                maxim = max(counter, maxim);
                passati[i] = 1;
                ric(control(estremo, i));
                counter--;
                passati[i]=0;
            }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i;
    cin >> N;

    for(i=0;i<N;i++){
        cin>>pezzi[i].first;
        cin>>pezzi[i].second;
    }
    for(i=0;i<N;i++){
        passati[i]=1;
        ric(pezzi[i].first);
        ric(pezzi[i].second);
        passati[i]=0;
    }
    
    cout<<maxim;

    return 0;
}

