
#include <vector>
#include <array>

typedef std::array<double, 3> vector3;
typedef std::array<double, 9> tensor;

#include "field.h"

int main()
{
    //vector of scalars
    Field<double> myFieldTest0(5);
    std::cout<< "magnitude of vector: " << myFieldTest0.mag() << std::endl;
    std::cout<< "   " <<std::endl;



    //vector of vectores
    Field<vector3> myFieldTest1(4, {0});

    vector3 total = myFieldTest1.magN();

    for (int i = 0; i < myFieldTest1.N; ++i)
    {

        std::cout<< "magnitude of vector:" << total[i] << std::endl;

    }    
    std::cout<< "   " <<std::endl;



    //vector of tensors    
    Field<tensor> myFieldTest2(2.0, {0});
    std::cout<< "   " <<std::endl;

    tensor totalT = myFieldTest2.magNT();

    for (int i = 0; i < myFieldTest2.M; ++i)
    {

        std::cout<< "magnitude of tensor:" << totalT[i] << std::endl;

    }
}

