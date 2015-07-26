#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdlib>
 
using namespace std;
 
int panini[100000],soluzioni[100000];
 
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    int numeroPanini,max=0;
    in >> numeroPanini;
    for (int i=0;i<numeroPanini;i++)
        in >> panini[i];
    for (int i=numeroPanini-1;i>=0;i--){
        max=0;
        for (int j=numeroPanini-1;j>i;j--){
            if (panini[i] > panini[j] && soluzioni[j]>max)
                max=soluzioni[j]; 
        }
        soluzioni[i] = max + 1;
    }
    
    max=soluzioni[0];
    for (int i=1; i< numeroPanini;i++)
        if (soluzioni[i] > max)
            max = soluzioni[i];
    out << max;
    in.close(); out.close();
 
    return 0;
}
// 8 389 207 155 300 299 170 158 65
