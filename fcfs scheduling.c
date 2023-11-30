#include<stdio.h>
int main(){
    int n,wt[20],bt[20],tat[20];
    float atat=0,awt=0;
    printf("Enter number of process \n");
    scanf("%d",&n);
    printf("Enter the burst time \n");
    for(int i=0;i<n;i++){
        printf("process %d:",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=0;
        for(int j=0;j<i;j++){
            wt[i]+=bt[j];
        }
        awt+=wt[i];
    }
    awt=awt/n;
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        atat+=tat[i];
    }
    atat=atat/n;
     printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f", atat);

    return 0;
    
}
