/**
 * @file MyClass.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief
 * @version 1.0
 * @date 2024-04-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./include/MyClass.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3)
{
  Allocate();
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
  Allocate();
}

S21Matrix::~S21Matrix()
{
  Remove();
}

S21Matrix::S21Matrix(const S21Matrix& other)
{
  if (other.rows_ > 0 && other.cols_ > 0) {
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    Allocate();
    CopyValues(other);
  }
}

void S21Matrix::Allocate()
{
  if(rows_ && cols_) {
    matrix_ = new double*[rows_];

    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
  }
}

void S21Matrix::Remove() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i]) {
        delete[] matrix_[i];
        matrix_[i] = NULL;
      }
    }

    delete[] matrix_;
    matrix_ = NULL;
  }
}

void S21Matrix::CopyValues(const S21Matrix& other)
{
  for(int i = 0; i < rows_; i++) {
    for(int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::MatrixPrint()
{
  if (rows_ && cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        std::cout << matrix_[i][j] << " ";
      }

      std::cout << std::endl;
    }
  }
}

void S21Matrix::FillMatrix(double* values)
{
  for (int i = 0, cnt = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = values[cnt++];
    }
  }
}

bool S21Matrix::IsNanOrInf() const
{
  bool check = NO;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::isnan(matrix_[i][j]) || std::isinf(matrix_[i][j])) {
        check = YES;
        i = rows_;
        j = cols_;
      }
    }
  }

  return check;
}

bool S21Matrix::ValidEqualSize(const S21Matrix& other) const
{
  return (rows_ == other.rows_ && cols_ == other.cols_ && rows_ && cols_) ? YES
                                                                          : NO;
}

void S21Matrix::SumMatrix(const S21Matrix& other)
{
  if (ValidEqualSize(other) && !IsNanOrInf() && !other.IsNanOrInf()) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other)
{
  if (ValidEqualSize(other) && !IsNanOrInf() && !other.IsNanOrInf()) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other)
{
  bool status = YES;

  if(ValidEqualSize(other) && !IsNanOrInf() && !other.IsNanOrInf()) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if(matrix_[i][j] != other.matrix_[i][j]) {
          status = NO;
          i = rows_;
          j = cols_;
        }
      }
    }
  } else {
    status = NO;
  }

  return status;
}

bool S21Matrix::operator==(const S21Matrix& other)
{
  bool status = EqMatrix(other);

  return status;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other)
{
  S21Matrix result(*this);
  result.SumMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other)
{
  S21Matrix result(*this);
  result.SubMatrix(other);

  return result;
}

void S21Matrix::operator+=(const S21Matrix& other)
{
  SumMatrix(other);
}

void S21Matrix::operator-=(const S21Matrix& other)
{
  SubMatrix(other);
}

void S21Matrix::operator=(const S21Matrix& other)
{
  if(this != &other && other.rows_ > 0 && other.cols_ > 0) {
    Remove();

    rows_ = other.rows_;
    cols_ = other.cols_;
    Allocate();
    CopyValues(other);
  }
}