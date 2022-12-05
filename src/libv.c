#include "libv.h"

/*============================================================
                                                  MEMORY
==============================================================*/

/*
 * Allocates memory and returns a void pointer
 * returns NULL if cannot allocate memory
 */

void *v_malloc(unsigned int len){
    int *ptr;
    ptr = malloc(len);
    if(ptr == NULL)
        fprintf(stderr, "Fail to allocate memory");
    return ptr;
}

/*
 * Copy the values of num bytes from the location pointed
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
 * Returns the difference between    
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
 * Deallocates memory previously
 * allocated in memory
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
 * Gives the length of a string
 * returns 0 if has no content
 *
 */

int v_strlen(char str[]){
    int i;
    i = 0;
    while(str[i])
        i++;
    return i;
}

/*
 * Returns str reversed and if 
 * str is not defined, returns
 * the same str
 */

char *v_strrev(char str[]){
    char *p1, *p2;

    if(!str || !*str)
        return str;
    for(p1 = str, p2 = str + v_strlen(str) - 1; p2 > p1; ++p1, --p2){
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

/*
 * If c is uppercase, returns its lower
 * equivalent
 */

int to_lower(int c){
    if(c >= 'A' && c <= 'Z')
        return (c + 32);
    return c;
}

/*
 * If c is lowercase, returns its upper
 * equivalent
 */ 

int to_upper(int c){
    if(c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}

/*
 * Prints on the screen
 * returns 0 if has no character
 */

int v_print(char str[]){
    int i;
    i = 0;
    while(str[i] != '\0')
        putchar(str[i++]);

    return i;
}

/*============================================================
                                                  MATH
==============================================================*/

/*
 * Returns the Greatest commom divisor
 * (gcd). if b is not defined, returns a
 */

int gcd(int a, int b){
    if(!b)
        return a;
    else 
        return gcd(b, a%b);
}

/* 
 * Returns the Least commom multiple
 * and if b is not defined, returns a
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
 * Returns the factorial of a number
 * and if n is 0 or negative, returns 1
 */

int factorial(int n){
    if(n > 0)
        return n * factorial(n - 1);
    return 1;
}

/* 
 * Return the square root of a number.
 * this functions use the babylonian method
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
 * Return the fsqrt, Fast Inverse Sqrt
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
 * Returns 0 if is not prime
 * and 1 if is it
 */

int is_prime(long long int n){
    register int i;
    int root = v_sqrt(n);

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
 * Returns 0 if is not a numeric digit 
 * and 1 if it is 
 */

int is_digit(int n){
    if(n < '0' || n > '9')
        return (0);
    return (1);
}

/*
 * Returns 0 if is not in ascii
 * and 1 if it is
 */

int is_ascii(int n){
    if(0 > n || 127 > n)
        return 0;
    return n;
}

/*
 * Returns 0 if is not alphabethic
 * and 1 if it is
 */

int is_alpha(int n){
    if(('A' > n || n > 'Z') && (n < 'a' || n > 'z'))
        return 0;
    return 1;
}

/*
 * Returns 0 if is not alphanumeric
 * and 1 if it is
 */ 

int is_alnum(int n){
    if((!is_digit(n)) && (!is_alpha(n)))
        return 0;
    return 1;
}

/*
 * An algorithm used to determine the points need for rasterizing
 * a circle. this algorithm is perfect to draw circle in some libraries
 * like SDL, Opengl, etc...
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

char *random_ip(void) {
    char *ip = NULL;
    int r1, r2, r3, r4;
    r1 = 1+(int) (255.0*rand()/(RAND_MAX+1.0));
    r2 = 1+(int) (255.0*rand()/(RAND_MAX+1.0));
    r3 = 1+(int) (255.0*rand()/(RAND_MAX+1.0));
    r4 = 1+(int) (255.0*rand()/(RAND_MAX+1.0));

    ip = v_malloc(16*sizeof(char));
    sprintf(ip, "%d.%d.%d.%d", r1, r2, r3, r4);
    return ip;
}


/*============================================================
                                                  FILES
==============================================================*/

/*
 * Returns 0 if the file doesnt exist
 * and 1 if exist and was writen
 */

int write_file(char *file, char *str) {
    FILE *opt_file;
    opt_file = fopen(file, "a");
    if(!opt_file) {
        fprintf(stderr, "Error in write_file: %s\n", file);
        return 0;
    }
    fprintf(stdout, "%s\n", str);
    fclose(opt_file);
    return 1;
}
