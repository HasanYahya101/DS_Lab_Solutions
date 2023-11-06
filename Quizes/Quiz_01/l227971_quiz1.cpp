#include <iostream>
using namespace std;



int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}





int min(int a, int b)
{
	if(a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}






int recursiveMaxArea(int *arr, int start, int end)// recursive function
{
    // base case
    if (start == end)
    {
        return 0;
    }
    // recursive case
    else
    {
        // find the max area between the start and end
        int maxArea = 0;
        for (int i = start; i < end; i++)
        {
            int area = (end - start) * min(arr[start], arr[end]);
            if (area > maxArea)
            {
                maxArea = area;
            }
        }

        // find the max area between the start and end - 1
        int maxArea1 = recursiveMaxArea(arr, start, end - 1); // recursion

        // find the max area between the start + 1 and end
        int maxArea2 = recursiveMaxArea(arr, start + 1, end); // recursion
        // return the max of the three

        return max(maxArea, max(maxArea1, maxArea2));
    }

}













// use reursion to solve this problem
int maxArea(int *arr, int n) // helper function
{
    recursiveMaxArea(arr, 0, n-1);
}






int main()
{
	int *arr = new int[9];
	//= [1,8,6,2,5,4,8,3,7]
	arr[0] = 1;
	arr[1] = 8;
	arr[2] = 6;
	arr[3] = 2;
	arr[4] = 5;
	arr[5] = 4;
	arr[6] = 8;
	arr[7] = 3;
	arr[8] = 7;
	
	// the answer should be 49
	int val = maxArea(arr, 9);
	cout << "The Maximum Area is: " << val << endl;
	
	delete arr;
	
	return 0;
}
