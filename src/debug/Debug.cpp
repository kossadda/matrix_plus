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
  S21Matrix matrix1(3, 2);
  double values1[] = {5.23, 53456.11, 534.532, 0.432567, 24.5363, 6453.23444};
  matrix1.Fill(values1);

  matrix1.Print();

  std::cout << std::endl;

  matrix1 = matrix1.Transpose();

  matrix1.Print();

  return 0;
}