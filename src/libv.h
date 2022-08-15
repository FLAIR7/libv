#ifndef LIBV_H
#define LIBV_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Memory */
void *vmalloc(unsigned int len);
void *vmemcpy(void *dest, const void *src, size_t len);
int vmemcmp(const void *x, const void *y, size_t len); 

/* Strings */
int vstrlen(const char*str);
int to_lower(int c);
int to_upper(int c);

/* Math */
int gcd(int a, int b);
int lcm(int a, int b);
int factorial(int n);
double v_sqrt(double n);
int is_prime(long long int n);
    

#endif
