/*
* Name: Adam Oberg
* File: generatetxt.cpp
* Description: generates a txt file filled with ints with an imputed value
* Date: 1/8/2021
*/

#include <stdio.h>      /* NULL */
#include <iostream>    // cout cin
#include <fstream>    // file stream
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


int main(int argc, char const *argv[]) {
  int rows, numValues, temp;
  std::ofstream file;
  srand(time(NULL));
  file.open("data.txt");
  std::cout << "How many rows do you want?:";
  std::cin >> rows;
  for (size_t i = 0; i < rows; i++) {
    std::cout << "How many values would you like to make for row " << i << "?:";
    std::cin >> numValues;
    file << numValues << " ";
    for (size_t i = 0; i < numValues; i++) {
      temp = rand() % 100 + 1;
      file << temp << " ";
    }
    file << "\n";
}
  return 0;
}
