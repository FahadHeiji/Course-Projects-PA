#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

bool IsScalarMarix(int Matrix1[3][3], short Rows, short Cols) {
    int FirstDiagElemement = Matrix1[0][0];
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            if (i == j && Matrix1[i][j] != FirstDiagElemement) {
                return false;
            } else if (i != j && Matrix1[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    if (IsScalarMarix(Matrix1, 3, 3))
        cout << "\nYES: Matrix is scalar.";
    else
        cout << "\nNo: Matrix is NOT scalar.";
    system("pause>0");
}
