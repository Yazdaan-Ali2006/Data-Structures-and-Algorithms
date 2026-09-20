#include <iostream>
using namespace std;

class Matrix
{
private:
    int **data;
    int rows;
    int cols;

public:

    // Constructor
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        data = new int *[rows]; //store pointers for rows

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols]; //points to the elements in the row
        }
    }

    // Copy Constructor
    Matrix(const Matrix &M)
    {
        rows = M.rows;
        cols = M.cols;

        data = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = M.data[i][j];
            }
        }
    }

    // Input function
    void input()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Element [" << i << "][" << j << "] = ";
                cin >> data[i][j];
            }
        }
    }

    // Print function
    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }

    // Operator * overloading
    Matrix operator*(const Matrix &B)
    {
        // Size check
        if (cols != B.rows)
        {
            cout << "Matrix multiplication NOT POSSIBLE!" << endl;

            return Matrix(0, 0);
        }

        // Result matrix size = rows of A × columns of B
        Matrix C(rows, B.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                C.data[i][j] = 0;

                for (int k = 0; k < cols; k++)
                {
                    C.data[i][j] +=C.data[i][k] * B.data[k][j];
                }
            }
        }

        return C;
    }


    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }

        delete[] data;
    }
};

int main()
{
    int ra, ca, rb, cb;

    // Matrix A dimensions
    cout << "Enter rows of Matrix A: ";
    cin >> ra;

    cout << "Enter columns of Matrix A: ";
    cin >> ca;

    // Matrix B dimensions
    cout << "Enter rows of Matrix B: ";
    cin >> rb;

    cout << "Enter columns of Matrix B: ";
    cin >> cb;

    // Creating Matrix objects
    Matrix A(ra, ca);
    Matrix B(rb, cb);

    // Input A
    cout << "\nEnter elements of Matrix A:" << endl;
    A.input();

    // Input B
    cout << "\nEnter elements of Matrix B:" << endl;
    B.input();

    // Display A
    cout << "\nMatrix A:" << endl;
    A.print();

    // Display B
    cout << "\nMatrix B:" << endl;
    B.print();

    // Matrix multiplication
    Matrix C = A * B;

    // Display result
    cout << "\nResult Matrix C = A * B:" << endl;
    C.print();

    return 0;
}