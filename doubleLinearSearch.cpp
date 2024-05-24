// Rahul Chaudhari
// This program find the index postions of a search value but until its 2nd occurance

#include <iostream>
#include <vector>

using namespace std;

/**
    This function does the double linear search in an array
    @param vec is the vector that is passed by reference which has all the values
    @param search_value the value which is to be search
    @return a vector of interger with the index position of each vector
*/
vector<int> Double_Linear_Search(const vector<int> &vec, int search_value);

int main()
{
    vector<int> numbers {10, 50, 16, 1, 9, 15, 16, 20, 16, 2, 5};
    int search_value = 16;
    vector<int> search_position = Double_Linear_Search(numbers, search_value);
    for (int i = 0; i < search_position.size(); i++)
    {
        cout << search_position.at(i) << " ";
    }

    return 0;  
}

vector<int> Double_Linear_Search(const vector<int> &vec, int search_value) 
{
    size_t vector_size = vec.size();
    vector<int> resultant_vector;
    for(int i = 0; i < vector_size; i++) 
    {
        if(vec.at(i) == search_value)
        {
            resultant_vector.push_back(i);
        }
        if (resultant_vector.size() == 2)
        {
            break; // as soon as the 2nd value is found jump out of the loop
        }
    }   
    if (resultant_vector.size() < 2)
    {
        // clear the vector just in case it has 1st occurance of search value
        resultant_vector.clear(); 
        resultant_vector.push_back(-1);
    }    
    return resultant_vector;
}
