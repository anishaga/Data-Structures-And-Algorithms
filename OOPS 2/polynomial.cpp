#include <bits/stdc++.h>
using namespace std;

class Polynomial
{
public:
    int *a;
    int size;

    Polynomial()
    {
        this->size = 10;
        a = new int[10];
        for (int i = 0; i < 10; i++)
        {
            a[i] = 0;
        }
    }
    //Copy Constructor
    Polynomial(Polynomial const &d)
    {
        this->a = new int[d.size];
        for (int i = 0; i < d.size; i++)
        {
            this->a[i] = d.a[i];
        }
        this->size = d.size;
    }

    //Copy Asignment Constructor

    void operator=(Polynomial const &d)
    {
        this->a = new int[d.size];
        for (int i = 0; i < d.size; i++)
        {
            this->a[i] = d.a[i];
        }
        this->size = d.size;
    }

    void setCoefficient(int i, int coefficient)
    {
        if (i == size)
        {
            int *newA = new int[2 * size];
            for (int i = 0; i < size; i++)
            {
                newA[i] = a[i];
            }
            for (i=size; i<2*size; i++)
            {
                newA[i] =0;
            }
            delete [] a;
            a = newA;
            size = 2 * size;
        }

        this->a[i] = coefficient;
    }

    Polynomial operator+(Polynomial const &p)
    {
        Polynomial p3;
        for (int i = 0; i < 10; i++)
        {
            p3.a[i] = this->a[i] + p.a[i];
        }

        return p3;
    }

    Polynomial operator-(Polynomial const &p)
    {
        Polynomial p3;
        for (int i = 0; i < 10; i++)
        {
            p3.a[i] = this->a[i] - p.a[i];
        }

        return p3;
    }

    Polynomial operator*(Polynomial const &p)
    {
        Polynomial p3;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                p3.a[i + j] = (this->a[i] * p.a[j]) + p3.a[i + j];
            }
            // return p3;
        }

        return p3;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i] != 0)
            {
                cout << a[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[100];
    inputArray(a, n);
    int b[100];
    inputArray(b, n);

    Polynomial p1;
    for (int i = 0; i < n; i++)
    {
        p1.setCoefficient(a[i], b[i]);
    }
    // p1.print();

    int m;
    cin >> m;
    int c[100];
    inputArray(c, m);
    int d[100];
    inputArray(d, m);

    Polynomial p2;
    for (int i = 0; i < m; i++)
    {
        p2.setCoefficient(c[i], d[i]);
    }
    // p2.print();

    int k;
    cin >> k;
    Polynomial p3;
    switch (k)
    {
    case 1:
        p3 = p1 + p2;
        p3.print();
        break;
    case 2:
        p3 = p1 - p2;
        p3.print();
        break;
    case 3:
        p3 = p1 * p2;
        p3.print();
        break;
    case 4:
        p3 = p1;
        p3.print();
        break;
    }

    return 0;
}
