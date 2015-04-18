#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>

#define PP pair <int,int>
using namespace std;

int main() {
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    vector<PP> altitudini;
    int N, altitudine = 5000, i, j;
    altitudini.push_back(PP(1, altitudine));
    in >> N;
    for (i = 0; i < N; i++) {
        int temp, cont = 0;
        in >> temp;
        altitudine += temp;
        for (j = 0; j < altitudini.size(); j++) {
            if (altitudini[j].second == altitudine) {
                altitudini[j].first++;
                cont = 1;
            }
        }
        if (cont == 0)
            altitudini.push_back(PP(1, altitudine));
    }

    sort(altitudini.begin(), altitudini.end(), greater <PP>());
    out << altitudini[0].second;
    in.close();
    out.close();
    return EXIT_SUCCESS;
}
