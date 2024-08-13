#include <iostream>
#include <vector>

void leftShuffle(std::vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;

    std::vector<int> temp(arr.begin() + k, arr.end());
    temp.insert(temp.end(), arr.begin(), arr.begin() + k);

    arr = temp;
}

int main() {
    std::vector<int> arr = {1, 0, 3, 4, 5};
    int k = 2; // Number of positions to left shift

    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    leftShuffle(arr, k);

    std::cout << "\nShuffled Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
