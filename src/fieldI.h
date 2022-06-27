#include "field.h"

template< typename vectorType>
Field<vectorType>::Field()
{

}

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

template< typename vectorType>
double Field<vectorType>::mag()
{
    double  total = 0;

    for (int i = 0; i < fieldValues.size(); ++i)
        {
            total += fieldValues[i]*fieldValues[i];                        //each element is multiplied by is own value and summed to a total
        }
    return sqrt(total);                                               //last step is to do the square root of the summed value to get the magnitude vector
}

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
         std::cout << "--- End vector ------------------- " << std::endl;
         fieldValues.push_back(vec);                                      
     }
     // this->vectorFieldMags=this->vectorFieldValues.this->mag();
 }


/*std::vector<double> Field::mag(vector3)
{
    std::vector<double> vectorMags(this->vectorFieldValues.size(),0.0);        // size of vectorFieldValues and inicialized to 0
    
    std::cout << "--- Magnitude of each vector: ----------------- " << std::endl;
    for (int posI = 0; posI < vectorMags.size(); posI++)
    {
        vectorMags[posI] = mag(this->vectorFieldValues[posI]);                 //magnitude for the vector inside vectorFieldValues in the pistion I
        std::cout << vectorMags[posI] << std::endl;                        
    }
    std::cout << "--- End of magnitudes ----------------- " << std::endl;
    return vectorMags;                                                
}

double Field::mag(const std::vector<double>& fieldValues)
{
    double  total = 0;

    for (int i = 0; i < fieldValues.size(); ++i)
        {
            total += fieldValues[i]*fieldValues[i];                        //each element is multiplied by is own value and summed to a total
        }
    return sqrt(total);                                                //last step is to do the square root of the summed value to get the magnitude vector
} */