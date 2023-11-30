#include<stdio.h>
int main(){
    int n_block,n_process,block[100],process[100],idx,allocation[100];
    printf("Enter the number memory blocks:");
    scanf("%d",&n_block);
    printf("Enter the memory sizes:");
    for(int i=0;i<n_block;i++){
        scanf("%d",&block[i]);
    }
    printf("Enter the number process:");
    scanf("%d",&n_process);
    printf("Enter the process:");
    for(int i=0;i<n_process;i++){
        scanf("%d",&process[i]);
    }
    for(int i=0;i<n_process;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n_process;i++){
        idx=-1;
        for(int j=0;j<n_block;j++){
            if(block[j] >= process[i]){
                if(idx==-1){
                    idx=j;
                }
                else if(block[j] >= block[idx]){
                    idx=j;
                }
            }
        }
        if(idx != -1){
            allocation[i]=idx;
            block[idx]-=process[i];
        }
    }
printf("\n process \t process size \t block no \n");
for(int i=0;i<n_process;i++){
    printf("%d \t \t %d\t\t",i+1,process[i]);
    if(allocation[i]!=-1){
        printf("%d \n",allocation[i]);
    }
    else{
        printf("not allocated \n");
    }
}

return 0;
}