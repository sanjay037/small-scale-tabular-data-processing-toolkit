#ifndef SYMMETRIC_MATRIX_H
#define SYMMETRIC_MATRIX_H_

<<<<<<< HEAD
#include "DataMatrix.h"
=======
#include "Matrix.h"

>>>>>>> 55666de28e927deae2c6382c195272e276f48ef9
//Inheriting from Matrix//
class SymmetricMatrix : public DataMatrix {
    private: 
<<<<<<< HEAD
    public: SymmetricMatrix(int M): DataMatrix(M,M){}//Calling Constructor of Matrix//
=======
    
    public: 
            SymmetricMatrix(int M): Matrix(M, M){}//Calling Constructor of Matrix//
>>>>>>> 55666de28e927deae2c6382c195272e276f48ef9
            // SymmetricMatrix(const SymmetricMatrix&);
            // ~SymmetricMatrix();
            double get_matrix_element(int i,int j);
};

#endif
