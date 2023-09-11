#include <iostream>
using namespace std;

template <class T>
class my_vector
{
    int size;
    int capacity;
    T *arr;

public:
    my_vector()
    {
        size = -1;
        capacity = 1;
        arr = new T[capacity];
    }
    void push_back(T val)
    {
        // Double the array size if it is filled
        if (size == capacity - 1)
        {
            T *temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[size + 1] = val;
        size++;
    }

    T pop_back(void)
    {
        // Reduce array by half if it is half empty
        if (size <= (capacity / 2))
        {
            T *temp = new T[capacity / 2];
            for (int i = 0; i < capacity / 2; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity /= 2;
            arr = temp;
        }
        size--;
        return arr[size + 1];
    }

    // copy constructor for deep copy
    my_vector(const my_vector &obj)
    {
        size = obj.size;
        capacity = obj.capacity;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = obj.arr[i];
        }
    }

    // + operator that adds given int into each element of array
    my_vector operator+(int val)
    {
        my_vector temp;
        temp.size = size;
        temp.capacity = capacity;
        temp.arr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp.arr[i] = arr[i] + val;
        }
        return temp;
    }

    // + operator that takes vector object and concatinates both arrays
    my_vector operator+(my_vector &obj)
    {
        my_vector temp;
        temp.size = size + obj.size + 1;
        temp.capacity = capacity + obj.capacity;
        temp.arr = new T[temp.capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp.arr[i] = arr[i];
        }
        for (int i = 0; i < obj.capacity; i++)
        {
            temp.arr[i + capacity] = obj.arr[i];
        }
        return temp;
    }

    // = operator for deep copy and if a value is already allocated then delete it first
    my_vector operator=(my_vector &obj)
    {
        if (arr != NULL)
        {
            delete[] arr;
        }
        size = obj.size;
        capacity = obj.capacity;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = obj.arr[i];
        }
        return *this;
    }

    // [index] operator that puts value at given index and returns bool
    bool operator[](int index)
    {
        if (index < 0 || index > size)
        {
            return false;
        }
        arr[index] = rand() % 100;
        return true;
    }

    // << operator which takes as input the elements of myVector.
    friend ostream &operator<<(ostream &out, my_vector &obj)
    {
        for (int i = 0; i < obj.capacity; i++)
        {
            out << obj.arr[i] << "\t";
        }
        return out;
    }

    // >> operator which prints the elements of myVector.
    friend istream &operator>>(istream &in, my_vector &obj)
    {
        for (int i = 0; i < obj.capacity; i++)
        {
            in >> obj.arr[i];
        }
        return in;
    }

    // getter
    int get_size(void)
    {
        return size + 1;
    }

    // getter
    int get_capacity(void)
    {
        return capacity;
    }

    void display_list(void)
    {
        cout << "Elements present in list are:\n";
        for (int i = 0; i < size + 1; i++) // changed from capacity to size + 1
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    // destructor
    ~my_vector()
    {
        if (arr != NULL)
        {
            delete[] arr;
        }
    }
};

int main()
{
    my_vector<int> list;
    for (int i = 0; i < 8; i++) // creates 8 elements
    {
        list.push_back(i + 1);
        list.display_list();
    }

    for (int j = 0; j <= 4; j++) // removes 5 elements
    {
        cout << "Extracted \t" << list.pop_back() << "\t from list" << endl;
        list.display_list();
    }

    system("pause");
    return 0;
}
