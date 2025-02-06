#ifndef TESTER_H
#define TESTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <random>
#include <unordered_set>

using namespace std;

class Tester {
  public:
    void initCapture();
    void endCapture();	
    void clearInputBuffer();
    void pressEnterToContinue();
    void find(const vector<int>& keys, const string* search, int& error);
    void findInOrder(const vector<int>& keys, const string* search, int& error);
    void confirmAbsent(const vector<int>& keys, const string* search, int& error);
    
    void find(const vector<int>& keys, const vector<string>& search, int& error);
    void findInOrder(const vector<int>& keys, const vector<string>& search, int& error);
    void confirmAbsent(const vector<int>& keys, const vector<string>& search, int& error);

    void find(const vector<string>& toFind, int& error);
    void findInOrder(const vector<string>& toFind, int& error);
    void confirmAbsent(const vector<string>& toFind, int& error);
    
    string getOutput() { return output; }
    void ran(vector<int>& list, int count, int range);
    int ran(int range_from, int range_to);

  private:
    streambuf* oldCoutStreamBuf;
    ostringstream strCout;
    string output;
};

#endif