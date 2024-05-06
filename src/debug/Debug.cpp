/**
 * @file debug.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief Separate module for manual testing
 * @version 1.0
 * @date 2024-04-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./../s21_matrix_oop.h"

int main()
{
  S21Matrix matrix1(3, 3);
  double values1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  matrix1.Fill(values1);

  S21Matrix matrix2(3, 3);
  double values2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  matrix2.Fill(values2);

  matrix1 *= matrix2;
  matrix1.Print();
}