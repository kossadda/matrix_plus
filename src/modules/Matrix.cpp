/**
 * @file Matrix.cpp
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
S21Matrix::S21Matrix() : rows_(DEFAULT), cols_(DEFAULT), matrix_(Alloc()) {}

/**
 * @brief Parameterized constructor
 *
 * @param[in] rows number of matrix rows
 * @param[in] cols number of matrix columns
 */
S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(Alloc()) {}

/// @brief Destructor
S21Matrix::~S21Matrix() { Remove(); }

/**
 * @brief Copy constructor
 *
 * @param[in] other Object to be copied
 */
S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(Alloc()) {
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
}

/**
 * @brief Move constructor
 *
 * @param[in] other Object to be moved
 */
S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

/// @brief Helper method. Allocates memory for a matrix with the current fields rows_ and cols_
double* S21Matrix::Alloc() {
  if (rows_ <= 0 || cols_ <= 0)
    throw std::invalid_argument("Constructor: invalid matrix size");

  try {
    return new double[rows_ * cols_]{};
  } catch (const std::bad_alloc& e) {
    throw std::runtime_error("Memory allocation failed");
  }
}

/// @brief Helper method. Clears the memory allocated in field matrix_
void S21Matrix::Remove() {
  if (matrix_) {
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

/**
 * @brief Helper method. Checks the validity of the matrix
 *
 * @retval NO (false) - if wrong size or matrix contains nan or inf values
 * @retval YES (true) - correct matrix
 */
bool S21Matrix::IsCorrect() const {
  bool correct = YES;

  if (correct) {
    for (int i = 0; i < rows_ * cols_; ++i) {
      if (std::isnan(matrix_[i]) || std::isinf(matrix_[i])) {
        correct = NO;
      }
    }
  }

  return correct;
}

/**
 * @brief Helper method. Compare size and valid of both matrix
 *
 * @param[in] other second matrix
 * @retval YES (true) - correct matrix
 * @retval NO (false) - if different size or contains nan or inf
 */
bool S21Matrix::CompareIsRight(const S21Matrix& other) const {
  return (rows_ != other.rows_ || cols_ != other.cols_ || !IsCorrect() ||
          !other.IsCorrect())
             ? NO
             : YES;
}

/**
 * @brief Fill matrix with values
 *
 * @param[in] values the array where the numbers are entered from
 */
void S21Matrix::Fill(const double* values) {
  std::copy(values, values + rows_ * cols_, matrix_);
}

/// @brief Print the matrix of the current object
void S21Matrix::Print() const {
  for (int i = 0; i < rows_ * cols_; i++) {
    if (i && i % cols_ == 0) std::cout << std::endl;
    std::cout << matrix_[i] << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief Get array element
 *
 * @param[in] row element row
 * @param[in] col element col
 * @return double - array element
 */
double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_)
    throw std::out_of_range("Index out of range");

  return matrix_[row * cols_ + col];
}

/**
 * @brief Checks matrices for equality with each other
 *
 * @param[in] other comparison matrix
 * @retval true  - the matrices are equal
 * @retval false - the matrices are not equal
 */
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool equal = CompareIsRight(other);

  if (equal) {
    for (int i = 0; i < rows_ * cols_ && equal; i++) {
      if (std::abs(matrix_[i] - other.matrix_[i]) > PRECISION) {
        equal = NO;
      }
    }
  }

  return equal;
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
 * @brief An assignment operator = that replaces the current matrix with the
 * input one
 *
 * @param other assignable matrix
 */
void S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    Remove();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = Alloc();
    std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
  }
}

/**
 * @brief Adds the second matrix to the current one
 *
 * @param[in] other added matrix
 */
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!CompareIsRight(other))
    throw std::invalid_argument("SumMatrix: invalid arguments");

  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] += other.matrix_[i];
  }
}

/**
 * @brief Subtracts another matrix from the current one
 *
 * @param[in] other subtractable matrix
 */
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!CompareIsRight(other))
    throw std::invalid_argument("SubMatrix: invalid arguments");

  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] -= other.matrix_[i];
  }
}

/**
 * @brief Multiplies a matrix by a matrix
 *
 * @param[in] num matrix to be multiplied
 */
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_ || !IsCorrect() || !other.IsCorrect())
    throw std::invalid_argument("MulMatrix: invalid arguments");

  S21Matrix res(rows_, other.cols_);

  for (int i = 0; i < res.rows_; i++) {
    for (int j = 0; j < res.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        res.matrix_[i * res.cols_ + j] += matrix_[i * cols_ + k] * other.matrix_[k * other.cols_ + j];
      }
    }
  }

  (*this) = std::move(res);
}

/**
 * @brief Multiplies a matrix by a number
 *
 * @param[in] num number to be multiplied
 */
void S21Matrix::MulNumber(const double num) {
  if (!IsCorrect() || std::isinf(num) || std::isnan(num))
    throw std::invalid_argument("MulNumber: invalid arguments");

  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] *= num;
  }
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
 * @brief Multiplies a matrix by a matrix via operator *
 *
 * @param[in] other matrix to be multiplied
 */
S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);

  return result;
}

/**
 * @brief Multiplies a matrix by a number via operator *
 *
 * @param[in] num number to be multiplied
 */
S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result(*this);
  result.MulNumber(num);

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
 * @param[in] other subtractable matrix
 */
void S21Matrix::operator-=(const S21Matrix& other) { SubMatrix(other); }

/**
 * @brief Multiplies a matrix by a matrix via operator *=
 *
 * @param[in] other matrix to be multiplied
 */
void S21Matrix::operator*=(const S21Matrix& other) { MulMatrix(other); }

/**
 * @brief Multiplies a matrix by a number via operator *=
 *
 * @param[in] num number to be multiplied
 */
void S21Matrix::operator*=(const double num) { MulNumber(num); }

/**
 * @brief Creates a transposed matrix
 * 
 * @return S21Matrix - transposed matrix
 */
S21Matrix S21Matrix::Transpose() {
  if(!IsCorrect())
    throw std::invalid_argument("Transpose: invalid argument");

  if(rows_ == cols_)
    return *this;

  S21Matrix tr(cols_, rows_);

  for(int i = 0; i < rows_; i++) {
    for(int j = 0; j < cols_; j++) {
      tr.matrix_[j * tr.cols_ + i] = matrix_[i * cols_ + j];
    }
  }

  return tr;
}

/**
 * @brief Computes and returns the determinant of a matrix
 * 
 * @return double - determinant of a matrix
 */
double S21Matrix::Determinant() {
  double determinant;

  if(rows_ != cols_ || !IsCorrect())
    throw std::invalid_argument("Determinant: invalid argument");

  if(rows_ == 1 && cols_ == 1)
    determinant = *matrix_;
  else
    determinant = Recursive();

  return determinant;
}

/**
 * @brief Helper method. Recursive loop for determining determinants of all minors
 * 
 * @return double - determinant of minor
 */
double S21Matrix::Recursive() {
  double minor_determ = 0;

  if(cols_ != 2) {
    for(int j = 0; j < cols_; j++) {
      S21Matrix minor(Minor(0, j));
      minor_determ += std::pow(-1, j) * matrix_[j] * minor.Recursive();
    }
  } else {
    minor_determ += matrix_[0] * matrix_[3] - matrix_[1] * matrix_[2];
  }

  return minor_determ;
}

/**
 * @brief Helper method. Forms a minor relative to the specified matrix cell
 * 
 * @param row cells row
 * @param col cells col
 * @return S21Matrix - matrix minor
 */
S21Matrix S21Matrix::Minor(int row, int col) {
  S21Matrix minor(rows_ - 1, cols_ - 1);

  for(int i = 0, m = 0; i < rows_; i++) {
    if(i == row) continue;

    for(int j = 0, n = 0; j < cols_; j++) {
      if(j == col) continue;
      
      minor.matrix_[m * minor.cols_ + n] = matrix_[i * cols_ + j];
      n++;
    }

    m++;
  }

  return minor;
}

S21Matrix S21Matrix::CalcComplements() {
  if(rows_ != cols_ || !IsCorrect())
    throw std::invalid_argument("CalcComplements: invalid argument");

  if(rows_ == 1)
    return *this;

  S21Matrix res(rows_, cols_);
  
  for(int i = 0; i < rows_; i++) {
    for(int j = 0; j < cols_; j++) {
      S21Matrix tmp(Minor(i, j));
      res.matrix_[i * res.cols_ + j] = tmp.Determinant() * std::pow(-1, i + j);
    }
  }

  return res;
}