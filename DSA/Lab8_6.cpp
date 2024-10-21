
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d) : data(d)
    {
        left = nullptr;
        right = nullptr;
    }
    friend class BST;
};

class BST
{
    node *head;

    node *insertion(node *head, int data)
    {
        if (head == nullptr)
        {
            return new node(data);
        }
        if (head->data == data)
        {
            return head;
        }
        if (data < head->data)
        {
            head->left = insertion(head->left, data);
        }
        else
        {
            head->right = insertion(head->right, data);
        }
        return head;
    }

public:
    BST() : head(nullptr) {}
    BST(node *n) : head(n) {}

    void insert(int data)
    {
        head = insertion(head, data);
    }

    node* getHead() {
        return head;
    }
};

node* swap(node* root, int& val1, int& val2) {
    if (root == nullptr) return nullptr;
  
    if (root->data == val1) {
        root->data = val2;
    } else if (root->data == val2) {
        root->data = val1;
    }
  
    swap(root->left, val1, val2);
    swap(root->right, val1, val2);

    return root;
}

void InOrderTraversal(node *root)
{
    if (root == nullptr)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

int main()
{
    BST tree;

    // Inserting nodes into the BST
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "In-order before swapping: ";
    InOrderTraversal(tree.getHead());
    cout << endl;

    int val1 = 7, val2 = 15;

    swap(tree.getHead(), val1, val2);

    cout << "In-order after swapping: ";
    InOrderTraversal(tree.getHead());
    cout << endl;

    return 0;
}

