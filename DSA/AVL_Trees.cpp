#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    return n->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;

    return node;
}

int getBalanceFactor(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // Duplicates are not allowed in AVL tree
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = getBalanceFactor(node);

    // LL case
    if (bf > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // RR case
    if (bf < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // LR case
    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL case
    if (bf < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* deleteNode(Node* root, int key){
    if(!root){
        return nullptr;
    }

    if(key < root->key){
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right,key);
    }
    else{
        // Leaf node
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        // Only one child exist
        else if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right && !root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Both child exist
        else{
            // Right side smallest element
            Node* curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }
            root->key = curr->key;
            root->right = deleteNode(root->right,curr->key);
        }
    }

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));

    int BF = getBalanceFactor(root);

    if(BF > 1){
        //LL
        if(getBalanceFactor(root->left) >= 0){
            return rightRotate(root);
        }
        //LR
        else{
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    else if(BF < -1){
        // RR
        if(getBalanceFactor(root->right)<=0){
            return leftRotate(root);
        }
        // RL
        else{
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    else{
        return root;
    }
}

// PreOrder Traversal: Root -> Left -> Right
void PreOrderTraversal(Node* ptr) {
    if (ptr != nullptr) {
        cout << ptr->key << endl;
        PreOrderTraversal(ptr->left);
        PreOrderTraversal(ptr->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    PreOrderTraversal(root);

    return 0;
}
