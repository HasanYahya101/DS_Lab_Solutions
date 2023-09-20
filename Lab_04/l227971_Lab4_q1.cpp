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
     * @brief Insert a new Node at the start of the list.
     * @param element It can be of any dataType.
     * @return void
     */
    void insertAtStart(dataType const element)
    {
        Node<dataType> *temp = new Node<dataType>(element);
        if (head_ptr == NULL)
        {
            head_ptr = temp;
            tail_ptr = temp;
        }
        else
        {
            temp->setPtr(head_ptr);
            head_ptr = temp;
        }
        size++;
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
     * @brief Delete the first Node of the list.
     * @return void
     */
    void DeleteAtStart() // delete first node
    {
        if (head_ptr == NULL)
        {
            cout << "List is Empty!" << endl;
        }
        else
        {
            Node<dataType> *temp = head_ptr;
            head_ptr = head_ptr->getPtr();
            delete temp;
            size--;
        }
    }

    /**
     * @brief Delete the last Node of the list.
     * @return void
     */
    void DeleteAtEnd()
    {
        if (head_ptr == NULL)
        {
            cout << "List is Empty!" << endl;
        }
        else
        {
            Node<dataType> *temp = head_ptr;
            while (temp->getPtr() != tail_ptr)
            {
                temp = temp->getPtr();
            }
            delete tail_ptr;
            tail_ptr = temp;
            tail_ptr->setPtr(NULL);
            size--;
        }
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
     * @brief Print the list in reverse direction.
     * @return void
     * @note It will first reverse the list in O(n) time and then print it.
     */
    void PrintReverse() // reserve the list in a single loop and then print
    {
        Node<dataType> *temp = head_ptr;
        Node<dataType> *prev = NULL;
        Node<dataType> *next = NULL;
        while (temp != NULL)
        {
            next = temp->getPtr();
            temp->setPtr(prev);
            prev = temp;
            temp = next;
        }
        head_ptr = prev;
        temp = head_ptr;
        // place the tail_ptr at the end
        Node<dataType> *temp_val = head_ptr;
        while (temp_val->getPtr() != NULL)
        {
            temp_val = temp_val->getPtr();
        }
        tail_ptr = temp_val;
        while (temp != NULL)
        {
            temp->print();
            temp = temp->getPtr();
        }
        cout << endl;
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
     * @brief Check if the list is empty or not.
     * @return bool - It returns true if the list is empty else false.
     */
    bool IsEmpty()
    {
        if (head_ptr == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
     * @brief Find the maximum value in the list. It does it in O(n) time.
     * @return int - It returns the maximum value in the list.
     */
    int FindMax() const
    {
        Node<dataType> *temp = head_ptr;
        int max = -1;
        while (temp != NULL)
        {
            if (temp->getVal() > max)
            {
                max = temp->getVal();
            }
            temp = temp->getPtr();
        }
        return max;
    }

    /**
     * @brief Find the middle element of the list. If the number of elements are even then it will return the average of to middle elements.
     * @brief It does it in O(n) time.
     * @return int - It returns the middle element of the list.
     */
    int ReturnMiddle() const
    {
        // if odd return middle element else if even, return average of two middle elements
        if (this->size == 0)
        {
            return -1;
        }
        else if (this->size == 1)
        {
            return head_ptr->getVal();
        }
        else
        {
            Node<dataType> *temp = head_ptr;
            int mid = this->size / 2;
            if (this->size % 2 == 0)
            {
                for (int i = 0; i < mid - 1; i++)
                {
                    temp = temp->getPtr();
                }
                cout << "Size of list is even so, returning the average of middle two elements!" << endl;
                return (temp->getVal() + temp->getPtr()->getVal()) / 2;
            }
            else
            {
                for (int i = 0; i < mid; i++)
                {
                    temp = temp->getPtr();
                }
                return temp->getVal();
            }
        }
    }

    /**
     * @brief Insert a new Node with value key after the first occurrence of value val.
     * @brief If the value val is not found then it will insert the new Node at the end of the list.
     * @param val It can be of any dataType.
     * @param key It can be of any dataType.
     * @return void
     */
    void InsertAfter(int val, int key)
    {
        // It should enter the new Node with the value key, before the first occurrence of value val.
        // If not found insert at Tail
        Node<dataType> *new_node = new Node<dataType>(key);
        Node<dataType> *temp = head_ptr;
        if (head_ptr == NULL)
        {
            head_ptr = new_node;
            tail_ptr = new_node;
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->getVal() == val)
                {
                    new_node->setPtr(temp->getPtr());
                    temp->setPtr(new_node);
                    break;
                }
                temp = temp->getPtr();
            }
            if (temp == NULL)
            {
                tail_ptr->setPtr(new_node);
                tail_ptr = new_node;
            }
        }
    }

    /**
     * @brief Insert a new Node with value key before the first occurrence of value val.
     * @brief If the value val is not found then it will insert the new Node at the end of the list.
     * @param val It can be of any dataType.
     * @param key It can be of any dataType.
     * @return void
     */
    void InsertBefore(int val, int key)
    {
        // It should enter the new Node with the value key, before the first occurrence of value val.
        // If not found insert at Tail
        Node<dataType> *new_node = new Node<dataType>(key);
        Node<dataType> *temp = head_ptr;
        if (head_ptr == NULL)
        {
            head_ptr = new_node;
            tail_ptr = new_node;
        }
        else
        {
            while (temp->getPtr() != NULL)
            {
                if (temp->getPtr()->getVal() == val)
                {
                    new_node->setPtr(temp->getPtr());
                    temp->setPtr(new_node);
                    break;
                }
                temp = temp->getPtr();
            }
            if (temp->getPtr() == NULL)
            {
                temp->setPtr(new_node);
                tail_ptr = new_node;
            }
        }
    }

    /**
     * @brief Insert a new Node with value val in sorted order.
     * @brief If the list is empty then it will insert the new Node at the start of the list.
     * @param val It can be of any dataType.
     * @return void
     */
    void insertSorted(dataType val) // ascending order
    {
        // that takes an element as argument and inserts in linked list in sorted order
        // (ascending order). If the list is empty, it should insert at the start.
        Node<dataType> *new_node = new Node<dataType>(val);
        Node<dataType> *temp = head_ptr;
        if (head_ptr == NULL)
        {
            head_ptr = new_node;
            tail_ptr = new_node;
        }
        else if (head_ptr->getVal() > val)
        {
            new_node->setPtr(head_ptr);
            head_ptr = new_node;
        }
        else
        {
            while (temp->getPtr() != NULL)
            {
                if (temp->getPtr()->getVal() > val)
                {
                    new_node->setPtr(temp->getPtr());
                    temp->setPtr(new_node);
                    break;
                }
                temp = temp->getPtr();
            }
            if (temp->getPtr() == NULL)
            {
                temp->setPtr(new_node);
                tail_ptr = new_node;
            }
        }
    }

    /**
     * @brief Delete all duplicate elements from the linked list. It will only traverse the list once.
     * @return void
     */
    void DeleteDuplicates() // traverse only once
    {
        // that deletes all duplicate elements from the linked list.
        // For example, if the list contains 1, 2, 2, 3, 4, 4, 4, 5, 6, 6
        // then after calling this function, the list should contain 1, 2, 3, 4, 5, 6.
        Node<dataType> *temp = head_ptr;
        Node<dataType> *prev = NULL;
        while (temp != NULL)
        {
            if (prev != NULL && prev->getVal() == temp->getVal())
            {
                prev->setPtr(temp->getPtr());
                delete temp;
                temp = prev->getPtr();
            }
            else
            {
                prev = temp;
                temp = temp->getPtr();
            }
        }
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
    linked_list<int> list_temp;
    cout << "The current list is Empty: ";
    if (list_temp.IsEmpty() == true)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << "Entering, 1, 2, 3, 4... at start" << endl;
    list_temp.insertAtStart(1);
    list_temp.insertAtStart(2);
    list_temp.insertAtStart(3);
    list_temp.insertAtStart(4);
    cout << "Entering 7, 8, 9 at the end..." << endl;
    list_temp.insertAtEnd(7);
    list_temp.insertAtEnd(8);
    list_temp.insertAtEnd(9);
    cout << "The list currently is: " << endl;
    list_temp.printForward();
    cout << "The Max Value in list is: " << list_temp.FindMax() << endl;
    cout << "The current list is Empty: ";
    if (list_temp.IsEmpty() == true)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << "The Middle Element of List is: " << list_temp.ReturnMiddle() << endl;
    cout << "Deleting the first element..." << endl;
    list_temp.DeleteAtStart();
    cout << "Deleting the last element..." << endl;
    list_temp.DeleteAtEnd();
    cout << "The list currently is: " << endl;
    list_temp.printForward();
    cout << "Reverse List is: ";
    list_temp.PrintReverse();
    cout << "The list currently is: " << endl;
    list_temp.printForward();
    cout << "Now adding 5 after 1..." << endl;
    list_temp.InsertAfter(1, 5);
    cout << "Now adding 6 before 7..." << endl;
    list_temp.InsertBefore(7, 6);
    cout << "Now adding 10 after 0..." << endl;
    list_temp.InsertAfter(0, 10);
    cout << "Now adding 11 before 9..." << endl;
    list_temp.InsertBefore(9, 11);
    cout << "The list currently is: " << endl;
    list_temp.printForward();
    cout << "Creating a new list with elements, 1, 2, 3, 4, 6" << endl;
    linked_list<int> list_temp2(1);
    list_temp2.insertAtEnd(2);
    list_temp2.insertAtEnd(3);
    list_temp2.insertAtEnd(4);
    list_temp2.insertAtEnd(6);
    cout << "The list currently is: " << endl;
    list_temp2.printForward();
    cout << "Adding 5 in sorted order..." << endl;
    list_temp2.insertSorted(5);
    cout << "The list currently is: " << endl;
    list_temp2.printForward();
    cout << "Creating Another ist with elements 1, 1, 1, 2, 3, 4, 5" << endl;
    linked_list<int> list_temp3(1);
    list_temp3.insertAtEnd(1);
    list_temp3.insertAtEnd(1);
    list_temp3.insertAtEnd(2);
    list_temp3.insertAtEnd(3);
    list_temp3.insertAtEnd(4);
    list_temp3.insertAtEnd(5);
    cout << "The list currently is: " << endl;
    list_temp3.printForward();
    cout << "Deleting Duplicates..." << endl;
    list_temp3.DeleteDuplicates();
    cout << "The list currently is: " << endl;
    list_temp3.printForward();

    system("pause");
    return 0;
}