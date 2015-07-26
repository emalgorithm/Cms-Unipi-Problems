#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    int N,M,i,c,q,max,a[30];
    ifstream in;
    in.open("input.txt");
    in>>N;in>>M;
    for(i=1;i<=N;i++) {
                     in>>a[i]; }
    max=a[1];
    for(i=1;i<=M;i++) {
                     in>>c;in>>q;
                     if(q==max) {
                                max=c;} }
    in.close();
    ofstream out;
    out.open("output.txt");
    out<<max<<endl;
    out.close();
    return EXIT_SUCCESS;
}
