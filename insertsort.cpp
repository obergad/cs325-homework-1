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
* 1 5
* 6 2 6 3 4 3 4
* 2 3 6
* 5 2 3 5 3 9
===============*/

using namespace std;

vector<int> sort(vector<int> v){





  return v;
}

int main(int argc, char const *argv[]) {
  ifstream file;
  vector<vector<int> > v;
  vector<int> inputVector;
  int  numint, value, numlines;
  file.open("data.txt");
  while (file >> numint) {
    for (int i = 0; i < numint; i++) {
        file >> value;
        inputVector.push_back(value);
        std::cout << value << " ";
    }
        v.push_back(inputVector);
        cout << endl;
  }
  cout << "done reading file" << '\n';
  file.close();
  return 0;
}
