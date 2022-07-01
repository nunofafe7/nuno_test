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
double total;

public:
    //vector of scalars
    std::vector<vectorType>  fieldValues;
    std::vector<std::vector<double>> vectorFieldValues;
    std::vector<double> vectorFieldMags;

// Member functions
    
    double mag();
    std::vector<double> mag(const std::vector<double>& fieldValues);
    
// Constructors

    Field();
    Field(int n);
    Field(int n, std::array<double, 3> vec);
    Field(double n, std::array<double, 9> ten);
};
#include "fieldI.h"

#endif