#include <iostream>
#include <vector>
using namespace std;

//1 - crossed
//0 - uncrossed

int lower = 0, upper = 100;
vector<int> result;
int number[upper - lower][2];

void set_numbers() {
    for(int i = 0; i < upper - lower + 1; i ++){
        for(int i = 0)
        result.push_back([i + lower, 0]);
    }
}

int main () {

    set_numbers();


    for(int i = 0; i < upper - lower; i ++){
        cout << result[i][0] << ',' << result[i][1] << endl;
    }
}