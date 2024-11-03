#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;

public:
    node(int d) : data(d), left(nullptr), right(nullptr) {}
    friend class BT;
};

class BT
{
    node *root;
    int countSubTrees = 0;

public:
    BT() : root(nullptr) {}

    void insert(int data)
    {
        if (!root)
        {
            root = new node(data);
            return;
        }

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *curr = q.front();
            q.pop();

            if (!curr->left)
            {
                curr->left = new node(data);
                return;
            }
            else
            {
                q.push(curr->left);
            }

            if (!curr->right)
            {
                curr->right = new node(data);
                return;
            }
            else
            {
                q.push(curr->right);
            }
        }
    }

    node *deletion(int data)
    {
        if (!root)
            return nullptr;

        if (root->data == data && !root->left && !root->right)
        {
            delete root;
            root = nullptr;
            return nullptr;
        }

        queue<node *> q;
        q.push(root);
        node *temp;
        node *target = nullptr;          // To hold the target node
        node *parentOfDeepest = nullptr; // To hold the parent of the deepest node

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            // If we find the target node
            if (temp->data == data)
            {
                target = temp;
            }

            // Track the parent of the deepest node
            parentOfDeepest = temp;

            // Push children into the queue
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        // If target node is found, swap with the deepest node
        if (target)
        {
            target->data = temp->data; // Replace target's data with deepest node's data

            // Delete the deepest node
            if (parentOfDeepest->left == temp)
            {
                delete parentOfDeepest->left;
                parentOfDeepest->left = nullptr; // Set to nullptr after deletion
            }
            else if (parentOfDeepest->right == temp)
            {
                delete parentOfDeepest->right;
                parentOfDeepest->right = nullptr; // Set to nullptr after deletion
            }
        }
        return root;
    }

    bool isBST(node *root, int minValue, int maxValue)
    {
        if (!root)
            return true;
        if (root->data <= minValue || root->data >= maxValue)
            return false;
        return isBST(root->left, minValue, root->data) && isBST(root->right, root->data, maxValue);
    }

    void countBSTSubtreesHelper(node *root)
    {
        if (!root)
            return;

        if (isBST(root, INT_MIN, INT_MAX))
        {
            countSubTrees++;
        }
        countBSTSubtreesHelper(root->left);
        countBSTSubtreesHelper(root->right);
    }

    int getCountSubTrees()
    {
        countSubTrees = 0;
        countBSTSubtreesHelper(root);
        return countSubTrees;
    }

    node *getRoot()
    {
        return root;
    }

    void levelOrderTraversal()
    {
        if (!root)
            return;

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }

    bool isCompleteBinaryTree()
    {
        if (!root)
            return true;

        queue<node *> q;
        q.push(root);
        bool end = false;

        while (!q.empty())
        {
            node *curr = q.front();
            q.pop();

            if (!curr)
            {
                end = true;
            }
            else
            {
                if (end)
                {
                    return false;
                }

                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};

int main()
{
    BT tree;
    tree.insert(45);
    tree.insert(88);
    tree.insert(12);
    tree.insert(5);
    tree.insert(3);
    tree.insert(23);
    tree.insert(80);
    tree.insert(99);
    tree.insert(100);
    tree.insert(0);
    tree.insert(454);
    tree.insert(2);
    tree.insert(33);
    // tree.insert(5);
    tree.insert(32);
    tree.insert(1);
    tree.insert(101);
    tree.levelOrderTraversal();
    tree.deletion(45);
    cout<<"After deletion: ";
    tree.levelOrderTraversal();


    cout << "Count of subtrees with both left and right children: " << tree.getCountSubTrees() << endl;

    if (tree.isCompleteBinaryTree())
    {
        cout << "The tree is a complete binary tree." << endl;
    }
    else
    {
        cout << "The tree is not a complete binary tree." << endl;
    }

    return 0;
}
