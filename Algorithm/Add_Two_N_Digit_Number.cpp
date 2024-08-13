#include <iostream>
#include <string>
using namespace std;

class Calculate {
    private:
        string value;

    public:
        Calculate(string value = "0") {
            this->value = value;
        }

        Calculate operator+(Calculate& obj1) {
            Calculate res;
            string num1 = this->value;
            string num2 = obj1.value;
            int len1 = this->value.length();
            int len2 = obj1.value.length();
            int maxLen = max(len1,len2);
            string result;

            while(num1.length() < maxLen){
                num1 = '0' + num1;
            }
            while(num2.length() < maxLen){
                num2 = '0' + num2;
            }
            while(result.length() < maxLen){
                result += '0';
            }

            int carry = 0;
            for(int i = maxLen-1; i >= 0; i--){
                int dig1 = num1[i] - '0';
                int dig2 = num2[i] - '0';
                int sum = (dig1 + dig2 + carry)%10;
                carry = (dig1 + dig2 + carry)/10;
                result[i] += sum;
            }
            if(carry){
                result = to_string(carry) + result;
            }
            res.value = result;

            return res;
        }

        void print() {
            cout << "Result: " << this->value << endl;
        }
};

int main() {

    string number1, number2;
    number1 = "99999999999999999999999";
    number2 = "135211111111111111111111116";

    Calculate obj1(number1), obj2(number2);
    Calculate obj3 = obj1 + obj2;

    obj3.print();
    return 0;
}
