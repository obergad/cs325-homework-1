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

std::vector<int> sort(std::vector<int> v){
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
