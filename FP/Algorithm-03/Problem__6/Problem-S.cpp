#include<iostream>
#include<string>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols) {
    short Counter = 0;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            Counter++;
            arr[i][j] = Counter;
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int arr[3][3];
    
    FillMatrixWithOrderedNumbers(arr, 3, 3);
    
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    
    PrintMatrix(arr, 3, 3);
    
    system("pause>0");
}
