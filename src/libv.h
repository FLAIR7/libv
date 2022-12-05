#ifndef LIBV_H
#define LIBV_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Memory */
void *v_malloc(unsigned int len);
void *v_memcpy(void *dest, const void *src, size_t len);
int v_memcmp(const void *x, const void *y, size_t len); 
void v_free_ptr(void **p);

/* Strings */
#define read_str(a) fgets(a, sizeof(a), stdin), a[strlen(a)-1] = '\0';

int v_strlen(char str[]);
char *v_strrev(char str[]);
int to_lower(int c);
int to_upper(int c);
int v_print(char str[]);

/* Array */
#define array_size(a) (sizeof(a) / sizeof *(a))

/* Math */
int gcd(int a, int b);
int lcm(int a, int b);
int factorial(int n);
double v_sqrt(double n);
float v_rsqrt(float n);
int is_prime(long long int n);

/* Util */
int is_ascii(int n);
int is_digit(int n);
int is_alpha(int n);
int is_alnum(int n);
void midpoint_algorithm(int x_centre, int y_centre, int radius);

/* File*/
int write_file(char *file, char *str);

/* Colors */
#define WHITE "\033[01;37m"
#define BLACK "\033[22;30m"
#define RED "\033[22;31m"
#define GREEN "\033[22;32m"
#define BLUE "\033[22;34m"

/* Macros */


#endif
