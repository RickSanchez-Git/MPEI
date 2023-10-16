#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
void calculateDefault(T a, T b) {
    cout << 1 / ( (1 / a) / ( 1 / b) ) << endl;
}

template<typename T>
void calculateShort(T a, T b) {
    cout << ( a * b ) /  ( a + b ) << endl;
}

void task1() {
    cout << "R1 = 0 | R2 = 0 | float | default" << endl;
    calculateDefault((float)0, (float)0);
    cout << "R1 = 0 | R2 = 0 | float | short" << endl;
    calculateShort((float)0, (float)0);

    cout << "R1 = 0 | R2 = 0 | double | default" << endl;
    calculateDefault((double)0, (double)0);
    cout << "R1 = 0 | R2 = 0 | double | short" << endl;
    calculateShort((double)0, (double)0);

    cout << endl << endl;

    cout << "R1 = 1 | R2 = -0 | float | default" << endl;
    calculateDefault((float)1, (float)-0);
    cout << "R1 = 1 | R2 = -0 | float | short" << endl;
    calculateShort((float)1, (float)-0);

    cout << "R1 = 1 | R2 = -0 | double | default" << endl;
    calculateDefault((double)1, (double)-0);
    cout << "R1 = 1 | R2 = -0 | double | short" << endl;
    calculateShort((double)1, (double)-0);

    cout << endl << endl;

    cout << "R1 = 0 | R2 = -0 | float | default" << endl;
    calculateDefault((float)0, (float)-0);
    cout << "R1 = 0 | R2 = -0 | float | short" << endl;
    calculateShort((float)0, (float)-0);

    cout << "R1 = 0 | R2 = -0 | double | default" << endl;
    calculateDefault((double)0, (double)-0);
    cout << "R1 = 0 | R2 = -0 | double | short" << endl;
    calculateShort((double)0, (double)-0);
}


float sum(float a, float b) {
    return a + b;
}

void task2() {
    float b = 1;
    float c = -1;
    float a;
    for (int i = 0; i < 30; i++) {
        a = pow(2, -i);
        float sum1 = sum(sum(a, b), c);
        float sum2 = sum(a, sum(b, c));
        if (sum1 != sum2) {
            cout << "k = " << i << endl;
        }
        cout << sum1 << "  =  " << sum2 << endl;
    }
}

int main()
{
    task1();
    task2();
}
