#include <iostream>
using namespace std;

/**
 * @brief This function converts a number to binary
 * @brief It is a recursive function
 * @note The time complexity of this function is O(log(n))
 */
int to_binary(int num) // recursive function
{
    // converting a number to binary
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 2 + 10 * to_binary(num / 2)); // recursion
    }
}

/**
 * @brief This function prints the 0 1 combinations
 * @brief It is a recursive function
 * @note The time complexity of this function is O(n), where n is the number of combinations
 */
void print_01_combinations(int max, int digits) // recursive function
{
    // printing 0 1 combinations
    if (max == 0)
    {
        return;
    }
    else
    {
        print_01_combinations(max - 1, digits); // recursion
        int bin = to_binary(max - 1);           // converting the number to binary
        int len = 0;
        int temp = bin;
        while (temp != 0)
        {
            len++;
            temp /= 10;
        }
        if (len < digits) // adding zeros in front if any are missing
        {
            if (bin != 0)
            {
                for (int i = 0; i < digits - len; i++)
                {
                    cout << "0";
                }
            }
            else
            {
                for (int i = 0; i < digits - len - 1; i++)
                {
                    cout << "0";
                }
            }
        }
        cout << bin << " ";
    }
}

/**
 * @brief This function calculates the power of 2
 * @brief It is a recursive function
 * @note The time complexity of this function is O(log(n))
 */
int power_of_2(int val) // recursive function
{
    // calculating 2^val recursively
    if (val == 0)
    {
        return 1;
    }
    else
    {
        return 2 * power_of_2(val - 1); // recursion
    }
}

/**
 * @brief This function prints the 0 1 combinations
 * @brief It is not a recursive function. It is simoly a function that calls the recursive function
 * @note The time complexity of this function is O(n) + O(log(n)) = O(n), where n is the number of combinations
 */
void print_01(int num)
{
    int val = 1;
    val = power_of_2(num);

    // gicing powers of 2, ie 2^num as input to the function as i will be checking the binarry combinations of 0 and 1 for num times
    print_01_combinations(val, num);
}

// -> This function is good and works, but I am going with the other one.
/*
void print_01_combinations(int num, string prefix = "")
{
    if (num == 0)
    {
        cout << prefix << " ";
    }
    else
    {
        print_01_combinations(num - 1, prefix + "0");
        print_01_combinations(num - 1, prefix + "1");
    }
}
*/

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    while (num < 1)
    {
        cout << "Enter a number greater than or equal to 1: ";
        cin >> num;
    }
    print_01(num);

    cout << endl;
    system("pause");
    return 0;
}