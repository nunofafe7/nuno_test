#include "field.h"

template< typename vectorType>
Field<vectorType>::Field()
{

}

//vector of scalars
template< typename vectorType>
Field<vectorType>::Field(int n)

{
     std::cout << "--- Start vector ----------------- " << std::endl;
     srand(time(NULL));
     for(int r= 0; r <n; r++){
         createdValue =(rand() %10)+(double(rand())/RAND_MAX);         //First we have the int number and then the decimal part
         fieldValues.push_back(createdValue);                          //created value is pushed into the fieldValues vector
         std::cout << createdValue << std::endl;
     }
     std::cout << "--- End vector ------------------- " << std::endl;

}

//vector of vectores
template< typename vectorType>
Field<vectorType>::Field(int n, std::array<double, 3> vec)
{
     srand(time(NULL));
     for(int r= 0; r <n; r++){

         //std::vector<double> inVector(3,0);

        std::cout << "--- Start vector ----------------- " << std::endl;
        for(int i=0; i<3; i++){
         createdValue =(rand() %10)+(double(rand())/RAND_MAX);         //First we have the int number and then the decimal part
         vec[i]=createdValue;                          //created value is pushed into the fieldValues vector
         std::cout << createdValue << std::endl;
         }
         vectorFieldValues.push_back(vec);
         std::cout << "--- End vector ------------------- " << std::endl;
     }
     
     // this->vectorFieldMags=this->vectorFieldValues.this->mag();
 }

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
Field<vectorType>::Field(double n, std::array<double, 9> ten)
{
     srand(time(NULL));
     for(int r= 0; r <n; r++){

         //std::vector<double> inVector(3,0);

        std::cout << "--- Start tensor ----------------- " << std::endl;
        for(int i=0; i<9; i++){
         createdValue =(rand() %10)+(double(rand())/RAND_MAX);         //First we have the int number and then the decimal part
         ten[i]=createdValue;                          //created value is pushed into the fieldValues vector
         std::cout << createdValue << std::endl;
         }
         std::cout << "--- End tensor ------------------- " << std::endl;
         tensorFieldValues.push_back(ten);
    }
}

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

}