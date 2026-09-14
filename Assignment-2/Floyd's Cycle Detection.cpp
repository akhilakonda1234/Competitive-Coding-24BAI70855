#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

bool hasCycle(Node* head)
{
    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
            return true;
    }

    return false;
}

int main()
{
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);

    // Create cycle
    head->next->next->next->next=head->next;

    if(hasCycle(head))
        cout<<"Cycle Found";
    else
        cout<<"No Cycle";

    return 0;
}
