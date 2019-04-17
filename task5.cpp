#include <bits/stdc++.h>
#include "task5.h"

using namespace std;

task5::task5(int n,int p,vector<vector<double>> a)
{
  this->n = n;
  this->p = p;
  for(int i=0;i<n;i++) original.push_back(a[i]);
}

void task5::eigen_calculator(vector <vector <double> > &eigen_vectors, vector <double> &eigen_values)
{
  for(int loop=0;loop<p;loop++)
  {
    vector<double> c(n);
    vector <double> x(n);
    vector<double> temp(n);
    double y=0,k=0,double_temp=0;
    for(int i=0;i<n;i++)x[i]=1;
    for(int i=0;i<n;i++) double_temp+=x[i]*x[i];
    double_temp = sqrt(double_temp);
    for(int i=0;i<n;i++) x[i]=x[i]/double_temp;
    do{
        for(int i=0;i<n;i++) c[i] = x[i];
        y=k;
        k = 0;
        for(int j=0;j<=loop-1;j++)
        {
          for(int l=0;l<n;l++) temp[l] = eigen_vectors[j][l];
          double_temp=0;
          for(int i=0;i<n;i++) double_temp+= c[i]*temp[i];
          for(int i=0;i<n;i++) temp[i] = temp[i]*double_temp;
          for(int i=0;i<n;i++) c[i] = c[i]-temp[i];
        }
        double_temp = 0;
        for(int i=0;i<n;i++){
            x[i]=0;
            for (int j=0;j<n;j++)  x[i]+=original[i][j]*c[j];
            double_temp += x[i]*x[i];
        }
        k = sqrt(double_temp);
        for(int i=0;i<n;i++) x[i]=x[i]/k;
      }while (fabs(k-y)>0.00001);
    if((x[0]<0 && c[0]>0) || (x[0]>0 && c[0]<0)) k = -k;
    eigen_values.push_back(k);
    eigen_vectors.push_back(x);
  }
}
