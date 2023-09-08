#include <iostream>
using namespace std;

template<class T>
class my_vector {
    int size;
    int capacity;
    T* arr;
public:
   my_vector() {
        size = -1;
        capacity = 1;
        arr = new T[capacity];
    }
   void push_back(T val) {
        //write code here
    }

    T pop_back(void) {
         //write code here
    }

    void display_list(void) {
        cout << "Elements present in list are:\n";
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }

};

int main()
{
    my_vector<int> list;
    for (int i = 0; i < 8; i++) {
        list.push_back(i + 1);
        list.display_list();

    }

    for (int j = 0; j<=4; j++) {
       cout<<"Extracted \t" << list.pop_back()<<"\t from list"<<endl;
       list.display_list();

    }
    
    return 0;
}