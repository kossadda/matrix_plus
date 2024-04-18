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

S21Matrix::S21Matrix(int rows, int cols)
{
  Status status = YES;
  
  if(rows > 0 && cols > 0) {
    this->rows_ = rows;
    this->cols_ = cols;
    this->matrix_ = new double* [rows_];

    if(matrix_) {
      for(int i = 0; i < rows_; i++) {
        matrix_[i] = new double [cols_]();
        
        if(!matrix_[i]) {
          status = NO;
        }
      }
    } else {
      status = NO;
    }
  } else {
    status = NO;
  }

  if(status == NO) {
    std::cerr << "Matrix construct: error while allocating memory" << std::endl;
  }
}

S21Matrix::~S21Matrix()
{
  if(matrix_) {
    for(int i = 0; i < rows_; i++) {
      if(matrix_[i]){
        delete[] matrix_[i];
      }
    }

    delete[] matrix_;
  }
}

S21Matrix::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
}

void S21Matrix::MatrixPrint()
{
  if(rows_ && cols_) {
    for(int i = 0; i < rows_; i++) {
      for(int j = 0; j < cols_; j++) {
        std::cout << matrix_[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
}

void S21Matrix::FillMatrix(double *values)
{
  for(int i = 0, cnt = 0; i < rows_; i++) {
    for(int j = 0; j < cols_; j++ ) {
      matrix_[i][j] = values[cnt++];
    }
  }
}

bool S21Matrix::EqualSize(const S21Matrix& other)
{
  return (rows_ != other.cols_ || cols_ != other.cols_) ? NO : YES; 
}

void S21Matrix::SumMatrix(const S21Matrix& other)
{
  if(EqualSize(other)) {
    for(int i = 0; i < rows_; i++) {
      for(int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  } else {
    std::cerr << "SumMatrix: matrix of different dimensions" << std::endl;
  }
}