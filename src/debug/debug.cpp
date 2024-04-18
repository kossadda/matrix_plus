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
  S21Matrix first(4, 4);
  S21Matrix second(4, 4);
  double init[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  first.FillMatrix(init);
  second.FillMatrix(init);
  first.SumMatrix(second);
  first.MatrixPrint();
}