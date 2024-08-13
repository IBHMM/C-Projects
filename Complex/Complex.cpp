#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;
const double Pi = 3.14159265359;

double nthRoot(int number, int power)
{
    double xPre = rand() % 10;
    double eps = 0.0001;
    double delX = INT_MAX;
    double xK;
    while (delX > eps)
    {
        xK = ((power - 1.0) * xPre +
        (double)number/pow(xPre, power-1)) / (double)power;
        delX = abs(xK - xPre);
        xPre = xK;
    }
 
    return xK;
}

class Calculate {
private:
    float real;
    float imag;
    string real_s;
    string imag_s;
    float degre = this->degree();
    float module = this->find_module();
public:

    Calculate(string expression = "0") {
        this->real = this->real_part(expression);
        this->imag = this->imagine_part(expression);
    }

    float real_part(string expression) {
        if(expression == "0"){
            return 0;
        }
        else if((expression.find('i') < expression.find('+')) || (expression.find('i') < expression.find('-'))){
            int start = expression.find('+') || expression.find('-');
            string real = "0";
            for(int i = start+2; i < expression.length(); i++){
                real += expression[i];
            }
            cout << real << endl;
            this->real = stof(real);
            return stod(real);
        }
        else{
            int i = 0;
            bool negative = false;
            string real = "0";

            for (int i = 0; i < expression.length(); i++) {
                if (i == 0 && expression[i] == '-') {
                    negative = true;
                } else if (expression[i] != '-' && expression[i] != '+') {
                    real = real + expression[i];
                } else if (i > 0 && (expression[i] == '-' || expression[i] == '+')) {
                    break;
                }
            }
            real.erase(0, 1);

            if (negative) {
                this->real_s = '-' + real;
                return -stof(real);
            } else {
                this->real_s = real;
                return stof(real);
            }
        }
    }

    float imagine_part(string expression) {
        if(expression == "0"){
            return 0;
        }
        else{
            string imag = "0";
            bool negative = false;
            size_t i_pos = expression.find('i');
            if (i_pos != string::npos) {
                for (int i = i_pos - 1; i >= 0; i--) {
                    if (expression[i] != '-' && expression[i] != '+') {
                        imag = expression[i] + imag;
                    } else if (expression[i] == '-') {
                        negative = true;
                        break;
                    } else if (expression[i] == '+') {
                        break;
                    }
                }
        }
            if (imag.empty()) {
                imag = "0";
            } else {
                imag.erase(imag.length() - 1);
            }

            if (negative) {
                this->imag_s = '-' + imag;
                return -stof(imag);
            } else {
                this->imag_s = imag;
                return stof(imag);
            }
        }
    }

    void show_imagine_part() {
        cout << "Imagine Part: " << this->imag << endl;
    }

    void show_real_part() {
        cout << "Real Part: " << this->real << endl;
    }

    float find_module() {
        return sqrt(pow(this->real,2) + pow(this->imag,2));
    }

    void trigonometric_form() {
        int r = this->find_module();
        float degree = this->degree();
        cout << r << "(cos" << degree << "\370" << " + i" << " sin" << degree << "\370" << ")" << endl;
    }

    float degree() {
        float degree = 0;
        //1
        if(this->real > 0 && this->imag > 0){
            degree = roundl(atan((this->real/this->imag))*57);
        }
        //2
        if(this->real < 0 && this->imag > 0){
            degree = 90 - roundl(atan((this->real/this->imag))*57);
        }
        //3
        if(this->real < 0 && this->imag < 0){
            degree = 180 + roundl(atan((this->real/this->imag))*57);
        }
        //4
        if(this->real > 0 && this->imag < 0){
            degree = 360 + roundl(atan((this->real/this->imag))*57);
        }
        return degree;
    }

    void conjuction() {
        this->real = this->real;
        this->imag = -this->imag;
        this->show();
    }

    void root(int n) {
        float r = nthRoot(this->module,n);
        float deg = this->degre;

        for(int i = 0; i < n; i++){
            float r_deg = (deg + 2*Pi*i)/n;
            cout << r << "(cos " << r_deg << "\370"  << " + "<<  "isin " << r_deg << "\370" <<")" << endl;
        }
    }

    void plot() {
        string pythonScript = "plot.py";
        string command = "python " + pythonScript + " " + to_string(this->real) + " " + to_string(this->imag);
        
        int result = system(command.c_str());
    }

    pair<double,double> getXY() const{
        return make_pair(this->real,this->imag);
    }

    Calculate operator+(Calculate& obj) {
        Calculate res;
        res.imag = this->imag + obj.imag;
        res.real = this->real + obj.real;
        return res;
    }

    Calculate operator-(Calculate& obj) {
        Calculate res;
        res.imag = this->imag - obj.imag;
        res.real = this->real - obj.real;
        return res;
    }

    Calculate operator*(Calculate& obj) {
        Calculate res;
        res.imag = (this->real * obj.imag) + (this->imag * obj.real);
        res.real = (this->real * obj.real) - (this->imag * obj.imag);
        return res;
    }

    Calculate operator/(Calculate& obj) {
        Calculate res;
        if (this->real == obj.real && this->imag == obj.imag) {
            res.real = 1;
            res.imag = 0;
        } else{
            float denom = (obj.real*obj.real) + (obj.imag*obj.imag);
            res.real = ((this->real*obj.real) - (this->imag*obj.imag))/denom;
            res.imag = ((this->real*obj.imag) + (this->imag*obj.real))/denom; 
            }
            return res;
        }
    
    void show() {
            if(this->imag > 0 && this->imag != 1){
            cout << "Result : " << this->real << "+" << this->imag << "i" << endl;
            }
            else if(this->imag < 0){
            cout << "Result : " << this->real << this->imag << "i" << endl;
            }
            else if(this->imag == 1){
            cout << "Result : " << this->real << "+" << "i" << endl;
            }
            else if(this->imag == 0){
                cout << "Result : " << this->real << endl;
            }
        }

};

int main () {

    Calculate obj1("4.532+5.234i"), obj2("5+6i");

    Calculate obj3 = obj1 + obj2;

    obj3.show();

    return 0;
}