#ifndef task5_H_
#define task5_H_
#include<vector>
using namespace std;
class task5
{
  public:
    task5(int n,int p,vector <vector< double>> original);
    void eigen_calculator(vector<vector<double>> &eigen_vectors, vector <double> &eigen_values);
  private:
    vector<vector<double>> original;
    int n,p;
};

#endif
