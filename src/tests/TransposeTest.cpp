/**
 * @file TransposeTest.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief Transpose method testing module
 * @version 1.0
 * @date 2024-05-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./MainTest.h"

TEST(TransposeTest, Test_1) {
  S21Matrix matrix1(5, 2);
  double values1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 0.0};
  matrix1.Fill(values1);

  S21Matrix expected(2, 5);
  double expected_values[] = {1.0, 3.0, 5.0, 7.0, 9.0, 2.0, 4.0, 6.0, 8.0, 0.0};
  expected.Fill(expected_values);

  matrix1 = matrix1.Transpose();
  EXPECT_TRUE(matrix1 == expected);
}
