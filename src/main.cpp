
#include <vector>
#include <array>

typedef std::array<double, 3> vector3;
typedef std::array<double, 9> tensor;

#include "field.h"

int main()
{
    Field<double> myFieldTest0(2);
    std::cout<< "magnitude of vector: " <<myFieldTest0.mag() << std::endl;
    Field<vector3> myFieldTest1(2, {0,0,0});
    //std::cout<< "magnitude of vector: " << myFieldTest1.mag() << std::endl;
    Field<tensor> myFieldTest2(2.0, {0,0,0});
}

