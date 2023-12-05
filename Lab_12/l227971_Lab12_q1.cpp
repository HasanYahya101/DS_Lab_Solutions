#include <iostream>
#include <string>
using namespace std;

struct KeyValue
{
    int key;
    string value;
};

class HashMap
{
protected:
    KeyValue *hashArray;
    int size;

public:
    HashMap()
    {
        size = 10;
        hashArray = new KeyValue[size];
        for (int i = 0; i < size; i++)
        {
            // initializing all keys to -1
            hashArray[i].key = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    virtual int getNextCandidateIndex(int key, int i)
    {
        return (hashFunction(key) + i) % size;
    }

    void insert(int key, string value)
    {
        int index = hashFunction(key);
        int i = 0;
        while (hashArray[index].key != -1 && hashArray[index].key != key)
        {
            cout << "Collision occurred at index " << index << endl;
            index = getNextCandidateIndex(key, ++i);
        }
        hashArray[index] = {key, value};
        cout << "Inserted " << value << " at index " << index << endl;
    }

    KeyValue *getHashArray()
    {
        return hashArray;
    }
};

class QHashMap : public HashMap
{
public:
    int getNextCandidateIndex(int key, int i) override
    {
        return (hashFunction(key) + i * i) % size;
    }
};

int main()
{
    cout << "Note i am using array of size 10" << endl;
    cout << "LINEAR PROBING\n";
    HashMap *map = new HashMap;
    map->insert(89, "hassan");
    map->insert(18, "ali");
    map->insert(49, "ayaan");
    map->insert(58, "ahsan");
    map->insert(69, "baber");

    cout << "QUADRATIC PROBING\n";
    QHashMap *Qmap = new QHashMap;
    Qmap->insert(89, "hassan");
    Qmap->insert(18, "ali");
    Qmap->insert(49, "ayaan");
    Qmap->insert(58, "ahsan");
    Qmap->insert(69, "baber");

    cout << endl
         << endl;

    cout << "You can see that in Quadratic Probing, the collision is handled better than Linear Probing\n";
    cout << "The collison for last 2 are handled at index 1 and 2 in Linear Probing\n";
    cout << "The collison for last 2 are handled at index 2 and 3 in Quadratic Probing\n";
    cout << endl;

    system("pause");
    return 0;
}