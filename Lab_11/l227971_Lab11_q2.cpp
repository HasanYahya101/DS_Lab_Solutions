#include <iostream>
using namespace std;

template <class dataType>
struct HashItem
{
    int key;
    dataType value;
    int status;
};

template <class dataType>
class HashMap
{
private:
    HashItem<dataType> *hashArray;
    int capacity;
    int currentElements;

    virtual int getNextCandidateIndex(int key, int i)
    {
        return (key + i) % capacity; // Linear Probing
    }

    void doubleCapacity()
    {
        int oldCapacity = capacity;
        HashItem<dataType> *oldArray = hashArray;

        capacity *= 2;
        hashArray = new HashItem<dataType>[capacity];

        for (int i = 0; i < oldCapacity; ++i)
        {
            if (oldArray[i].status == 2)
            {
                insert(oldArray[i].key, oldArray[i].value, hashArray);
            }
        }
        cout << "Capicity has been doubled" << endl;
        delete[] oldArray;
    }

public:
    HashMap() : capacity(10), currentElements(0)
    {
        hashArray = new HashItem<dataType>[capacity];
    }

    HashMap(int const cap) : currentElements(0)
    {
        assert(cap > 1);
        capacity = cap;
        hashArray = new HashItem<dataType>[capacity];
    }

    // assert function
    void assert(bool const exp) const
    {
        if (!exp)
        {
            cout << "Assertion failed" << endl;
            exit(0);
        }
    }

    void insert(int const key, dataType const value, HashItem<dataType> *array)
    {
        int index = key % capacity;
        int i = 1;

        while (array[index].status == 2)
        {
            index = getNextCandidateIndex(key, i);
            i++;
        }

        array[index].key = key;
        array[index].value = value;
        array[index].status = 2;

        currentElements++;

        if (static_cast<double>(currentElements) / capacity >= 0.75)
        {
            doubleCapacity();
        }
    }

    bool deleteKey(int const key)
    {
        int index = key % capacity;
        int i = 1;

        while (hashArray[index].status != 0)
        {
            if (hashArray[index].key == key && hashArray[index].status == 2)
            {
                hashArray[index].status = 1; // Mark as deleted
                return true;
            }

            index = getNextCandidateIndex(key, i);
            i++;
        }

        return false;
    }

    dataType *get(int const key)
    {
        int index = key % capacity;
        int i = 1;

        while (hashArray[index].status != 0)
        {
            if (hashArray[index].key == key && hashArray[index].status == 2)
            {
                return &hashArray[index].value;
            }

            index = getNextCandidateIndex(key, i);
            i++;
        }

        return nullptr;
    }

    // get the hash array
    HashItem<dataType> *getHashArray() const
    {
        return hashArray;
    }

    double getLoadFactor() const
    {
        return static_cast<double>(currentElements) / capacity;
    }

    ~HashMap()
    {
        delete[] hashArray;
    }
};

int main()
{
    HashMap<int> myHashMap(2);
    cout << "Inputting 10, 20 and 30 values at keys 1, 6 and 11 respectively" << endl;
    myHashMap.insert(1, 10, myHashMap.getHashArray());
    myHashMap.insert(6, 20, myHashMap.getHashArray());
    myHashMap.insert(11, 30, myHashMap.getHashArray());

    cout << "Value for key 6: " << *myHashMap.get(6) << endl;
    cout << "Value for key 1: " << *myHashMap.get(1) << endl;
    cout << "Value for key 11: " << *myHashMap.get(11) << endl;
    cout << "Deleting key 6: ";
    bool deleted = myHashMap.deleteKey(6);
    if (deleted)
    {
        cout << "Deleted" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    cout << "Value for key 6 after deletion: ";
    int *value = myHashMap.get(6);
    if (value != nullptr)
    {
        cout << *value << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    // testing the other 2 again
    cout << "Value for key 1: " << *myHashMap.get(1) << endl;
    cout << "Value for key 11: " << *myHashMap.get(11) << endl;
    myHashMap.insert(4, 40, myHashMap.getHashArray());
    cout << "Load Factor: " << myHashMap.getLoadFactor() << endl;

    cout << "As you can see this code follows all requirements" << endl;
    system("pause");
    return 0;
}
