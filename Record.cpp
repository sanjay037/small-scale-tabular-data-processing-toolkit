#include "Record.h"

Record::Record(vector<string> rec)
{
	for(int i = 0; i < rec.size(); i++)
	{
		feature.push_back(rec[i]);
	}
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
}

void Record::setNormal(float f)
{
	normalVal = f;
}

float Record::getNormal()
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
		// cout << "ED " << stof(feature[i]) << " " << stof(r.getFeatureValue(i)) << "\n";
		diff = stof(feature[i]) - stof(r.getFeatureValue(i));
		diff = pow(diff, 2);
		res = res + diff;

	}
	res = pow(res, 0.5);
	// cout << "EDF " << res << "\n";
	return res;
}

void Record::printRecord()
{
	for(int i = 0; i < feature.size(); i++)
	{
		cout << feature[i] << " ";
	}
	// cout << endl;
}
