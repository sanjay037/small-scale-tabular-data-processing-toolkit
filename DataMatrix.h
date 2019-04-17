#ifndef D_MATRIX_H
#define D_MATRIX_H
#include "Matrix.h"
#include "Record.h"
#include <iostream>

using namespace std;

class DataMatrix:public Matrix{
private:
    int nRows, nColumns;
		vector<Record> _data;

public:
    DataMatrix(int i, int j):Matrix(i,j){}
    // ~DataMatrix();
    //DataMatrix(const DataMatrix&);
		Record getData(int i){ return _data[i];}
		int getNumRows(){return nRows;}
		void addRecord(Record r);
};
#endif
