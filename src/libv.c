#include "libv.h"

/*============================================================
                                                  MEMORY
==============================================================*/

/*
 * allocates memory and returns a void pointer
 * returns NULL if cannot allocate memory
 *
 */

void *v_malloc(unsigned int len){
    int *ptr;
    ptr = malloc(len);
    if(ptr == NULL)
        return NULL;
    return ptr;
}

/*
 * copy the values of num bytes from the location pointed
 * to by source directly to the memory - 
 * returns NULL if both have none content
 */

void *v_memcpy(void *dest, const void *src, size_t len){
    void *ptr;
    if(dest == NULL && src == NULL)
        return NULL;
    ptr = dest;
    while(len-- > 0)
       *(char *)dest++ = *(char *)src++;
    return ptr;
}

/* 
 * returns the difference between    
 * the characters in ASCII table, 0 if 
 * there's no difference
 */

int v_memcpm(const void *x, const void *y, size_t len){
    while(len-- > 0) {
        if(*(unsigned char *)x != *(unsigned char *)y)
            return (*(unsigned char *) x - *(unsigned char *)y);
        x++;
        y++;
    }

    return (0);
}

/*
 *
 *
 *
 */

void v_free_ptr(void **p){
    if(*p){
        free(*p);
        *p = NULL;
    }
}

/*============================================================
                                                  STRINGS
==============================================================*/

/*
 * gives the length of a string
 * returns 0 if has no content
 *
 */

int v_strlen(const char *str){
    int i;
    i = 0;
    while(str[i])
        i++;
    return i;
}

/*
 * returns str reversed and if 
 * str is not defined, returns
 * the same str
 */

char *v_strrev(char *str){
    char *x, *y;

    if(!str || !*str)
        return str;
    for(x = str, y = str + v_strlen(str) - 1; y > x; ++x, --y){
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
    return str;
}

/*
 * if c is upercase, returns its lower
 * equivalent
 *
 */

int to_lower(int c){
    if(c >= 'A' && c <= 'Z')
        return (c + 32);
    return c;
}

/*
 * if c is lowercase, returns its upper
 * equivalent
 *
 */ 

int to_upper(int c){
    if(c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}

/*============================================================
                                                  MATH
==============================================================*/

/*
 * returns the Greatest commom divisor
 * (gcd). if b is not defined, returns a
 *
 */

int gcd(int a, int b){
    if(!b)
        return a;
    else 
        return gcd(b, a%b);
}

/* 
 * returns the Least commom multiple
 * and if b is not defined, returns a
 *
 */

int lcm(int a, int b){
    int x;
    if(!b)
        return a;
    else 
        x = (a * b) / (gcd(a, b));
    
    return x;
}

/*
 * returns the factorial of a number
 * and if n is 0 or negative, returns 1
 *
 */

int factorial(int n){
    if(n <= 1)
        return 1;
    else 
        return n * factorial(n - 1);
}

/* 
 * return the square root of a number.
 * this functions use the babylonian method
 *
 */

double v_sqrt(double n){
    double error = n * 10e-8;
    double s = n;
    while((s - n / s) > error) {
        s = (s + n / s) / 2;
    }
    return s;
}

/*
 * return the fsqrt, fast inverse sqrt
 * can be used to normalize a vector
 * this function was used in quake 
 */

float v_rsqrt(float n){
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = n * 0.5F;
    y = n;
    i = * (long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (float *) &i;
    y = y * (threehalfs - ( x2 * y * y));

    return y;
}

/*
 * test if the number is prime
 * returns 1 if it is and 0 if
 * is not
 */

int is_prime(long long int n){
    register int i;
    int root = sqrt(n);

    if(n == 2)
        return 1;

    if(n < 2 || !(n % 2))
        return 0;

    for(i = 3; i <= root; i+=2){
        if(!(n % i))
            return 0;
    }

    return 1;
}

/*============================================================
                                                  UTILS
==============================================================*/

/*
 * returns 0 if n is not a numberic digit
 * and 1 if it is
 *
 */

int is_digit(int n){
    if(n < '0' || n > '9')
        return 0;
    return 1;
}

/*
 * returns 0 if is not in ascii
 * and 1 if it is
 *
 */

int is_ascii(int n){
    if(0 > n || 127 > n)
        return 0;
    return n;
}

/*
 * and algorithm used to determine the points need for rasterizing
 * a circle. this algorithm is perfect to draw circle in some libraries
 * SDL, Opengl
 */

void midpoint_algorithm(int x_centre, int y_centre, int radius){
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - radius;

    while(x >= y){
        printf("(%d, %d)", x_centre + x, y_centre + y);
        printf("(%d, %d)", x_centre + y, y_centre + x);
        printf("(%d, %d)", x_centre - y, y_centre + x);
        printf("(%d, %d)", x_centre - x, y_centre + y);
        printf("(%d, %d)", x_centre - x, y_centre - y);
        printf("(%d, %d)", x_centre - y, y_centre - x);
        printf("(%d, %d)", x_centre + y, y_centre - x);
        printf("(%d, %d)", x_centre + x, y_centre - y);

        if(err <= 0){
            y++;
            err += dy;
            dy += 2;
        }

        if(err > 0){
            x--;
            dx += 2;
            err += (dx - radius);
        }
    }
}

