/**
 * @file MyClass.h
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

#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  bool ValidEqualSize(const S21Matrix& other) const;
  bool IsNanOrInf() const;
  void Allocate();
  void Remove();
  void CopyValues(const S21Matrix& other);

 public:
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix();
  ~S21Matrix();
  enum Status { NO, YES };
  void FillMatrix(const double* values);
  void MatrixPrint() const;
  int GetRows() const { return rows_; };
  int GetCols() const { return cols_; };
  double GetCell(int row, int col) const { return matrix_[row][col]; };
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  bool operator!=(const S21Matrix& other) const;
  void operator=(const S21Matrix& other);
};

#endif  // MATRIX_H