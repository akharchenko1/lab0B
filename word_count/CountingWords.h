#pragma once
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
#include<exception>

 using namespace std;

class CountingWords
{
private:
    int summ;
    map <string, int> mp;
public:
    CountingWords();
    void addText(const std::string& fileName);
    void writingCSV(const std::string& fileName);
    ~CountingWords()
    {}

};