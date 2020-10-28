#pragma once
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>

 using namespace std;

class CountingWords
{
private:
    int summ;
    map <string, int> mp;
    string str, buffer;
    const string a = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
    double persent;
public:
    CountingWords();
    static bool comparatorSort(const pair<string, int>& f, const pair<string, int>& b);
    void addText(const std::string& fileName);
    void writingCSV(const std::string& fileName);
    ~CountingWords()
    {}

};