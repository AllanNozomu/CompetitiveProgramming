#include <stdio.h>
 
int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    if ((n + m) % 2){
        printf("0\n");
    } else {
        printf("1\n");
    }
    
    return 0;
}