#include <iostream>
using namespace std;

template <typename dataType>
class Node
{
public:
    dataType val;         // value of the node
    Node<dataType> *next; // pointer to the next node
    Node<dataType> *prev; // pointer to the previous node
};

template <typename dataType>
class Linked_list
{
private:
    Node<dataType> *head; // pointer to the head of the list
    Node<dataType> *tail; // pointer to the tail of the list
    int size = 0;         // size of the list. It is an Integer

public:
    class Iterator
    {
    private:
        Node<dataType> *current; // pointer to the current node

    public:
        /**
         * @brief Construct a new Iterator object
         * @note Time complexity: O(1).
         * @param node It is a pointer to the current node. It can be of any dataType
         * @return None - It is a constructor
         */
        Iterator(Node<dataType> *node)
        {
            current = node;
        }

        /**
         * @brief Operator overloading of '++' for going to next node.
         * @note Time complexity: O(1).
         * @return Iterator& - It returns the current Iterator
         */
        Iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        /**
         * @brief Operator overloading of '*' for dereferencing the current node.
         * @note Time complexity: O(1).
         * @return Iterator& - It returns the data of the current node
         */
        dataType &operator*()
        {
            return current->val;
        }

        /**
         * @brief Operator overloading of '!=' for comparing two iterators.
         * @param other It is the other iterator to be compared with.
         * @return true - If the iterators are not equal
         * @return false - If the iterators are equal
         */
        bool operator!=(const Iterator &other)
        {
            return current != other.current;
        }
    };

    /**
     * @brief Construct a new Linked_list object
     * @note Time complexity: O(1).
     */
    Linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    /**
     * @brief It pushes the value at the end of the list.
     * @note Time complexity: O(1).
     * @param value It is the value to be pushed at the end of the list.
     */
    void push_back(dataType value)
    {
        Node<dataType> *newNode = new Node<dataType>;
        newNode->val = value;
        newNode->next = nullptr;

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    /**
     * @brief It returns the iterator to the first node of the list.
     * @note Time complexity: O(1).
     * @return Iterator - It returns the iterator to the first node of the list.
     */
    Iterator begin()
    {
        return Iterator(head);
    }

    /**
     * @brief It returns the iterator with nullptr initialised.
     * @return Iterator
     * @note Time complexity: O(1).
     */
    Iterator end()
    {
        return Iterator(nullptr);
    }

    /**
     * @brief It removes the first node with the given value.
     * @note Time complexity: O(n).
     * @param value It is the value to be removed from the list.
     */
    void remove(dataType value)
    {
        Node<dataType> *current = head;
        while (current != nullptr)
        {
            if (current->val == value)
            {
                if (current->prev)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }
                if (current->next)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }
                delete current;
                size--;
                break;
            }
            current = current->next;
        }
    }
};

int main()
{
    Linked_list<int> linkedList;
    linkedList.push_back(10);
    linkedList.push_back(20);
    linkedList.push_back(30);
    linkedList.push_back(40);
    linkedList.push_back(50);

    cout << "Original List (using iterators):" << endl;
    for (auto it = linkedList.begin(); it != linkedList.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    linkedList.push_back(60);

    cout << "List after adding 60 (using iterators):" << endl;
    for (auto it = linkedList.begin(); it != linkedList.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    linkedList.remove(30);

    cout << "List after removing 30 (using iterators):" << endl;
    for (auto it = linkedList.begin(); it != linkedList.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}