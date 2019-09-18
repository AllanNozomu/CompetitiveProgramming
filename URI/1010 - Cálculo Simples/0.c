#include <stdio.h>
 
int main() {
    int n1, n2, lixo;
    double v1, v2;
    scanf("%d %d %lf %d %d %lf", &lixo, &n1, &v1, &lixo, &n2, &v2);
    printf("VALOR A PAGAR: R$ %.2lf\n", n1*v1 + n2*v2);
    return 0;
}