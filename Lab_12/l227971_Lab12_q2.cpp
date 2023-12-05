#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int key;
    string name;
};

class DoubleHashingHashTable
{
private:
    Student *hashArray;
    int size;

public:
    DoubleHashingHashTable(int tableSize)
    {
        size = tableSize;
        hashArray = new Student[size];
        for (int i = 0; i < size; i++)
        {
            // initializing all keys to -1
            hashArray[i].key = -1;
        }
    }

    int hash1(int key)
    {
        return key % size;
    }

    int hash2(int key)
    {
        // Using a simple secondary hash function for demonstration
        return 1 + (key % (size - 1));
    }

    int getNextCandidateIndex(int key, int i)
    {
        int step = hash2(key);
        return (hash1(key) + i * step) % size;
    }

    void insert(int key, string name)
    {
        int index = hash1(key);
        int i = 0;
        while (hashArray[index].key != -1)
        {
            cout << "Collision occurred at index " << index << endl;
            index = getNextCandidateIndex(key, ++i);
        }
        hashArray[index] = {key, name};
        cout << "Inserted " << name << " at index " << index << endl;
    }

    void displayTable()
    {
        for (int i = 0; i < size; i++)
        {
            if (hashArray[i].key != -1)
            {
                cout << "Index " << i << ": " << hashArray[i].key << " - " << hashArray[i].name << endl;
            }
            else
            {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

int main()
{
    cout << "The size of array is 10" << endl;
    cout << "DOUBLE HASHING\n";
    DoubleHashingHashTable hashTable(10);
    hashTable.insert(101, "Alice");
    hashTable.insert(201, "Bob");
    hashTable.insert(301, "Charlie");
    hashTable.insert(401, "David");

    cout << "Displaying the hash table:\n";
    hashTable.displayTable();
    cout << endl;

    system("pause");
    return 0;
}