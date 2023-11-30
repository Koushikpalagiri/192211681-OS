#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,rq[100],head,seek=0;
    printf("Enter the number of requests:");
    scanf("%d",&n);
    printf("Enter the requests sequences:");
    for(int i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter the head value");
    scanf("%d",&head);
    for(int i=0;i<n;i++){
        seek+=abs(rq[i]-head);
        head=rq[i];
    }
    printf("seek time = %d",seek);
    return 0;
}