#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int x=0;x<n;x++)
    { 
        int r=x*x;
        if(r<=n) continue;
        else printf("%d\n", x-1);
            break;

    }
    return 0;
}