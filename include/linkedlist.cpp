#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;
};

// Linked list class
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Add a node at the beginning of the linked list
    void addToHead(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Add a node at the end of the linked list
    void addToTail(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Remove the node at the beginning of the linked list
    void removeFromHead()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Remove the node at the end of the linked list
    void removeFromTail()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }

    // Traverse the linked list and print the values of each node
    void traverse()
    {
        if (head == NULL)
        {
            cout << "The linked list is empty." << endl;
            return;
        }
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    // Add nodes to the linked list
    list.addToHead(2);
    list.addToHead(1);
    list.addToTail(3);
    list.addToTail(4);

    // Traverse the linked list
    cout << "Linked list values: ";
    list.traverse();

    // Remove nodes from the linked list
    list.removeFromHead();
    list.removeFromTail();

    // Traverse the linked list again
    cout << "Linked list values after removal: ";
    list.traverse();

    return 0;
}
