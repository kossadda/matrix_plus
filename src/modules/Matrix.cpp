/**
 * @file MyClass.cpp
 * @author kossadda (https://github.com/kossadda)
 * @brief Module containing descriptions of S21Matrix class methods
 * @version 1.0
 * @date 2024-04-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./include/Matrix.h"

/// @brief Default constructor (creates a 3x3 matrix)
S21Matrix::S21Matrix() : rows_(3), cols_(3) { Allocate(); }

/**
 * @brief Parameterized constructor
 *
 * @param[in] rows number of matrix rows
 * @param[in] cols number of matrix columns
 */
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  Allocate();
}

/// @brief Destructor
S21Matrix::~S21Matrix() { Remove(); }

/**
 * @brief Copy constructor
 *
 * @param[in] other Object to be copied
 */
S21Matrix::S21Matrix(const S21Matrix& other) {
  if (other.rows_ > 0 && other.cols_ > 0) {
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    Allocate();
    CopyValues(other);
  }
}

/// @brief Allocates memory for a matrix with the current fields rows_ and cols_
void S21Matrix::Allocate() {
  if (rows_ && cols_) {
    matrix_ = new double*[rows_];

    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
  }
}

/// @brief Clears the memory allocated in field matrix_
void S21Matrix::Remove() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i]) {
        delete[] matrix_[i];
        matrix_[i] = NULL;
      }
    }

    delete[] matrix_;
    matrix_ = NULL;
  }
}

/**
 * @brief Copies values from the given matrix to the current one
 *
 * @param[in] other data to be copied
 */
void S21Matrix::CopyValues(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

/// @brief Print the matrix of the current object
void S21Matrix::MatrixPrint() const {
  if (rows_ && cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        std::cout << matrix_[i][j] << " ";
      }

      std::cout << std::endl;
    }
  }
}

/**
 * @brief Fill matrix with values
 *
 * @param[in] values the array where the numbers are entered from
 */
void S21Matrix::FillMatrix(const double* values) {
  for (int i = 0, cnt = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = values[cnt++];
    }
  }
}

/**
 * @brief Checks the validity of the matrix
 *
 * @retval true  - if the matrix contains nan or inf values
 * @retval false - correct matrix
 */
bool S21Matrix::IsNanOrInf() const {
  bool check = NO;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::isnan(matrix_[i][j]) || std::isinf(matrix_[i][j])) {
        check = YES;
        i = rows_;
        j = cols_;
      }
    }
  }

  return check;
}

/**
 * @brief Compares dimensionality and dimensional validity
 *
 * @param[in] other comparison matrix
 * @retval true  - correct matrix
 * @retval false - invalid size or size mismatch
 */
bool S21Matrix::ValidEqualSize(const S21Matrix& other) const {
  return (rows_ == other.rows_ && cols_ == other.cols_ && rows_ && cols_) ? YES
                                                                          : NO;
}

/**
 * @brief Adds the second matrix to the current one
 *
 * @param[in] other added matrix
 */
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (ValidEqualSize(other) && !IsNanOrInf() && !other.IsNanOrInf()) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

/**
 * @brief Subtracts another matrix from the current one
 *
 * @param[in] other subtractable matrix
 */
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (ValidEqualSize(other) && !IsNanOrInf() && !other.IsNanOrInf()) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

/**
 * @brief Checks matrices for equality with each other
 *
 * @param[in] other comparison matrix
 * @retval true  - the matrices are equal
 * @retval false - the matrices are not equal
 */
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool status = YES;

  if (ValidEqualSize(other) && !IsNanOrInf() && !other.IsNanOrInf()) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > 0.01) {
          status = NO;
          i = rows_;
          j = cols_;
        }
      }
    }
  } else {
    status = NO;
  }

  return status;
}

/**
 * @brief Checks matrices for equality with each other via operator ==
 *
 * @param[in] other comparison matrix
 * @retval true - the matrices are equal
 * @retval false - the matrices are not equal
 */
bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

/**
 * @brief Checks matrices for non-equality with each other via operator !=
 *
 * @param[in] other comparison matrix
 * @retval true  - the matrices are not equal
 * @retval false - the matrices are equal
 */
bool S21Matrix::operator!=(const S21Matrix& other) const {
  return !EqMatrix(other);
}

/**
 * @brief Adds the second matrix to the current one via operator +
 *
 * @param[in] other added matrix
 * @return S21Matrix - result of addition
 */
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);

  return result;
}

/**
 * @brief Subtracts another matrix from the current one via operator -
 *
 * @param[in] other subtractable matrix
 * @return S21Matrix - result of addition
 */
S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);

  return result;
}

/**
 * @brief Adds the second matrix to the current one via operator +=
 *
 * @param[in] other added matrix
 */
void S21Matrix::operator+=(const S21Matrix& other) { SumMatrix(other); }

/**
 * @brief Subtracts another matrix from the current one via operator -=
 *
 * @param other subtractable matrix
 */
void S21Matrix::operator-=(const S21Matrix& other) { SubMatrix(other); }

/**
 * @brief An assignment operator = that replaces the current matrix with the
 * input one
 *
 * @param other assignable matrix
 */
void S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other && other.rows_ > 0 && other.cols_ > 0) {
    Remove();

    rows_ = other.rows_;
    cols_ = other.cols_;
    Allocate();
    CopyValues(other);
  }
}