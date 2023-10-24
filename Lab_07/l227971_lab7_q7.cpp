#include <iostream>
using namespace std;

/**
 * @brief Calculates the future value of an investment.
 * @param principal The initial investment.
 * @param rate The annual interest rate.
 * @param years The number of years.
 * @param contribution The annual contribution.
 * @return double
 * @pre principal, rate, years, and contribution are positive numbers.
 * @note The time complexity of this function is O(n). Where n is the value of years only. It doesn't matter if principal, rate, or contribution are positive or negative or larger.
 */
double calculateFutureValue(double principal, double rate, int years, double contribution)
{
    if (years == 0)
    {
        return principal;
    }
    else
    {
        // this one also works
        /*double interest = principal * rate;
        principal += interest + contribution;
        return calculateFutureValue(principal, rate, years - 1, contribution);*/
        return calculateFutureValue(principal * (1 + rate) + contribution, rate, years - 1, contribution);
    }
}

int main()
{
    cout << endl;
    double principal = 1000.0;   // Initial investment
    double rate = 0.05;          // Annual interest rate (5%)
    int years = 5;               // Number of years
    double contribution = 100.0; // Annual contribution
    double futureValue = calculateFutureValue(principal, rate, years, contribution);
    cout << "The future value of the investment is: $" << futureValue << endl;

    cout << endl;
    system("pause");
    return 0;
}