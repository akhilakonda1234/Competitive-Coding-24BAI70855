#include <iostream>
using namespace std;

int addDigits(int num)
{
    if(num == 0)
        return 0;

    return 1 + (num - 1) % 9;
}

int main()
{
    int num;

    cout << "Enter number: ";
    cin >> num;

    cout << "Digital Root = " << addDigits(num) << endl;

    return 0;
}
