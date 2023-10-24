#include <iostream>
using namespace std;

/**
 * @brief Returns a string of the number val.
 * @note Time Complexity: O(log(n)), where n is the val of the number.
 */
string to_str(int val) // this is a recursive function
{
    if (val < 10)
    {
        return string(1, val + '0');
    }
    else
    {
        return to_str(val / 10) + string(1, val % 10 + '0');
    }
}

/**
 * @brief Returns a string with commas in the right places. Ie if you have 1000, it will return 1,000.
 * @brief If you have 1234567, it will return 1,234,567. It also, works for negative numbers.
 * @note Time Complexity: O(log(n)), where n is the val of the number. This assumed that the to_string() function is O(1).
 */
string return_comma_string(int val) // this is a recursive function
{
    if (val < 0)
    {
        return "-" + return_comma_string(-val);
    }

    if (val < 1000)
    {
        return to_str(val);
    }
    else
    {
        return return_comma_string(val / 1000) + "," + to_str(val % 1000);
    }
}

// the overall time complexity of this program is O(log(n)).

int main()
{
    int val;
    cout << "Enter a number: ";
    cin >> val;
    cout << "The comma string is: " << return_comma_string(val) << endl;
    cout << endl;
    system("pause");
    return 0;
}