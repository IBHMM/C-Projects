#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    vector<float> boxes = {1.0, 1.0, 1.0, 1.0, 1.0, 2.0};
    vector<float> items = {0.5, 0.6, 0.7, 0.2, 0.5, 1.0, 0.5, 0.6, 0.7, 0.2, 0.5, 1.0};
    vector<string> visual(boxes.size()); 

    for (int i = 0; i < items.size(); i++) {
        string name = " Item " + to_string(i + 1);
        bool fitted = false;
        for (int j = 0; j < boxes.size(); j++) {
            if (boxes[j] >= items[i]) {
                boxes[j] -= items[i];
                items[i] = 10000000;
                if (visual[j].empty()) {
                    visual[j] += name;
                } else {
                    visual[j] += "," + name;
                }
                fitted = true;
                break;
            }
        }
        if (!fitted) {
            cout << name << " with size " << items[i] << " cannot fit in any box." << endl;
        }
    }
    
    cout << endl;

    for (int j = 0; j < visual.size(); j++) {
        if (visual[j].empty()) {
            cout << "Box " << j + 1 << ":  empty" << endl << "free space : "  << boxes[j] << endl;
        } else {
            if(boxes[j] >= 1.0){
                cout << "Box " << j + 1 << ": " << visual[j] << endl << "free space : 1.0"  << endl;
            }else{
                cout << "Box " << j + 1 << ": " << visual[j] << endl << "free space : " << boxes[j]  << endl;
            }
        }
        cout << endl;
    }

    return 0;
}

1 n -1 n -1 n - 1 n - 1 