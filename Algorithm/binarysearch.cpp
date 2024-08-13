#include <iostream>

using namespace std;

int main() {
    float arr[] = {3, 5, 3, 4, 8, 5, 6, 4, 3, 2, 4, 6};
    int n = 12;

    // Sorting using selection sort
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            float temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    bool flag = false;
    
    float element;
    cout << "Enter the element to search for: ";
    cin >> element;

    while (start <= end) {
        if (arr[mid] == element) {
            cout << "Element found at index: " << mid << endl;
            flag = true;
            break;
        } else if (element > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    } 

    if(!flag) {
        cout << "There is no " << element << " in list" << endl;
    }
    
    return 0;
}
