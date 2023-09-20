#include <iostream>
using namespace std;

template <class dataType>

class Node
{
private:
    dataType val;
    Node<dataType> *ptr;

public:
    /**
     * @brief Construct a new Node<dataType>:: Node object.
     * @brief This is a Default Constructor.
     * @brief It will initialize the ptr to NULL.
     */
    Node()
    {
        ptr = NULL;
    }

    /**
     * @brief Construct a new Node<dataType>:: Node object.
     * @brief This is a Parameterized Constructor.
     * @brief It will initialize the val to val and ptr to NULL.
     * @param val It can be of any dataType.
     */
    Node(dataType val)
    {
        this->val = val;
        ptr = NULL;
    }

    /**
     * @brief Construct a new Node<dataType>:: Node object.
     * @brief This is a Parameterized Constructor.
     * @brief It will initialize the val to val and ptr to ptr.
     * @param val It can be of any dataType.
     * @param ptr It is a pointer to the next Node.
     */
    Node(dataType val, Node<dataType> *ptr)
    {
        this->val = val;
        this->ptr = ptr;
    }

    /**
     * @brief Set the Val object
     * @param val It can be of any dataType.
     * @return void
     */
    void setVal(dataType val)
    {
        this->val = val;
    }

    /**
     * @brief Get the Val object
     * @return dataType
     */
    dataType getVal()
    {
        return val;
    }

    /**
     * @brief Set the Ptr object
     * @param ptr It is a pointer to the next Node.
     * @return void
     */
    void setPtr(Node<dataType> *ptr)
    {
        this->ptr = ptr;
    }

    /**
     * @brief Get the Ptr object
     * @return Node<dataType>* - It returns the address of pointer to the next Node.
     */
    Node<dataType> *getPtr()
    {
        return ptr;
    }

    /**
     * @brief It will print the value of the Node.
     * @return void
     */
    void print()
    {
        cout << val << " ";
    }

    /**
     * @brief Destroy the Node<dataType>:: Node object
     */
    ~Node()
    {
        // delete ptr;
    }
};

template <class dataType>

class linked_list
{
private:
    Node<dataType> *head_ptr;
    Node<dataType> *tail_ptr;
    int size;

public:
    /**
     * @brief This is a Default Constructor.
     * @brief It will initialize the head_ptr and tail_ptr to NULL and size to 0.
     * @return void
     */
    linked_list()
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        size = 0;
    }

    /**
     * @brief This is a Parameterized Constructor.
     * @brief It will initialize the head_ptr and tail_ptr to a new Node with value val and size to 1.
     * @param val It can be of any dataType.
     * @return void
     */
    linked_list(int val)
    {
        head_ptr = new Node<dataType>(val);
        tail_ptr = head_ptr;
        size = 1;
    }

    /**
     * @brief Insert a new Node at the end of the list.
     * @param element It can be of any dataType.
     * @return void
     */
    void insertAtEnd(dataType const element)
    {
        Node<dataType> *temp = new Node<dataType>(element);
        if (head_ptr == NULL)
        {
            head_ptr = temp;
            tail_ptr = temp;
        }
        else
        {
            tail_ptr->setPtr(temp);
            tail_ptr = temp;
        }
        size++;
    }

    /**
     * @brief Print the list in forward direction.
     * @return void
     * @note It will print the list in forward direction.
     */
    void printForward() const
    {
        Node<dataType> *temp = head_ptr;
        while (temp != NULL)
        {
            temp->print();
            temp = temp->getPtr();
        }
        cout << endl;
    }

    /**
     * @brief It will delete the Node at the given index.
     * @param index It is the index of the Node to be deleted.
     * @return void
     */
    void remove_node(int index)
    {
        if (head_ptr == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        if (index < 0 || index >= size)
        {
            cout << "Index Out of Bound" << endl;
            return;
        }
        if (index == 0)
        {
            Node<dataType> *temp = head_ptr;
            head_ptr = head_ptr->getPtr();
            delete temp;
            size--;
            return;
        }
        Node<dataType> *temp = head_ptr;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->getPtr();
        }
        Node<dataType> *temp2 = temp->getPtr();
        temp->setPtr(temp2->getPtr());
        delete temp2;
        size--;
        // put tail_ptr at the end of the list
        temp = head_ptr;
        while (temp->getPtr() != NULL)
        {
            temp = temp->getPtr();
        }
        tail_ptr = temp;
    }

    /**
     * @brief It will print the missing numbers in the list.
     * @param n It is the size of the list.
     * @return void
     */
    void print_missing(int n)
    {
        // the list should have all numbers from 1 to n
        // if any number is missing then it will print that number
        // the values are not in ascending order
        bool *found = new bool[n + 1]; // Initialize an array to track found numbers
        for (int i = 1; i <= n; i++)
        {
            found[i] = false; // Initialize all values to false
        }

        Node<dataType> *temp = head_ptr;
        while (temp != NULL)
        {
            int val = temp->getVal();
            if (val >= 1 && val <= n)
            {
                found[val] = true; // Mark the value as found
            }
            temp = temp->getPtr();
        }

        cout << "Missing Numbers: ";
        for (int i = 1; i <= n; i++)
        {
            if (!found[i])
            {
                cout << i << " "; // Print missing numbers
            }
        }
        cout << endl;

        delete[] found; // Don't forget to free the dynamically allocated array
    }

    /**
     * @brief Get the Size object
     * @return int - It returns the size of the list.
     */
    int Size() const
    {
        return this->size;
    }

    /**
     * @brief It will randomize the list.
     * @return void
     */
    void __randomize__()
    {
        if (head_ptr == NULL)
        {
            return;
        }
        // change the position of each node in list randomly
        // it will take O(n^2) time
        Node<dataType> *temp = head_ptr;
        for (int i = 0; i < size; i++)
        {
            int random = rand() % size;
            Node<dataType> *temp2 = head_ptr;
            for (int j = 0; j < random; j++)
            {
                temp2 = temp2->getPtr();
            }
            int temp_val = temp->getVal();
            temp->setVal(temp2->getVal());
            temp2->setVal(temp_val);
            temp = temp->getPtr();
        }
        // put tail_ptr at the end of the list
        temp = head_ptr;
        while (temp->getPtr() != NULL)
        {
            temp = temp->getPtr();
        }
        tail_ptr = temp;
    }

    /**
     * @brief Destroy the linked_list<dataType>:: linked_list object
     * @note It will delete the head_ptr and tail_ptr.
     */
    ~linked_list()
    {
        delete head_ptr;
        delete tail_ptr;
    }
};

int main()
{
    cout << "Enter a Number: ";
    int n;
    cin >> n;
    while (n < 1)
    {
        cout << "Enter a Number greater then Zero: ";
        cin >> n;
    }
    // create a list upto n
    linked_list<int> list;
    for (int i = 1; i <= n; i++)
    {
        list.insertAtEnd(i);
    }
    list.__randomize__();
    cout << "List: ";
    list.printForward();
    bool flag = true;
    while (flag == true)
    {
        cout << "Enter an Index to delete: ";
        int num;
        cin >> num;
        if (num < 1)
        {
            cout << "Enter a Number greater then Zero: ";
            cin >> num;
        }
        if (num > list.Size())
        {
            cout << "Enter a Number less then or equal to " << list.Size() << ": ";
            cin >> num;
        }
        list.remove_node(num - 1);
        cout << "List: ";
        list.printForward();
        if (list.Size() == 1)
        {
            flag = false;
        }
        cout << "Do you want to delete more elements (y/n): ";
        char ch;
        cin >> ch;
        if (ch == 'n')
        {
            flag = false;
        }
    }
    cout << "your current list is: ";
    list.printForward();
    cout << "Missing Numbers: ";
    list.print_missing(n);

    system("pause");
    return 0;
}