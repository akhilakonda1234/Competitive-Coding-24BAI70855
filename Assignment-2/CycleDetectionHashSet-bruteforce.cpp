#include <iostream>
#include <unordered_set>
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
    unordered_set<Node*> visited;

    while(head != NULL)
    {
        if(visited.count(head))
            return true;

        visited.insert(head);
        head = head->next;
    }

    return false;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    
    head->next->next->next->next = head->next;

    if(hasCycle(head))
        cout<<"Cycle Found";
    else
        cout<<"No Cycle";

    return 0;
}
