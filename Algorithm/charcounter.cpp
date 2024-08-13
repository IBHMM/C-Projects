#include <iostream>
#include <string>
using namespace std;

int main () {
    string exp = "efkjqewgfiuwegfxnugxxwmveqw8ogfmxeugfxqu";
    while(exp.length()){
    char current_char = exp[0];
        for(int i = 0; i < exp.length(); i++){
            if(current_char == exp[i]){
                cout <<exp[i];
                exp.erase(i,1);
                if(current_char == exp[i]){
                    i--;
                }
            }
        }
        cout << endl;
    }
    return 0;
}