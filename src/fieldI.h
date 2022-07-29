#include "field.h"

template< typename vectorType>
Field<vectorType>::Field()
{

}

template< typename vectorType>
Field<vectorType>::Field(int n)
{
    //srand(time(NULL));  //see this!!!
    for(int r= 0; r <n; r++)
    {   
        createdValue=0;
        if(typeid(vectorType) == typeid(double))
        {
            createdValue =(rand() %10)+(double(rand())/RAND_MAX);         //First we have the int number and then the decimal part
            std::cout << createdValue << std::endl;
            fieldValues.push_back(createdValue);                          //created value is pushed into the fieldValues vector
        }

        else if(typeid(vectorType) == typeid(vector3))
        {  
            std::cout << "--- Start vector ----------------- " << std::endl;
            std::array<double, 3> vec;
            for(int i=0; i<3; i++)
            {
            createdValue =(rand() %10)+(double(rand())/RAND_MAX);         //First we have the int number and then the decimal part
            vec[i]=createdValue;
            std::cout << createdValue << std::endl;
            }
            vectorFieldValues.push_back(vec);                          //created value is pushed into the fieldValues vector
            std::cout << "--- End vector ------------------- " << std::endl;
        }

        else if(typeid(vectorType) == typeid(tensor))
        {   
            std::cout << "--- Start vector ----------------- " << std::endl;
            std::array<double, 9> vec;
            for(int i=0; i<9; i++)
            {
            createdValue =(rand() %10)+(double(rand())/RAND_MAX);         //First we have the int number and then the decimal part
            vec[i]=createdValue;                          //created value is pushed into the fieldValues vector
            std::cout << createdValue << std::endl;
            }
            tensorFieldValues.push_back(vec);
            std::cout << "--- End vector ------------------- " << std::endl;
        }
    }
}

//magnitude

/*template < typename vectorType>
std::vector<double> Field<vectorType>::mag(int n){
    for(int i = 0; i < n; i++)
    {   
        fieldMags[i]=vectorField.at(i).calcMag();
    }
    return fieldMags;
};

template < typename vectorType>
double Field<vectorType>::calcMag()
    {       
        vectorType vector;
        double total = 0;
        for (int j = 0; j < vector.size(); j++)
        {
            total += vector[j]*vector[j];                     
            std::cout << "magnitude of vector is: " << sqrt(total) << std::endl;
        }
        return sqrt(total);
    };

template <>
double Field<tensor>::calcMag()
{
    tensor vector;
    double total = 0;
    for (int j = 0; j < vector.size(); j+=4)
    {
        total += vector[j]*vector[j];                     
        std::cout << "magnitude of vector is: " << sqrt(total) << std::endl;
    }
    return sqrt(total);
}*/


template < typename vectorType>
std::vector<double> Field<vectorType>::mag()
{
    return {0};
};

template<>
std::vector<double>  Field<double>::mag()
{
    for(int r = 0; r < fieldValues.size(); r++)
    {
        total=0;
        total += fieldValues[r]*fieldValues[r];                     
        std::cout << "magnitude of scalar is: " << sqrt(total) << std::endl;
        fieldMags.push_back(sqrt(total));
    }
    return fieldMags;
}

template<>
std::vector<double>  Field<vector3>::mag()
{
    for(int r = 0; r < vectorFieldValues.size(); r++)
    {
        double total=0;
        for(int j = 0; j < 3; j++)
        {   
            total += vectorFieldValues[r][j]*vectorFieldValues[r][j];                     
        }
        std::cout << "magnitude of vector is: " << sqrt(total) << std::endl;
        fieldMags.push_back(sqrt(total));
    }
    return fieldMags;
}

template<>
std::vector<double>  Field<tensor>::mag()
{
    for(int r = 0; r < tensorFieldValues.size(); r++)
    {   
        total=0;
        int j=0;
            double diag1 = tensorFieldValues[r][j=0]*tensorFieldValues[r][j=4];        //ok              
            double diag2 = tensorFieldValues[r][j=0]*tensorFieldValues[r][j=8];         //ok
            double diag3 = tensorFieldValues[r][j=4]*tensorFieldValues[r][j=8];         //ok
            double diag4 = tensorFieldValues[r][j=1]*tensorFieldValues[r][j=3];         //ok
            double diag5 = tensorFieldValues[r][j=5]*tensorFieldValues[r][j=7];         //ok
            double diag6 = tensorFieldValues[r][j=2]*tensorFieldValues[r][j=6];         //ok
                        
        total=diag1+diag2+diag3-diag4-diag5-diag6;
        std::cout << "magnitude of tensor is: " << total << std::endl;
    }
    fieldMags.push_back(total);
    return fieldMags;
}



