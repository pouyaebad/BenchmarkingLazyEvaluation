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

// File name: main.cpp (1 out of 4 project files)


// This is companion code of the article for performance benchmarking of
//	"Eager Evaluation" & "Lazy Evaluation" in C++ 20
//	"Expression Templates" is used in this C++ code for "Lazy Evaluation"
//
//  This small project is ONLY for educational purposes & part of related article
//  Wherever in this project, member functions of classes were not needed for  
//  the tests, they are not implemented 

#include "matrix_eager.h"
#include "matrix_lazy.h"
#include <chrono>

const size_t matrix_rows{ 4000 }; // Number of Rows    of all Matrices
const size_t matrix_cols{ 3000 }; // Number of Columns of all Matrices

/*********************************************************************************/
/*                                                                               */
/*                              The Main Function                                */
/*                                                                               */
/*********************************************************************************/


int main() {

	//This is an educational code, otherwise we must catch possible exceptions 
	//       may be thrown in the following line if memory cannot be allocated

	// Uncomment only 1 of the following 2 lines to run the "performance test"
//	MatrixEager<double, matrix_rows, matrix_cols> m[10], m_total;
	MatrixLazy<double, matrix_rows, matrix_cols> m[10], m_total;

	cout << "\n\n== Matrix Operation (Summation) Started ===================\n\n";
	auto tStart = chrono::high_resolution_clock::now();

	m_total = m[0] + m[1] + m[2] + m[3] + m[4] + m[5] + m[6] + m[7] + m[8] + m[9];

	auto tEnd = chrono::high_resolution_clock::now();
	cout << "\n\n== Matrix Operation (Summation) Ended =====================\n\n";



	cout << "\n\n\n==================== Test Results =====================\n\n\n";

	const chrono::duration<double, milli> time_passed = tEnd - tStart;
	cout << "Time Spent on Operations: " << (size_t)time_passed.count() << " ms\n";


	const size_t row_no{ 0 }; // Row    number of the element to be printed
	const size_t col_no{ 0 }; // Column number of the element to be printed

	cout << "\nSample of summation of a matrix element:\n" << m[0][row_no][col_no];

	for (int mtrx_indx = 1; mtrx_indx < sizeof(m) / sizeof(m[0]); mtrx_indx++)
		cout << " + " << m[mtrx_indx][row_no][col_no];

	cout << " = " << m_total[row_no][col_no] << "\n\n";
}
