#include <iostream>

using namespace std;

int main () {

    int arr[10] = {4,6,2,6,98,4,12,4,7,8};

    for(int i = 1; i < 10; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = key;
    }

     for(int i = 0; i < 10; i++){
       cout << arr[i] << " ";
    }

    return 0;

}