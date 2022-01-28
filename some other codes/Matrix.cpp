#include "Matrix.h"

TA::Matrix::Matrix(TA::matrix m) {
	for (Row row: m) {
		addRow(row);
	}
}

void TA::Matrix::addRow() {
	m.push_back(Row());
}

void TA::Matrix::addRow(TA::Row row) {
	Row new_row;
	for (int element: row) {
		new_row.push_back(element);
	}
	this->m.push_back(new_row);
}

void TA::Matrix::addColumn() {
	Row row(m.size(), 0);
	addColumn(row);
}

void TA::Matrix::addColumn(TA::Row row) {
	const int size = m[0].size();
	for (int i = 0; i < size; ++i) {
		m[i].push_back(row[i]);
	}
}
