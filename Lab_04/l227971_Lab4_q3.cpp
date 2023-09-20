#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node() // Default constructor
    {
        next = NULL;
    }
    Node(int data) // Parameterized constructor
    {
        this->data = data;
        next = NULL;
    }
    Node(int data, Node *next) // Parameterized constructor
    {
        this->data = data;
        this->next = next;
    }
    void setData(int data) // Setter
    {
        this->data = data;
    }
    int getData() // Getter
    {
        return data;
    }
    void setNext(Node *next) // Setter
    {
        this->next = next;
    }
    Node *getNext() // Getter
    {
        return next;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    /**
     * @brief Construct a new Linked List object
     * @brief This is a Default Constructor.
     * @brief It will initialize the head to NULL.
     * @return void
     */
    LinkedList() // Default constructor
    {
        head = NULL;
    }

    /**
     * @brief Insert a new node at the beginning of the linked list
     * @param val It can be of any dataType.
     * @return bool It will return true if the node is inserted successfully, otherwise false.
     */
    bool insert(int val) // do it in O(1)
    {
        Node *newNode = new Node(val);
        if (newNode == NULL)
        {
            return false;
        }
        newNode->setNext(head);
        head = newNode;
        return true;
    }

    /**
     * @brief Display the linked list. It is in O(n)
     * @return void
     */
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    /**
     * @brief Count the number of nodes in the linked list. It is in O(n)
     * @return int It will return the number of nodes in the linked list.
     */
    int countNodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->getNext();
        }
        return count;
    }

    /**
     * @brief return the int stored in first node
     * @return int It will return the int stored in first node
     * @note If the list is empty, it will return -1
     * @note It is in O(1)
     */
    int returnFirst()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->getData();
    }

    /**
     * @brief return the int stored in last node
     * @return int It will return the int stored in last node
     * @note If the list is empty, it will return -1
     * @note It is in O(n)
     */
    int returnLast()
    {
        if (head == NULL)
        {
            return -1;
        }
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        return temp->getData();
    }

    /**
     * @brief Delete the first node of the linked list
     * @return int It will return the data stored in the first node
     * @note If the list is empty, it will return -1
     * @note It is in O(1)
     */
    int pop()
    {
        if (head == NULL)
        {
            return -1;
        }
        Node *temp = head;
        int data = temp->getData();
        head = head->getNext();
        delete temp;
        return data;
    }

    /**
     * @brief ShuffleMerge the two linked lists.
     * @brief If first list has 1 and 2 elements and second list has 3 and 4 elements.
     * @brief The Resultant list will be 1 3 2 4.
     * @param list1 It is the first linked list
     * @param list2 It is the second linked list
     * @return void
     * @note It is in O(n)
     */
    void shuffleMerge(LinkedList &list1, LinkedList &list2)
    {
        Node *temp1 = list1.head;
        Node *temp2 = list2.head;
        Node *next1, *next2;

        // If either list is empty, set head to the non-empty list
        if (temp1 == NULL)
        {
            head = temp2;
            list2.head = NULL; // Prevent list2 from deleting the nodes
            return;
        }
        else if (temp2 == NULL)
        {
            head = temp1;
            list1.head = NULL; // Prevent list1 from deleting the nodes
            return;
        }

        // Set head to the first node of list1
        head = temp1;
        Node *current = head;
        temp1 = temp1->getNext();

        while (temp1 != NULL && temp2 != NULL)
        {
            // Save the next nodes
            next1 = temp1->getNext();
            next2 = temp2->getNext();

            // Link current node of list1 to current node of list2
            current->setNext(temp2);

            // Link current node of list2 to next node of list1
            temp2->setNext(temp1);

            // Move to the next pair of nodes
            current = temp1;
            temp1 = next1;
            temp2 = next2;
        }

        // If list1 is longer, append remaining nodes to the merged list
        if (temp1 != NULL)
        {
            current->setNext(temp1);
        }

        // If list2 is longer, append remaining nodes to the merged list
        if (temp2 != NULL)
        {
            current->setNext(temp2);
        }

        // Prevent list1 and list2 from deleting the nodes
        list1.head = NULL;
        list2.head = NULL;
    }

    /**
     * @brief Insert a new node at the nth index of the linked list
     * @param data It is the data to be inserted in the new node
     * @param n It is the index at which the new node is to be inserted
     * @return bool It will return true if the node is inserted successfully, otherwise false.
     * @note If the index is invalid, it will return false
     * @note It is in O(n)
     */
    bool insertNthNode(int data, int n)
    {
        if (n < 0 || n > countNodes())
        {
            return false;
        }
        if (n == 0)
        {
            return insert(data);
        }
        Node *temp = head;
        for (int i = 0; i < n - 1; i++)
        {
            temp = temp->getNext();
        }
        Node *newNode = new Node(data);
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
        return true;
    }

    /**
     * @brief Combine the two linked lists. The first linked list will be at the beginning of the combined linked list
     * @brief The Second linked list will be at the end of the combined linked list
     * @param list1 It is the first linked list
     * @param list2 It is the second linked list
     * @return void
     * @note It is in O(n)
     */
    void combine(LinkedList &list1, LinkedList &list2) // not allowed to create another node
    {
        if (list1.head == NULL)
        {
            head = list2.head;
            list2.head = NULL; // Prevent list2 from deleting the nodes
            return;
        }
        if (list2.head == NULL)
        {
            head = list1.head;
            list1.head = NULL; // Prevent list1 from deleting the nodes
            return;
        }

        head = list1.head;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(list2.head);

        // Prevent list1 and list2 from deleting the nodes
        list1.head = NULL;
        list2.head = NULL;
    }

    /**
     * @brief Insert a new node in the Ascending Order in an already assumed sorted linked list
     * @param newNode It is the new node to be inserted
     * @return void
     */
    void sortedInsert(Node *newNode)
    {
        Node *current;
        /* Special case for the head end */
        if (head == NULL || (head)->getData() >= newNode->getData())
        {
            newNode->setNext(head);
            head = newNode;
        }
        else
        {
            /* Locate the node before the point of insertion */
            current = head;
            while (current->getNext() != NULL &&
                   current->getNext()->getData() < newNode->getData())
            {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
        }
    }

    /**
     * @brief Destroy the Linked List object
     * @return void
     */
    ~LinkedList() // Destructor
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *next = current->getNext();
            delete current;
            current = next;
        }
        head = NULL; // Set head to NULL after deleting all nodes
    }
};

int main()
{
    LinkedList list1;
    cout << "Entering 1, 2, 3, 4 into a linked list" << endl;
    list1.insert(4);
    list1.insert(3);
    list1.insert(2);
    list1.insert(1);
    cout << "Displaying the linked list" << endl;
    list1.display();
    cout << "Size of the linked list is: " << list1.countNodes() << endl;
    cout << "Popping the First Node: " << list1.pop() << endl;
    cout << "Displaying the linked list" << endl;
    list1.display();
    cout << "The data at first node is: " << list1.returnFirst() << endl;
    cout << "The data at last node is: " << list1.returnLast() << endl;
    cout << "Inserting 1 into new Node at the frst index" << endl;
    list1.insertNthNode(1, 0);
    cout << "Displaying the linked list" << endl;
    list1.display();
    cout << "Inserting 5 into new Node at the last index" << endl;
    list1.insertNthNode(5, list1.countNodes());
    cout << "Displaying the linked list" << endl;
    list1.display();
    cout << "Creating a new Linked List" << endl;
    LinkedList list2;
    cout << "Entering 6, 7, 9, 11 into a linked list" << endl;
    list2.insert(11);
    list2.insert(9);
    list2.insert(7);
    list2.insert(6);
    cout << "Displaying the linked list" << endl;
    list2.display();
    cout << "Combining the two linked lists" << endl;
    LinkedList list3;
    list3.combine(list1, list2);
    cout << "Displaying the linked list" << endl;
    list3.display();
    cout << "Creating new linked lists" << endl;
    LinkedList list4;
    LinkedList list5;
    cout << "Entering 1, 2, 3, 4 into a linked list" << endl;
    list4.insert(4);
    list4.insert(3);
    list4.insert(2);
    list4.insert(1);
    cout << "Displaying the linked list" << endl;
    list4.display();
    cout << "Entering 6, 7, 9, 11 into a linked list" << endl;
    list5.insert(11);
    list5.insert(9);
    list5.insert(7);
    list5.insert(6);
    cout << "Displaying the linked list" << endl;
    list5.display();
    cout << "Shuffling the two linked lists" << endl;
    LinkedList list6;
    list6.shuffleMerge(list4, list5);
    cout << "Displaying the linked list" << endl;
    list6.display();
    cout << "Creating a Sorted List" << endl;
    LinkedList list7;
    cout << "Entering 1, 2, 3, 4 into a linked list" << endl;
    list7.insert(5);
    list7.insert(3);
    list7.insert(2);
    list7.insert(1);
    cout << "Displaying the linked list" << endl;
    list7.display();
    cout << "Creating a new node with data 4" << endl;
    Node *node = new Node(4);
    cout << "Inserting the node into the sorted list" << endl;
    list7.sortedInsert(node);
    cout << "Displaying the linked list" << endl;
    list7.display();

    system("pause");
    return 0;
}