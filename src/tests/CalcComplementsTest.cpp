/**
 * @file CalcComplementsTest.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief CalcComplements method testing module
 * @version 1.0
 * @date 2024-05-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./MainTest.h"

TEST(CalcComplementsInvalidTest, Test_1) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.0, 0.0 / 0.0, 3.0, 4.0};
  matrix1.Fill(values1);

  ASSERT_THROW(matrix1.Determinant(), std::invalid_argument);
}

TEST(CalcComplementsInvalidTest, Test_2) {
  S21Matrix matrix1(1, 2);

  ASSERT_THROW(matrix1.CalcComplements(), std::invalid_argument);
}

TEST(CalcComplementsTest, Test_1) {
  S21Matrix matrix1(3, 3);
  double values1[] = {0.73, -0.19, -0.12, -0.07, 0.72, -0.17, -0.12, -0.15, 0.92};
  matrix1.Fill(values1);

  S21Matrix expected(3, 3);
  double expected_values[] = {0.6369, 0.0848, 0.0969, 0.1928, 0.6572, 0.1323, 0.1187, 0.1325, 0.5123};
  expected.Fill(expected_values);

  EXPECT_TRUE(matrix1.CalcComplements() == expected);
}

TEST(CalcComplementsTest, Test_2) {
  S21Matrix matrix1(1, 1);
  double values1[] = {1.123};
  matrix1.Fill(values1);

  S21Matrix expected(matrix1);

  EXPECT_TRUE(matrix1.CalcComplements() == expected);
}