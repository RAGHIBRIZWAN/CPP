#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    
    node(int val) : data(val), next(nullptr) {}
};

class list {
    node* head;

public:
    list() : head(nullptr) {}

    // Function to insert node at the end
    void insertNodeAtEnd(int val) {
        node* newptr = new node(val);
        if (head == nullptr) {
            head = newptr;
            return;
        }

        node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newptr;
    }

    // Function to traverse and print the list
    void traversal() const {
        node* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    // Function to split the list into two halves
    node* splitList(node* head) {
        node* slow = head;
        node* fast = head->next;
        
        // Use two-pointer technique to find the middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        node* secondHalf = slow->next;
        slow->next = nullptr;
        return secondHalf;
    }

    node* mergeSortedLists(node* l1, node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->data < l2->data) {
            l1->next = mergeSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeSortedLists(l2->next, l1);
            return l2;
        }
    }

    // Recursive function to sort the linked list using Merge Sort
    node* mergeSort(node* head) {
        if (!head || !head->next) {
            return head;  // Base case: single node or empty list
        }

        node* secondHalf = splitList(head);  // Split the list into two halves

        // Recursively sort each half
        head = mergeSort(head);
        secondHalf = mergeSort(secondHalf);

        // Merge the sorted halves
        return mergeSortedLists(head, secondHalf);
    }

    // Public function to sort the list
    void sortList() {
        head = mergeSort(head);
    }
};

int main() {
    list li;
    li.insertNodeAtEnd(4);
    li.insertNodeAtEnd(2);
    li.insertNodeAtEnd(8);
    li.insertNodeAtEnd(1);
    li.insertNodeAtEnd(5);

    cout << "Original List: ";
    li.traversal();

    li.sortList();  // Apply Merge Sort on the list

    cout << "Sorted List: ";
    li.traversal();

    return 0;
}
