#include "libv.h"

/*
 * allocates memory and returns a void pointer
 * returns NULL if cannot allocate memory
 *
 */

void *vmalloc(unsigned int len){

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

void *vmemcpy(void *dest, const void *src, size_t len){

    void *ptr;
    if(dest == NULL && src == NULL)
        return NULL;
    ptr = dest;
    while(len-- > 0)
       *(char *)dest++ = *(char *)src++;
    return ptr;

}

/* 
 * returns int - the difference between the characters
 * in ASCII table, 0 if there's no difference
 *
 */

int vmemcpm(const void *x, const void *y, size_t len){
    
    while(len-- > 0) {
        if(*(unsigned char *)x != *(unsigned char *)y)
            return (*(unsigned char *) x - *(unsigned char *)y);
        x++;
        y++;
    }

    return (0);

}



/*
 * gives the length of a string
 * returns 0 if has no content
 *
 */


int vstrlen(const char *str){
    
    int i;
    i = 0;
    while(str[i])
        i++;
    return i;

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

int to_upper(int c){
    if(c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}


int gcd(int a, int b){
    
    if(!b)
        return a;
    else 
        return gcd(b, a%b);

}

int lcm(int a, int b){
    
    int x;
    if(!b)
        return a;
    else 
        x = (a * b) / (gcd(a, b));
    
    return x;

}

int factorial(int n){
    if(n <= 1)
        return 1;
    else 
        return n * factorial(n - 1);
}

double v_sqrt(double n){
    double error = n * 10e-8;
    double s = n;
    while((s - n / s) > error) {
        s = (s + n / s) / 2;
    }
    return s;
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

