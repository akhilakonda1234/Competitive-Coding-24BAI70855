#include <iostream>
#include <vector>
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
    vector<int> arr;

    while(head != NULL)
    {
        arr.push_back(head->data);
        head = head->next;
    }

    int left = 0;
    int right = arr.size() - 1;

    while(left < right)
    {
        if(arr[left] != arr[right])
            return false;

        left++;
        right--;
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

    Node* head = new Node(x);
    Node* temp = head;

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
