#include <iostream>
#include <vector>


class Matrix {
private:
	std::vector<std::vector<double>> data;
	int rows;
	int cols;


public:
	Matrix(int rows, int cols) : rows(rows), cols(cols) {
		data.resize(rows, std::vector<double>(cols, 0.0));
	}


	Matrix(const std::vector<std::vector<double>>& input_data) : rows(input_data.size()), cols(input_data[0].size()) {
		data = input_data;
	}


	int getRows() const {
		return rows;
	}


	int getCols() const {
		return cols;
	}


	double getElement(int row, int col) const {
		return data[row][col];
	}


	void setElement(int row, int col, double value) {
		data[row][col] = value;
	}


	Matrix add(const Matrix& other) const {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				result.setElement(i, j, data[i][j] + other.getElement(i, j));
			}
		}
		return result;
	}


	Matrix subtract(const Matrix& other) const {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				result.setElement(i, j, data[i][j] - other.getElement(i, j));
			}
		}
		return result;
	}


	Matrix multiply(const Matrix& other) const {
		Matrix result(rows, other.getCols());
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < other.getCols(); ++j) {
				for (int k = 0; k < cols; ++k) {
					result.setElement(i, j, result.getElement(i, j) + data[i][k] * other.getElement(k, j));
				}
			}
		}
		return result;
	}


	Matrix transpose() const {
		Matrix result(cols, rows);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				result.setElement(j, i, data[i][j]);
			}
		}
		return result;
	}


	static Matrix identity(int size) {
		Matrix identityMatrix(size, size);
		for (int i = 0; i < size; ++i) {
			identityMatrix.setElement(i, i, 1.0);
		}
		return identityMatrix;
	}


	void print() const {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				printf("%f ", data[i][j]);
			}
			printf("\n");
		}
	}
};


int main() {
	Matrix matrix1(2, 3);
	matrix1.setElement(0, 0, 1.0);
	matrix1.setElement(0, 1, 2.0);
	matrix1.setElement(0, 2, 3.0);
	matrix1.setElement(1, 0, 4.0);
	matrix1.setElement(1, 1, 5.0);
	matrix1.setElement(1, 2, 6.0);


	Matrix matrix2(3, 2);
	matrix2.setElement(0, 0, 7.0);
	matrix2.setElement(0, 1, 8.0);
	matrix2.setElement(1, 0, 9.0);
	matrix2.setElement(1, 1, 10.0);
	matrix2.setElement(2, 0, 11.0);
	matrix2.setElement(2, 1, 12.0);


	printf("Matrix 1:\n");
	matrix1.print();


	printf("Matrix 2:\n");
	matrix2.print();


	Matrix sum = matrix1.add(matrix1);
	printf("Sum:\n");
	sum.print();


	Matrix product = matrix1.multiply(matrix2);
	printf("Product:\n");
	product.print();


	Matrix identity = Matrix::identity(3);
	printf("Identity Matrix:\n");
	identity.print();


	return 0;
}