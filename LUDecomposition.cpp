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
double A[10][10], b[10];
double L[10][10] = {}, U[10][10] = {};
cout << "Enter coefficients matrix A:\n";
for (int i = 0; i < n; i++) {
cout << "Row " << i + 1 << " coefficients (" << n << " values): ";
for (int j = 0; j < n; j++)
cin >> A[i][j];
}
cout << "Enter constants vector b:\n";
for (int i = 0; i < n; i++) {
cout << "b[" << i << "] = ";
cin >> b[i];
}
for (int pivot = 0; pivot < n; pivot++) {
for (int col = pivot; col < n; col++) {
U[pivot][col] = A[pivot][col];
for (int k = 0; k < pivot; k++)
U[pivot][col] -= L[pivot][k] *
U[k][col];
}
if (U[pivot][pivot] > -1e-9 && U[pivot][pivot]  < 1e-9) {
cout << "Error: Matrix is singular. No unique solution exists.\n";
return 2;
}
L[pivot][pivot] = 1;
for (int row = pivot + 1; row < n; row++) { L[row][pivot] = A[row][pivot];
for (int k = 0; k < pivot; k++)
L[row][pivot] -= L[row][k] *
U[k][pivot];
L[row][pivot] /= U[pivot][pivot];
}
}
double y[10];
for (int i = 0; i < n; i++) {
y[i] = b[i];
for (int j = 0; j < i; j++)
y[i] -= L[i][j] * y[j];
}
double x[10];
for (int i = n - 1; i >= 0; i--) {
x[i] = y[i];
for (int j = i + 1; j < n; j++)
x[i] -= U[i][j] * x[j];
x[i] /= U[i][i];
}
cout << "The solution of elimination:";
for (int i = 0; i < n; i++)
cout << "x[" << i << "] = " << x[i] << "\n";
return 0;
}
