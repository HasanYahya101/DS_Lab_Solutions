#include <iostream>
using namespace std;

/**
 * A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. This List is Array Based.
 * @param size Size of list
 * @param array Array to store list elements
 * @param maxsize Maximum size of list
 * @param listsize Current no of list items
 */
class linked_list
{
private:
    int *array;
    int maxsize;  // Maximum size of list
    int listsize; // Current # of list items
    int currsize; // Position of current element

public:
    /**
     * Constructor to initialize list
     * @param size Size of list
     */
    linked_list(int size)
    {
        maxsize = size;
        array = new int[maxsize];
        listsize = 0;
        currsize = -1;
    }

    /**
     * Insert element at start of list
     * @param num Number to insert
     * @return void
     */
    void insert_at_start(int num) // insert element at start of list
    {
        if (listsize >= maxsize)
        {
            cout << "List is full" << endl;
            int choice;
            cout << "1. Delete at start" << endl;
            cout << "2. Add new Node at Start" << endl; // resize array
            cout << "Enter choice: ";
            cin >> choice;
            while (choice != 1 && choice != 2)
            {
                cout << "Invalid choice" << endl;
                cout << "Enter choice: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                delete_at_start();
                insert_at_start(num);
            }
            else
            {
                int *temp = new int[maxsize + 1];
                for (int i = 0; i < listsize; i++)
                {
                    temp[i + 1] = array[i];
                }
                temp[0] = num;
                delete[] array;
                array = temp;
                listsize++;
                currsize++;
            }
            return;
        }
        else
        {
            for (int i = listsize; i > 0; i--)
            {
                array[i] = array[i - 1];
            }
            array[0] = num;
            listsize++;
            currsize++;
        }
    }

    /**
     * Insert element at end of list
     * @param num Number to insert
     * @return void
     */
    void insert_at_end(int num) // insert element at end of list
    {
        if (listsize >= maxsize)
        {
            cout << "List is full" << endl;
            int choice;
            cout << "1. Delete at end" << endl;
            cout << "2. Add new Node at end" << endl; // resize array
            cout << "Enter choice: ";
            cin >> choice;
            while (choice != 1 && choice != 2)
            {
                cout << "Invalid choice" << endl;
                cout << "Enter choice: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                delete_at_end();
                insert_at_end(num);
            }
            else
            {
                int *temp = new int[maxsize + 1];
                for (int i = 0; i < listsize; i++)
                {
                    temp[i] = array[i];
                }
                temp[listsize] = num;
                delete[] array;
                array = temp;
                listsize++;
                currsize++;
            }
            return;
        }
        else
        {
            array[listsize] = num;
            listsize++;
            currsize++;
        }
    }

    /**
     * Delete element at start of list
     * @return void
     */
    void delete_at_start()
    {
        if (listsize == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < listsize - 1; i++)
            {
                array[i] = array[i + 1];
            }
            listsize--;
            currsize--;
        }
    }

    /**
     * Delete element at end of list
     * @return void
     */
    void delete_at_end()
    {
        if (listsize == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            listsize--;
            currsize--;
        }
    }

    /**
     * Print all elements of the list
     * @return void
     */
    void print()
    {
        if (listsize == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < listsize; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }

    /**
     * Insert element after a given key
     * @param val Value to insert
     * @param key Key (number) after which to insert
     * @return void
     */
    void insert_after(int val, int key)
    {
        if (listsize >= maxsize)
        {
            cout << "List is full" << endl;
            int choice;
            cout << "1. Delete at end" << endl;
            cout << "2. Add new Node at end" << endl; // resize array
            cout << "Enter choice: ";
            cin >> choice;
            while (choice != 1 && choice != 2)
            {
                cout << "Invalid choice" << endl;
                cout << "Enter choice: ";
                cin >> choice;
            }
            if (choice == 1)
            {
                delete_at_end();
                // insert value after key
                for (int i = 0; i < listsize; i++)
                {
                    if (array[i] == key)
                    {
                        for (int j = listsize; j > i + 1; j--)
                        {
                            array[j] = array[j - 1];
                        }
                        array[i + 1] = val;
                        listsize++;
                        currsize++;
                        return;
                    }
                }
                cout << "Key not found" << endl;
            }
            else
            {
                // still insert after the key
                for (int i = 0; i < listsize; i++)
                {
                    if (array[i] == key)
                    {
                        for (int j = listsize; j > i + 1; j--)
                        {
                            array[j] = array[j - 1];
                        }
                        array[i + 1] = val;
                        listsize++;
                        currsize++;
                        return;
                    }
                }
                cout << "Key not found" << endl;
            }
            return;
        }
        else
        {
            for (int i = 0; i < listsize; i++)
            {
                if (array[i] == key)
                {
                    for (int j = listsize; j > i + 1; j--)
                    {
                        array[j] = array[j - 1];
                    }
                    array[i + 1] = val;
                    listsize++;
                    currsize++;
                    return;
                }
            }
            cout << "Key not found" << endl;
        }
    }

    /**
     * Find Largest Number in the list
     * @return Maximum element as int
     */
    int Find_Max()
    {
        if (listsize == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        else
        {
            int max = array[0];
            for (int i = 1; i < listsize; i++)
            {
                if (array[i] > max)
                {
                    max = array[i];
                }
            }
            return max;
        }
    }

    /**
     * Get size of list
     * @return Size of list as int
     */
    int size()
    {
        return listsize + 1;
    }

    /**
     * Destructor to free memory
     */
    ~linked_list()
    {
        if (array != NULL)
        {
            delete[] array;
        }
    }
};

int main()
{
    int size;
    cout << "Enter size of list: ";
    cin >> size;
    linked_list list(size);
    int choice;
    int num;
    int key;
    while (1)
    {
        cout << "1. Insert at start" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Delete at start" << endl;
        cout << "4. Delete at end" << endl;
        cout << "5. Print list" << endl;
        cout << "6. Insert after" << endl;
        cout << "7. Find max" << endl;
        cout << "8. Size of list" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> num;
            list.insert_at_start(num);
            break;
        case 2:
            cout << "Enter number: ";
            cin >> num;
            list.insert_at_end(num);
            break;
        case 3:
            list.delete_at_start();
            break;
        case 4:
            list.delete_at_end();
            break;
        case 5:
            list.print();
            break;
        case 6:
            cout << "Enter number to Insert: ";
            cin >> num;
            cout << "Enter value to insert after: ";
            cin >> key;
            list.insert_after(num, key);
            break;
        case 7:
            cout << "Max: " << list.Find_Max() << endl;
            break;
        case 8:
            cout << "Size: " << list.size() << endl;
            break;
        case 9:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }

    cout << endl;
    system("pause");
    return 0;
}