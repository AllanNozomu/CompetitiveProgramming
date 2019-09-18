#include <stdio.h>
 
int main() {
 
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("MEDIA = %.5lf\n", (a*7/2+b*15/2)/11);
 
    return 0;
}