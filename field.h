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
double  total;

public:
    //vector of scalars
    std::vector<vectorType>  fieldValues;

    //vector of vectores
    //std::vector<std::vector<double>> vectorFieldValues;
    //std::vector<double> vectorFieldMags;

    //vector of tensors
    //std::array<double, 9> tensor;
    //std::vector<tensor> tensorValues;


// Member functions
    
    double mag();

// Constructors

    Field();
    // Field(int n);
    // Field(int n, std::vector<double> vec);
};
#include "fieldI.h"

#endif