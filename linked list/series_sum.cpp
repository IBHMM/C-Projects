#include <iostream>
#include <vector>

using namespace std;

int main () {

    vector<double> elements;

    double start = 0.0000001;
    double end = 1.0;
    double step = 0.0000001;
    double sum = 0;
    
    for(double i = start; i < end; i += step){
        elements.push_back(i);
    }

    for(double i = end; i > start; i -= step){
        sum += elements[i];
    }

    std::cout << sum ;
}
