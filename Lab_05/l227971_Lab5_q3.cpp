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
     * Getter to get the head of the link list
     * @param void
     * @return the head of the link list as an address of the node
     * @note Time Complexity: O(n)
     */
    void add_Ascending_without_Duplicates(dataType val)
    {
        Node<dataType> *temp = new Node<dataType>(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            size++;
            return;
        }
        Node<dataType> *temp2 = head;
        while (temp2 != NULL)
        {
            if (temp2->getData() == val)
            {
                return;
            }
            temp2 = temp2->getNext();
        }
        temp2 = head;
        if (temp2->getData() > val)
        {
            temp->setNext(temp2);
            temp2->setPrev(temp);
            head = temp;
            size++;
            return;
        }
        while (temp2->getNext() != NULL)
        {
            if (temp2->getNext()->getData() > val)
            {
                temp->setNext(temp2->getNext());
                temp->setPrev(temp2);
                temp2->getNext()->setPrev(temp);
                temp2->setNext(temp);
                size++;
                return;
            }
            temp2 = temp2->getNext();
        }
        temp2->setNext(temp);
        temp->setPrev(temp2);
        tail = temp;
        size++;
    }

    /**
     * Find the triplets whose sum is less than the number entered by the user.
     * @param num the number upto which the triplets are to be found.
     * @return the number of triplets found.
     * @note Time Complexity: O(n^3).
     */
    int findTripletsUpto(int num)
    {
        cout << "Triplets are: ";
        int triplets = 0;
        Node<dataType> *temp = head;
        while (temp != NULL)
        {
            Node<dataType> *temp2 = temp->getNext();
            while (temp2 != NULL)
            {
                Node<dataType> *temp3 = temp2->getNext();
                while (temp3 != NULL)
                {
                    if (temp->getData() + temp2->getData() + temp3->getData() < num)
                    {
                        cout << "(" << temp->getData() << "," << temp2->getData() << "," << temp3->getData() << ") ";
                        triplets++;
                    }
                    temp3 = temp3->getNext();
                }
                temp2 = temp2->getNext();
            }
            temp = temp->getNext();
        }
        cout << endl;
        return triplets;
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
    cout << "Note: In this question, by Upto it means that the sum of the triplets should be less than the number you enter." << endl;
    cout << "The Lab Manual Example is being followed" << endl
         << endl;
    linkedList<int> list;
    bool flag = true;
    while (flag == true)
    {
        cout << "Enter Number to add in the list: ";
        int num;
        cin >> num;
        list.add_Ascending_without_Duplicates(num);
        cout << "Do you want to add more numbers? (y/n): ";
        char ch;
        cin >> ch;
        if (ch == 'n' || ch == 'N')
        {
            flag = false;
        }
    }

    cout << "The List is: ";
    list.print();

    cout << "Enter Number you want to count triplets upto: ";
    int num;
    cin >> num;
    while (num < 2)
    {
        cout << "Enter Number you want to count triplets upto: ";
        cin >> num;
    }
    int trip = list.findTripletsUpto(num);
    cout << endl
         << "Total Triplets: " << trip << endl;

    cout << endl
         << "Just in Case you ment less than or equal to, here is the list of triplets less then and equal to " << num << endl;
    trip = list.findTripletsUpto(num + 1);
    cout << "Total Triplets: " << trip << endl;

    cout << endl;
    system("pause");
    return 0;
}