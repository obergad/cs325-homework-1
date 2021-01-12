/*
* Name: Adam Oberg
* File: merge.cpp
* Description: program to create do a merge sort algorithm
* Date: 1/8/2021
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


//Expected Input
/*==============
* 1 5
* 6 2 6 3 4 3 4
* 2 3 6
* 5 2 3 5 3 9
===============*/

//Interpreted from https://www.geeksforgeeks.org/merge-sort/
std::vector<int> sort(std::vector<int> v, int l_index, int middle_index, int r_index){

  int num1 = middle_index - l_index + 1;
  int num2 = r_index - middle_index;
  int i, j;
  //temp vectors
  std::vector<int> vRight;
  std::vector<int> vLeft;

  //copy data from v to temp1 and 2
  for (i = 0; i < num1; i++)
    vRight[i] = vRight[l_index + i];
  for (j = 0; j < num2; j++)
    vLeft[j] = vLeft[middle_index + 1 + j];

  i = 0;
  j = 0; // reset i and j

  int k = l_index;

  while (i < num1 && j < num2) {
    if(vRight[i] <= vLeft[j]){
      v[k] = vLeft[i];
      i++;
    }
    else{
      v[k] = vRight[j];
      j++;
    }
    k++;
  }
  
//copy elements of vleft if ther is any
while (i < num1) {
  v[k] = vLeft[i];
  i++;
  k++;
}

//copy elements of vright if ther is any
while (j < num2) {
  v[k] = vRight[i];
  j++;
  k++;
}

  return v;
}
//Interpreted from https://www.geeksforgeeks.org/merge-sort/
std::vector<int> mergeSort(std::vector<int> v, int l_index, int r_index){
  if(l_index  >= r_index)
    return v;
  int middle_index = (l_index + r_index - 1) / 2;
  mergeSort(v,l_index, middle_index);
  mergeSort(v, middle_index + 1, r_index);
  v = sort(v, l_index, middle_index ,r_index);
}


//Print the vector to stdout
void printVector(std::vector<int> v){
  int vSize = v.size();
  for (size_t i = 0; i < vSize; i++) {
    std::cout << v[i] << ' ';
  }
    std::cout << '\n';
}


int main(int argc, char const *argv[]) {
  std::ifstream file;
  std::vector<int> v;
  int  numint, value, numlines;
  file.open("data.txt");
  while (file >> numint) {
    for (int i = 0; i < numint; i++) {
        file >> value;
        v.push_back(value);
    }
    mergeSort(v, 0, v.size() - 1);
    printVector(v);
    std::cout << '\n';
    v.clear();
  }
  file.close();
  return 0;
}
