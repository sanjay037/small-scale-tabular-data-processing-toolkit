#ifndef RCM_REORDERING_
#define RCM_REORDERING_ 

#include<iostream>
#include"Matrix.h"
#include"Record.h"
#include<vector>
#include"SymmetricMatrix.h"

using namespace std;

class RCM_reordering{
    private:
        SymmetricMatrix _matrix;

    public:
        RCM_reordering(SymmetricMatrix _symSquareMatrix);
        RCM_reordering(const RCM_reordering &matrix);
        // ~rcm_reordering();
        void sparsify();
        int max_degree();
        vector<int> Degrees();
        vector<int> reverse_cuthill();
};
#endif
