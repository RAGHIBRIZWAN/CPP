
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
};

node* NewBST(int arr[], int si, int ei)
{
    if (si > ei)
    {
        return nullptr;
    }

    int mid = si + (ei - si) / 2;

    node *tree = new node(arr[mid]);

    tree->left = NewBST(arr, si, mid - 1);
    tree->right = NewBST(arr, mid + 1, ei);
    return tree;
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    node *root = NewBST(arr, 0, 6);
    InOrderTraversal(root);
}
