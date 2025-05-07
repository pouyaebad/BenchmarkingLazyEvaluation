//
// Copyright 2025, Pouya Ebadollahyvahed
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the “Software”),
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, 
// sublicense, and /or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following 
// conditions :
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

// File name: matrix.h (2 out of 4 project files)


// This small C++ project is ONLY for educational purposes & part of related article
#pragma once

#include <iostream>
#include <random>

/*********************************************************************************/
/*                          Definition - Globals                                 */
/*********************************************************************************/

using namespace std;

template<typename T> concept ArithmeticType = is_arithmetic_v<T>;

// Just to generate some random numbers, 50 & 11 are also random
const float rnd_nums_mean{ 50.0f }, rnd_nums_std_dev{ 11.0f };


/*********************************************************************************/
/*                      Definition - Class - Matrix                              */
/*********************************************************************************/

// Although following is a concrete class but it is defined ONLY to be parent of
// "MatrixLazy" & "MatrixEager" classes & we instantiate only from these 2 classes

template<ArithmeticType T, size_t ROWS, size_t COLS>
class Matrix {
public:
	using value_type = T;

	Matrix() {
		pBuffer = new T[ROWS * COLS];

		normal_distribution<T>  rnd{ (T)rnd_nums_mean, (T)rnd_nums_std_dev };
		for (size_t pos = 0; pos != ROWS * COLS; ++pos)
			pBuffer[pos] = rnd(rnd_eng);
	}

	~Matrix() {
		delete[] pBuffer;
	}

	Matrix(const Matrix&) { cout << "Matrix Copy Constructor\n"; }
	Matrix(const Matrix&&) { cout << "Matrix Move Constructor\n"; }
	Matrix& operator=(const Matrix&) { cout << "Matrix copy =\n"; return *this; }
	Matrix& operator=(const Matrix&&) { cout << "Matrix move =\n"; return *this; }

	const T& get_element(const size_t pos) const { return pBuffer[pos]; }
	void set_element(const size_t pos, const T val) { this->pBuffer[pos] = val; }

	T* operator[] (const size_t row_num) { return (pBuffer + row_num * COLS); }

protected:
	T* pBuffer;

private:
	static inline default_random_engine rnd_eng{};
};
