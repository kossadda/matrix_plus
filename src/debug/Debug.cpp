/**
 * @file debug.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief 
 * @version 1.0
 * @date 2024-04-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./../s21_matrix_oop.h"

int main()
{
  S21Matrix first(3, 3);
  double init[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double init2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  S21Matrix second;
  first.FillMatrix(init);
  second.FillMatrix(init2);
  first.SumMatrix(second);
  S21Matrix k(first);
  k.MatrixPrint();
}