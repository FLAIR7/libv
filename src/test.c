#include "libv.h"
#include <stdio.h>
#include <stdlib.h>


void test(int n, int *p){
    if(n != 0 || p != NULL)
        fprintf(stdout, "Test success\n");
    else 
        fprintf(stdout, "test failed!\n");
}

void print_test(const char *test_name){
    fprintf(stdout, "\n%s test\n", test_name);
}


int main(void){
 
/*==========================================================
                                                MEMORY
============================================================*/
    void *p;
    void **p2;
    
    //v_malloc
    p = v_malloc(5);
    p2 = &p;
    print_test("v_malloc");
    test(0, p);
    
    //v_free_ptr
    v_free_ptr(p2);
    print_test("v_free_ptr");



/*==========================================================
                                                STRING
============================================================*/   
    int a; 

    //v_strlen
    a = v_strlen("ola");
    print_test("vstrlen");
    test(a, NULL);

    //to_lower 
    a = to_lower('A');
    print_test("to_lower");
    test(a, NULL);
    
    //to_upper
    a = to_upper('a');
    print_test("to_upper");
    test(a, NULL);

/*==========================================================
                                                MATH
============================================================*/
    int b; 

    //gcd
    b = gcd(12, 9);
    print_test("gdc");
    test(b, NULL);
    
    // lcm
    b = lcm(12, 9);
    print_test("lcm");
    test(b, NULL);
    
    b = factorial(5);
    print_test("factorial");
    test(b, NULL);

    return 0;
}

