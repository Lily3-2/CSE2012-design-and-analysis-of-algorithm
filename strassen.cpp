//Strassen’s Matrix Multiplication
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
using namespace std;
int power2(int k)
{
    return pow(2, int(ceil(log2(k))));
}
void show(vector<vector<int>> &matrix, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (j != 0)
            {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
void add(vector<vector<int>> &matixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC,int length)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            matrixC[i][j] = matixA[i][j] + matrixB[i][j];
        }
    }
}
void sub(vector<vector<int>> &matixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC,int length)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            matrixC[i][j] = matixA[i][j] - matrixB[i][j];
        }
    }
}
void STRASSEN_Multiplication(vector<vector<int>> &matixA, vector<vector<int>> &matrixB,vector<vector<int>> &matrixC, int length)
{
    if (length == 1)
    {
        matrixC[0][0] = matixA[0][0] * matrixB[0][0];
        return;
    }
    else
    {
        int new_size = length / 2;
        vector<int> z(new_size);
        vector<vector<int>>
            a11(new_size, z), a12(new_size, z), a21(new_size, z), a22(new_size, z),
            b11(new_size, z), b12(new_size, z), b21(new_size, z), b22(new_size, z),
            c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
            p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
            p5(new_size, z), p6(new_size, z), p7(new_size, z),
            aResult(new_size, z), bResult(new_size, z);
        int i, j;
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                a11[i][j] = matixA[i][j];
                a12[i][j] = matixA[i][j + new_size];
                a21[i][j] = matixA[i + new_size][j];
                a22[i][j] = matixA[i + new_size][j + new_size];
                b11[i][j] = matrixB[i][j];
                b12[i][j] = matrixB[i][j + new_size];
                b21[i][j] = matrixB[i + new_size][j];
                b22[i][j] = matrixB[i + new_size][j + new_size];
            }
        }
        
        add(a11, a22, aResult, new_size); 
        add(b11, b22, bResult, new_size); 
        STRASSEN_Multiplication(aResult, bResult, p1, new_size);
        
        add(a21, a22, aResult, new_size); 
        STRASSEN_Multiplication(aResult, b11, p2, new_size);
        
        sub(b12, b22, bResult, new_size);
        STRASSEN_Multiplication(a11, bResult, p3, new_size);
        sub(b21, b11, bResult, new_size); 
        STRASSEN_Multiplication(a22, bResult, p4, new_size);
        
        add(a11, a12, aResult, new_size); 
        STRASSEN_Multiplication(aResult, b22, p5, new_size);
        
        sub(a21, a11, aResult, new_size);
        add(b11, b12, bResult, new_size);

        STRASSEN_Multiplication(aResult, bResult, p6, new_size);

        sub(a12, a22, aResult, new_size); 
        add(b21, b22, bResult, new_size);
        STRASSEN_Multiplication(aResult, bResult, p7, new_size);
        
        add(p3, p5, c12, new_size);          
        add(p2, p4, c21, new_size);          
        add(p1, p4, aResult, new_size);      
        add(aResult, p7, bResult, new_size); 
        sub(bResult, p5, c11, new_size);     
        add(p1, p3, aResult, new_size);      
        add(aResult, p6, bResult, new_size); 
        sub(bResult, p2, c22, new_size);     
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                matrixC[i][j] = c11[i][j];
                matrixC[i][j + new_size] = c12[i][j];
                matrixC[i + new_size][j] = c21[i][j];
                matrixC[i + new_size][j + new_size] = c22[i][j];
            }
        }
    }
}
void STRASSEN_Multiplication(vector<vector<int>> &matixA, vector<vector<int>> &matrixB, int x,int y, int a, int b)
{
    int k = max({x, y, a, b});
    int s = power2(k);
    vector<int> z(s);
    vector<vector<int>> P(s, z), Q(s, z), R(s, z);
    for (unsigned int i = 0; i < x; i++)
    {
        for (unsigned int j = 0; j < y; j++)
        {
            P[i][j] = matixA[i][j];
        }
    }
    for (unsigned int i = 0; i < a; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            Q[i][j] = matrixB[i][j];
        }
    }
    STRASSEN_Multiplication(P, Q, R, s);
    vector<int> temp1(b);
    vector<vector<int>> matrixC(x, temp1);
    for (unsigned int i = 0; i < x; i++)
    {
        for (unsigned int j = 0; j < b; j++)
        {
            matrixC[i][j] = R[i][j];
        }
    }
    show(matrixC, x, b);
}
bool check(int y, int a)
{
    if (y == a)
        return true;
    else
        return false;
}
int main()
{
    int x, y, a, b;
    cout << "Matrix Multiplication using Strassen algorithm" << endl;
    cout << "Enter rows and columns of first matrix" << endl;
    cin >> x >> y;
    cout << "enter values into first matrix" << endl;
    vector<vector<int>> matixA;
    for (int i = 0; i < x; i++)
    {
        vector<int> temp;
        for (int j = 0; j < y; j++)
        {
            int i;
            cin >> i;
            temp.push_back(i);
        }
        matixA.push_back(temp);
    }
    cout << "Enter rows and columns of second matrix" << endl;
    cin >> a >> b;
    cout << "enter values into second matrix" << endl;
    vector<vector<int>> matrixB;
    for (int i = 0; i < a; i++)
    {
        vector<int> temp;
        for (int j = 0; j < b; j++)
        {
            int i;
            cin >> i;
            temp.push_back(i);
        }
        matrixB.push_back(temp);
    }
    bool k = check(y, a);
    if (k)
    {
        STRASSEN_Multiplication(matixA, matrixB, x, y, a, b);
    }
    return 0;
}