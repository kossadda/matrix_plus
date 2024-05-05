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
  double init1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  double init2[] = {9, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  S21Matrix first;
  S21Matrix second;
  first.Fill(init1);
  second.Fill(init2);
  second = first;
  // std::cout << ((first == second) ? "\nMatrix are equal\n\n" : "\nMatrix are not equal\n\n");
  // first.Print();
  // first.FillMatrix(init);
  second.Print();
  // first.SumMatrix(second);
  // S21Matrix k(first);
  // k.MatrixPrint();
}