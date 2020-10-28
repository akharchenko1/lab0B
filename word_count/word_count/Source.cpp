
#include "CountingWords.h"


int main(int argc, char* argv[])
{
    CountingWords countingWords;
    countingWords.addText(argv[1]);
    countingWords.writingCSV(argv[2]);
    return 0;
}