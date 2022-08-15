#ifndef LIBV_H
#define LIBV_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Memory */
void *v_malloc(unsigned int len);
void *v_memcpy(void *dest, const void *src, size_t len);
int v_memcmp(const void *x, const void *y, size_t len); 
void v_free_ptr(void **p);

/* Strings */
int v_strlen(const char*str);
char *v_strrev(char *str);
int to_lower(int c);
int to_upper(int c);

/* Math */
int gcd(int a, int b);
int lcm(int a, int b);
int factorial(int n);
double v_sqrt(double n);
int is_prime(long long int n);

/* Util */
int is_ascii(int n);
int is_digit(int n);
void midpoint_algorithm(int x_centre, int y_centre, int radius);


#endif
