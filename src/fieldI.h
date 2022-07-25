#include "field.h"

template< typename vectorType>
Field<vectorType>::Field()
{

}

template< typename vectorType>
Field<vectorType>::Field(int n)
{
    srand(time(NULL));
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

template< typename vectorType>
std::vector<double> Field<vectorType>::mag()
{
    N= (int)fieldValues.size();

    for(int r= 0; r < fieldValues.size(); r++){

    if(typeid(vectorType) == typeid(double))
    {
        for (int i = 0; i < fieldValues.size(); i++)
        {
            FieldMags.push_back(fieldValues[i]);
        }
    }


    else if(typeid(vectorType) == typeid(vector3))
    {  
        N= (int)vectorFieldValues.size();
        std::vector<double> total;

        for (int i = 0; i < vectorFieldValues.size(); i++)
        {
            for (int j = 0; j < vectorFieldValues[i].size(); j++)
            { 
                total[i] += vectorFieldValues[i][j]*vectorFieldValues[i][j];                        //each element is multiplied by is own value and summed to a total
            }
        
            FieldMags.push_back(sqrt(total[i]));
        }
    }


    else if(typeid(vectorType) == typeid(tensor))
    {   

    }
}
return FieldMags;
}

/*
//vector of vectores
template< typename vectorType>
vectorType Field<vectorType>::mag(){

    double  total = 0;

    for (int i = 0; i < fieldValues.size(); ++i)
        {
            total += fieldValues[i]*fieldValues[i];                        //each element is multiplied by is own value and summed to a total
        }
    return sqrt(total);   
}

template< typename vectorType>
vectorType Field<vectorType>::magN(){
    
    std::cout << "--- Magnitude of each vector: ----------------- " << std::endl;

    std::array<double, 3> total;

    N= (int)vectorFieldValues.size();

    for (int i = 0; i < vectorFieldValues.size(); i++)
    {
       for (int j = 0; j < vectorFieldValues[i].size(); j++)
       { 
            total[i] += vectorFieldValues[i][j]*vectorFieldValues[i][j];                        //each element is multiplied by is own value and summed to a total
       }

        total[i] = sqrt(total[i]);
    }
    
    return total;
}
          

            

//vector of tensors
template< typename vectorType>
vectorType Field<vectorType>::magNT(){

    std::cout << "--- Magnitude of each tensor: ----------------- " << std::endl;

    std::array<double, 9> totalT;

    M= (int)tensorFieldValues.size();

    for (int i = 0; i < tensorFieldValues.size(); i++)
    {
        for (int j = 0; j < tensorFieldValues[i].size(); j++)
            { 
                totalT[i] += tensorFieldValues[i][j]*tensorFieldValues[i][j];                        //each element is multiplied by is own value and summed to a total
            }

        totalT[i] = sqrt(totalT[i]);
    }
    
    return totalT;

}*/