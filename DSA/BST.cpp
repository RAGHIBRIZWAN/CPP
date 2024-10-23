#include <iostream>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;

public:
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

    node *insert(node *root, int data)
    {
        if (root == nullptr)
        {
            return new node(data);
        }
        if (root->data == data)
            return root;

        if (root->data > data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }

public:
    BST() : head(nullptr) {}
    BST(node *n) : head(n) {}

    void insertion(int data)
    {
        head = insert(head, data);
    }

    int search(node *root, int val)
    {
        if (root == nullptr)
            return -1;

        node *ptr = root;

        if (ptr->data == val)
        {
            return ptr->data;
        }
        if (ptr->data > val)
        {
            search(ptr->left, val);
        }
        else
        {
            search(ptr->right, val);
        }
    }

    int height(node *root)
    {
        if (root == nullptr)
            return -1;

        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
        {
            return lheight + 1;
        }
        else
        {
            return rheight + 1;
        }

        return -1;
    }

    void preOrderTraversal(node *root)
    {
        if (root == nullptr)
        {
            cout << "-1" << " ";
            return;
        }

        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void traverse()
    {
        preOrderTraversal(head);
    }

    node* Head(){
        return head;
    }

    void printGivenLevel(node* root,int level){
        if (root == nullptr) return;

        else if(level == 0){
            cout<<root->data<<" ";
        }
        else{
            printGivenLevel(root->left,level-1);
            printGivenLevel(root->right,level-1);
        }
    }

    void BFS(node* root){
        int h = height(root);

        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(root,i);
        }
    }

    node* minValueNode(node* r){
        node* current = r;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    node* deleteNode(node* root, int v){
        if (root == nullptr) return nullptr;

        else if(v < root->data){
            root->left = deleteNode(root->left,v);
        }

        else if(v > root->data){
            root->right = deleteNode(root->right,v);
        }

        else{
            if(root->left == nullptr){
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                node* temp = root->left;
                delete root;
                return temp;
            }
            else{
                node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right,temp->data);
            }
        }
    }

    node* deleting(int data){
        head = deleteNode(head,data);
    }
};

int main()
{
    BST *b1 = new BST;
    b1->insertion(1);
    b1->insertion(2);
    b1->insertion(3);
    b1->insertion(4);
    b1->insertion(5);
    b1->traverse();
    cout<<"\nSearch: "<<b1->search(b1->Head(),3);
    cout<<"\nHeight:"<<b1->height(b1->Head())<<endl;
    b1->BFS(b1->Head());
    b1->deleting(2);
    cout<<"\nAfter Deletion: "<<endl;
    b1->BFS(b1->Head());
}
