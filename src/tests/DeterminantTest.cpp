/**
 * @file DeterminantTest.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief Determinant method testing module
 * @version 1.0
 * @date 2024-05-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./MainTest.h"

TEST(DeterminantInvalidTest, Test_1) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.0, 0.0 / 0.0, 3.0, 4.0};
  matrix1.Fill(values1);

  ASSERT_THROW(matrix1.Determinant(), std::invalid_argument);
}

TEST(DeterminantInvalidTest, Test_2) {
  S21Matrix matrix1(1, 2);

  ASSERT_THROW(matrix1.Determinant(), std::invalid_argument);
}

TEST(DeterminantTest, Test_1) {
  S21Matrix matrix1(4, 4);
  double values1[] = {1.123, 4.534, 1.1235, 6.331, 7.77, 0.5345, 111.14, 456.66, 57.787, 354.11, 1231, 4.565, 0.0, 14.44, 23.333, 1.534};
  matrix1.Fill(values1);

  EXPECT_TRUE(std::abs(matrix1.Determinant() - -7429360.2403818) < 1.0e-6);
}

TEST(DeterminantTest, Test_2) {
  S21Matrix matrix1(1, 1);
  double values1[] = {1.123};
  matrix1.Fill(values1);

  EXPECT_TRUE(matrix1.Determinant() == 1.123);
}