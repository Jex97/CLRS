#include "common.h"

using namespace std;


// ���ؾ���˷�
// ʱ�临�Ӷȣ�O(n^3)


typedef vector<vector<int>> Matrix;
/*
* SquareMatrixMultiply: ���ؾ���˷�;
* A: ���˾���;
* B: ���˾���;
* return: Matrix C(n*n);
*/
Matrix SquareMatrixMultiply(const Matrix& A, const Matrix& B) {
	int n = A.size();
	Matrix C;
	for (int i = 0; i < n; ++i) {
		vector<int> line(n, 0);
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				line[j] += A[i][k] * A[k][j];
			}
		}
		C.push_back(line);
	}
	return C;
}