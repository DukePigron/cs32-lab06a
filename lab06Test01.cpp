#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {
    std::string str1 = WordCount::makeValidWord("12mOnkEYs-$");
    std::string str2 = WordCount::makeValidWord("Pa55ive");
    std::string str3 = WordCount::makeValidWord("\'emRight-There");

    assertEquals("monkeys", str1, "WordCount::makeValidWord(\"12mOnkEYs-$\") should return \"monkeys\"", 1);
    assertEquals("paive", str2, "WordCount::makeValidWord(\"Pa55ive\") should return \"paive\"", 2);
    assertEquals("emright-there", str3, "WordCount::makeValidWord(\"\'emRight-There\") should return \"emright-there\"", 3);

    return 0;
}