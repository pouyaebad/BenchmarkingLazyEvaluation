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

// File name: matrix_eager.h (4 out of 4 project files)


// This small C++ project is ONLY for educational purposes & part of related article
#pragma once

#include "matrix.h"

/*********************************************************************************/
/*                    Definition - Class - MatrixEager                           */
/*********************************************************************************/


template<ArithmeticType T, size_t ROWS, size_t COLS>
class MatrixEager : public Matrix<T, ROWS, COLS> {

public:
	// This is an educational code, otherwise according to RULE-OF-FIVE, we had to 
	// implement copy constructor, move constructor, move assignment & destructor
	
	MatrixEager& operator=(const MatrixEager& rhs) {

		for (size_t pos = 0; pos != ROWS * COLS; ++pos)
			this->pBuffer[pos] = rhs.get_element(pos);

		return *this;
	}


	MatrixEager operator+(const MatrixEager& rhs) {

		MatrixEager<T, ROWS, COLS> sum;

//		cout << this->get_element(0) << " + " << rhs.get_element(0) << "\n";


		for (size_t pos = 0; pos != ROWS * COLS; ++pos)
			sum.set_element(pos, this->get_element(pos) + rhs.get_element(pos));

		return sum;
	}
};
