#ifndef FIELD_H
#define FIELD_H


#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <stdlib.h>
#include <time.h>

template< typename vectorType>
class Field

{

private:

    // Data members

    double createdValue;

public:

    double total;
    //vector of scalars
    std::vector<double>  fieldValues;
    std::vector<vector3> vectorFieldValues;
    std::vector<tensor> tensorFieldValues;
    std::vector<vectorType> vectorField;
    std::vector<double> fieldMags;

// Member functions
    std::vector<double> mag();
         
    int N;
    int M;
    
// Constructors
    Field();
    Field(int n);
};

#include "fieldI.h"

#endif