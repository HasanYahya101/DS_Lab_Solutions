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
    void heapSort(int *arr, int N)
    {
        // Build a min heap using the given array
        for (int i = 0; i < N; i++)
        {
            insertASingleValueInHeap(arr[i]);
        }

        // Extract elements from the heap one by one
        for (int i = 0; i < N; i++)
        {
            arr[i] = getMin();
            deleteMin();
        }
    }

    void heapSortDescending(int *arr, int n)
    {
        // Build a min heap using the given array
        for (int i = 0; i < n; i++)
        {
            insertASingleValueInHeap(arr[i]);
        }

        // Extract elements from the heap one by one and store in reverse order
        for (int i = n - 1; i >= 0; i--)
        {
            arr[i] = getMin();
            deleteMin();
        }
    }

    void printSmallerThan(int *arr, int n, int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < x)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

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

int main()
{
    cout << "Entering 20, 40, 100, 85, 5, 80, 50, 90, 80, 30 (10 Numbers) in an array" << endl;
    int arr[10] = {20, 40, 100, 85, 5, 80, 50, 90, 80, 30};
    MinHeap heap;
    cout << "Printing the Unsorted Current Array" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Testing the Heap Sort Function" << endl;
    heap.heapSort(arr, 10);
    cout << "Printing the Heap Sorted Array" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nTesting the Heap Sort Descending Function" << endl;
    MinHeap heap2;
    heap2.heapSortDescending(arr, 10);
    cout << "Printing the Heap Sorted Descending Array" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nNow creating another array of 10 numbers and entering 20, 40, 100, 85, 5, 80, 50, 90, 80, 30" << endl;
    int arr2[10] = {20, 40, 100, 85, 5, 80, 50, 90, 80, 30};
    cout << "Sorting the array using heap sort" << endl;
    heap.heapSort(arr2, 10);
    cout << "Printing the new sorted array" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "Now Printing values less than 50 in the array" << endl;
    heap.printSmallerThan(arr2, 10, 50);

    cout << endl;
    cout << endl;
    system("pause");
    return 0;
}