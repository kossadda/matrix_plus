# s21_matrix+

Implementation of the s21_matrix_oop.h library.

The English version of the README can be found in the repository.

## Contents
1. [Project description](#project-description)
2. [Building project](#building-project)
3. [Feedback](#feedback)

<br>

## [Project description](#s21_matrix)

The goal of this project is to implement a class in the C++ programming language that simulates full-fledged work with matrices.
Below is a brief description of the operations on matrices that were implemented in the developed library.

| Operation                                | Description                                                                 | Exceptional situations                                                                 |
| ---------------------------------------- | --------------------------------------------------------------------------- | -------------------------------------------------------------------------------------- |
| `bool EqMatrix(const S21Matrix& other)`  | Checks matrices for equality with each other.                               |                                                                                        |
| `void SumMatrix(const S21Matrix& other)` | Adds the second matrix to the current one.                                  | Different matrix dimensions.                                                           |
| `void SubMatrix(const S21Matrix& other)` | Subtracts another matrix from the current one.                              | Different matrix dimensions.                                                           |
| `void MulNumber(const double num)`       | Multiplies the current matrix by a number.                                  |                                                                                        |
| `void MulMatrix(const S21Matrix& other)` | Multiplies the current matrix by the second matrix.                         | The number of columns of the first matrix is not equal to the number of second matrix. |
| `S21Matrix Transpose()`                  | Ceates a new transposed matrix from the current one and returns it.         |                                                                                        |
| `S21Matrix CalcComplements()`            | Calculates the algebraic addition matrix of the current one and returns it. | The matrix is not square.                                                              |
| `double Determinant()`                   | Calculates and returns the determinant of the current matrix.               | The matrix is not square.                                                              |
| `S21Matrix InverseMatrix()`              | Calculates and returns the inverse matrix.                                  | Matrix determinant is 0.                                                               |

In addition to implementing these operations, constructors and destructors are implemented:

| Method                              | Description                                                                 |
| ----------------------------------- | --------------------------------------------------------------------------- |
| `S21Matrix()`                       | A basic constructor that initialises a matrix of some predefined dimension. |  
| `S21Matrix(int rows, int cols)`     | Parametrized constructor with number of rows and columns.                   | 
| `S21Matrix(const S21Matrix& other)` | Copy constructor.                                                           |
| `S21Matrix(S21Matrix&& other)`      | Move constructor.                                                           |
| `~S21Matrix()`                      | Destructor.                                                                 |

The following operators are also overloaded, partially corresponding to the operations above:

| Operator          | Description                                                  | Exceptional situations                                                                            |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------------------------------------------- |
| `+`               | Addition of two matrices.                                    | Different matrix dimensions.                                                                      |
| `-`               | Subtraction of one matrix from another.                      | Different matrix dimensions.                                                                      |
| `*`               | Matrix multiplication and matrix multiplication by a number. | The number of columns of the first matrix is not equal to the number of second matrix.            |
| `==`              | Checks for matrices equality (`EqMatrix`).                   |                                                                                                   |
| `=`               | Assignment of values from one matrix to another one.         |                                                                                                   |
| `+=`              | Addition assignment (`SumMatrix`).                           | Different matrix dimensions.                                                                      |
| `-=`              | Difference assignment (`SubMatrix`).                         | Different matrix dimensions.                                                                      |
| `*=`              | Multiplication assignment (`MulMatrix`/`MulNumber`).         | The number of columns of the first matrix does not equal the number of rows of the second matrix. |
| `(int i, int j)`  | Indexation by matrix elements (row, column).                 | Index is outside the matrix.                                                                      |

- The program was developed in C++ language standard C++17 using the gcc compiler;
- The program code is located in the src folder;
- Code formatting is made in accordance with Google Style;
- The matrix is implemented as the class `S21Matrix`;
- Only private fields `matrix_`, `rows_` and `cols_` are stored;
- Access to private fields `rows_` and `cols_` is implemented through accessor and mutator. When the size increases, the matrix is supplemented with zero elements; when decreased, the excess is simply discarded;
- The solution is designed as a static library (with a header file s21_matrix_oop.h);
- Prepared full coverage of library functions with unit tests using the GTest library;
- A Makefile is provided for building the library and tests (with goals all, clean, test, s21_matrix_oop.a).

## [Building project](#s21_matrix)

The following main targets for working with the project have been added to the Makefile:

| #  | Target             | Target description                                                           |
|----| ------------------ | ---------------------------------------------------------------------------- |
| 1  | `all`              | Builds the project and generates project documentation.                      |
| 2  | `s21_matrix_oop`   | Builds modules into a static library.                                        |
| 3  | `test`             | Performs module testing.                                                     |
| 4  | `gcov_report`      | Performs module testing and generates a coverage report in `html` format.    |
| 5  | `dvi`              | Generates documentation in `html` and `manual` format for the functionality. |
| 6  | `clean`            | Cleans the repository of generated files.                                    |
| 7  | `rebuild`          | Rebuilds the project.                                                        |
| 8  | `clang_check`      | Testing modules for compliance with `Google style`.                          |
| 9  | `valgrind`         | Testing modules for working with memory using `Valgrind`.                    |
| 10 | `dependencies`     | Installs the necessary dependencies for building and testing the project.    |

<br>

## [Feedback](#s21_matrix)

If you have any questions regarding the features or other aspects of the project that interest you, please contact <br>

|          |                       |
| ---------| --------------------- |
| mail     | gabilov1997@gmail.com |
| telegram | @kossadda             |
| vk       | vk.com/kossadda       |

Thank you for your attention. I hope you enjoy this project and find it useful.

<br>

[К оглавлению](#s21_matrix)