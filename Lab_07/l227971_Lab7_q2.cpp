#include <iostream>
using namespace std;

template <typename dataType>

class Node
{
public:
    dataType val;
    Node<dataType> *next;
    Node<dataType> *prev;
};

template <typename dataType>

class Queue
{
private:
    Node<dataType> *head;
    Node<dataType> *tail;
    int size;

public:
    /**
     * @brief Construct a new Queue object
     * @note Time Complexity is O(1).
     */
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /**
     * @brief Pushes an element to the queue
     * @note Time Complexity: O(1)
     */
    void __push__(dataType val)
    {
        if (head == nullptr)
        {
            head = new Node<dataType>;
            head->val = val;
            head->next = nullptr;
            head->prev = nullptr;
            tail = head;
        }
        else
        {
            Node<dataType> *temp = new Node<dataType>;
            temp->val = val;
            temp->next = nullptr;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    /**
     * @brief Removes the first element from the queue
     * @note Time Complexity: O(1)
     */
    dataType __pop__()
    {
        if (head == nullptr)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
        {
            Node<dataType> *temp = head;
            dataType val = head->val;
            head = head->next;
            delete temp;
            head->prev = nullptr;
            size--;
            return val;
        }
    }

    /**
     * @brief Reverses the first K elements of the queue
     * @note Time Complexity: O(K), where K is the number of elements to be reversed
     */
    void reverse_first_k_elements(int K)
    {
        /*
        Example:
        Input:
        queue elements: 1, 2, 3, 4, 5
        K = 3
        Output: Modified queue: 3, 2, 1, 4, 5
        */

        if (K < 0)
        {
            K = 0;
        }

        if (K == 0)
        {
            return;
        }

        if (K > this->size)
        {
            K = this->size;
        }

        Node<dataType> *temp = head;
        Node<dataType> *temp2 = nullptr;
        Node<dataType> *temp3 = nullptr;

        for (int i = 0; i < K; i++)
        {
            temp2 = temp->next;
            temp->next = temp3;
            temp3 = temp;
            temp = temp2;
        }

        head->next = temp;
        head = temp3;

        if (K == this->size)
        {
            tail = temp3;
        }

        return;
    }

    /**
     * @brief Prints the queue
     * @note Time Complexity: O(N), where N is the number of elements in the queue
     */
    void __print__()
    {
        Node<dataType> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * @brief Returns the size of the queue
     * @note Time Complexity: O(1)
     */
    int __size__()
    {
        return this->size;
    }

    /**
     * @brief Destroy the Queue object
     * @note Time Complexity: O(N), where N is the number of elements in the queue
     */
    ~Queue()
    {
        while (head != nullptr)
        {
            Node<dataType> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template <typename dataType>

/**
 * @brief Reverses the first K elements of the queue
 * @note Time Complexity: O(K), where K is the number of elements to be reversed
 */
void reverse_first_k_elements(Queue<dataType> &queue, int &K)
{
    queue.reverse_first_k_elements(K);
}

int main()
{
    cout << "Creating 3 queues and putting elements 1 to 10 in them" << endl;
    Queue<int> queue_1;
    Queue<int> queue_2;
    Queue<int> queue_3;

    for (int i = 1; i <= 10; i++)
    {
        queue_1.__push__(i);
        queue_2.__push__(i);
        queue_3.__push__(i);
    }

    cout << "Printing Queue 1" << endl;
    queue_1.__print__();

    cout << "Now reversing the first 7 elements of Queue 1" << endl;
    int K = 7;
    reverse_first_k_elements(queue_1, K);
    cout << "Printing the Queue Again" << endl;
    queue_1.__print__();

    cout << "Now taking the second queue" << endl;
    queue_2.__print__();

    cout << "Now reversing the first 0 elements of Queue 2" << endl;
    K = 0;
    reverse_first_k_elements(queue_2, K);
    cout << "Printing the Queue Again" << endl;
    queue_2.__print__();
    cout << "Now reversing the first -1 elements of Queue 2" << endl;
    K = -1;
    reverse_first_k_elements(queue_2, K);
    cout << "Printing the Queue Again" << endl;
    queue_2.__print__();

    cout << "Now taking the third queue" << endl;
    queue_3.__print__();
    cout << "Now reversing the first 15 elements of Queue 3" << endl;
    K = 15;
    reverse_first_k_elements(queue_3, K);
    cout << "Printing the Queue Again" << endl;
    queue_3.__print__();

    cout << endl
         << "As you can see all Rules are followed" << endl;

    system("pause");
    return 0;
}
