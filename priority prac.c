#include<stdio.h>
int main(){
    int n,wt[20],bt[20],tat[20],p[20];
    float atat=0,awt=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("Enter the brust time and priority \n");
    for(int i=0;i<n;i++){
        printf("process %d:",i+1);
        scanf("%d %d",&bt[i],&p[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i]<p[j]){
                int temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=0;
        for(int j=0;j<i;j++){
            wt[i] += bt[j];
        }
        awt += wt[i];
    }
    awt=awt/n;
    atat=awt;
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        atat += tat[i];
    }
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, bt[i], p[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f", atat);
    return 0;
}