#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> product;
int number;

bool is_prime(int n) {
    if (n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void prime() {
    for(int i = 2; i <= number; i++){
        if(is_prime(i)){
            while(number % i == 0){
                product.push_back(i);
                number /= i;
            }
        }
    }
}

int main () {
    cout << "Enter the number: ";
    cin >> number;
    int rnumber = number;
    prime();
    string result = to_string(rnumber) + " = ";

    for(int i = 0; i < product.size(); i++){ 
       result += to_string(product[i]) + " * ";
    }
    result.erase(result.length() - 3); 

    cout << result << endl;

    return 0;
}
