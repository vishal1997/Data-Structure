#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int d;
    scanf("%d %d",&n,&d);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int temp[n];
    int i=0;
    for(;i<d;i++)
        {
        temp[i]=arr[i];
    }
    for(;i<n;i++)
        {
        arr[i-d]=arr[i];
    }
    int j=0;
    for(i=n-d;i<n;i++)
        {
        arr[i]=temp[j];
        j++;
    }
    for(int i=0;i<n;i++)
        {
        printf("%d ",arr[i]);
    }
    return 0;
}
