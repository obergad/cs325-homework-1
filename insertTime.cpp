/*
* Name: Adam Oberg
* File: insertTime.cpp
* Description: program to create do a insersion sort algorithm and time it
* Date: 1/8/2021
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>

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
    v = sort(v); // sort
    auto end = std::chrono::steady_clock::now(); // stop the steady_clock
    v.clear();
    std::cout << "Ran sort n =" << i << "\nTaking:" <<
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
    << " milliseconds." <<'\n';
    i += 4999;
  }
  return 0;
}
