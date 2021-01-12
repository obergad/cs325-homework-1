/*
* Name: Adam Oberg
* File: mergeTime.cpp
* Description: program to create do a merge sort algorithm and time it
* Date: 1/8/2021
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>



//Expected Input
/*==============
* 1 5
* 6 2 6 3 4 3 4
* 2 3 6
* 5 2 3 5 3 9
===============*/

//Interpreted from https://www.geeksforgeeks.org/merge-sort/
void merge(std::vector<int> v, int l_index, int middle_index, int r_index){

  int num1 = middle_index - l_index + 1;
  int num2 = r_index - middle_index;
  int i, j;
  //temp vectors
  std::vector<int> aRight;
  std::vector<int> aLeft;
  //copy data from v to temp1 and 2
  for (i = 0; i < num1; i++)
    aRight.push_back(v[l_index + i]);
  for (j = 0; j < num2; j++)
    aLeft.push_back(v[middle_index + 1 + j]);

  i = 0;
  j = 0; // reset i and j

  int k = l_index;

  while (i < num1 && j < num2) {
    if(aRight[i] <= aLeft[j]){
      v[k] = aLeft[i];
      i++;
    }
    else{
      v[k] = aRight[j];
      j++;
    }
    k++;
  }
//copy elements of aLeft if ther is any
while (i < num1) {
  v[k] = aLeft[i];
  i++;
  k++;
}
//These two while loops merge the arrays togeather
//copy elements of aRight if ther is any
while (j < num2) {
  v[k] = aRight[j];
  j++;
  k++;
}
}
//Interpreted from https://www.geeksforgeeks.org/merge-sort/
void mergeSort(std::vector<int> v, int l_index, int r_index){
  if(l_index  >= r_index)
    return;
  int middle_index = (l_index + r_index - 1) / 2;
  mergeSort(v,l_index, middle_index);
  mergeSort(v, middle_index + 1, r_index);
  merge(v, l_index, middle_index ,r_index);

}


//Print the vector to stdout
void printVector(std::vector<int> v){
  int vSize = v.size();
  for (size_t i = 0; i < vSize; i++) {
    std::cout << v[i] << ' ';
  }
    std::cout << '\n';
}

std::vector<int> generateVector(int numValues){
  std::vector<int> v;
  int temp;
  v.push_back(numValues);
  for (size_t i = 0; i < numValues; i++) {
    temp = rand() % 10000 + 1;
    v.push_back(temp);
  }
  return v;
}

int main(int argc, char const *argv[]) {
  std::vector<int> v;
  srand(time(NULL));
  int  numint, value, numlines;
  //Interpreted chrono code from https://www.techiedelight.com/measure-elapsed-time-program-chrono-library/
  for (size_t i = 5000; i <= 50000; i++) {
    v = generateVector(i);
    auto start = std::chrono::steady_clock::now(); //start the clock
    mergeSort(v, 0, v.size() - 1); // sort
    auto end = std::chrono::steady_clock::now(); // stop the steady_clock
    v.clear();
    std::cout << "Ran sort n =" << i << "\nTaking:" <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
    << " milliseconds." <<'\n';
    i += 4999;
  }
  return 0;
}
