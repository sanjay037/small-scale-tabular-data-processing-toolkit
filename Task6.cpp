#include "SymmetricMatrix.h"
#include "DataMatrix.h"
#include "Record.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator>

using namespace std;

//Setting feature vector//
void Record::setFeatureVector(vector<double> newFeatureVector){
    featureVector = newFeatureVector;
}
//Adding new record object to matrix//
void DataMatrix::addRecord(Record r) {
    _data.push_back(r);
}

//Getting value of feature from matrix//
double SymmetricMatrix::get_matrix_element(int i, int j){
    vector<double> feature = getData(i).getFeatureVector();
    return feature[j];
}
//Task6.....Basic minimum degree ordering algorithm//
vector<int> basicMinDegreeOrdering(vector<int> newPermutedObject, vector<int> permutedObject, SymmetricMatrix &matrixInput){
   	//Recursion base case//
 		if(permutedObject.size() == 1){
        newPermutedObject.push_back(permutedObject[0]);
        return newPermutedObject;
    }
    vector<double> sumOfDegrees;
    int r = matrixInput.getNumRows();
    SymmetricMatrix matrix(r-1);
    for(int i = 0; i < r; i++){
        double flag = 0.0;
        for(int j = 0; j < r; j++){
            if(i != j){
                flag += matrixInput.get_matrix_element(i,j);
            }
        }
        sumOfDegrees.push_back(flag);
    }
    vector<double>:: iterator it;
    it = min_element(sumOfDegrees.begin(), sumOfDegrees.end());
    int in = it - sumOfDegrees.begin();
		//Making submatrix//
    for(int i = 0; i < r; i++){
        if(i != in){
            Record record(r-1,r-1);
            vector<double> newFeature;
            vector<double> oldFeature = matrixInput.getData(i).getFeatureVector();
            for(int j = 0; j < r; j++){
                if(j != in){
                    newFeature.push_back(oldFeature[j]);
                }
            }
            record.setFeatureVector(newFeature);
            matrix.addRecord(record);
        }
    }
		//Proxy permutation vector//
    vector<int> proxyPermutation;
    for(int i = 0; i < r; i++){
			if(i != in){
				proxyPermutation.push_back(permutedObject[i]);
    	}
		}        
    newPermutedObject.push_back(permutedObject[in]);    
    return basicMinDegreeOrdering(newPermutedObject, proxyPermutation, matrix);
}
int main(){
	return 0;
}
