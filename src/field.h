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

// Member functions
    
    double mag();
    //double mag(const std::vector<double>& fieldValues);
    //std::vector<double> mag();

// Constructors

    Field();
    Field(int n);
    Field(int n, std::vector<double> vec);
};
#include "fieldI.h"

#endif