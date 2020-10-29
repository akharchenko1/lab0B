
#include "CountingWords.h"
#include <iostream>


int main(int argc, char* argv[])
{
    try {
    if (argc > 2)
    {       
        CountingWords countingWords;
        for (int i = 1; i < (argc - 1); i++)
        {
            countingWords.addText(argv[i]);
        }
        countingWords.writingCSV(argv[argc-1]);
    }
    else
    {
        std::cout << "Write two or more arguments ('../input.txt ../output.csv')" << std::endl;
    }
    }
    catch (std::exception& ex) {
        std::cerr << ex.what();
    }
    return 0;
}