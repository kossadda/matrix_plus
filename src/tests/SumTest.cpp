/**
 * @file SumTest.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief SumMatrix method testing module
 * @version 1.0
 * @date 2024-04-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./MainTest.h"

TEST(SumMatrixInvalidTest, Test_1) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.0, 2.0, 3.0, 4.0};
  matrix1.Fill(values1);

  S21Matrix matrix2(2, 1);
  double values2[] = {5.0, 2.0};
  matrix2.Fill(values2);

  ASSERT_THROW(matrix1.SumMatrix(matrix2), std::invalid_argument);
}

TEST(SumMatrixInvalidTest, Test_2) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.0, 2.0, 3.0, 4.0};
  matrix1.Fill(values1);

  S21Matrix matrix2(2, 2);
  double values2[] = {5.0, 1.0 / 0.0};
  matrix2.Fill(values2);

  ASSERT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}

TEST(SumMatrixTest, Test_1) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.0, 2.0, 3.0, 4.0};
  matrix1.Fill(values1);

  S21Matrix matrix2(2, 2);
  double values2[] = {5.0, 6.0, 7.0, 8.0};
  matrix2.Fill(values2);

  S21Matrix expected(2, 2);
  double expected_values[] = {6.0, 8.0, 10.0, 12.0};
  expected.Fill(expected_values);

  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_2) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  matrix1.Fill(values1);

  S21Matrix matrix2(3, 3);
  double values2[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  matrix2.Fill(values2);

  S21Matrix expected(3, 3);
  double expected_values[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  expected.Fill(expected_values);

  matrix1 += matrix2;
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_3) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1.7357, 5234.32456745, 3455.2358258, -457387.2345, 1.111,
                      2.222,  3.333,         4.444,        5.555};
  matrix1.Fill(values1);

  S21Matrix matrix2(3, 3);
  double values2[] = {4.543543, -1.5432534, 783465.543867453,
                      12.54345, 1.111,      2.222,
                      3.333,    4.444,      5.555};
  matrix2.Fill(values2);

  S21Matrix expected(3, 3);
  double expected_values[] = {6.279243,      5232.78131405, 786920.779693253,
                              -457374.69105, 2.222,         4.444,
                              6.666,         8.888,         11.11};
  expected.Fill(expected_values);

  matrix1 = matrix1 + matrix2;

  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_4) {
  S21Matrix matrix1(1, 5);
  double values1[] = {1.7357, 5234.32456745, 3455.2358258, -457387.2345,
                      4.543543};
  matrix1.Fill(values1);

  S21Matrix matrix2(1, 5);
  double values2[] = {-1.5432534, 783465.543867453, 12.54345, 0, 1};
  matrix2.Fill(values2);

  S21Matrix expected(1, 5);
  double expected_values[] = {0.1924466, 788699.868434903, 3467.7792758,
                              -457387.2345, 5.543543};
  expected.Fill(expected_values);

  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_5) {
  S21Matrix matrix1(7, 1);
  double values1[] = {6534.6534645,     -6453.654654,    345345.6765,
                      65434234.4234234, 1.1111111111111, -7.77777777,
                      345.6789};
  matrix1.Fill(values1);

  S21Matrix matrix2(7, 1);
  double values2[] = {-9876.54321, 123456.789,  -123456789.123456, 0.0000001,
                      1000000.0,   -0.12345789, 0.987654321};
  matrix2.Fill(values2);

  S21Matrix expected(7, 1);
  double expected_values[] = {
      -3341.8897455,         117003.134346, -123111443.446956, 65434234.4234235,
      1000001.1111111111111, -7.90123566,   346.666554321};
  expected.Fill(expected_values);

  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_6) {
  S21Matrix matrix1(2, 3);
  double values1[] = {
      0, 1, 6534.6534645, -6453.654654, 345345.6765, 65434234.4234234};
  matrix1.Fill(values1);

  S21Matrix matrix2(2, 3);
  double values2[] = {1.1111111111111, -7.77777777, 345.6789,
                      -9876.54321,     123456.789,  -123456789.123456,
                      0.0000001,       1000000.0};
  matrix2.Fill(values2);

  S21Matrix expected(2, 3);
  double expected_values[] = {1.1111111111111, -7.77777777, 345.6789,
                              -9876.54321,     123456.789,  -123456789.123456,
                              1.0000001,       1000001.0};
  expected.Fill(expected_values);

  matrix1.SumMatrix(matrix2);
  EXPECT_FALSE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_7) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.7357, 5234.32456745, 3455.2358258, -457387.2345};
  matrix1.Fill(values1);

  S21Matrix matrix2(2, 2);
  double values2[] = {4.543543, -1.5432534, 783465.543867453, 12.54345};
  matrix2.Fill(values2);

  S21Matrix expected(2, 2);
  double expected_values[] = {6.279243, 5232.78131405, 786920.779693253,
                              -457374.69105};
  expected.Fill(expected_values);

  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_8) {
  S21Matrix matrix1(3, 4);
  double values1[] = {6534.6534645,      -6453.654654,    345345.6765,
                      65434234.4234234,  1.1111111111111, -7.77777777,
                      345.6789,          -9876.54321,     123456.789,
                      -123456789.123456, 0.0000001,       1000000.0};
  matrix1.Fill(values1);

  S21Matrix matrix2(3, 4);
  double values2[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  matrix2.Fill(values2);

  S21Matrix expected(3, 4);
  double expected_values[] = {6534.6534645,      -6453.654654,    345345.6765,
                              65434234.4234234,  1.1111111111111, -7.77777777,
                              345.6789,          -9876.54321,     123456.789,
                              -123456789.123456, 0.0000001,       1000000.0};
  expected.Fill(expected_values);

  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_9) {
  S21Matrix matrix1(9, 3);
  double values1[] = {6534.6534645,
                      -6453.654654,
                      345345.6765,
                      65434234.4234234,
                      1.1111111111111,
                      -7.77777777,
                      345.6789,
                      -9876.54321,
                      123456.789,
                      -123456789.123456,
                      0.0000001,
                      1000000.0,
                      2.71828,
                      3.14159,
                      -1.61803,
                      1.41421,
                      0.57721,
                      -0.30103,
                      1000.0,
                      -10000.0,
                      3141592.653589793,
                      -2718281.828459045,
                      1618033.988749895,
                      -1414213.562373095,
                      -6453.654654,
                      345345.6765,
                      65434234};
  matrix1.Fill(values1);

  S21Matrix matrix2(9, 3);
  double values2[] = {5772156.649015329,
                      -3010299.956639812,
                      123456789.0,
                      -987654321.0,
                      456789123.0,
                      -123456789.0,
                      100000000.0,
                      -1000000000.0,
                      2.71828,
                      3.14159,
                      -1.61803,
                      1.41421,
                      0.57721,
                      -0.30103,
                      1000.0,
                      -10000.0,
                      16411.1966745,
                      -129910.443654,
                      123802134.79995,
                      0.0005432,
                      0.000000123,
                      0.0000001,
                      1000000.0,
                      -123456787.8888888888889,
                      987654313.22222223,
                      -456788777.3211,
                      74324.77121211};
  matrix2.Fill(values2);

  S21Matrix expected(9, 3);
  double expected_values[] = {5778691.302479829,
                              -3016753.611293812,
                              123802134.6765,
                              -922220086.5765766,
                              456789124.1111111111111,
                              -123456796.77777777,
                              100000345.6789,
                              -1000009876.54321,
                              123459.50728,
                              -123456785.981866,
                              -1.6180299,
                              1000001.41421,
                              3.29549,
                              2.84056,
                              998.38197,
                              -9998.58579,
                              16411.7738845,
                              -129910.744684,
                              123803134.79995,
                              -9999.9994568,
                              3141592.653589916,
                              -2718281.828458945,
                              2618033.988749895,
                              -124871001.4512619838889,
                              987647859.56756823,
                              -456443431.6446,
                              65508558.77121211};
  expected.Fill(expected_values);

  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(SumMatrixTest, Test_10) {
  S21Matrix matrix1(8, 4);
  double values1[] = {1.7357,
                      5234.32456745,
                      3455.2358258,
                      -457387.2345,
                      4.543543,
                      -1.5432534,
                      783465.543867453,
                      12.54345,
                      0,
                      1,
                      6534.6534645,
                      -6453.654654,
                      345345.6765,
                      65434234.4234234,
                      1.1111111111111,
                      -7.77777777,
                      345.6789,
                      -9876.54321,
                      123456.789,
                      -123456789.123456,
                      0.0000001,
                      1000000.0,
                      -0.12345789,
                      0.987654321,
                      789.123456,
                      -1234.56789,
                      123.456789,
                      12345678.9,
                      -9876543.21,
                      1234567.89,
                      -123456.789,
                      12345.6789};
  matrix1.Fill(values1);

  S21Matrix matrix2(8, 4);
  double values2[] = {2.71828,
                      3.14159,
                      -1.61803,
                      1.41421,
                      0.57721,
                      -0.30103,
                      1000.0,
                      -10000.0,
                      3141592.653589793,
                      -2718281.828459045,
                      1618033.988749895,
                      -1414213.562373095,
                      5772156.649015329,
                      -3010299.956639812,
                      123456789.0,
                      -987654321.0,
                      456789123.0,
                      -123456789.0,
                      100000000.0,
                      -1000000000.0,
                      2.71828,
                      3.14159,
                      -1.61803,
                      1.41421,
                      0.57721,
                      -0.30103,
                      1000.0,
                      -10000.0,
                      5423.453534,
                      4533.645645,
                      -125342.1111,
                      57347234.234234};
  matrix2.Fill(values2);

  S21Matrix expected(8, 4);
  double expected_values[] = {4.45398,
                              5237.46615745,
                              3453.6177958,
                              -457385.82029,
                              5.120753,
                              -1.8442834,
                              784465.543867453,
                              -9987.45655,
                              3141592.653589793,
                              -2718280.828459045,
                              1624568.642214395,
                              -1420667.217027095,
                              6117502.325515329,
                              62423934.466783588,
                              123456790.1111111111111,
                              -987654328.77777777,
                              456789468.6789,
                              -123466665.54321,
                              100123456.789,
                              -1123456789.123456,
                              2.7182801,
                              1000003.14159,
                              -1.74148789,
                              2.401864321,
                              789.700666,
                              -1234.86892,
                              1123.456789,
                              12335678.9,
                              -9871119.756466,
                              1239101.535645,
                              -248798.9001,
                              57359579.913134};
  expected.Fill(expected_values);

  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}