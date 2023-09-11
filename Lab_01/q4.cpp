#include <iostream>
using namespace std;

class Polynomial
{
private:
    int num_terms;
    int *coeff;
    int *exp;

public:
    Polynomial()
    {
        this->num_terms = 0;
        this->coeff = NULL;
        this->exp = NULL;
    }
    Polynomial(int num_terms, int *coeff, int *exp)
    {
        this->num_terms = num_terms;
        this->coeff = new int[num_terms];
        this->exp = new int[num_terms];
        for (int i = 0; i < num_terms; i++)
        {
            this->coeff[i] = coeff[i];
            this->exp[i] = exp[i];
        }
    }
    Polynomial(const Polynomial &obj)
    {
        this->num_terms = obj.num_terms;
        this->coeff = new int[num_terms];
        this->exp = new int[num_terms];
        for (int i = 0; i < num_terms; i++)
        {
            this->coeff[i] = obj.coeff[i];
            this->exp[i] = obj.exp[i];
        }
    }
    ~Polynomial()
    {
        delete[] this->coeff;
        delete[] this->exp;
    }
    Polynomial operator+(const Polynomial &obj)
    {
        Polynomial temp;
        temp.num_terms = this->num_terms + obj.num_terms;
        temp.coeff = new int[temp.num_terms];
        temp.exp = new int[temp.num_terms];
        int i = 0, j = 0, k = 0;
        while (i < this->num_terms && j < obj.num_terms)
        {
            if (this->exp[i] > obj.exp[j])
            {
                temp.exp[k] = this->exp[i];
                temp.coeff[k] = this->coeff[i];
                i++;
            }
            else if (this->exp[i] < obj.exp[j])
            {
                temp.exp[k] = obj.exp[j];
                temp.coeff[k] = obj.coeff[j];
                j++;
            }
            else
            {
                temp.exp[k] = this->exp[i];
                temp.coeff[k] = this->coeff[i] + obj.coeff[j];
                i++;
                j++;
            }
            k++;
        }
        while (i < this->num_terms)
        {
            temp.exp[k] = this->exp[i];
            temp.coeff[k] = this->coeff[i];
            i++;
            k++;
        }
        while (j < obj.num_terms)
        {
            temp.exp[k] = obj.exp[j];
            temp.coeff[k] = obj.coeff[j];
            j++;
            k++;
        }
        return temp;
    }
    Polynomial operator+(int num)
    {
        Polynomial temp;
        temp.num_terms = this->num_terms;
        temp.coeff = new int[temp.num_terms];
        temp.exp = new int[temp.num_terms];
        for (int i = 0; i < temp.num_terms; i++)
        {
            temp.coeff[i] = this->coeff[i] + num;
            temp.exp[i] = this->exp[i];
        }
        return temp;
    }
    Polynomial operator++()
    {
        Polynomial temp;
        temp.num_terms = this->num_terms;
        temp.coeff = new int[temp.num_terms];
        temp.exp = new int[temp.num_terms];
        for (int i = 0; i < temp.num_terms; i++)
        {
            temp.coeff[i] = this->coeff[i] + 1;
            temp.exp[i] = this->exp[i];
        }
        return temp;
    }
    Polynomial operator++(int)
    {
        Polynomial temp;
        temp.num_terms = this->num_terms;
        temp.coeff = new int[temp.num_terms];
        temp.exp = new int[temp.num_terms];
        for (int i = 0; i < temp.num_terms; i++)
        {
            temp.coeff[i] = this->coeff[i] + 1;
            temp.exp[i] = this->exp[i];
        }
        return temp;
    }
    bool operator!()
    {
        if (this->num_terms == 1 && this->coeff[0] == 0 && this->exp[0] == 0)
            return true;
        return false;
    }
    bool operator!=(const Polynomial &obj)
    {
        if (this->num_terms != obj.num_terms)
            return true;
        for (int i = 0; i < this->num_terms; i++)
        {
            if (this->coeff[i] != obj.coeff[i] || this->exp[i] != obj.exp[i])
                return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, const Polynomial &obj)
    {
        for (int i = 0; i < obj.num_terms; i++)
        {
            if (obj.coeff[i] != 0)
            {
                if (obj.exp[i] == 0)
                    out << obj.coeff[i];
                else if (obj.exp[i] == 1)
                    out << obj.coeff[i] << "x";
                else
                    out << obj.coeff[i] << "x^" << obj.exp[i];
                if (i != obj.num_terms - 1)
                    out << "+";
            }
        }
        return out;
    }
    Polynomial &operator=(const Polynomial &obj)
    {
        if (this != &obj)
        {
            delete[] this->coeff;
            delete[] this->exp;
            this->num_terms = obj.num_terms;
            this->coeff = new int[this->num_terms];
            this->exp = new int[this->num_terms];
            for (int i = 0; i < this->num_terms; i++)
            {
                this->coeff[i] = obj.coeff[i];
                this->exp[i] = obj.exp[i];
            }
        }
        return *this;
    }
};

int main()
{
    int coeff_P1[] = {1, 2, 5};         // Coefficients for Polynomial P1
    int exp_P1[] = {4, 2, 0};           // Exponents for Polynomial P1
    int coeff_P2[] = {4, 3};            // Coefficients for Polynomial P2
    int exp_P2[] = {6, 2};              // Exponents for Polynomial P2
    Polynomial P1(3, coeff_P1, exp_P1); // Creates P1 with 3 terms (P1 = 1x^4 + 2x^2 + 5x^0 )
    Polynomial P2(2, coeff_P2, exp_P2); // Creates P2 with 2 terms (P2 = 4x^6 + 3x^2)
    cout << "P1 = " << P1 << endl;      // Prints P1 = x^4+2x^2+5
    cout << "P2 = " << P2 << endl;      // Prints P2 = 4x^6+3x^2
    if (!P1)
    {
        cout << "P1 is zero" << endl; /*if the polynomial has only 1 term and its coeff and exp are zero. i.e. if p1 = 0.*/
    }
    if (P1 != P2)
    {
        cout << "P1 is Not Equal to P2" << endl;
    }
    cout << ++P1 << endl; // adds 1 in all the coefficients.
    cout << P1 << endl;
    cout << P1++ << endl; // adds 1 in all the coefficients.
    cout << P1 << endl;
    Polynomial P3 = P1 + P2;       // Adds P1 and P2 and saves result in P3.You may consume extra space for resultant Polynomial in Add function
    cout << "P3 = " << P3 << endl; // Prints P3 = 4x^6+x^4+5x^2+5
    P3 = P1 + 2;
    cout << "P3 = " << P3 << endl;
    Polynomial P4;
    P4 = P1;
    cout << "P4 = " << P4 << endl;

    return 0;
}
