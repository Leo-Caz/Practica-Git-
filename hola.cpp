#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double A[3][3], inv[3][3];
    cout << "Ingrese los datos de la matriz 3x3:\n";
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    double det = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1])
                 - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0])
                 + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    if (det == 0) {
        cout << "\nLa matriz NO tiene inversa (determinante = 0).\n";
        return 0;
    }
    inv[0][0] = (A[1][1]*A[2][2] - A[1][2]*A[2][1]) / det;
    inv[0][1] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]) / det;
    inv[0][2] = (A[0][1]*A[1][2] - A[0][2]*A[1][1]) / det;

    inv[1][0] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]) / det;
    inv[1][1] = (A[0][0]*A[2][2] - A[0][2]*A[2][0]) / det;
    inv[1][2] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]) / det;

    inv[2][0] = (A[1][0]*A[2][1] - A[1][1]*A[2][0]) / det;
    inv[2][1] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]) / det;
    inv[2][2] = (A[0][0]*A[1][1] - A[0][1]*A[1][0]) / det;

    cout << fixed << setprecision(4);
    cout << "\nMatriz inversa (4 decimales):\n";
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << setw(10) << inv[i][j];
        }
        cout << "\n";
    }
    return 0;
}
