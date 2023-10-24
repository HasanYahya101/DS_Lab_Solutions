#include <iostream>
using namespace std;

/**
 * @brief Compares two character strings.
 * @brief Returns 0 if both strings are equal.
 * @brief Returns 1 if string1 ASCII at some index is greater than string2.
 * @brief Returns -1 if string1 ASCII at some index is less than string2.
 * @param string1 The first string to be compared.
 * @param string2 The second string to be compared.
 * @return int
 * @pre string1 and string2 are null-terminated strings.
 * @note The time complexity of this function is O(n). Where n is the length of the larger string.
 */
int stringCompare(char const *string1, char const *string2)
{
    if (*string1 == '\0' && *string2 == '\0')
    {
        return 0;
    }
    else if (*string1 == '\0')
    {
        return -1;
    }
    else if (*string2 == '\0')
    {
        return 1;
    }
    else if (*string1 > *string2)
    {
        return 1;
    }
    else if (*string1 < *string2)
    {
        return -1;
    }
    else
    {
        return stringCompare(string1 + 1, string2 + 1); // recursion
    }
}

int main()
{
    string str1, str2;
    cout << "Enter string 1: ";
    getline(cin, str1);
    cout << "Enter string 2: ";
    getline(cin, str2);
    int result = stringCompare(str1.c_str(), str2.c_str());
    if (result == 0)
    {
        cout << "The strings are equal." << endl;
    }
    else if (result == 1)
    {
        cout << "String 1 ASCII at some Index is greater than string 2." << endl;
    }
    else
    {
        cout << "String 1 ASCII at some Index is less than string 2." << endl;
    }

    system("pause");
    return 0;
}