#include <iostream>

using namespace std;

// creating struct for node
struct Node {
    int data;
    Node* next;
};

// creating linked list class 
class LinkedList {
private:
    Node* head;

public:
    LinkedList() { // constructor that sets head to nullptr 
        head = nullptr;
    }
    
    // function that calls insertAtEnd function that performs the adding of a new node
    // at the end of the linked list recursively
    void append(int data) {
        head = insertAtEnd(data, head);
    }

    /*
    When this function is first called, the int variable data and a pointer to the head (called node) of the linked list 
    is passed in to the function. If the node pointer points to nullptr (base case) it has reached the end of linked list
    and a new node is created and the function returns a pointer to the newly created node. 

    If the node pointer is not nullptr, we move the pointer down the linked list by passing node->next as the pointer
    variable in the recursion call and setting the result of that recursion call to node->next,
    this repeats until the base case is reached.

    The final return result is a pointer to the head of the linked list.
    */
   
    Node* insertAtEnd(int data, Node* node) {
        if (node == nullptr) { // base case: when node pointer points to nullptr
            // creating new node
            node = new Node;
            node->data = data;
            node->next = nullptr;
        }
        else {
            // if base case it not reached we call the function again with node->next passed in
            // as the pointer variable and set the return value of the function call to node->next
            node->next = insertAtEnd(data, node->next);
        }
        return node; // returns node pointer
    }

    // iterates through the linked list and prints out linked list
    void printList() {
        Node* current = head; // create current pointer which is a copy of head

        // if current is not equal to nullptr we print out the data value in each node
        // and continue down the linked list
        while (current != nullptr) {
            cout << current->data << "--> ";
            current = current->next;
        }
        cout << "null";
    }
};

int main() {
    LinkedList list; // creating linked list

    // adding nodes to linked list
    list.append(1);
    list.append(2);
    list.append(3);

    list.printList(); // call to function to print list

    return 0;
}

