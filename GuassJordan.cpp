#include <iostream>
using namespace std;
int main() {
int n;
cout << "Enter number of equations: ";
cin >> n;
if (n <= 0 || n > 10) {
cout << "Error: Matrix size must be between 1  and 10.\n";
return 1;
}
double matrix[10][11];
cout << "Enter coefficients matrix A and constants  b row by row:\n";
for (int i = 0; i < n; i++) {
cout << "Row " << i + 1 << " coefficients (" << n << " values): ";
for (int j = 0; j < n; j++)
cin >> matrix[i][j];
cout << "Row " << i + 1 << " constant (b[" << i << "]): ";
cin >> matrix[i][n];
}
for (int pivot = 0; pivot < n; pivot++) {
int max_row = pivot;
for (int r = pivot + 1; r < n; r++)
if (abs(matrix[r][pivot]) >
abs(matrix[max_row][pivot]))
max_row = r;
if (max_row != pivot)
for (int col = 0; col <= n; col++)
swap(matrix[pivot][col],
matrix[max_row][col]);
if (matrix[pivot][pivot] > -1e-9 &&
matrix[pivot][pivot] < 1e-9) {
cout << "Error: Matrix is singular. No unique solution exists.\n";
return 2;
}
double divisor = matrix[pivot][pivot];
for (int col = 0; col <= n; col++)
matrix[pivot][col] /= divisor;
for (int row = 0; row < n; row++) {
if (row == pivot) continue;
double factor = matrix[row][pivot];
for (int col = 0; col <= n; col++)
matrix[row][col] -= factor *
matrix[pivot][col];
}
}
cout << "The solution of guass jordan elimination:";
for (int i = 0; i < n; i++)
cout << "x[" << i << "] = " << matrix[i][n] << "\n";
return 0;
}
