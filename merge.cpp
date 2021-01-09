/*
* Name: Adam Oberg
* File: merge.cpp
* Description: program to create do a merge sort algorithm
* Date: 1/8/2021
*/


#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
  ifstream file;
  string fileName;
  std::cout << "What is the name the file you want to be sorted: ";
  std::cin >> fileName;
  file.open(fileName);

  return 0;
}
