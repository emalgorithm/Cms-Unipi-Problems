#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int d, s, sol, used[100];

pair<int, int> p[100];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>d>>s;

    for(int i=0;i<s;i++)
        cin>>p[i].second>>p[i].first;
    
    sort(p, p + s);
    reverse(p, p + s);

    int currDay = 0;
    while(currDay <= d - 1){
        for(int i=0;i<s;i++)
            if(!used[i] && p[i].second <= currDay){
                used[i] = 1;
                currDay = p[i].first + 1;
                sol++;
                break;
            }
    }
    cout<<sol;

    return 0;
}
