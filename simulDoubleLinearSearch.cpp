// Rahul Chaudhari
// Simulation of DoubleLinearSearch Algorithm
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>

using namespace std;

const int NOT_FOUND = -1;

/**
    This function generate random values
    @param min the minimum range for random value
    @param max the maximum range for random value
    @return random values between the max and min. 
*/
int random_value(int min, int max);

/**
    This function does the double linear search in an array
    @param vec is the vector that is passed by reference which has all the values
    @param search_value the value which is to be search
    @param count_steps the value that will return the total steps taken
    @return a vector of interger with the index position of each vector
*/
vector<int> Double_Linear_Search(const vector<int> &vec, int search_value, int & count_steps);

int main() 
{
  const long SIMUL_SIZE = 1000;
  const int MIN = 0;
  const int MAX = 15000;
  cout << "----------------------------------" << endl;
  // numbers of values that will go into vectors during sulumations
  vector <int> input_sizes {10000, 20000, 35000, 50000, 75000, 100000};
  
  // Use current time as seed for random generator 
  srand(time(0));  
  
  // This loop will run 6 times for different values above from 10K to 100K
  for (int i = 0; i < input_sizes.size(); i++)
  {
    int N = input_sizes.at(i); // taking different input sizes
    int total_steps = 0;
    int hits = 0;
    int misses = 0;
    int min_steps = INT_MAX;
  
    // main simulation loop;
    for (int simul_index = 0; simul_index < SIMUL_SIZE; simul_index++)
    {
      vector<int> array;
      int step_count = 0;
      
      // filling the vector with randoms values
      for (int array_index = 0; array_index < N; array_index++) 
      {
        int values = random_value(MIN,MAX);
        array.push_back(values);
      }
      
      // getting a random search value
      int search_value = random_value(MIN, MAX);
      vector<int> result = Double_Linear_Search(array, search_value, step_count);
      total_steps += step_count;
      
      if(result.at(0) != NOT_FOUND)
      {
        hits++;
      }
      else
      {
        misses++;
      }
      if (step_count < min_steps)
      {
        min_steps = step_count;
      }

    } 

    double average_steps = static_cast<double> (total_steps) / static_cast<double> (SIMUL_SIZE);
    cout << "Input Size (N): " << N << endl;
    cout << "Average Number of Steps: " << average_steps << endl;
    cout << "Hits: " << hits << endl;
    cout << "Misses: " << misses << endl;
    cout << "Minimum Steps: " << min_steps << endl;
    cout << "----------------------------------" << endl;
  
  }

  return 0;
}

// generate random values between min and max (inclusive)
int random_value(int min, int max)
{
  return min + rand() % (max - min) + 1;
}

// search the 2 occurance of a search value in vector
vector<int> Double_Linear_Search(const vector<int> &vec, int search_value, int & count_steps)
{
  size_t vector_size = vec.size();
  vector<int> resultant_vector;
  count_steps = 0;
  
  for(int i = 0; i < vector_size; i++) 
  {
    ++count_steps;
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
