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

TEST(TransposeInvalidTest, Test_1) {
  S21Matrix matrix1(1, 2);
  double values1[] = {1.0, 0.0 / 0.0};
  matrix1.Fill(values1);

  ASSERT_THROW(matrix1.Transpose(), std::invalid_argument);
}

TEST(TransposeTest, Test_1) {
  S21Matrix matrix1(5, 2);
  double values1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 0.0};
  matrix1.Fill(values1);

  S21Matrix expected(2, 5);
  double expected_values[] = {1.0, 3.0, 5.0, 7.0, 9.0, 2.0, 4.0, 6.0, 8.0, 0.0};
  expected.Fill(expected_values);

  EXPECT_TRUE(matrix1.Transpose() == expected);
}

TEST(TransposeTest, Test_2) {
  S21Matrix matrix1(1, 3);
  double values1[] = {1.0, 2.0, 3.0};
  matrix1.Fill(values1);

  S21Matrix expected(3, 1);
  double expected_values[] = {1.0, 2.0, 3.0};
  expected.Fill(expected_values);

  EXPECT_TRUE(matrix1.Transpose() == expected);
}

TEST(TransposeTest, Test_3) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.0, 2.0, 3.0, 4.0};
  matrix1.Fill(values1);

  S21Matrix expected(matrix1);

  EXPECT_TRUE(matrix1.Transpose() == expected);
}