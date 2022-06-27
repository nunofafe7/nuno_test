
#include <vector>
#include <array>

typedef std::array<double, 3> vector3;

#include "field.h"

int main()
{
    Field<double> myFieldTest0(5);
    std::cout<< "magnitude of vector: " <<myFieldTest0.mag() << std::endl;
    //Field<vector3> myFieldTest1(3);
}

