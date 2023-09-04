#include <iostream>
using namespace std;

int** createPascalTriangle (int size);
void displayPascalTriangle (int** triangle, int size);
void deallocatePascalTriangle (int** triangle, int size);
/*int comb(int n, int r);
int factorial(int n);*/
int fact(int n);
int nCr(int n, int r);

int main()
{
	int size;
	cout << "Enter Size of Pascal Triangle: ";
	cin >> size;
	while (size < 1)
	{
		cout << "Error, value must be greater then zero!!! Enter size: " << endl;
		cin >> size;
	}
	
	int ** triangle = createPascalTriangle (size);
	
	displayPascalTriangle(triangle, size);
	
	deallocatePascalTriangle (triangle, size);
	
	return 0;
}

int** createPascalTriangle (int size)
{
	int **triangle = new int *[size];
	
	for (int i = 1; i <= size; i++)
	{
		triangle[i-1] = new int[i];
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			triangle[i][j] = nCr(i, j);
		}
	}
	
	return triangle;
}

void displayPascalTriangle (int** triangle, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
	
}

void deallocatePascalTriangle (int** triangle, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		delete[] triangle[i];
	}
	delete[] triangle;
	
}
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// factorial of n
int fact(int n)
{
    if(n==0)
    {
	  
      return 1;
	}
    int res = 1;
    
    for (int i = 2; i <= n; i++)
    {
        res = res * i;
	}
	return res;
}
/*
int comb(int n, int r)
{
	n = factorial(n);
	int n_r = factorial(n - r);
	r = factorial(r);
	
	int numerator = n;
	int denominator = n_r * r;
	
	int val = numerator/denominator;
	
	return val;
}

int factorial(int n)
{
	int num;
	for (int i = n; i > 0; i--)
	{
		num = num * n;
	}
	
	return num;
}*/
