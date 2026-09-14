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
Node* oddEvenList(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
void display(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    if(n == 0)
    {
        cout << "List is Empty";
        return 0;
    }
    cout << "Enter node values: ";
    cin >> x;
    Node* head = new Node(x);
    Node* temp = head;

    for(int i = 1; i < n; i++)
    {
        cin >> x;
        temp->next = new Node(x);
        temp = temp->next;
    }

    cout << "Original List: ";
    display(head);

    head = oddEvenList(head);

    cout << "Odd Even List: ";
    display(head);

    return 0;
}
