#ifndef TASESSIONS_MATRIX_H
#define TASESSIONS_MATRIX_H

#include <vector>

using namespace std;

namespace TA {
	typedef vector <int> Row;
	typedef vector <Row> matrix;
	
	struct Matrix {
		matrix m;
		
		Matrix() { }
		Matrix(matrix m);
		
		void addRow();
		void addRow(Row row);
		
		void addColumn();
		void addColumn(Row row);
	};
}

#endif //TASESSIONS_MATRIX_H
