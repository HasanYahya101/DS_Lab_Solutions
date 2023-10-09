#include <iostream>
using namespace std;

/**
 * @brief DataType is a Template class which can be of any DataType
 */
template <typename dataType>

class Stack_List
{
private:
    /**
     * @brief Node is a struct which contains data and a pointer to the next node.
     * @brief It is a private member of the Stack_List class.
     * @brief It has a Constructor, Destructor and a Parameterized Constructor.
     */
    struct Node
    {
        dataType data; // data stored, it can be of any DataType
        Node *next;    // pointer to the next node
        /**
         * @brief Construct a new Node object
         * @brief It sets the next pointer to NULL
         * @param none No parameter is passed
         * @return none No value is returned
         * @note The time complexity is O(1)
         */
        Node()
        {
            next = NULL;
        }

        /**
         * @brief Construct a new Node object
         * @brief It sets the data and next pointer to the passed values. It is a parameterized constructor.
         * @param d It is the data to be stored in the node
         * @param n It is the pointer to the next node
         * @return none No value is returned
         * @note The time complexity is O(1)
         */
        Node(dataType d, Node *n = NULL)
        {
            data = d;
            next = n;
        }

        /**
         * @brief Destroy the Node object
         * @brief It deletes the next pointer
         * @param none No parameter is passed
         * @return none No value is returned
         * @note The time complexity is O(1)
         */
        ~Node()
        {
            delete next;
        }
    };
    Node *top; // head of the stack.
    int size;  // size of the stack, ie the total elements.

public:
    /**
     * @brief Construct a new Stack_List object.
     * @brief It sets the top pointer to NULL and size to 0.
     * @param none No parameter is passed
     * @return none No value is returned
     * @note The time complexity is O(1)
     */
    Stack_List()
    {
        top = NULL;
        size = 0;
    }

    /**
     * @brief It returns the size of the stack.
     * @param none No parameter is passed
     * @return int It returns the size of the stack
     * @note The time complexity is O(1)
     */
    int __size__()
    {
        return size;
    }

    /**
     * @brief It checks if the stack is empty or not.
     * @param none No parameter is passed
     * @return bool It returns true if the stack is empty, else false.
     * @note The time complexity is O(1)
     */
    bool __isEmpty__()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
     * @brief It returns the top element of the stack through the parameter passed.
     * @param __to_pass__ It is the variable in which the top element is passed.
     * @return bool It returns true if the stack is not empty, else false.
     * @note The time complexity is O(1)
     */
    bool __top__(dataType &__to_pass__)
    {
        if (top == NULL)
        {
            return false;
        }
        else
        {
            __to_pass__ = top->data;
            return true;
        }
    }

    /**
     * @brief It prints the stack.
     * @param none No parameter is passed
     * @return none No value is returned
     * @note The time complexity is O(n)
     */
    void __print__()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    /**
     * @brief It pops the top element of the stack.
     * @param none No parameter is passed
     * @return none No value is returned
     * @note The time complexity is O(1)
     * @note It does not return the popped element.
     */
    void __pop__()
    {
        if (top == NULL)
        {
            return;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
    }

    /**
     * @brief It pushes the passed element to the stack.
     * @param val It is the element to be pushed to the stack.
     * @return none No value is returned
     * @note The time complexity is O(1)
     * @note It does not return the pushed element.
     */
    void __push__(dataType const &val)
    {
        Node *temp = new Node(val, top);
        top = temp;
        size++;
    }

    /**
     * @brief Destroy the Stack_List object
     * @brief It deletes the top pointer
     * @param none No parameter is passed
     * @return none No value is returned
     * @note The time complexity is O(1)
     */
    ~Stack_List()
    {
        delete top;
    }
};

int main() // testing the main functionality of stack class
{
    cout << "Testing Stack_List class" << endl;
    Stack_List<int> stack_temp;
    cout << "Pushing 1, 2, 3, 4, 5" << endl;
    stack_temp.__push__(1);
    stack_temp.__push__(2);
    stack_temp.__push__(3);
    stack_temp.__push__(4);
    stack_temp.__push__(5);
    cout << "Printing stack: " << endl;
    stack_temp.__print__();
    cout << "The size of the Stack is: " << stack_temp.__size__() << endl;
    cout << "Poping 2 times" << endl;
    stack_temp.__pop__();
    stack_temp.__pop__();
    cout << "Printing stack: " << endl;
    stack_temp.__print__();
    cout << "Testing top function" << endl;
    int temp;
    stack_temp.__top__(temp);
    cout << "The top element is: " << temp << endl;
    cout << "Printing the Stack: " << endl;
    stack_temp.__print__();
    cout << "Testing isEmpty function" << endl;
    if (stack_temp.__isEmpty__())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    cout << endl;

    system("pause");
    return 0;
}