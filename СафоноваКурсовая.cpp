#include <iostream>
using namespace std;

double Function(double x)
{
    return x * x + 2. * x;
}

typedef double(*Func)(double x);

double Solve(double Start, double End, Func f, double Step = 0.00001)
{
    double xMin = Start;
    double fMin = f(Start);
    while (Start < End)
    {
        if (f(Start) < fMin)
        {
            xMin = Start;
            fMin = f(Start);
        }
        Start += Step;
    }
    return xMin;
}
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    double Start = 0, End = 0;
    cout << "Введите начало и конец функции:" << "\n";
    cin >> Start >> End;
    double x = 0;
    x = Solve(Start, End, &Function);
    cout << "x = " << x << endl;
    system("pause");
    return 0;
}