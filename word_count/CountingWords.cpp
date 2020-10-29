#include "CountingWords.h"
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

CountingWords::CountingWords()
{
    summ = 0;
}

namespace {
    bool comparatorSort(const pair<string, int>& f, const pair<string, int>& b)
    {
        return f.second > b.second;
    }
}

void CountingWords::addText(const string& fileName)
{
    ifstream input(fileName);
    if (!input) {
        throw std::invalid_argument("Can not open input file.");
    }
    else
    {
        string str, buffer;
        const string a = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
        while (getline(input, str)) {
            while (!str.empty())
            {
                std::size_t found = str.find_first_not_of(a);
                if (found != std::string::npos)
                {
                    if (found != 0)
                    {
                        buffer.append(str, 0, found);
                        str.erase(0, found + 1);
                        mp[buffer]++;
                        buffer.clear();
                        summ++;
                    }
                    else
                    {
                        str.erase(0, found + 1);
                    }
                }
                else
                {
                    buffer.append(str, 0);

                    str.erase(0, str.size());
                    mp[buffer]++;
                    buffer.clear();
                    summ++;
                }
            }
        }
        input.close();
    }
}

void CountingWords::writingCSV(const std::string& fileName) {
    vector <pair<string, int>> vecofwords(mp.begin(), mp.end());
    sort(vecofwords.begin(), vecofwords.end(), comparatorSort);
    ofstream fout(fileName);
    double persent;
    for (int i = 0; i < vecofwords.size(); ++i) {
        persent = vecofwords[i].second * 100.0 / summ;
        fout << vecofwords[i].first << ',' << vecofwords[i].second << ',' << persent << '%' << endl;
    }
    fout.close();
}
