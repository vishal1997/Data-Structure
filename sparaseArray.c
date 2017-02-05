#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    scanf("%d",&n);
    char str[n][21];
    for(int i=0;i<n;i++) {
        scanf(" %[^\n]s",str[i]);
    }
    scanf("%d",&q);
    char qr[q][21];
    for(int i=0;i<q;i++) {
        scanf(" %[^\n]s",qr[i]);
    }
    /*for(int i=0;i<n;i++) {
        printf("\n%s\n",str[i]);
    }
    for(int i=0;i<q;i++)
        printf("\n%s\n",qr[i]);*/
    for(int i=0;i<q;i++) {
        int count=0;
        for(int j=0;j<n;j++) {
            if(strlen(qr[i])==strlen(str[j])) {
                if(!strcmp(qr[i],str[j]))
                    count++;
            }

        }
        printf("%d\n",count);
    }
    return 0;
}

