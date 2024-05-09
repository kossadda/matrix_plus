/**
 * @file Matrix.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header for the S21Matrix class
 * @version 1.0
 * @date 2024-04-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <algorithm>
#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double* matrix_;
  bool IsCorrect() const;
  bool CompareIsRight(const S21Matrix& other) const;
  double* Alloc();
  void Remove();
  double Recursive();
  S21Matrix Minor(int row, int col);
  enum Status { NO, YES, DEFAULT = 3 };

 public:
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  S21Matrix();
  ~S21Matrix();
  void Fill(const double* values);
  void Print() const;
  void Resize(int rows, int cols);
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  double& operator()(int row, int col);
  bool operator==(const S21Matrix& other) const;
  bool operator!=(const S21Matrix& other) const;
  void operator=(const S21Matrix& other);
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double num);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();
  int GetRows() const { return rows_; };
  int GetCols() const { return cols_; };
};

#endif  // MATRIX_H