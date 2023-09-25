#include <iostream>
using namespace std;

class JosephusList;

class PersonNode
{
    friend class JosephusList;

private:
    int id;
    PersonNode *next;
};

class JosephusList
{
private:
    PersonNode *head;

public:
    /**
     * @brief Construct a new Josephus List object
     * @note Time Complexity: O(1)
     */
    JosephusList()
    {
        head = NULL;
    }

    /**
     * @brief Adds a new node at the end of the list
     * @note Time Complexity: O(n)
     * @return void
     */
    void addAtLast()
    {
        PersonNode *newNode = new PersonNode;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            newNode->id = 1;
        }
        else
        {
            PersonNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->id = temp->id + 1;
        }
    }

    /**
     * @brief Makes the list circular
     * @note Time Complexity: O(n)
     * @return void
     */
    void toCircular()
    {
        PersonNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
    }

    /**
     * @brief Finds the winner of the game. It skips k people before elimination each time untill only one person is left.
     * @note Time Complexity: O(nk)
     * @param k Number of people to skip before elimination
     * @return int The id of the winner
     */
    int findWinner(int k)
    {
        cout << "Elimination Order: ";
        PersonNode *temp = head;
        PersonNode *prev = NULL;
        while (temp->next != temp)
        {
            if (k != 0)
            {
                for (int i = 0; i < k; i++)
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
            else
            {
                // When k = 0, eliminate the first person
                prev = temp;
                while (prev->next != temp)
                {
                    prev = prev->next;
                }
            }
            cout << temp->id << " ";
            prev->next = temp->next;
            if (temp == head)
            {
                head = temp->next;
            }
            delete temp;
            temp = prev->next;
        }
        cout << endl;
        return temp->id;
    }

    /**
     * @brief Prints the list
     * @note Time Complexity: O(n)
     * @return void
     */
    void print()
    {
        PersonNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * @brief Destroy the Josephus List object
     */
    ~JosephusList()
    {
        delete head;
    }
};

int main()
{
    JosephusList list;
    cout << "How many Members should be in the Game: ";
    int n;
    cin >> n;
    while (n < 2)
    {
        cout << "Please enter a number greater than 1: ";
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        list.addAtLast();
    }
    cout << "The order of the members in the game is: ";
    list.print();
    list.toCircular(); // making the list circular
    cout << "Enter Number to skip before Elimination: ";
    int k;
    cin >> k;
    while (k < 0)
    {
        cout << "Please enter a number greater than -1: ";
        cin >> k;
    }
    int winner = list.findWinner(k);
    cout << "The Winner is: " << winner << endl;

    cout << endl;
    system("pause");
    return 0;
}