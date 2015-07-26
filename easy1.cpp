#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int N,max;
    in>>N;
    for(int i=0;i<N;i++){
        int temp;
        in>>temp;
        if(temp>max || i==0)
            max=temp;
    }
    out<<max;
    system("PAUSE");
    return EXIT_SUCCESS;
}
