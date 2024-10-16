#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *iarr_to_str(char *buf, int *iarr, int ialen) {
    bool first = true;
    char ibuf[16];
    strcpy(buf, "[");
    for(int i = 0; i < ialen; i++) {
        if(first)
            first = false;
        else
            strcat(buf, ", ");
        sprintf(ibuf, "%d", iarr[i]);
        strcat(buf, ibuf);
    }
    strcat(buf, "]");
    return buf;
}
int isum(int *iarr, int ialen) {
    int sum = 0;
    for(int i = 0; i < ialen; i++) 
        sum += iarr[i];
    return sum;
}
int *iaccumsum(int *idest, int *iarr, int ialen) {
    int sum = 0;
    for(int i = 0; i < ialen; i++) {
        sum += iarr[i];
        idest[i] = sum;
    }
    return idest;
}
int ialtdiff(int *iarr, int ialen) {
    int diff = 0;
    int sign = 1;
    for(int i = 0; i < ialen; i++) {
        diff +=  sign*iarr[i];
        sign = - sign;
    }
    return diff;
}
int iprod(int *iarr, int ialen) {
    int prod = 1;
    for(int i = 0; i < ialen; i++) 
        prod *= iarr[i];
    return prod;
}
int *iaccumprod(int *idest, int *iarr, int ialen) {
    int prod = 1;
    for(int i = 0; i < ialen; i++) {
        prod *= iarr[i];
        idest[i] = prod;
    }
    return idest;
}
int main() {
    char buf[128];
    int primes[] = {2, 3, 5, 7, 11, 13, 15};
    int odd[] = {1, 3, 5, 7, 9, 11, 13};
    int accum[7];
    printf("array: %s\n", iarr_to_str(buf, primes, 7));
    printf("  sum: %d\n", isum(primes, 7));
    printf("  accum sum: %s\n", iarr_to_str(buf, iaccumsum(accum, primes, 7), 7));
    printf("  prod: %d\n", iprod(primes, 7));
    printf("  accum prod: %s\n", iarr_to_str(buf, iaccumprod(accum, primes, 7), 7));
    printf("array: %s\n", iarr_to_str(buf, odd, 7));
    printf("  sum: %d\n", isum(odd, 7));
    printf("  accum sum: %s\n", iarr_to_str(buf, iaccumsum(accum, odd, 7), 7));
    printf("  prod: %d\n", iprod(odd, 7));
    printf("  accum prod: %s\n", iarr_to_str(buf, iaccumprod(accum, odd, 7), 7));
    return 0;
}