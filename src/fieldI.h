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

    double  total = 0;

    for (int i = 0; i < fieldValues.size(); ++i)
        {
            total += fieldValues[i]*fieldValues[i];                        //each element is multiplied by is own value and summed to a total
        }
     std::cout<< "magnitude of vector: " << sqrt(total) << std::endl;
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

        for (int i = 0; i < vectorFieldValues.size(); ++i)
                double  total = 0;
            {
                std::vector<double> vectorMags(vec.size(),0.0);        // size of vectorFieldValues and inicialized to 0
                for (int posI = 0; posI < vectorMags.size(); posI++)
                {
                    vectorMags[posI] = vec[posI];                 //magnitude for the vector inside vectorFieldValues in the pistion I                       
                }

                for (int i = 0; i < vectorMags.size(); ++i)
                {
                    total += vectorMags[i]*vectorMags[i];                      
                }
            }
            std::cout<< "magnitude of vector: " << sqrt(total) << std::endl;
     }
     
     // this->vectorFieldMags=this->vectorFieldValues.this->mag();
 }





 /*//magnitude
template< typename vectorType>
double Field<vectorType>::mag()
{   
    double  total = 0;

    for (int i = 0; i < fieldValues.size(); ++i)
        {
            total += fieldValues[i]*fieldValues[i];                        //each element is multiplied by is own value and summed to a total
        }
    return sqrt(total); 
}     

template< typename vectorType>
std::vector<double>  Field<vectorType>::mag(const std::vector<double>& fieldValues)
{
    std::vector<double> vectorMags(fieldValues.size(),0.0);        // size of vectorFieldValues and inicialized to 0
    
    std::cout << "--- Magnitude of each vector: ----------------- " << std::endl;
    for (int posI = 0; posI < vectorMags.size(); posI++)
    {
        vectorMags[posI] = mag(fieldValues[posI]);                 //magnitude for the vector inside vectorFieldValues in the pistion I
        std::cout << vectorMags[posI] << std::endl;                        
    }
    std::cout << "--- End of magnitudes ----------------- " << std::endl;
    return vectorMags;                                                
}
*/


/*template< typename vectorType>
double Field::mag(const std::vector<double>& fieldValues)
{
    double  total = 0;

    for (int i = 0; i < vectorValues.size(); ++i)
        {
            total += vectorValues[i]*vectorValues[i];                      
        }
    return sqrt(total);
}*/






//vector of tensors

template< typename vectorType>
Field<vectorType>::Field(double n, std::array<double, 9> ten)
{
     srand(time(NULL));
     for(int r= 0; r <n; r++){

         //std::vector<double> inVector(3,0);

        std::cout << "--- Start vector ----------------- " << std::endl;
        for(int i=0; i<9; i++){
         createdValue =(rand() %10)+(double(rand())/RAND_MAX);         //First we have the int number and then the decimal part
         ten[i]=createdValue;                          //created value is pushed into the fieldValues vector
         std::cout << createdValue << std::endl;
         }
         std::cout << "--- End vector ------------------- " << std::endl;
         tensorFieldValues.push_back(ten);

        for (int i = 0; i < tensorFieldValues.size(); ++i)
        double  total = 0;
        {
            std::vector<double> tensorMags(ten.size(),0.0);        // size of vectorFieldValues and inicialized to 0
            for (int posI = 0; posI < tensorMags.size(); posI++)
            {
                tensorMags[posI] = ten[posI];                 //magnitude for the vector inside vectorFieldValues in the pistion I                       
            }

            for (int i = 0; i < tensorMags.size(); ++i)
            {
                total += tensorMags[i]*tensorMags[i];                      
            }
        }
        std::cout<< "magnitude of tensor: " << sqrt(total) << std::endl;
     }
     
     // this->vectorFieldMags=this->vectorFieldValues.this->mag();
 }