#include <iostream>
#include <math.h>
#include "Matrix.h"
#include "Record.h"

Matrix::Matrix(int r, int c)
{
	nRows = r;
	nColumns = c;
	data = new float*[nRows];
	for(int i = 0; i < nRows; i++)
	{
		data[i] = new float [nColumns];
		for(int j = 0; j < nColumns; j++)
		{
			data[i][j] = 0;
		}
	}
}

Matrix::~Matrix()
{
	delete [] data;
}

Matrix::Matrix(const Matrix& m)
{
	nRows = m.nRows;
	nColumns = m.nColumns;

	data = new float*[nRows];
	for(int i = 0; i < nColumns; i++) new float[nColumns];
}

void Matrix::setData(int i, int j, float x)
{
	data[i][j] = x;
}

float Matrix::getData(int i, int j)
{
	return data[i][j];
}

void Matrix::printMatrix()
{
	for(int i = 0; i < nRows; i++)
	{
		for(int j = 0; j < nColumns; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

SquareMatrix::SquareMatrix(int n) : Matrix(n, n){};

ostream& operator << (ostream& mos, Matrix &m)
{
	mos << m.nRows << "," << m.nColumns << endl;
	for(int i = 0; i < m.nRows; i++)
	{
		for(int j = 0; j < m.nColumns; j++)
		{
			mos << m.data[i][j] << ",";
		}
		mos << endl;
	}
	return mos;
}

Record::Record(vector<string> rec)
{
	feature = rec;
}

void Record::setIndex(int i)
{
	idx = i;
}

int Record::getIndex() const
{
	return idx;
}

Record::~Record()
{
	feature.clear();
}

Record::Record(const Record& r)
{
	for(int i = 0; i < r.feature.size(); i++)
	{
		feature.push_back(r.feature[i]);
	}
	normalVal = r.getNormal();
	idx = r.getIndex();
}

void Record::setNormal(float f)
{
	normalVal = f;
}

float Record::getNormal()	const
{
	return normalVal;
}

float Record::getEuc()
{
	return eucDis;
}

void Record::setEuc(float ec)
{
	eucDis = ec;
}

string Record::getFeatureValue(int idx)
{
	return feature[idx];
}

void Record::setFeatureValue(string value, int idx)
{
	feature[idx] = value;
}

int Record::getSize()
{
	return feature.size();
}

float Record::euclideanDistance(Record r, int thre)
{
	int count;
	float res = 0;
	float diff = 0;
	for(int i = thre; i < feature.size(); i++)
	{
		diff = stof(feature[i]) - stof(r.getFeatureValue(i));
		diff = pow(diff, 2);
		res = res + diff;

	}
	res = pow(res, 0.5);
	return res;
}

void Record::printRecord() const
{
	for(int i = 0; i < feature.size(); i++)
	{
		cout << feature[i] << " ";
	}
	cout << endl;
}

void Record::setIndx(int i)
{
	idx = i;
}
