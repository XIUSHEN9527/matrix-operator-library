#include "matrix.h"
#include <optional>
// 构造函数
Matrix::Matrix(unsigned int M, unsigned int N, float val){
    m_Data.resize(M * N, val);
    m_M = M;
    m_N = N;
}

Matrix::Matrix(std::vector<float> buff, unsigned int M, unsigned int N) : m_M(M), m_N(N), m_Data(buff) {}


// 成员函数
Matrix Matrix::Multiple(const Matrix& A, const Matrix& B) {
    Matrix C(A.m_M, B.m_N, 0.0f);

    for (int i = 1; i <= A.m_M; i++) {
        for (int j = 1; j <= B.m_N; j++) {
            float sum = 0.0f;
            for (unsigned int k = 1; k <= A.m_N; k++) {
                sum += A(i, k) * B(k, j);
            }
            C(i, j) = sum;
        }
    }
    return C;
}

std::optional<Matrix> Matrix::Multiple_check(const Matrix& A, const Matrix& B) {
    /*unsigned int MB, NB;
    std::tie(MB, NB) = B.getSize();*/

    Matrix C(A.m_M, B.m_N, 0.0f);

    if (A.m_N != B.m_M) return {};
    for (unsigned int i = 1; i <= A.m_M; i++) {
        for (unsigned int j = 1; j <= B.m_N; j++) {
            float sum = 0.0f;
            for (unsigned int k = 1; k <= A.m_N; k++) {
                sum += A(i, k) * B(k, j);
            }
            C(i, j) = sum;
        }
    }
    return { C };
}


void Matrix::print(const Matrix& A){
    for (unsigned int i = 1; i <= A.m_M; i++) {
        for (unsigned int j = 1; j <= A.m_N; j++) {
            std::cout << A(i, j) << " ";
        }
        puts("");
    }
    return;
}

void Matrix::print(std::optional<Matrix>& A) {
    if (A) {
        auto B = *A;
        for (unsigned int i = 1; i <= B.m_M; i++) {
            for (unsigned int j = 1; j <= B.m_N; j++) {
                //std::cout << B.element(i, j) << " ";
                std::cout << B(i, j) << " ";
                //printf("%f ", B.getElement(i, j));
            }
            puts("");
        }
        return;
    }
    else {
        std::cout << "Error: Dimension mismatch matrix" << std::endl;
    }
}

float& Matrix::operator() (unsigned int i, unsigned int j) {
    return m_Data[(i - 1)*m_N + j - 1];
}

float Matrix::element(unsigned int i, unsigned int j) const{
    return m_Data[(i - 1)*m_N + j - 1];
}

Matrix operator*(const Matrix& A, const Matrix& B) {
    return Matrix::Multiple(A, B);
}

const float& Matrix::operator() (unsigned int i, unsigned int j) const {
    return m_Data[(i - 1)*m_N + j - 1];
}
