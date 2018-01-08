#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <sstream>
#include <vector>

class Matrix {
public:
	int lines, cols;
	std::vector<std::vector<float> > mat;

	Matrix (int lines, int cols) : lines(lines), cols(cols) {
		mat = std::vector<std::vector<float> > (lines);
		for (int i = 0; i < lines; i++)
			mat[i] = std::vector<float> (cols);
	}

	#ifdef STD_CPP_11
		template < int pos = 0, typename ...Args>
		void initializare (float arg, Args ...args) {
			mat[pos / lines][pos % cols] = arg;
			initializare<pos + 1>(args...);
		}

		template <int pos>	
		void initializare (float arg) {
			mat[pos / lines][pos % cols] = arg;
		}
	#endif

	Matrix adunare (const Matrix& arg) {
		Matrix result(lines, cols);

		if (arg.lines != lines || arg.cols != cols) {
			std::cout << "Invalid size for matrix addition" << std::endl;
			return result;
		}
 		
		for (int i = 0; i < lines; i++)
			for (int j = 0; j < cols; j++)
				result.mat[i][j] = mat[i][j] + arg.mat[i][j];

		return result;
	}

	Matrix inmultire (const Matrix& arg) {
		Matrix result(lines, cols);

		if (arg.lines != cols) {
			std::cout << "Invalid size for matrix multiplication" << std::endl;
			return result;
		}
 		
		for (int i = 0; i < lines; i++)
			for (int j = 0; j < arg.cols; j++)
				for (int k = 0; k < arg.lines; k++)
					result.mat[i][j] += mat[i][k] * arg.mat[k][j];

		return result;
	}

	Matrix pow (int power) {
		Matrix result(lines, cols);
		
		if (lines != cols) {
			std::cout << "Matrix must be a square matrix" << std::endl;
			return result;
		} 

		for (int i = 0; i < lines; i++)
			result.mat[i][i] = 1;

		for (int i = 0; i < power; i++) {
			result = result.inmultire(*this);
		}

		return result;
	}

	std::string toString() {
		std::stringstream ss;
		
		ss << "lines: " << lines << " cols: " << cols << std::endl;
		
		for (int i = 0; i < lines; i++, ss << std::endl)
			for (int j = 0; j < cols; j++)
				ss << mat[i][j] << " ";

		return ss.str();
	}

	float& operator () (int i, int j) {
		return mat[i][j];
	}

	friend std::istream& operator >> (std::istream& stream, Matrix& arg) {
		for (int i = 0; i < arg.lines; i++)
			for (int j = 0; j < arg.cols; j++)
				stream >> arg.mat[i][j];

		return stream;
	}
};

#endif
