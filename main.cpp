#include "matrix.h"

using namespace std;

int main()
{
    cout << "A: " << endl;
    Matrix A(2, 2, 1.0f);
    Matrix::print(A);
    puts("");

    Matrix B({ 0.0f, -1.0f, 1.0f, 0.0f }, 2, 2);
    Matrix C({ 0.0f, -1.0f, 1.0f, 0.0f }, 2, 2);
    Matrix D({ 1.0f, 0.0f,0.0f,0.0f,1.0f, 0.0f,0.0f,0.0f,1.0f }, 3, 3);
    auto E = Matrix::Multiple_check(C, D);
    auto F = Matrix::Multiple(B, C);
    auto G = C * B;

    cout << "E = C * D: " << endl;
    Matrix::print(E);
    puts("");
    cout << "F = B * C: " << endl;
    Matrix::print(F);
    puts("");
    cout << "E = B * C: " << endl;
    Matrix::print(G);
    puts("");
    cout << "D: " << endl;
    Matrix::print(D);
    puts("");
    cout << "D(After Revised): " << endl;
    D(1, 2) = 2;
    Matrix::print(D);

    return 0;
}
