#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int v) {
        val = v;
    }
};

Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;

    Node* clone = new Node(node->val);

    for (Node* nbr : node->neighbors) {
        clone->neighbors.push_back(cloneGraph(nbr));
    }

    return clone;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n3);

    Node* cloned = cloneGraph(n1);

    cout << "Cloned Graph: ";
    cout << cloned->val << " ";
    cout << cloned->neighbors[0]->val << " ";
    cout << cloned->neighbors[0]->neighbors[0]->val;

    return 0;
}
