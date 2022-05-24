#pragma once

#include <iostream>
#include <vector>
#include <optional>

class Matrix {

//静态方法
public:
    static std::optional<Matrix> Multiple_check(const Matrix& A, const Matrix& B);
    static Matrix Multiple(const Matrix& A, const Matrix& B);
    static void print(const Matrix& A);
    static void print(std::optional<Matrix>& A);
// 数据访问
public:
    //运算符operator重载
    float& operator() (unsigned int i, unsigned int j); // 非常量函数
    const float& operator() (unsigned int i, unsigned int j) const; // 常量函数，常量的Matrix对象可以调用

    //element简化getElement、setElement，将它定义为常量函数，这样常量的matrix也可以访问
    float element(unsigned int i, unsigned int j) const;

// 构造
public:
    Matrix(unsigned int M, unsigned int N, float val = 0.0f);
    Matrix(std::vector<float> buff, unsigned int M, unsigned int N);

// 成员数据
private:
    // 尺寸
    unsigned int m_M, m_N;
    // 实际数据
    std::vector<float> m_Data;
};

// 普通函数的运算符重载
Matrix operator*(const Matrix& A, const Matrix& B);
