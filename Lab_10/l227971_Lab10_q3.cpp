#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int *heap;    // Using dynamic array
    int size;     // Current size of the heap
    int capacity; // Maximum capacity of the heap

    // Helper function to swap two elements in the heap
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void bubble_up(int i) // A recursive method to heapify a subtree with the root at given index. It maintains heap property during insertion.
    {
        // time complexity of this operation is O(log n)
        if (i == 0)
        {
            return;
        }

        int parent = (i - 1) / 2;

        if (heap[parent] < heap[i])
        {
            swap(heap[parent], heap[i]);
            bubble_up(parent);
        }
    }

    void bubble_down(int i)
    {
        // time complexity of this operation is O(log n)
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            bubble_down(largest);
        }
    }

public:
    // Constructor to initialize the heap with a given capacity
    MaxHeap(int maxCapacity) : size(0), capacity(maxCapacity)
    {
        heap = new int[capacity];
    }

    // Implement the insertion operation for the max heap
    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap is full" << endl;
            return;
        }

        heap[size] = value;
        size++;
        bubble_up(size - 1);
    }

    // Implement the deletion operation for the max heap
    void deleteMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }

        heap[0] = heap[size - 1];
        size--;
        bubble_down(0);
    }

    // Implement a function to print the elements of the heap
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free the dynamically allocated memory
    ~MaxHeap()
    {
        delete[] heap;
    }
};
int main()
{
    MaxHeap heap(10);
    heap.insert(10);
    heap.insert(50);
    heap.insert(30);
    heap.insert(90);
    heap.insert(40);
    heap.insert(60);
    heap.insert(20);
    heap.insert(30); // duplicate
    heap.insert(80);
    heap.insert(70);
    cout << "Inserting 10, 50, 30, 90, 40, 60, 20, 30, 80, 70 in heap" << endl;
    cout << "Displaying Sorted Heap:" << endl;
    heap.display();
    cout << "Removing Max Value" << endl;
    heap.deleteMax();
    cout << "Displaying Sorted Heap:" << endl;
    heap.display();
    for (int i = 0; i < 9; i++)
    {
        cout << "Removing Max Value" << endl;
        heap.deleteMax();
        cout << "Displaying Sorted Heap:" << endl;
        heap.display();
    }
    cout << "As you can see the three functions work properly" << endl;

    cout << endl;
    cout << endl;
    system("pause");
    return 0;
}
