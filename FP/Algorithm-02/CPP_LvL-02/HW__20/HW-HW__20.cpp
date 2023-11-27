#include <iostream>
#include "../../My_Libraries/Layout.h"
using namespace std;

int main()
{

    Layout::setProgramHeader("int & Float & String[arr & char] Format printf()");
    int num = 3, result = 5;
    double num1 = 3.45346, result1 = 5.34534;
    char arr[] = "Fahad", g = 'G';

    printf("when im plaing i like use number %d cuz its my lucky number, so i won the %d matches :)\n", num, result);
    printf("and he won percentage was %0*d%\n", result, num);

    printf("\nwhen im plaing i like use number %.2f cuz its my lucky number, so i won the %.3f matches :)\n", num1, result1);
    printf("and he won percentage was %.*f%\n", 3, num1);
    printf("\nwhen %s was plaing i like use number 5 cuz its my lucky number, so he won the 3 matches :)\n", arr);
    printf("%*c and he won percentage was 0.3%\n", 3, g);
    return 0;
}