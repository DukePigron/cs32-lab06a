#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {
    WordCount w;

    w.incrWordCount("Monkey");
    w.incrWordCount("monkey");
    w.incrWordCount("MonKey");
    w.incrWordCount("MonkEy");
    w.incrWordCount("MonkeY");
    w.incrWordCount("MoNkey");

    w.incrWordCount("apple");
    w.incrWordCount("apple");
    w.incrWordCount("pear");
    w.incrWordCount("banana");

    assertEquals(6, w.getWordCount("monkey"), "w.getWordCount(\"monkey\") should return 6", 1);
    assertEquals(10, w.getTotalWords(), "w.getTotalWords() should return 10", 2);
    assertEquals(4, w.getNumUniqueWords(), "w.getNumUniqueWords() should return 4", 3);

    w.decrWordCount("MoNkey");
    assertEquals(5, w.getWordCount("monkey"), "w.getWordCount(\"monkey\") should return 5", 4);

    w.decrWordCount("pear");
    assertEquals(0, w.getWordCount("pear"), "w.getWordCount(\"pear\") should return 0", 5);

    return 0;
}