#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
    queue<int> q1,q2;

public:
    void push(int x)
    {
        q2.push(x);

        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1,q2);
        cout<<"Element Pushed Successfully!"<<endl;
    }

    int pop()
    {
        if(q1.empty())
        {
            cout<<"Stack is Empty!"<<endl;
            return -1;
        }

        int x=q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        if(q1.empty())
        {
            cout<<"Stack is Empty!"<<endl;
            return -1;
        }

        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack s;
    int choice, x;

    do
    {
        cout << "\n===== Stack Using Two Queues =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Element: ";
                cin >> x;
                s.push(x);
                break;

            case 2:
                x = s.pop();
                if(x != -1)
                    cout << "Popped Element: " << x << endl;
                break;

            case 3:
                x = s.top();
                if(x != -1)
                    cout << "Top Element: " << x << endl;
                break;

            case 4:
                if(s.empty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is Not Empty" << endl;
                break;

            case 5:
                cout << "Program Ended" << endl;
                break;

            default:
                cout << "Invalid Choice! Please try again." << endl;
        }

    } while(choice != 5);

    return 0;
};
