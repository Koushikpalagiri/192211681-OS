#include<stdio.h>
int main(){
    int n,wt[20],bt[20],at[20],tat[20],ct[20],temp;
    float atat=0,awt=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("Enter arrivel time and brust time \n");
    for(int i=0;i<n;i++){
        printf("process %d:",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=0;
    for(int i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        atat+=tat[i];
        awt+=wt[i];
    }
    awt/=n;
    atat/=n;
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f", atat);

    return 0;
}