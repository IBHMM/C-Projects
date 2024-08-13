#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double Pi = 22/7;

void print_number(double real, double imag) {
    if (real != 0 && imag != 0) {
        if (imag > 0) {
            cout << real << " + " << imag << "i" << endl;
        } else if (imag < 0) {
            cout << real << " - " << -imag << "i" << endl;
        } else {
            cout << real << endl;
        }
    } else if (real == 0 && imag != 0) {
        cout << imag << "i" << endl;
    } else {
        cout << real << endl;
    }
}
void print_operations() {
    cout << "1.  Add" << endl;
    cout << "2.  Subtraction" << endl;
    cout << "3.  Multiply" << endl;
    cout << "4.  Divition" << endl;
    cout << "5.  Find n root" << endl;
    cout << "6.  Conjuction" << endl;
    cout << "7.  Absolute Value" << endl;
    cout << "8.  Angle" << endl;
    cout << "9.  Trigonametric Form" << endl;
    cout << "10. Real" << endl;
    cout << "11. Imaginary" << endl;
}
double real_part(string number) {
    if (number.find("i") == -1) {
        return stod(number);
    } else {
        string r = "0";
        int i = (number[0] == '-') ? 1 : 0;
        while (number[i] != '-' && number[i] != '+') {
            r += number[i];
            i++;
        }
        if (number[0] == '-') {
            r = '-' + r;
        }
        return stod(r);
    }
}
double imag_part(string number) {
    if (number.find("i") == -1) {
        return 0;
    } else {
        int index = number.find('+');
        if (index == -1) {
            index = number.find('-');
        }
        string im = "";
        int i = index + 1;
        while (i < number.size() && number[i] != 'i') {
            im += number[i];
            i++;
        }
        if (index != -1 && number[index] == '-') {
            im = "-" + im;
        }
        return stod(im);
    }
}
void add(double r1, double r2, double i1, double i2) {
    double rr = r1 + r2;
    double ri = i1 + i2;

    print_number(rr, ri);
}
void subtract(double r1, double r2, double i1, double i2) {
    double rr = r1 - r2;
    double ri = i1 - i2;

    print_number(rr, ri);
}
void multiply(double r1, double r2, double i1, double i2) {
    double rr = r1 * r2 - i1 * i2;
    double ri = r1 * i2 + r2 * i1;

    print_number(rr, ri);
}
void divide(double r1, double r2, double i1, double i2) {
    if (r2 == 0 && i2 == 0) {
        cout << "Division by zero is not allowed." << endl;
        return;
    }

    double denominator = r2 * r2 + i2 * i2;
    double rr = (r1 * r2 + i1 * i2) / denominator;
    double ri = (r2 * i1 - r1 * i2) / denominator;

    print_number(rr, ri);
}
void absolute(double real, double imag) {
    cout << sqrt(real * real + imag * imag) << endl;
}
double angle(double imag, double real) {
    // Calculate the angle using the atan2 function
    double result = atan2(imag, real);

    // Convert the angle from radians to degrees
    result = result * 180 / M_PI;

    // Ensure the angle is in the range [0, 360)
    if (result < 0) {
        result += 360;
    }

    return result;
}
void real(double real){
    cout << real << endl;
}
void imag(double imag) {
    cout << imag << endl;
}
void conjuction(double real, double imag) {
    print_number(real, -imag);
}
void trigonametric(double real, double imag) {
    float m =  sqrt(real * real + imag * imag);
    float d =  angle(real,imag);
    cout << m << '(' << " Cos" << d <<  "\370" << " + " << " iSin" << d << "\370" << ')' << endl;
}
void root(double real, double imag, int n){
    double r = pow(sqrt(real * real + imag * imag),-n);
    for(int k = 0; k < n; k++ ) {
        float d =  (angle(real,imag) + 2*Pi*k)/n;
        cout << "Root " << k+1 << " :  " << r << '(' << " Cos" << d <<  "\370" << '+' << "iSin" << d << "\370" << " )" << endl;
    }
}
void base(string number1, string number2, string value) {
    double real1, real2, imag1, imag2;
    real1 = real_part(number1);
    imag1 = imag_part(number1);

    if (number2 != "unnecessary") {
        real2 = real_part(number2);
        imag2 = imag_part(number2);
    }

    int v = stoi(value);
    switch (v) {
        case 1:
            add(real1, real2, imag1, imag2);
            break;
        case 2:
            subtract(real1, real2, imag1, imag2);
            break;
        case 3:
            multiply(real1, real2, imag1, imag2);
            break;
        case 4:
            divide(real1, real2, imag1, imag2);
            break;
        case 5:
            int n;
            cout << "Number of roots: ";
            cin >> n;
            root(real1, imag1, n);
            break;
        case 6:
            conjuction(real1, imag1);
            break;
        case 7:
            absolute(real1, imag1);
            break;
        case 8:
            cout << angle(real1, imag1) << "\370" << endl;
            break;
        case 9:
            trigonametric(real1, imag1);
            break;
        case 10:
            real(real1);
            break;
        case 11:
            imag(imag1);
            break;
        default:
            cout << "Invalid operation" << endl;
            break;
    }
}
void Select(string value) {
    string number1, number2;
    if (value == "1" || value == "2" || value == "3" || value == "4") {
        cout << "Enter first number: ";
        cin >> number1;
        cout << "Enter second number: ";
        cin >> number2;
        base(number1, number2, value);
    } else {
        cout << "Enter number: ";
        cin >> number1;
        number2 = "unnecessary";
        base(number1, number2, value);
    }
}

int main() {

    string value;
    cout << "Select operation " << endl;
    print_operations();
    cout << "Input (type end if you're done): ";
    cin >> value;

    while (value != "end") {
        Select(value);
        cout << "Input (type end if you're done): ";
        cin >> value;
    }

    return 0;
}
