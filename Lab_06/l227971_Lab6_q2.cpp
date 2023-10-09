#include <iostream>
using namespace std;

/**
 * @brief It is a Template for the Node class. It can be of any DataType.
 */
template <typename dataType>

/**
 * @brief It is a Node for a Linked List type Stack.
 * @brief It has 2 constructors and one destructor.
 * @brief It has 2 attributes, data and next.
 */
class Node
{
public:
    dataType data; // data stored, it can be of any DataType
    Node *next;    // pointer to the next node

    /**
     * @brief It is a default constructor for the Node class.
     * @brief It will set the next pointer to NULL.
     * @param none It has no Parameters.
     * @return It will return nothing.
     * @note The time complexity is O(1).
     */
    Node()
    {
        next = NULL;
    }

    /**
     * @brief It is a parameterized constructor for the Node class.
     * @brief It will set the data and next pointer.
     * @param d It is the data to be stored in the node.
     * @param n It is the pointer to the next node.
     * @return It will return nothing.
     * @note The time complexity is O(1).
     */
    Node(dataType d, Node<dataType> *n = NULL)
    {
        data = d;
        next = n;
    }

    /**
     * @brief It is a destructor for the Node class.
     * @brief It will delete the next pointer.
     * @param none It has no Parameters.
     * @return It will return nothing.
     * @note The time complexity is O(1).
     */
    ~Node()
    {
        delete next;
    }
};

template <typename dataType>

/**
 * @brief It is a class for Stack using Linked List.
 * @brief It has 1 constructor and 1 destructor.
 * @brief It has 2 attributes, top and size.
 */
class Stack_List
{
private:
    Node<dataType> *top; // head of the stack.
    int size;            // size of the stack, ie the total elements.

public:
    /**
     * @brief It is a default constructor for the Stack_List class.
     * @brief It will set the top pointer to NULL and size to 0.
     * @param none It has no Parameters.
     * @return It will return nothing.
     * @note The time complexity is O(1).
     */
    Stack_List()
    {
        top = NULL;
        size = 0;
    }

    /**
     * @brief It is a destructor for the Stack_List class.
     * @brief It will delete the top pointer.
     * @param none It has no Parameters.
     * @return It will return nothing.
     * @note The time complexity is O(1).
     */
    int __size__()
    {
        return size;
    }

    /**
     * @brief It is a function to get the next element in the stack.
     * @brief It will return the next element in the stack.
     * @param none It has no Parameters.
     * @return It will return the next element in the stack. It can be of any dataType.
     * @note The time complexity is O(1).
     */
    dataType get_Next()
    {
        Node<dataType> *temp;
        temp = top->next;
        return temp->data;
    }

    /**
     * @brief It is a function to check if the stack is empty or not.
     * @brief It will return true if the stack is empty, else false.
     * @param none It has no Parameters.
     * @return It will return true if the stack is empty, else false.
     * @note The time complexity is O(1).
     */
    bool __isEmpty__()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
     * @brief It is a function to get the top element in the stack.
     * @brief It will return the top element in the stack.
     * @param __to_pass__ It is the variable to store the top element.
     * @return It will return a bool value based of of the operation was successful or not.
     * @note The time complexity is O(1).
     */
    bool __top__(dataType &__to_pass__)
    {
        if (top == NULL)
        {
            return false;
        }
        else
        {
            __to_pass__ = top->data;
            return true;
        }
        return false;
    }

    /**
     * @brief It is a function to print the stack.
     * @brief It will print the stack.
     * @param none It has no Parameters.
     * @return void - It will return nothing.
     * @note The time complexity is O(n).
     */
    void __print__()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node<dataType> *temp = top;
            while (temp != NULL)
            {
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    /**
     * @brief It is a function to pop the top element from the stack.
     * @brief It will pop the top element from the stack.
     * @param none It has no Parameters.
     * @return void - It will return nothing.
     * @note The time complexity is O(1).
     */
    void __pop__()
    {
        if (top == NULL)
        {
            return;
        }
        else
        {
            Node<dataType> *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
    }

    /**
     * @brief It is a function to push an element onto the stack.
     * @brief It will push an element onto the stack.
     * @param val It is the value to be pushed onto the stack.
     * @return `void` - It will return nothing.
     * @note The time complexity is O(1).
     */
    void __push__(dataType const &val)
    {
        Node<dataType> *temp = new Node<dataType>(val, top);
        top = temp;
        size++;
    }

    /**
     * @brief It is a function to get the top pointer.
     * @brief It returns the `this->top` pointer.
     * @param none It has no Parameters.
     * @return It will return a Node pointer for any DataType.
     * @note The time complexity is O(1).
     */
    Node<dataType> *__get_top_pointer__()
    {
        return this->top;
    }

    /**
     * @brief It is a destructor for the `Stack_List` class.
     * @brief It will delete the `this->top` pointer.
     * @param none It has no Parameters.
     * @return It will return nothing.
     * @note The time complexity is O(1).
     */
    ~Stack_List()
    {
        delete top;
    }
};

template <typename dataType>

/**
 * @brief It is a class for a Media Player.
 * @brief It has 1 constructor and 1 destructor.
 * @brief It has 1 attribute, playlist.
 * @brief It has 6 functions, addToPlaylist, removeFromPlaylist, play, displayPlaylist, print_Next, print_Prev.
 */
class MediaPlayer
{
private:
    Stack_List<string> playlist; // the stack of strings

public:
    /**
     * @brief It is a default constructor for the MediaPlayer class.
     * @param none It has no Parameters.
     * @return It will return nothing.
     * @note The time complexity is 0.
     */
    MediaPlayer()
    {
        // Nothing to do here
    }

    /**
     * @brief It is a function to add media onto the playlist.
     * @brief It will add media on top of the stack.
     * @param media It is the `string` to be added onto the playlist.
     * @return `void` - It will return nothing.
     * @note The time complexity is O(1).
     */
    void addToPlaylist(const string &media) // this function will add media onto the playlist
    {
        playlist.__push__(media);
    }

    /**
     * @brief It is a function to remove media from the playlist.
     * @brief It will remove media from the top of the stack.
     * @param none It has no Parameters.
     * @return `void` - It will return nothing.
     * @note The time complexity is O(1).
     */
    void removeFromPlaylist() // it remove element from the playlist
    {
        playlist.__pop__();
    }

    /**
     * @brief It is a function to play media from the playlist.
     * @brief It will play media from the top of the stack.
     * @param none It has no Parameters.
     * @return `void` - It will return nothing.
     * @note The time complexity is O(1).
     */
    void play() // it will play element from the playlist
    {
        string temp;
        playlist.__top__(temp);
        cout << temp << endl;
    }

    /**
     * @brief It is a function to display the playlist.
     * @brief It will print the playlist.
     * @param none It has no Parameters.
     * @return `void` - It will return nothing.
     * @note The time complexity is O(n).
     */
    void displayPlaylist() // it will display the playlist
    {
        playlist.__print__();
    }

    /**
     * @brief It is a function to print the next element in the playlist.
     * @param none It has no Parameters.
     * @return `void` - It will return nothing.
     * @note The time complexity is O(1).
     */
    void print_Next()
    {
        if (playlist.__get_top_pointer__() == NULL)
        {
            cout << "There are no Elements in the Stack" << endl;
        }
        else
        {
            cout << "The Next Node is: " << playlist.get_Next();
        }
    }

    /**
     * @brief It is a function to print the previous element in the playlist.
     * @param none It has no Parameters.
     * @return `void` - It will return nothing.
     * @note The time complexity is O(1).
     */
    void print_Prev()
    {
        if (playlist.__get_top_pointer__() == NULL)
        {
            cout << "There are no Elements in the Stack" << endl;
        }
        else
        {
            cout << "There is Nothing at the Back" << endl;
        }
    }

    /**
     * @brief It is a destructor for the MediaPlayer class.
     * @param none It has no Parameters.
     * @return It will return nothing.
     * @note The time complexity is 0 (because it is empty)
     */
    ~MediaPlayer()
    {
        // Nothing to do here
    }
};

int main() // testing main function
{
    MediaPlayer<string> player;
    player.addToPlaylist("Song 1");
    player.addToPlaylist("Song 2");
    player.addToPlaylist("Song 3");
    cout << "Displaying playlist: " << endl;
    player.displayPlaylist();
    cout << "Plating the Top Element from Playlist!!!" << endl;
    player.play();
    cout << "Remove top element from playlist!!!" << endl;
    player.removeFromPlaylist();
    cout << "Displaying playlist: " << endl;
    player.displayPlaylist();

    cout << "Testing Forward Function" << endl;
    player.print_Next();
    cout << endl;
    cout << "Testing Previous Function" << endl;
    player.print_Prev();

    system("pause");
    return 0;
}