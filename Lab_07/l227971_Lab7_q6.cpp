#include <iostream>
using namespace std;

/**
 * @brief Returns the product of two numbers.
 * @param num_1 The first number.
 * @param num_2 The second number.
 * @return int
 * @pre num_1 and num_2 are integers.
 * @note The time complexity of this function is O(n). Where n is the value of num_2 only. It doesn't matter if num_1 is positive or negative or larger.
 */
int product(int num_1, int num_2) // recursive function
{
    if (num_2 == 0)
    {
        return 0;
    }
    else if (num_1 < 0 && num_2 > 0)
    {
        return -product(-num_1, num_2); // recursion
    }
    else if (num_1 > 0 && num_2 < 0)
    {
        return -product(num_1, -num_2); // recursion
    }
    else if (num_1 < 0 && num_2 < 0)
    {
        return product(-num_1, -num_2); // recursion
    }
    else
    {
        return num_1 + product(num_1, num_2 - 1); // recursion
    }
}

int main()
{
    int num_1, num_2;
    cout << "Enter first number: ";
    cin >> num_1;
    cout << "Enter second number: ";
    cin >> num_2;
    cout << "Product of " << num_1 << " and " << num_2 << " is: " << product(num_1, num_2) << endl;

    system("pause");
    return 0;
}