#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[],int len){

    int temp;
    int opcount=0;

    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            
            if(arr[j]>arr[j+1]){
                opcount++;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("opcount = %d",opcount);
}


int main(){
        int arr[100];
        printf("enter number of elements ");
        int len;
        
        scanf("%d",&len);

        
        for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }

        bubbleSort(arr,len);



        return 0;
}
