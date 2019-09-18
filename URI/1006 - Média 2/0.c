#include <stdio.h>
 
int main() {
 
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("MEDIA = %.1lf\n", (a/5 + b*0.3 + c/2));
 
    return 0;
}