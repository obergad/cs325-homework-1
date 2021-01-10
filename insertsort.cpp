/*
* Name: Adam Oberg
* File: insersion.cpp
* Description: program to create do a insersion sort algorithm
* Date: 1/8/2021
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

//Expected Input
/*==============
* 1 9 5
* 6 2 6 3 4 3 4
* 4 11 4 5 76
* 5 2 3 5 3 9
===============*/
//Expected Output
/*==============
* 2 5 9
* 6 2 3 3 4 4 6
* 4 4 5 11 76
* 5 2 3 3 5 9
===============*/


std::vector<int> sort(std::vector<int> v){
  int i, key, j, n;
  n = v.size();
    for (i = 1 ; i < n; i++) { //start at 1 not 0
      // std::cout << "begining of for loop" << '\n';
      key = v[i]; //set key
      j = i - 1; // set key - 1
      /*moving elements of v that are greater than the key
      to one pos ahead of their current pos*/
      while (j >= 0 && v[j] > key) {
        // std::cout << "begining of while loop" << '\n';
        v[j + 1] = v[j];
        j = j - 1;
      //end while loop
      }
      v[j + 1] = key;
  //end for loop
  }
  return v;
}

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
        v = sort(v);
        printVector(v);
        std::cout << '\n';
        v.clear();

  }
  file.close();
  return 0;
}
