/**
 * @file MulTest.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief MulNumner and MulMatrix method testing module
 * @version 1.0
 * @date 2024-04-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./MainTest.h"

TEST(MulNumberInvalidTest, Test_1) {
  S21Matrix matrix1;
  double values1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  matrix1.Fill(values1);

  double num = 0.0 / 0.0;

  ASSERT_THROW(matrix1.MulNumber(num), std::invalid_argument);
}

TEST(MulNumberInvalidTest, Test_2) {
  S21Matrix matrix1;
  double values1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  matrix1.Fill(values1);

  double num = 1.0 / 0.0;

  ASSERT_THROW(matrix1.MulNumber(num), std::invalid_argument);
}

TEST(MulNumberInvalidTest, Test_3) {
  S21Matrix matrix1;
  double values1[] = {1, 2, 3, 4, 5, 6, 7, 1.0 / 0.0, 9};
  matrix1.Fill(values1);

  double num = 1.0;

  ASSERT_THROW(matrix1.MulNumber(num), std::invalid_argument);
}

TEST(MulMatrixInvalidTest, Test_1) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(2, 3);

  ASSERT_THROW(matrix1.MulMatrix(matrix2), std::invalid_argument);
}

TEST(MulMatrixInvalidTest, Test_2) {
  S21Matrix matrix1(3, 3);
  double values1[] = {1, 2, 3, 4, 5, 6, 7, 1.0 / 0.0, 9};
  matrix1.Fill(values1);
  S21Matrix matrix2(3, 3);

  ASSERT_THROW(matrix1.MulMatrix(matrix2), std::invalid_argument);
}

TEST(MulMatrixInvalidTest, Test_3) {
  S21Matrix matrix1(3, 3);
  S21Matrix matrix2(3, 3);
  double values2[] = {1, 2, 3, 4, 5, 6, 7, 0.0 / 0.0, 9};
  matrix2.Fill(values2);

  ASSERT_THROW(matrix1.MulMatrix(matrix2), std::invalid_argument);
}

TEST(MulNumberTest, Test_1) {
  S21Matrix matrix1(2, 2);
  double values1[] = {5.23, 53456.11, 534.532, 0.432567};
  matrix1.Fill(values1);

  double num = 95.4637612;

  S21Matrix expected(2, 2);
  double expected_values[] = {499.275471076, 5103121.319720932,
                              51028.4352017584, 41.2944727910004};
  expected.Fill(expected_values);

  matrix1 = matrix1 * num;
  EXPECT_TRUE(matrix1 == expected);
}

TEST(MulNumberTest, Test_2) {
  S21Matrix matrix1;
  double values1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  matrix1.Fill(values1);

  double num = 12.312;

  S21Matrix expected;
  double expected_values[] = {12.312, 24.624, 36.936, 49.248, 61.56,
                              73.872, 86.184, 98.496, 110.808};
  expected.Fill(expected_values);

  matrix1 *= num;
  EXPECT_TRUE(matrix1.EqMatrix(expected))
      << Print(matrix1, 0) << Print(expected, 1);
}

TEST(MulNumberTest, Test_3) {
  S21Matrix matrix1;
  double values1[] = {345.6765, 654.4234234, 1.1111111111111,
                      2.71828,  3.14159,     -1.61803,
                      1.41421,  0.57721,     -1.5432534};
  matrix1.Fill(values1);

  double num = 914.555;

  S21Matrix expected;
  double expected_values[] = {
      316140.1714575, 598506.213987587, 1016.1722222222120605,
      2486.0165654,   2873.15684245,    -1479.77742665,
      1293.37282655,  527.89029155,     -1411.390113237};
  expected.Fill(expected_values);

  matrix1.MulNumber(num);
  EXPECT_TRUE(matrix1.EqMatrix(expected))
      << Print(matrix1, 0) << Print(expected, 1);
}

TEST(MulMatrixTest, Test_1) {
  S21Matrix matrix1(3, 2);
  double values1[] = {5.23, 53456.11, 534.532, 0.432567, 24.5363, 6453.23444};
  matrix1.Fill(values1);

  S21Matrix matrix2(2, 3);
  double values2[] = {7.3442, 76.4344, 54.1112, 4.004, 1.11111, 21.14552};
  matrix2.Fill(values2);

  S21Matrix expected(3, 3);
  double expected_values[] = {
      214076.674606,  59795.3702941,     1130640.2447032,
      3927.441912668, 40857.11333031937, 28933.31481254984,
      26018.95019222, 9045.6706873484,   137784.6865522688};
  expected.Fill(expected_values);

  matrix1 = matrix1 * matrix2;
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(MulMatrixTest, Test_2) {
  S21Matrix matrix1(4, 2);
  double values1[] = {1.112342, 46.61,   34.442, 54.4111,
                      0.555233, 11.1234, 1.1111, 0.0001};
  matrix1.Fill(values1);

  S21Matrix matrix2(2, 6);
  double values2[] = {100.0,   1.432,  2.312, 5.1234523, 214.2345, 1.523453,
                      75.6342, 42.111, 5.66,  11.11,     0.0,      1.0};
  matrix2.Fill(values2);

  S21Matrix expected(4, 6);
  double expected_values[] = {
      3636.544262,    1964.386583744,  266.384334704, 523.5361311782866,
      238.302032199,  48.304600756926, 7559.54001962, 2340.6267761,
      387.59673,      780.9692651166,  7378.664649,   106.881868226,
      896.83276028,   469.212591056,   64.242142696,  126.4256837908859,
      118.9500641385, 11.969271379549, 111.11756342,  1.5953063,
      2.5694292,      5.69377885053,   238.03595295,  1.6928086283};
  expected.Fill(expected_values);

  matrix1 *= matrix2;
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}

TEST(MulMatrixTest, Test_3) {
  S21Matrix matrix1(5, 1);
  double values1[] = {100.0, 1.432, 2.312, 5.1234523, 214.2345};
  matrix1.Fill(values1);

  S21Matrix matrix2(1, 4);
  double values2[] = {1.112342, 46.61, 34.442, 54.4111};
  matrix2.Fill(values2);

  S21Matrix expected(5, 4);
  double expected_values[] = {
      111.2342,        4661,          3444.2,         5441.11,
      1.592873744,     66.74552,      49.320944,      77.9166952,
      2.571734704,     107.76232,     79.629904,      125.7984632,
      5.6990311782866, 238.804111703, 176.4619441166, 278.77267544053,
      238.302032199,   9985.470045,   7378.664649,    11656.73480295};
  expected.Fill(expected_values);

  matrix1.MulMatrix(matrix2);
  EXPECT_TRUE(matrix1 == expected) << Print(matrix1, 0) << Print(expected, 1);
}
