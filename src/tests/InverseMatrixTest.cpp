/**
 * @file InverseMatrixTest.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief InverseMatrix method testing module
 * @version 1.0
 * @date 2024-05-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./MainTest.h"

TEST(InverseMatrixInvalidTest, Test_1) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.0, 0.0 / 0.0, 3.0, 4.0};
  matrix1.Fill(values1);

  ASSERT_THROW(matrix1.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixInvalidTest, Test_2) {
  S21Matrix matrix1(1, 2);

  ASSERT_THROW(matrix1.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixInvalidTest, Test_3) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  matrix1.Fill(values1);

  ASSERT_THROW(matrix1.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixInvalidTest, Test_4) {
  S21Matrix matrix1(1, 1);
  double values1[] = {0};
  matrix1.Fill(values1);
  
  ASSERT_THROW(matrix1.InverseMatrix(), std::invalid_argument);
}

TEST(InverseMatrixTest, Test_1) {
  S21Matrix matrix1(4, 4);
  double values1[] = {1.123, 4.534, 1.1235, 6.331, 7.77, 0.5345, 1.14, 4.66, 7.787, 4.11, 0.433, 4.565, 0.0, 3.42, 3.333, 1.534};
  matrix1.Fill(values1);

  S21Matrix expected(4, 4);
  double expected_values[] = {-0.1064846, 0.0388999, 0.1049608, 0.0089534, -0.0102129, -0.2397261, 0.2406755, 0.0541702, -0.0808835, 0.1852758, -0.1732068, 0.2864256, 0.1985089, 0.1319027, -0.1602426, -0.0912118};
  expected.Fill(expected_values);

  matrix1 = matrix1.InverseMatrix();
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(InverseMatrixTest, Test_2) {
  S21Matrix matrix1(1, 1);
  double values1[] = {1.123};
  matrix1.Fill(values1);

  S21Matrix expected(1, 1);
  double expected_values[] = {0.8904719};
  expected.Fill(expected_values);
  
  matrix1 = matrix1.InverseMatrix();
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}