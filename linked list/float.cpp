#include <iostream>
#include <cmath>
using namespace std;


int main () {

    float a1 = 0.0001;
    double a2 = 0.00001;
    float sum = 0;
    double sum2 = 0;
    for(int i = 0; i < 10000; i ++){
        sum += a1;
        sum2 += a2;
    }
    cout << "a1: " << sum << endl;
    cout << "a2: " << sum2 << endl;

    return 0;
}


