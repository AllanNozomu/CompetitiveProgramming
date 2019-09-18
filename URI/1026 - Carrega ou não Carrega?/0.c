#include <stdio.h>
 
int main() {
    long long unsigned int a, b;
    while(scanf("%lld %lld", &a, &b) != EOF) {
        printf("%lld\n", a ^ b);
    }
 
    return 0;
}