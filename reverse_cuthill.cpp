#include"RCM_reordering.h"
#include"Matrix.h"
#include<queue>
#include<vector>
#include<bits/stdc++.h>

RCM_reordering::RCM_reordering(SymmetricMatrix m): _matrix(m){}

//copy constructor
RCM_reordering::RCM_reordering(RCM_reordering &other_matrix){
    for(int i=0; i<other_matrix.getNoRows(); i++){
        for(int j=0; i<other_matrix.getNoCols(); j++){
            _matrix.setData(i, j, other_matrix.getData(i, j));
        }
    }
}

//sparsifies the function to convert the matrix into a adjacency matrix
void RCM_reordering::sparsify(){
    for(int i=0; i<_matrix.getNoRows(); i++){
        for(int j=0; j<_matrix.getNoCols(); j++){
            if(_matrix.getData(i, j) < 0.75){
                _matrix.setData(i, j, 0);
            }
            else{
                _matrix.setData(i, j, 1);
            }
        }
    }
}

//counting the degrees of rach function
vector<int> RCM_reordering::Degrees(){
    vector<int> degrees;
    for(int i=0; i<_matrix.getNoRows(); i++){
        int count = 0;
        for(int j=0; j<_matrix.getNoCols(); j++){
            count += _matrix.getData(i, j);
        }
        degrees.push_back(count);
    }
}

//calcuate minimum index
int minIndex(vector<pair<int, double> >array){
    int min = 0;
    for(int i=0; i<array.size(); i++){
        if(array[i].second < array[min].second)
            min = i;
    }
    return min;
}

//sorting the temp array
vector<int> sortTemp(vector<int> temp, vector<int> degrees){
   int i, j; 
   for (i = 0; i < temp.size()-1; i++){       
       for (j = 0; j < temp.size()-i-1; j++){  
           if (degrees[i] > degrees[j]){
               int extra;
               extra = temp[i];
               temp[i] = temp[j];
               temp[j] = extra;
           }
       } 
    }  
    return temp;    
}


int getIndex(vector<pair<int, double> >array, int j){
    for(int i=0; i<array.size(); i++){
        if(array[i].first == j)
            return i;
    }
    return -1;
}

//BFS
vector<int> RCM_reordering::reverse_cuthill(){
    queue<int> Q;
    vector<int> R;
    
    vector<pair<int, double> > notVisited;
    sparsify();
    vector<int> degrees = Degrees();

    for(int i=0; i<_matrix.getNoRows(); i++){
        notVisited.push_back(make_pair(i, degrees[i]));
    }
    while(notVisited.size()){
        int min = minIndex(notVisited);
        Q.push(notVisited[min].first);
        notVisited.erase(notVisited.begin() + min);
        while(!Q.empty()){
            vector<int> temp;
            for(int i=0; i<_matrix.getNoCols(); i++){
                if (getIndex(notVisited, i) != 1){
                    if(i!=Q.front() && _matrix.getData(Q.front(), i) == 1)
                        temp.push_back(i);
                        notVisited.erase(notVisited.begin() + getIndex(notVisited, i));
                }
            }
            temp = sortTemp(temp, degrees);
            for(int i=0; i<temp.size(); i++){
                Q.push(temp[i]);
            }
            R.push_back(Q.front());
            Q.pop();
        }
    }
    return R;
}   

