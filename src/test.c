#include "libv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(int n, int *p, char *str){
    if(n != 0 || p != NULL || str != NULL)
        fprintf(stdout, "Test success\n");
    else 
        fprintf(stdout, "Test failed!\n");
}

void print_test(const char *test_name){
    fprintf(stdout, "\n%s Test\n", test_name);
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
    test(0, p, NULL);
    
    //v_free_ptr
    v_free_ptr(p2);
    print_test("v_free_ptr");
    printf("CANNOT MAKE THIS TEST, BECAUSE IT HAS SIDE EFFECT\n");

/*==========================================================
                                                STRING
============================================================*/   
    int a; 
    //char *str = strdup("ola");
    char str[] = "ola";
    char *s;

    //v_strlen
    a = v_strlen("ola");
    print_test("v_strlen / LENGTH STRING");
    test(a, NULL, NULL);
    
    //v_strrev
    s = v_strrev(str); //alo
    print_test("v_strrev / REVERSE STRING");
    test(0, NULL, s);

    //to_lower 
    a = to_lower('A');
    print_test("to_lower / TO LOWER");
    test(a, NULL, NULL);
    
    //to_upper
    a = to_upper('a');
    print_test("to_upper / TO UPPER");
    test(a, NULL, NULL);

    //v_print
    print_test("print / PRINT");
    printf("CANNOT MAKE THIS TEST, BECAUSE IT HAS SIDE EFFECT\n");

/*==========================================================
                                                MATH
============================================================*/
    int b; 
    double b1;

    //gcd
    b = gcd(12, 9);
    print_test("gcd / GREATEST COMMON DIVISOR");
    test(b, NULL, NULL);
    
    // lcm
    b = lcm(12, 9);
    print_test("lcm / LEAST COMMON MULTIPLE");
    test(b, NULL, NULL);
    
    //factorial
    b = factorial(5);
    print_test("factorial / FACTORIAL");
    test(b, NULL, NULL);

    //v_sqrt
    b1 = v_sqrt(2);
    print_test("v_sqrt / SQUARE ROOT"); 
    test((int)b1, NULL, NULL);
    
    //v_rsqrt
    b1 = v_rsqrt(1500.5F);
    print_test("v_rsqrt / REVERSE SQUARE ROOT");
    printf("CANNOT MAKE THIS TEST, BECAUSE IT HAS SIDE EFFECT\n");
    
    //is_prime
    b = is_prime(2);
    print_test("is_prime / IS PRIME");
    test(b, NULL, NULL);
    
    //is_digit
    b = is_digit('3');
    print_test("is_digit / IS DIGIT");
    test(b, NULL, NULL);

    return 0;
}

