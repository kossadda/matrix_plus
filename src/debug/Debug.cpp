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
  S21Matrix matrix1(1, 1);
  double values1[] = {1.123};
  matrix1.Fill(values1);

  matrix1 = matrix1.CalcComplements();

  matrix1.Print();
  return 0;
}