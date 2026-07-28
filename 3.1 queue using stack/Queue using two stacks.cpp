#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
    stack<int> s1,s2;

public:

    void push(int x)
    {
        s1.push(x);
        cout<<"Element Inserted Successfully!"<<endl;
    }

    int pop()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if(s2.empty())
        {
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }

        int x=s2.top();
        s2.pop();
        return x;
    }

    int front()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if(s2.empty())
        {
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }

        return s2.top();
    }

    bool empty()
    {
        return s1.empty()&&s2.empty();
    }
};

int main()
{
    MyQueue q;
    int choice, x;

    do
    {
        cout << "\n===== Queue Using Two Stacks =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Front" << endl;
        cout << "4. Empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Element: ";
                cin >> x;
                q.push(x);
                break;

            case 2:
                x = q.pop();
                if(x != -1)
                    cout << "Deleted Element: " << x << endl;
                break;

            case 3:
                x = q.front();
                if(x != -1)
                    cout << "Front Element: " << x << endl;
                break;

            case 4:
                if(q.empty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is Not Empty" << endl;
                break;

            case 5:
                cout << "Program Ended" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}
