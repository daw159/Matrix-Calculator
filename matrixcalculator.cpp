#include <iostream>
#include <fstream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

double inv[2][2];
const int z = 10;
struct Matrix
{
    int row, col;
    int a[z][z];
};
void inputMatrix(Matrix &mat);
void printMatrix(const Matrix &mat);
Matrix add(const Matrix &a, const Matrix &b);
Matrix subtract(const Matrix &a, const Matrix &b);
Matrix multiply(const Matrix &a, const Matrix &b);
Matrix transpose(const Matrix &mat);
Matrix power(const Matrix &mat, int exp);
double determinant(const Matrix &mat);
int trace(const Matrix &mat);
void inverse2x2(const Matrix &mat);

void save(const Matrix &mat, const string &filename);

void logOperation(const string &op)
{
    ofstream fout("result.txt", ios::app); 
    fout << "Operation: " << op << endl;
    fout << "_____________________________" << endl;
    fout.close();
}

int main()
{
    Matrix m1, m2, res;
    int choice, exp, k, sum = 0;
    do
    {
        system("cls");
    cout << CYAN << "====================================================" << RESET << endl;
    cout << CYAN << "|                                                  |" << RESET << endl;
    cout << GREEN << "|           Welcome to Matrix Calculator         |" << RESET << endl;
    cout << CYAN << "|__________________________________________________|" << RESET << endl;
    cout << CYAN << "|                                                  |" << RESET << endl;
    cout << YELLOW << "|  Choose an operation from the list below:        |" << RESET << endl;
    cout << CYAN << "|                                                  |" << RESET << endl;
    cout << BLUE << "|  1.  Add two matrices                            |" << RESET << endl<<endl;
    cout << BLUE << "|  2.  Subtract two matrices                       |" << RESET << endl<<endl;
    cout << BLUE << "|  3.  Scalar multiply a matrix                    |" << RESET << endl<<endl;
    cout << BLUE << "|  4.  Multiply two matrices                       |" << RESET << endl<<endl;
    cout << BLUE << "|  5.  Transpose of a matrix                       |" << RESET << endl<<endl;
    cout << BLUE << "|  6.  Power of the matrix                         |" << RESET << endl<<endl;
    cout << BLUE << "|  7.  Trace of the matrix                         |" << RESET << endl<<endl;
    cout << BLUE << "|  8.  Determinant of an n x n matrix              |" << RESET << endl<<endl;
    cout << BLUE << "|  9.  Inverse of a 2 x 2 matrix                   |" << RESET << endl<<endl;
    cout << RED  << "| 10.  Exit                                        |" << RESET << endl<<endl;
    cout << CYAN << "|__________________________________________________|" << RESET << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m1);
            cout << "Matrix 2 Details: " << endl<<endl;
            inputMatrix(m2);
            res = add(m1, m2);
            cout << "Result of addition: " << endl;
            printMatrix(res);
            save(res, "result.txt");
            logOperation("Addition");
            system("pause");
            break;
        case 2:
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m1);
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m2);
            res = subtract(m1, m2);
            cout << "Result of subtraction: " << endl;
            printMatrix(res);
            save(res, "result.txt");
            logOperation("Subtarction");
            system("pause");
            break;
        case 3:
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m1);
            cout << "Enter scaler value: ";
            cin >> k;
            for (int i = 0; i < m1.row; i++)
            {
                for (int j = 0; j < m1.col; j++)
                {
                    m1.a[i][j] *= k;
                }
            }
            cout << "Result of scaler multiplication: " << endl;
            printMatrix(m1);
            save(m1, "result.txt");
            logOperation("Scaler Multiplication and the value of k is : " + to_string(k));
            system("pause");
            break;
        case 4:
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m1);
            cout << "Matrix 2 Details " << endl<<endl;
            inputMatrix(m2);
            res = multiply(m1, m2);
            cout << "Result of multiplication: " << endl;
            printMatrix(res);
            save(res, "result.txt");
            logOperation("Multiplication");
            system("pause");
            break;
        case 5:
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m1);
            res = transpose(m1);
            cout << "Result of transpose: " << endl;
            printMatrix(res);
            save(res, "result.txt");
            logOperation("Transpose");
            system("pause");
            break;
        case 6:
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m1);
            cout << "Enter exponent: ";
            cin >> exp;
            res = power(m1, exp);
            cout << "Result of power: " << endl;
            printMatrix(res);
            save(res, "result.txt");
            logOperation("Power is  : " + to_string(exp));
            system("pause");
            break;
        case 7:
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m1);
            sum = trace(m1);
            cout << "Trace of the Matrix is : " << sum << endl;
            save(m1, "result.txt");
            logOperation("Trace and its answer is : " + to_string(sum));
            system("pause");
            break;
        case 8:
            cout << "Matrix 1 Details: " << endl<<endl;
            inputMatrix(m1);
            if (m1.row == m1.col)
            {
                int det = determinant(m1);
                cout << "Determinant of the Matrix is : " << det << endl;
                save(m1, "result.txt");
                logOperation("Determinant and its answer is the : " + to_string(det));
            }
            else
            {
                cout << "Determinant is not defined for non-square matrices." << endl;
            }
            system("pause");

            break;
        case 9:
            cout << "Enter a 2x2 matrix to find inverse: " << endl<<endl;
            inputMatrix(m1);
            if (m1.row == 2 && m1.col == 2)
            {
                inverse2x2(m1);
                save(m1, "result.txt");
                logOperation("Inverse");
            }
            else
            {
                cout << "Inverse is only defined for 2x2 matrices." << endl;
            }
            system("pause");
            break;
        case 10:
            cout << "Thank you for using Matrix Calculator!" << endl;

            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
            system("pause");
            break;
        }
    } while (choice != 10);

    return 0;
}
void inputMatrix(Matrix &mat)
{
    cout << "Enter number of rows and columns: ";
    cin >> mat.row >> mat.col;
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            cin >> mat.a[i][j];
        }
    }
}
void printMatrix(const Matrix &mat)
{

    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            cout << GREEN << mat.a[i][j] << " " << RESET;
;
        }
        cout << endl;
    }
}
Matrix add(const Matrix &a, const Matrix &b)
{
    Matrix result;
    if (a.row != b.row || a.col != b.col)
    {
        cout << "Matrices must have the same dimensions for addition." << endl;
        return result;
    }
    result.row = a.row;
    result.col = a.col;
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < a.col; j++)
        {
            result.a[i][j] = a.a[i][j] + b.a[i][j];
        }
    }
    return result;
}
Matrix subtract(const Matrix &a, const Matrix &b)
{
    Matrix result;
    if (a.row != b.row || a.col != b.col)
    {
        cout << "Matrices must have the same dimensions for subtraction" << endl;
        return result;
    }
    result.row = a.row;
    result.col = a.col;
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < a.col; j++)
        {
            result.a[i][j] = a.a[i][j] - b.a[i][j];
        }
    }
    return result;
}
int trace(const Matrix &mat)
{
    if (mat.row != mat.col)
    {
        cout << "Trace is only defined for square matrices." << endl;
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < mat.row; i++)
    {
        sum += mat.a[i][i];
    }
    return sum;
}
Matrix transpose(const Matrix &mat)
{
    Matrix result;
    result.row = mat.col;
    result.col = mat.row;
    for (int i = 0; i < mat.col; i++)
    {
        for (int j = 0; j < mat.row; j++)
        {
            result.a[i][j] = mat.a[j][i];
        }
    }
    return result;
}
Matrix multiply(const Matrix &a, const Matrix &b)
{
    Matrix result;
    if (a.col != b.row)
    {
        cout << "Matrices cannot be multiplied due to incompatible dimensions." << endl;
        return result;
    }
        result.row = a.row;
        result.col = b.col;
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < b.col; j++)
            {
                result.a[i][j] = 0;
                for (int k = 0; k < a.col; k++)
                {
                    result.a[i][j] += a.a[i][k] * b.a[k][j];
                }
            }
        }
    
    return result;
}
Matrix power(const Matrix &mat, int exp)
{

    Matrix result = mat;
    if (exp < 0)
    {
        cout << "Negative exponent not supported for matrix power." << endl;
        return result;
    }
    for (int i = 1; i < exp; i++)
    {
        result = multiply(result, mat);
    }
    return result;
}
double determinant(const Matrix &mat)
{
    double det = 1;
    int n = mat.row;
    double temp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = mat.a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (temp[i][i] == 0)
        {
            bool swap = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (temp[j][i] != 0)
                {
                    swap = 1;
                    for (int k = 0; k < n; k++)
                    {
                        double t = temp[i][k];
                        temp[i][k] = temp[j][k];
                        temp[j][k] = t;
                    }
                    det *= -1;
                    break;
                }
            }
            if (swap == 0)
            {
                cout << "Determminant is 0" << endl;
                return 0;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (temp[j][i] != 0)
            {
                double r = temp[j][i] / temp[i][i];
                for (int k = 0; k < n; k++)
                {
                    temp[j][k] -= (r * temp[i][k]);
                }
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        det *= temp[j][j];
    }
    return det;
}


void inverse2x2(const Matrix &mat)
{
    double det = determinant(mat);
    if (det == 0)
    {
        cout << "Matrix is singular, inverse does not exist." << endl;
        return;
    }

    inv[0][0] = mat.a[1][1] / det;
    inv[0][1] = -mat.a[0][1] / det;
    inv[1][0] = -mat.a[1][0] / det;
    inv[1][1] = mat.a[0][0] / det;

    cout << "Inverse of the matrix is: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout <<GREEN<< inv[i][j] <<RESET<< " ";
        }
        cout << endl;
    }
}


void save(const Matrix &mat, const string &filename)
{
    ofstream fout(filename, ios::app); // open in append mode
    if (!fout)
    {
        cout << "Error opening file to save result." << endl;
        return;
    }

    fout << "Matrix (" << mat.row << "x" << mat.col << "):" << endl;
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            fout << mat.a[i][j] << " ";
        }
        fout << endl;
    }
    fout << "------------------------" << endl;

    fout.close();
}
