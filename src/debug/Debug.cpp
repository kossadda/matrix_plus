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

  S21Matrix matrix2(2, 3);
  double values2[] = {7.3442, 76.4344, 54.1112, 4.004, 1.11111, 21.14552};
  matrix2.Fill(values2);

  S21Matrix expected(3, 3);
  double expected_values[] = {214076.674606, 59795.3702941, 1130640.2447032, 3927.441912668, 40857.11333031937, 28933.31481254984, 26018.95019222, 9045.6706873484, 137784.6865522688};
  expected.Fill(expected_values);

  matrix1 = matrix1 * matrix2;
  matrix1.Print();
}