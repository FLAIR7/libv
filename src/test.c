#include "libv.h"
#include <stdio.h>
#include <stdlib.h>


void test(int n){
    if(n != 0)
        fprintf(stdout, "Test success\n");
    else 
        fprintf(stdout, "test failed!\n");
}

void print_test(const char *test_name){
    fprintf(stdout, "\n%s test\n", test_name);
};


int main(void){
    
    //vstrlen
    int p;
    p = vstrlen("ola");
    print_test("vstrlen");
    test(p);

    //to_lower 
    p = to_lower('A');
    print_test("to_lower");
    test(p);
    
    //to_upper
    p = to_upper('a');
    print_test("to_upper");
    test(p);


    //gcd
    p = gcd(12, 9);
    print_test("gdc");
    test(p);
    
    // lcm
    p = lcm(12, 9);
    print_test("lcm");
    test(p);
    
    p = factorial(5);
    print_test("factorial");
    test(p);

    return 0;
}

