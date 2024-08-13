#include <iostream>
#include <cmath>
using namespace std;


int main () {

    float a = 1.0;
    float b = 3000.001;
    float c = 3;
    float r1 =  (-2*c)/b+sqrt(b*b-4*a*c);
    float r2 =  (-2*c)/b-sqrt(b*b-4*a*c);

    cout << r1 << endl;
    cout << r2;

    return 0;
}


