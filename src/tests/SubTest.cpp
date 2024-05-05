/**
 * @file SubTest.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief SubMatrix method testing module
 * @version 1.0
 * @date 2024-04-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./MainTest.h"

TEST(Sub_Matrix, Test_1) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.0, 2.0, 3.0, 4.0};
  matrix1.FillMatrix(values1);

  S21Matrix matrix2(2, 2);
  double values2[] = {5.0, 6.0, 7.0, 8.0};
  matrix2.FillMatrix(values2);

  S21Matrix expected(2, 2);
  double expected_values[] = {-4, -4, -4, -4};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected);
}

TEST(Sub_Matrix, Test_2) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  matrix1.FillMatrix(values1);

  S21Matrix matrix2(3, 3);
  double values2[] = {345345.6765, 65434234.4234234, 1.1111111111111,
                      2.71828,     3.14159,          -1.61803,
                      1.41421,     0.57721,          -1.5432534};
  matrix2.FillMatrix(values2);

  S21Matrix expected(3, 3);
  double expected_values[] = {-345344.6765, -65434232.4234234, 1.8888888888889,
                              1.28172,      1.85841,           7.61803,
                              5.58579,      7.42279,           10.5432534};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_3) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.7357, 5234.32456745, 3455.2358258, -457387.2345};
  matrix1.FillMatrix(values1);

  S21Matrix matrix2(2, 2);
  double values2[] = {4.543543, -1.5432534, 783465.543867453, 12.54345};
  matrix2.FillMatrix(values2);

  S21Matrix expected(2, 2);
  double expected_values[] = {-2.807843, 5235.86782085, -780010.308041653,
                              -457399.77795};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_4) {
  S21Matrix matrix1(1, 5);
  double values1[] = {1.7357, 5234.32456745, 3455.2358258, -457387.2345,
                      4.543543};
  matrix1.FillMatrix(values1);

  S21Matrix matrix2(1, 5);
  double values2[] = {-1.5432534, 783465.543867453, 12.54345, 0, 1};
  matrix2.FillMatrix(values2);

  S21Matrix expected(1, 5);
  double expected_values[] = {3.2789534, -778231.219300003, 3442.6923758,
                              -457387.2345, 3.543543};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_5) {
  S21Matrix matrix1(7, 1);
  double values1[] = {6534.6534645,     -6453.654654,    345345.6765,
                      65434234.4234234, 1.1111111111111, -7.77777777,
                      345.6789};
  matrix1.FillMatrix(values1);

  S21Matrix matrix2(7, 1);
  double values2[] = {-9876.54321, 123456.789,  -123456789.123456, 0.0000001,
                      1000000.0,   -0.12345789, 0.987654321};
  matrix2.FillMatrix(values2);

  S21Matrix expected(7, 1);
  double expected_values[] = {
      16411.1966745,         -129910.443654, 123802134.799956, 65434234.4234233,
      -999998.8888888888889, -7.65431988,    344.691245679};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_6) {
  S21Matrix matrix1(11, 2);
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
                      1000000.0};
  matrix1.FillMatrix(values1);

  S21Matrix matrix2(11, 2);
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
                      4325435.324234,
                      0.32472346};
  matrix2.FillMatrix(values2);

  S21Matrix expected(11, 2);
  double expected_values[] = {
      -0.98258,           5231.18297745,      3456.8538558,
      -457388.64871,      3.966333,           -1.2422234,
      782465.543867453,   10012.54345,        -3141592.653589793,
      2718282.828459045,  -1611499.335285395, 1407759.907719095,
      -5426810.972515329, 68444534.380063212, -123456787.8888888888889,
      987654313.22222223, -456788777.3211,    123446912.45679,
      -99876543.211,      876543210.876544,   -4325435.3242339,
      999999.67527654};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_7) {
  S21Matrix matrix1(2, 2);
  double values1[] = {1.7357, 5234.32456745, 3455.2358258, -457387.2345};
  matrix1.FillMatrix(values1);

  S21Matrix matrix2(2, 2);
  double values2[] = {4.543543, -1.5432534, 783465.543867453, 12.54345};
  matrix2.FillMatrix(values2);

  S21Matrix expected(2, 2);
  double expected_values[] = {-2.807843, 5235.86782085, -780010.308041653,
                              -457399.77795};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_8) {
  S21Matrix matrix1(3, 4);
  double values1[] = {6534.6534645,      -6453.654654,    345345.6765,
                      65434234.4234234,  1.1111111111111, -7.77777777,
                      345.6789,          -9876.54321,     123456.789,
                      -123456789.123456, 0.0000001,       1000000.0};
  matrix1.FillMatrix(values1);

  S21Matrix matrix2(3, 4);
  double values2[] = {6534.6534645,      -6453.654654,    345345.6765,
                      65434234.4234234,  1.1111111111111, -7.77777777,
                      345.6789,          -9876.54321,     123456.789,
                      -123456789.123456, 0.0000001,       1000000.0};
  matrix2.FillMatrix(values2);

  S21Matrix expected(3, 4);
  double expected_values[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                              0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_9) {
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
  matrix1.FillMatrix(values1);

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
  matrix2.FillMatrix(values2);

  S21Matrix expected(9, 3);
  double expected_values[] = {-5765621.995550829,
                              3003846.301985812,
                              -123111443.3235,
                              1053088555.4234234,
                              -456789121.8888888888889,
                              123456781.22222223,
                              -99999654.3211,
                              999990123.45679,
                              123454.07072,
                              -123456792.265046,
                              1.6180301,
                              999998.58579,
                              2.14107,
                              3.44262,
                              -1001.61803,
                              10001.41421,
                              -16410.6194645,
                              129910.142624,
                              -123801134.79995,
                              -10000.0005432,
                              3141592.65358967,
                              -2718281.828459145,
                              618033.988749895,
                              122042574.3265157938889,
                              -987660766.87687623,
                              457134122.9976,
                              65359909.22878789};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_10) {
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
  matrix1.FillMatrix(values1);

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
  matrix2.FillMatrix(values2);

  S21Matrix expected(8, 4);
  double expected_values[] = {
      -0.98258,           5231.18297745,      3456.8538558,
      -457388.64871,      3.966333,           -1.2422234,
      782465.543867453,   10012.54345,        -3141592.653589793,
      2718282.828459045,  -1611499.335285395, 1407759.907719095,
      -5426810.972515329, 68444534.380063212, -123456787.8888888888889,
      987654313.22222223, -456788777.3211,    123446912.45679,
      -99876543.211,      876543210.876544,   -2.7182799,
      999996.85841,       1.49457211,         -0.426555679,
      788.546246,         -1234.26686,        -876.543211,
      12355678.9,         -9881966.663534,    1230034.244355,
      1885.3221,          -57334888.555334};
  expected.FillMatrix(expected_values);

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(Sub_Matrix, Test_11) {
  S21Matrix example1(0, 2);
  S21Matrix example2(2, 0);
  S21Matrix example3(0, 0);
  S21Matrix example;
  double values[] = {0.0, 0.0, 0.0, 1.0 / 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  example.FillMatrix(values);
  example.MatrixPrint();
  S21Matrix copy(example);
  example += copy;
  example -= copy;
  example = copy + copy - example;
  example == copy;
  example != copy;
}