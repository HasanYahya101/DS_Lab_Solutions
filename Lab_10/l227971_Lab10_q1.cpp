#include <iostream>
using namespace std;

class MinHeap // Array Based
{
private:
    int *arr;
    int Max_Size;
    int Current_Size;

    void bubble_up(int i) // A recursive method to heapify a subtree with the root at given index. It maintains heap property during insertion.
    {
        // time complexity of this operation is O(log n)
        if (i == 0)
        {
            return;
        }

        int parent = (i - 1) / 2;

        if (arr[parent] > arr[i])
        {
            swap(arr[parent], arr[i]);
            bubble_up(parent);
        }
    }
    void bubble_down(int i) // A recursive method to heapify a subtree with the root at given index. It maintains
    {
        // time complexity of this operation is O(log n)
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < Current_Size && arr[left] < arr[smallest])
        {
            smallest = left;
        }

        if (right < Current_Size && arr[right] < arr[smallest])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            bubble_down(smallest);
        }
    }

public:
    MinHeap()
    {
        Max_Size = 100;
        Current_Size = 0;
        arr = new int[Max_Size];
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void buildMinHeap()
    {
        for (int i = (Current_Size - 2) / 2; i >= 0; i--)
        {
            bubble_down(i);
        }
    }

    void insertASingleValueInHeap(const int &x)
    {
        if (Current_Size == Max_Size)
        {
            cout << "Heap is full" << endl;
            return;
        }

        arr[Current_Size] = x;
        Current_Size++;
        bubble_up(Current_Size - 1);
    }

    bool isEmpty() const
    {
        if (Current_Size == 0)
        {
            return true;
        }
        return false;
    }

    const int getMin() const // returns minimum value this operation should be performed in O(1)
    {
        if (isEmpty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }

        return arr[0];
    }

    void deleteMin() // deletes minimum value this operation should be performed in O(log n)
    {
        if (isEmpty())
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[0] = arr[Current_Size - 1];
        Current_Size--;
        bubble_down(0); // performed in Log(n)
    }

    void printHeap() const
    {
        for (int i = 0; i < Current_Size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MinHeap()
    {
        delete[] arr;
    }
};

string to_str(bool val)
{
    if (val)
    {
        return "true";
    }
    return "false";
}

int main()
{
    // writing main to test all the functions
    MinHeap min_heap;
    cout << "Inserting 20, 40, 60, 70, 10, 80, 50, 90, 80, 30, 100, 85, 5 in heap" << endl;
    min_heap.insertASingleValueInHeap(20);
    min_heap.insertASingleValueInHeap(40);
    min_heap.insertASingleValueInHeap(60);
    min_heap.insertASingleValueInHeap(70);
    min_heap.insertASingleValueInHeap(10);
    min_heap.insertASingleValueInHeap(80);
    min_heap.insertASingleValueInHeap(50);
    min_heap.insertASingleValueInHeap(90);
    min_heap.insertASingleValueInHeap(80); // duplicate
    min_heap.insertASingleValueInHeap(30);
    min_heap.insertASingleValueInHeap(100);
    min_heap.insertASingleValueInHeap(85);
    min_heap.insertASingleValueInHeap(5);

    cout << "Printing Heap: ";
    min_heap.printHeap();
    cout << endl;

    cout << "Building Min Heap" << endl;
    min_heap.buildMinHeap();

    cout << "Printing Heap: ";
    min_heap.printHeap();

    cout << "Getting Minimum Value: " << min_heap.getMin() << endl;
    cout << "Deleting Minimum Value" << endl;
    min_heap.deleteMin();
    cout << "Printing Heap: ";
    min_heap.printHeap();
    cout << "Getting Minimum Value: " << min_heap.getMin() << endl;

    cout << "Testing isEmpty Function: " << to_str(min_heap.isEmpty()) << endl; // should return "false"
    cout << "Now deleting val in heap and testing isEmpty Function: " << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << "Deleting Minimum Value" << endl;
        min_heap.deleteMin();
        cout << "Printing Heap: ";
        min_heap.printHeap();
    }
    cout << "Testing isEmpty Function: " << to_str(min_heap.isEmpty()) << endl; // should return "true"
    cout << "As you can see the heap is empty now" << endl;
    cout << "The code has all the functionality required, the delete function is made to test the rest of functionality" << endl;

    cout << endl;
    system("pause");
    return 0;
}