/**
 * @file OtherTest.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief Other methods testing module
 * @version 1.0
 * @date 2024-05-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./MainTest.h"

TEST(DefaultConstructorTest, Test_1) {
  S21Matrix matrix1;

  EXPECT_TRUE(matrix1.GetCols() == 0);
  EXPECT_TRUE(matrix1.GetRows() == 0);
}

TEST(MoveConstructorTest, Test_1) {
  S21Matrix matrix1(2, 3);
  double values1[] = {
      0, 1, 6534.6534645, -6453.654654, 345345.6765, 65434234.4234234};
  matrix1.Fill(values1);

  S21Matrix copy(matrix1);
  S21Matrix move(std::move(matrix1));

  EXPECT_TRUE(copy == move);
  EXPECT_TRUE(matrix1.GetCols() == 0);
  EXPECT_TRUE(matrix1.GetRows() == 0);
}

TEST(IndexTest, Test_1) {
  S21Matrix matrix1(2, 3);
  double values1[] = {
      0, 1, 6534.6534645, -6453.654654, 345345.6765, 65434234.4234234};
  matrix1.Fill(values1);

  ASSERT_THROW(matrix1(4, 1), std::out_of_range);
}

TEST(IndexTest, Test_2) {
  S21Matrix matrix1(2, 3);
  double values1[] = {
      0, 1, 6534.6534645, -6453.654654, 345345.6765, 65434234.4234234};
  matrix1.Fill(values1);

  ASSERT_THROW(matrix1(0, 4), std::out_of_range);
}

TEST(IndexTest, Test_3) {
  S21Matrix matrix1(2, 3);
  double values1[] = {
      0, 1, 6534.6534645, -6453.654654, 345345.6765, 65434234.4234234};
  matrix1.Fill(values1);

  EXPECT_TRUE(matrix1(0, 2) == 6534.6534645);
}

TEST(ConstructorTest, Test_1) {
  ASSERT_THROW(S21Matrix matrix(-1, 2), std::invalid_argument);
}

TEST(ConstructorTest, Test_2) {
  ASSERT_THROW(S21Matrix matrix(2, -1), std::invalid_argument);
}

TEST(ConstructorTest, Test_3) {
  ASSERT_THROW(S21Matrix matrix(0, 2), std::invalid_argument);
}

TEST(ConstructorTest, Test_4) {
  ASSERT_THROW(S21Matrix matrix(2, 0), std::invalid_argument);
}

TEST(ConstructorTest, Test_5) {
  ASSERT_THROW(S21Matrix matrix(-2, -2), std::invalid_argument);
}

TEST(PrintTest, Test_1) {
  S21Matrix matrix(3, 3);
  matrix.Print();
}

TEST(EqualOperatorTest, Test_1) {
  S21Matrix matrix(1, 1);
  matrix = matrix;
}

TEST(SetColsTest, Test_1) {
  S21Matrix matrix1(4, 4);
  double values1[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2,
                      3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
  matrix1.Fill(values1);

  S21Matrix expected(4, 3);
  double expected_values[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
  expected.Fill(expected_values);

  matrix1.SetCols(3);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SetColsTest, Test_2) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
  matrix1.Fill(values1);

  S21Matrix expected(3, 4);
  double expected_values[] = {1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0};
  expected.Fill(expected_values);

  matrix1.SetCols(4);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SetColsTest, Test_3) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
  matrix1.Fill(values1);

  S21Matrix expected(matrix1);

  matrix1.SetCols(3);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SetColsTest, Test_4) {
  S21Matrix matrix1(3, 3);

  ASSERT_THROW(matrix1.SetCols(0), std::invalid_argument);
}

TEST(SetRowsTest, Test_1) {
  S21Matrix matrix1(4, 4);
  double values1[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2,
                      3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
  matrix1.Fill(values1);

  S21Matrix expected(3, 4);
  double expected_values[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
  expected.Fill(expected_values);

  matrix1.SetRows(3);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SetRowsTest, Test_2) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
  matrix1.Fill(values1);

  S21Matrix expected(4, 3);
  double expected_values[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 0, 0, 0};
  expected.Fill(expected_values);

  matrix1.SetRows(4);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SetRowsTest, Test_3) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
  matrix1.Fill(values1);

  S21Matrix expected(matrix1);

  matrix1.SetRows(3);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SetRowsTest, Test_4) {
  S21Matrix matrix1(3, 3);

  ASSERT_THROW(matrix1.SetRows(0), std::invalid_argument);
}