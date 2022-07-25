#include <vector>
#include <array>

typedef std::array<double, 3> vector3;
typedef std::array<double, 9> tensor;

#include "field.h"

int main()
{
    //vector of scalars
    Field<double> myFieldTest0(5);
    std::cout<< "   " <<std::endl;



    //vector of vectores
    Field<vector3> myFieldTest1(2);
    std::cout<< "   " <<std::endl;




    //vector of tensors    
    Field<tensor> myFieldTest2(1);
    std::cout<< "   " <<std::endl;




    std::vector<double> FieldMags = myFieldTest0.mag();

    for (int r = 0; r < myFieldTest0.N; ++r)
    {

        std::cout<< "magnitude is:" << FieldMags[r] << std::endl;

    }
}

