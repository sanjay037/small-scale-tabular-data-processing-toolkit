#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>

using namespace std;

class Record
{
private:
    vector<string> feature;
    int idx;
    float eucDis, normalVal;
		int variables;
		int numericalVariables;
		vector<double> featureVector;

public:
    Record();
		Record(int v,int n):variables(v),numericalVariables(n){}
    Record(vector<string>);
    //~Record();
    //Record(const Record&);

    string getFeatureValue(int);
    void setFeatureValue(string, int);
		void setFeatureVector(vector<double> newFeatureVector);
    int getIndex() const;
    void setIndex(int);
    void setNormal(float);
    float getNormal() const;
    float getEuc();
    void setEuc(float);
    int getSize();
    float euclideanDistance(Record, int);
    void setIndx(int);
    void printRecord() const;
		vector<double> getFeatureVector(){return featureVector;} 

    // friend bool operator < (const Record&, const Record&);
};

#endif
