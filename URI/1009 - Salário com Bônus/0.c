#include <stdio.h>
 
int main() {
 
    char n[50];
    double s, v;
    scanf("%s %lf %lf", n, &s, &v);
    printf("TOTAL = R$ %.2lf\n", s + v * 0.15);
 
    return 0;
}