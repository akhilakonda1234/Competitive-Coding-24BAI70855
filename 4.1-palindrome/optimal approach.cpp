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

bool isPalindrome(Node* head)
{
    if(head == NULL || head->next == NULL)
        return true;

    Node *slow = head, *fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *prev = NULL;
    Node *curr = slow->next;

    while(curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    Node *first = head;
    Node *second = prev;

    while(second != NULL)
    {
        if(first->data != second->data)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0)
    {
        cout << "List is Empty";
        return 0;
    }

    cout << "Enter node values: ";

    int x;
    cin >> x;

    Node *head = new Node(x);
    Node *temp = head;

    for(int i = 1; i < n; i++)
    {
        cin >> x;
        temp->next = new Node(x);
        temp = temp->next;
    }

    if(isPalindrome(head))
        cout << "Output: True";
    else
        cout << "Output: False";

    return 0;
}
