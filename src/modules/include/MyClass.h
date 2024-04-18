/**
 * @file MyClass.h
 * @author kossadda (https://github.com/kossadda)
 * @brief 
 * @version 1.0
 * @date 2024-04-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

class S21Matrix
{
private:
  int rows_, cols_;
  double **matrix_;
  bool EqualSize(const S21Matrix& other);
public:
  S21Matrix(int rows, int cols);
  S21Matrix();
  ~S21Matrix();
  enum Status {NO, YES};
  void FillMatrix(double *values);
  void MatrixPrint();
  void SumMatrix(const S21Matrix& other);
};

#endif // MYCLASS_H