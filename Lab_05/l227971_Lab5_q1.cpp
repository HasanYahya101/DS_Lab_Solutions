#include <iostream>
using namespace std;

template <class dataType>

class Node
{
private:
    dataType data;
    Node *next;
    Node *prev;

public:
    /**
     * Default Constructor to initialize the node.
     * @param void
     * @note Time Complexity: O(1)
     */
    Node(dataType data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }

    /**
     * Perametirized Constructor to initialize the node.
     * @param data the data to be stored in the node. It can be of any data type.
     * @param next the address of the next node.
     * @param prev the address of the previous node.
     * @return void
     * @note Time Complexity: O(1)
     */
    Node(dataType data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    /**
     * Getter to get the data of the node.
     * @param void
     * @return Data of the node. It can be of any data type.
     * @note Time Complexity: O(1)
     */
    dataType getData()
    {
        return data;
    }

    /**
     * Setter to set the data of the node.
     * @param data the data to be stored in the node. It can be of any data type.
     * @return void
     * @note Time Complexity: O(1)
     */
    void setData(dataType data)
    {
        this->data = data;
    }

    /**
     * Getter to get the address of the next node.
     * @param void
     * @return Address of the next node.
     * @note Time Complexity: O(1)
     */
    Node *getNext()
    {
        return next;
    }

    /**
     * Setter to set the address of the next node.
     * @param next the address of the next node.
     * @return void
     * @note Time Complexity: O(1)
     */
    void setNext(Node *next)
    {
        this->next = next;
    }

    /**
     * Getter to get the address of the previous node.
     * @param void
     * @return Address of the previous node.
     * @note Time Complexity: O(1)
     */
    Node *getPrev()
    {
        return prev;
    }

    /**
     * Setter to set the address of the previous node.
     * @param prev the address of the previous node.
     * @return void
     * @note Time Complexity: O(1)
     */
    void setPrev(Node *prev)
    {
        this->prev = prev;
    }
};

template <class dataType>

class linkedList
{
private:
    Node<dataType> *head;
    Node<dataType> *tail;
    int size;

public:
    /**
     * Default Constructor to initialize the link list
     * @param void
     * @return void
     * @note Time Complexity: O(1)
     */
    linkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /**
     * Perametirized Constructor to initialize the link list
     * @param head the head of the link list as an address of the node
     * @param tail the tail of the link list as an address of the node
     * @param size the size of the link list as an integer
     * @return void
     * @note Time Complexity: O(1)
     */
    linkedList(Node<dataType> *head, Node<dataType> *tail, int size)
    {
        this->head = head;
        this->tail = tail;
        this->size = size;
    }

    /**
     * Add a new node at the start of the link list
     * @param val the value to be added in the link list
     * @return void
     * @note Time Complexity: O(1)
     */
    void addAtStart(dataType val)
    {
        Node<dataType> *newNode = new Node<dataType>(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;
        }
        size++;
    }

    /**
     * Add a new node at the end of the link list
     * @param val the value to be added in the link list
     * @return void
     * @note Time Complexity: O(1)
     */
    void addatLast(dataType val)
    {
        Node<dataType> *newNode = new Node<dataType>(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->setPrev(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
        size++;
    }

    /**
     * Check if the link list is palindrome or not
     * @param void
     * @return bool
     * @note Time Complexity: O(n)
     */
    bool isPalindrome()
    {
        Node<dataType> *temp = head;
        Node<dataType> *temp2 = tail;
        while (temp != NULL)
        {
            if (temp->getData() != temp2->getData())
            {
                return false;
            }
            temp = temp->getNext();
            temp2 = temp2->getPrev();
        }
        return true;
    }

    /**
     * Shuffle the link list in the format L0 → Ln→ L1 → Ln - 1 → L2 → Ln - 2 → ...
     * For Example, a list with 1 2 3 4 5 elements in it will be shuffled as 1 5 2 4 3.
     * @param void
     * @return void
     * @note Time Complexity: O(n)
     */
    void Shuffle()
    {
        if (head == NULL || head->getNext() == NULL)
        {
            return;
        }

        Node<dataType> *first = head;
        Node<dataType> *last = tail;

        while (first != last && first->getNext() != last)
        {
            // Save the next node of the first node
            Node<dataType> *nextFirst = first->getNext();

            // Save the previous node of the last node
            Node<dataType> *prevLast = last->getPrev();

            // Set the next of the first node to the last node
            first->setNext(last);

            // Set the previous of the last node to the first node
            last->setPrev(first);

            // Set the next of the last node to the nextFirst node
            last->setNext(nextFirst);

            // Set the previous of the nextFirst node to the last node
            nextFirst->setPrev(last);

            // Update the first node and the last node
            first = nextFirst;
            last = prevLast;
        }

        // If the list has an odd number of nodes, then set the next of the last node to NULL
        if (first == last)
        {
            last->setNext(NULL);
        }
    }

    /**
     * Swap the nth node from the start with the nth node from the end
     * @param nth the nth node from the start in integer
     * @return void
     * @note Time Complexity: O(n)
     */
    void swapNodes(int nth)
    {
        if (nth > size)
        {
            cout << "Invalid Value" << endl;
            return;
        }
        Node<dataType> *temp = head;
        Node<dataType> *temp2 = tail;
        for (int i = 1; i < nth; i++)
        {
            temp = temp->getNext();
            temp2 = temp2->getPrev();
        }
        dataType data = temp->getData();
        temp->setData(temp2->getData());
        temp2->setData(data);
    }

    /**
     * Remove all nodes from the double link list which contain elements whose digit sum is even and find
     * the sum and product of the remaining elements.
     * @param void
     * @return void
     * @note Time Complexity: O(n)
     */
    void removeNodes()
    {
        Node<dataType> *temp = head;
        while (temp != NULL)
        {
            int sum = 0;
            int num = temp->getData();
            while (num != 0)
            {
                sum += num % 10;
                num /= 10;
            }
            if (sum % 2 == 0)
            {
                if (temp == head)
                {
                    head = temp->getNext();
                    head->setPrev(NULL);
                    delete temp;
                    temp = head;
                }
                else if (temp == tail)
                {
                    tail = temp->getPrev();
                    tail->setNext(NULL);
                    delete temp;
                    temp = NULL;
                }
                else
                {
                    temp->getPrev()->setNext(temp->getNext());
                    temp->getNext()->setPrev(temp->getPrev());
                    Node<dataType> *temp2 = temp;
                    temp = temp->getNext();
                    delete temp2;
                }
            }
            else
            {
                temp = temp->getNext();
            }
        }

        temp = head;
        int sum = 0;
        int product = 1;
        while (temp != NULL)
        {
            sum += temp->getData();
            product *= temp->getData();
            temp = temp->getNext();
        }
        cout << "Sum: " << sum << endl;
        cout << "Product: " << product << endl;
    }

    /**
     * Reverse the link list. Using pointers only, not allowed to copy data.
     * @param void
     * @return void
     * @note Time Complexity: O(n)
     */
    void reverseList()
    {
        Node<dataType> *temp = head;
        Node<dataType> *temp2 = tail;
        while (temp != NULL)
        {
            Node<dataType> *next = temp->getNext();
            Node<dataType> *prev = temp->getPrev();
            temp->setNext(prev);
            temp->setPrev(next);
            temp = next;
        }
        head = temp2;
        tail = temp;
        /**
         * Note: I could have returned the pointer to the head node but i don't think it is necessary.
         */
    }

    /**
     * Print the link list
     * @param void
     * @return void
     * @note Time Complexity: O(n)
     */
    void print()
    {
        Node<dataType> *temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
};

int main()
{
    linkedList<int> list;
    list.addAtStart(1);
    list.addAtStart(2);
    list.addAtStart(3);
    list.addAtStart(1);
    cout << "Creating new List..." << endl;
    cout << "List: ";
    list.print();
    if (list.isPalindrome())
    {
        cout << "List is Palindrome" << endl;
    }
    else
    {
        cout << "List is not Palindrome" << endl;
    }
    linkedList<int> list2;
    list2.addAtStart(1);
    list2.addAtStart(2);
    list2.addAtStart(2);
    list2.addAtStart(1);
    cout << "Creating new List..." << endl;
    cout << "List: ";
    list2.print();
    if (list2.isPalindrome())
    {
        cout << "List is Palindrome" << endl;
    }
    else
    {
        cout << "List is not Palindrome" << endl;
    }
    linkedList<int> list3;
    list3.addAtStart(5);
    list3.addAtStart(4);
    list3.addAtStart(3);
    list3.addAtStart(2);
    list3.addAtStart(1);
    cout << "Creating new List..." << endl;
    cout << "List: ";
    list3.print();
    cout << "Shuffling List..." << endl;
    list3.Shuffle();
    cout << "List: ";
    list3.print();
    linkedList<int> list4;
    list4.addAtStart(5);
    list4.addAtStart(4);
    list4.addAtStart(3);
    list4.addAtStart(2);
    list4.addAtStart(1);
    cout << "Creating new List..." << endl;
    cout << "List: ";
    list4.print();
    cout << "Swapping 2nd node from start with 2nd node from last..." << endl;
    list4.swapNodes(2);
    cout << "List: ";
    list4.print();
    linkedList<int> list5;
    list5.addAtStart(52);
    list5.addAtStart(41);
    list5.addAtStart(33);
    list5.addAtStart(21);
    list5.addAtStart(11);
    cout << "Creating new List..." << endl;
    cout << "List: ";
    list5.print();
    cout << "Removing nodes..." << endl;
    list5.removeNodes();
    cout << "List: ";
    list5.print();
    linkedList<int> list6;
    list6.addAtStart(1);
    list6.addAtStart(2);
    list6.addAtStart(3);
    list6.addAtStart(4);
    list6.addAtStart(5);
    cout << "Creating new List..." << endl;
    cout << "List: ";
    list6.print();
    cout << "Reversing List..." << endl;
    list6.reverseList();
    cout << "List: ";
    list6.print();

    cout << endl;
    system("pause");
    return 0;
}