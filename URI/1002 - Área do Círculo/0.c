#include <stdio.h>
#define PI 3.14159
 
int main() {
    double r;
    scanf("%lf", &r);
    printf("A=%.4lf\n", r*r*PI);
    
    return 0;
}