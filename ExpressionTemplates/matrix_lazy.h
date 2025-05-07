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

// File name: matrix_lazy.h (3 out of 4 project files)


// This small C++ project is ONLY for educational purposes & part of related article
#pragma once

#include "matrix.h"

/*********************************************************************************/
/*                     Definition - Class - SumProxy                             */
/*********************************************************************************/
template<typename LHS, typename RHS>
class SumProxy {
public:
	using value_type = typename RHS::value_type;

	SumProxy(const LHS& lh, const RHS& rh) : lhs{ lh }, rhs{ rh } {
//		cout << "SumProxy Default Constructor\n";
	}
	SumProxy(const SumProxy&) { cout << "SumProxy Copy Constructor\n"; }
	SumProxy(const SumProxy&&) { cout << "SumProxy Move Constructor\n"; }
	~SumProxy() {}

	SumProxy& operator=(const SumProxy&) { cout << "SumProxy Copy =\n"; return *this; }
	SumProxy& operator=(const SumProxy&&) { cout << "SumProxy Move =\n"; return *this; }

	value_type get_element(const size_t pos) const {
		return lhs.get_element(pos) + rhs.get_element(pos);
	}
private:
	const LHS& lhs;
	const RHS& rhs;
};

/*********************************************************************************/
/*                    Definition - Class - MatrixLazy                            */
/*********************************************************************************/
template<ArithmeticType T, size_t ROWS, size_t COLS>
class MatrixLazy : public Matrix<T, ROWS, COLS> {
public:
	template<typename LHS, typename RHS>
	MatrixLazy& operator=(const SumProxy<LHS, RHS>& rhs) {
//		cout << "\nMatrixLazy copy assignment with SumProxy argument\n\n";
		for (size_t pos = 0; pos != ROWS * COLS; ++pos)
			this->pBuffer[pos] = rhs.get_element(pos);

		return *this;
	}
};

/*********************************************************************************/
/*                     Overloading - Operators                                   */
/*********************************************************************************/
template<typename LHS, typename RHS>
SumProxy<LHS, RHS> operator+(const LHS& lhs, const RHS& rhs) {
// An educational code, otherwise we must check equality of operands rows & columns
//	cout << "+ operator called, right operand: " << typeid(RHS).name() << "\n";
//	cout << "                    left operand: " << typeid(LHS).name() << "\n\n";
	return SumProxy<LHS, RHS>(lhs, rhs);
}
