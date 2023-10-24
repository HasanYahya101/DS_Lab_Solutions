#include <iostream>
using namespace std;

template <typename dataType>

/**
 * @brief Node class for the Queue
 * @note Time Complexity for this class members is: 1 + 1 + 1: O(1)
 * @note Space Complexity for this class members is: T + T + T, where T is the value for the data type used.
 * @note For char, it is 1 byte, int and float have 4 bytes, each.
 */
class Node
{
public:
    dataType val;         // O(1), time
    Node<dataType> *next; // O(1), time
    Node<dataType> *prev; // O(1), time
};

template <typename dataType>

/**
 * @brief Queue class for the Josephus Problem
 * @note Time Complexity for this class data members is: 1 + 1 + 1: O(1)
 * @note Space Complexity for this class data members depends on the the type of data used. Int is 4, char is 1.
 * @note The space complexity of the whole class, because of nodes will be O(n), where n is the number of nodes.
 */
class Josephus_Queue
{
private:
    Node<dataType> *head; // O(1), time
    Node<dataType> *tail; // O(1), time
    int size;             // O(1), time

public:
    /**
     * @brief Construct a new Josephus_Queue object
     * @note The time complexity for this is, 1+1+1 = O(1).
     *@note The space complexity for this depends on if int or char are used. If int are used, then it is 4+4+4 = 12 bytes.
     */
    Josephus_Queue()
    {
        head = NULL; // 1
        tail = NULL; // 1
        size = 0;    // 1
    }

    /**
     * @brief Pushes the value in the queue
     * @param val The value to be pushed in the queue
     * @note The time complexity for this is, 1+1+1+1+1+1+1+1+1+1+1+1+1+1+1 = O(1).
     * @note The space complexity for this depends on the type of data used.
     */
    void __push__(dataType val)
    {
        Node<dataType> *temp = new Node<dataType>;
        temp->val = val;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    /**
     * @brief Pops the value from the queue
     * @return dataType The value that is popped from the queue
     * @note The time complexity for this is, 1+1+1+1+1+1+1+1+1+1+1+1+1+1+1 = O(1).
     * @note The space complexity for this depends on the dataType used.
     */
    dataType __pop__()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return dataType();
        }
        else
        {
            Node<dataType> *temp = head;
            dataType val = head->val;
            head = head->next;
            delete temp;
            size--;
            return val;
        }
    }

    /**
     * @brief Returns the size of the queue
     * @return int The size of the queue
     * @note The time complexity for this is: O(1).
     * @note The space complexity for this is: 4 bytes, as this will have int by default.
     */
    int __size__()
    {
        return size;
    }

    /**
     * @brief Prints the queue
     * @note The time complexity is O(n), where n is number of nodes.
     */
    void __print__()
    {
        Node<dataType> *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * @brief Destructor for the Queue Class
     * @note Time complexity is O(n).
     */
    ~Josephus_Queue()
    {
        while (head != NULL)
        {
            Node<dataType> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    /**
     * The Time and Space Complexity are as below:
     * Time complexity for this code will be, O(N*S), where N is number of Nodes and S is the number of skips.
     * The space complexity will differ based on if there are int or char used.
     * Space complexity depends on the number of nodes and number of skips.
     */
    Josephus_Queue<int> queue;
    cout << "Enter the Amount of People: ";
    int num;
    cin >> num;
    while (num < 1)
    {
        cout << "Enter a valid number, must be greater then 0: ";
        cin >> num;
    }

    for (int i = 1; i <= num; i++)
    {
        queue.__push__(i);
    }

    cout << "Enter the number of people to be skipped: ";
    int skip;
    cin >> skip;

    while (skip < 1)
    {
        cout << "Enter a valid number, must be greater then 0: ";
        cin >> skip;
    }

    cout << "Your Queue is: " << endl;
    queue.__print__();

    while (queue.__size__() > 1)
    {
        for (int i = 1; i < skip; i++)
        {
            queue.__push__(queue.__pop__());
        }
        cout << queue.__pop__() << " is killed" << endl;
    }

    cout << "The winner is: " << queue.__pop__() << endl
         << endl;

    system("pause");
    return 0;
}