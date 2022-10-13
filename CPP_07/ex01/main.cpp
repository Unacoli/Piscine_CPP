#include "iter.hpp"

int main(void)
{
    int iarr[4] = {1, 2, 3, 4};
    char    carr[6] = "hello";
    float   farr[3] = {0.1f, 2.2f, 3.3f};
    std::string sarr[5] = {"owo", "uwu", "awa", "iwi", "ewe"};

    printTest(iarr, 4, "INT");
    printTest(carr, 6, "CHAR");
    printTest(farr, 3, "FLOAT");
    printTest(sarr, 5, "STRING");
    
    return (0);
}