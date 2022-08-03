#include <vector>
#include <array>

typedef std::array<double, 3> vector3;
typedef std::array<double, 9> tensor;

#include "field.h"

int main()
{
    //vector of scalars
    Field<double> myFieldTest0(4);
    myFieldTest0.mag();
    std::cout<< "   " <<std::endl;


    //vector of vectores
    Field<vector3> myFieldTest1(3);
    myFieldTest1.mag();
    std::cout<< "   " <<std::endl;


    //vector of tensors    
    Field<tensor> myFieldTest2(2);
    myFieldTest2.mag();
    std::cout<< "   " <<std::endl;
}
