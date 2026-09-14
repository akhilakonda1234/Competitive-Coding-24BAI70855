#include <iostream>
using namespace std;

int addDigits(int num)
{
    while(num >= 10)
    {
        int sum = 0;

        while(num > 0)
        {
            sum = sum + (num % 10);
            num = num / 10;
        }

        num = sum;
    }

    return num;
}

int main()
{
    int num;

    cout << "Enter number: ";
    cin >> num;

    cout << "Digital Root = " << addDigits(num) << endl;

    return 0;
}
