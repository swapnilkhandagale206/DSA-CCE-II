
#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() {
        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";

        cout << endl;
    }
};

int main() {
    Complex c1, c2, result;
    int r, i;

    cout << "Enter real and imaginary parts of first number: ";
    cin >> r >> i;
    c1 = Complex(r, i);

    cout << "Enter real and imaginary parts of second number: ";
    cin >> r >> i;
    c2 = Complex(r, i);

    result = c1 + c2;

    cout << "\nFirst Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Addition: ";
    result.display();

    return 0;
}
