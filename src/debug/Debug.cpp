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
  S21Matrix matrix1(4, 4);
  double values1[] = {1.123, 4.534, 1.1235, 6.331, 7.77, 0.5345, 111.14, 456.66, 57.787, 354.11, 1231, 4.565, 0.0, 14.44, 23.333, 1.534};
  matrix1.Fill(values1);

  matrix1 = matrix1.InverseMatrix();

  // matrix1.Print();
  return 0;
}