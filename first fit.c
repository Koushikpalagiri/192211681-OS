#include<stdio.h>
int main(){
    int block[100],allocation[100],process[100];
    int n_block,n_process;
    printf("Enter the number of blocks:");
    scanf("%d",&n_block);
    printf("Enter the size of blocks:");
    for(int i=0;i<n_block;i++){
        scanf("%d",&block[i]);
    }
    printf("Enter the number of process:");
    scanf("%d",&n_process);
    printf("enter the size of process:");
    for(int i=0;i<n_process;i++){
        scanf("%d",&process[i]);
    }
    for(int i=0;i<n_process;i++){
        allocation[i]=-1;
        for(int j=0;j<n_block;j++){
            if(block[j] >= process[i]){
                allocation[i]=j;
                block[j] -= process[i];
                break;
            }
        }
 
    }
    printf("\nprocess no \t process size \t block no\n");
    for(int i=0;i<n_process;i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i] != -1){
            printf("%d\n",allocation[i]);
        }else{
            printf("not allocated \n");
        }
    }
} 