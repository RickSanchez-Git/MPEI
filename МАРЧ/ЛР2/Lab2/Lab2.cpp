#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Expression {
    int a, b, c;
    float x1, x2, D;

public:
    Expression(int _a, int _b, int _c) {
        a = _a, b = _b, c = _c;
        D = pow(b, 2) - 4 * a * c;
    }

    void calculate() {
        if (D < 0) {
            return;
        }
        x1 = (-b + pow(D, 0.5)) / (2 * a);
        x2 = (-b - pow(D, 0.5)) / (2 * a);
    }

    void getResult() {
        if (D < 0) {
            cout << "D less then zero" << endl;
            return;
        }
        cout << a << "|" << b << "|" << c << "| " << x1 << " | " << x2 << " | ";
        cout << a * pow(x1, 2) + b * x1 + c << " | " << a * pow(x2, 2) + b * x2 + c << endl;
        //string resultString = to_string(a) + "|" + to_string(b) + "|" + to_string(c) + "| " + to_string(x1) + " | " + to_string(x2) + " | ";
        //resultString += to_string(a * pow(x1, 2) + b * x1 + c) + " | ";
        //resultString += to_string(a * pow(x2, 2) + b * x2 + c);
    }
};


template<typename T>
T calculatePoints(vector<T>& vec1, vector<T>& vec2) {
    vector<T> resultVector;
    T result = 0;
    for (int i = 0; i < vec1.size(); i++) {
        resultVector.push_back(vec1[i] * vec2[i]);
    }
    for (auto& item : resultVector) {
        result += item;
    }
    return result;
}


void printTask1(int alpha, int beta) {
    //double
    vector<double> vec1 = {
        pow(10, alpha),
        1223,
        pow(10, alpha - 1),
        pow(10, alpha - 2),
        3,
        -pow(10, alpha - 5)
    };

    vector<double> vec2 = {
        pow(10, beta),
        2,
        -pow(10, beta + 1),
        pow(10, beta),
        2111,
        pow(10, beta + 3)
    };

    //float
    vector<float> vec3 = {
        (float)pow(10, alpha),
        1223,
        (float)pow(10, alpha - 1),
        (float)pow(10, alpha - 2),
        3,
        -(float)pow(10, alpha - 5)
    };

    vector<float> vec4 = {
        (float)pow(10, beta),
        2,
        -(float)pow(10, beta + 1),
        (float)pow(10, beta),
        2111,
        (float)pow(10, beta + 3)
    };

    cout << "Double: " << calculatePoints(vec1, vec2);
    cout << "   Float: " << calculatePoints(vec3, vec4) << endl;
}


void printTask2(int a, int b, int c) {
    Expression myExpr(a, b, c);
    myExpr.calculate();
    myExpr.getResult();
}

void printTask3() {
    int i = 0;
    float epsilon_f = 1.0;

    while (1.0f + epsilon_f > 1.0f)
    {
        epsilon_f = epsilon_f / 2.0f;
        i++;
    }

    int j = 0;
    double epsilon_d = 1.0;

    while (1.0 + epsilon_d > 1.0)
    {
        epsilon_d = epsilon_d / 2.0;
        j++;
    }
    cout << "Machine epsilon for float type: " << epsilon_f << "\nMachine epsilon for double type: " << epsilon_d << endl;
    cout << "The amount of iterations for float type:" << i << "\nThe amount of iterations for double type:" << j;
}

int main()
{
    cout << "Valid value = 8779.0" << endl;
    for (int i = 0; i < 25; i++) {
        cout << to_string(i) + "|" + to_string(i) + " ";
        printTask1(i, i);
    }
    for (int i = 1, j = 2000, k = -25; i < 20; i+=1, j+=1000, k+=1) {
        printTask2(i, j, k);
    }
    printTask3();
}
