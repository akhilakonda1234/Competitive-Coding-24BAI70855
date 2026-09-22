#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int total = 1 << n;

    cout << "\nAll Subsets:\n";

    for(int mask = 0; mask < total; mask++)
    {
        cout << "{ ";

        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i))
            {
                cout << nums[i] << " ";
            }
        }

        cout << "}\n";
    }

    return 0;
}
