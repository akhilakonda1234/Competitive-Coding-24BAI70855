#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        int n = q.size();
        while(n > 1)
        {
            q.push(q.front());
            q.pop();
            n--;
        }
        cout << "Element Pushed Successfully!" << endl;
    }

    int pop()
    {
        if(q.empty())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        if(q.empty())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack s;
    int choice,x;

    do{
        cout<<"\n1.Push\n2.Pop\n3.Top\n4.Empty\n5.Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter Element: ";
                cin>>x;
                s.push(x);
                break;

            case 2:
                x=s.pop();
                if(x!=-1)
                    cout<<"Popped Element: "<<x<<endl;
                break;

            case 3:
                x=s.top();
                if(x!=-1)
                    cout<<"Top Element: "<<x<<endl;
                break;

            case 4:
                cout<<(s.empty()?"Stack is Empty":"Stack is Not Empty")<<endl;
                break;

            case 5:
                cout<<"Program Ended"<<endl;
                break;
        }

    }while(choice!=5);

    return 0;
}
