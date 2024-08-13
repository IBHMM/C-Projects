#include <iostream> 
using namespace std;
int main () {
    int n = 13;
    int arr[n] = {0,0,0,0,0,0,0,0,0,0,0,0,7};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] == 0 && arr[j+1] != 0){
                arr[j] += arr[j+1];arr[j+1] = 0;
                }
            }
        }
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    return 0;
}