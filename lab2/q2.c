#include<stdio.h>

int max(int a,int b){
    if(a>b){
        return a;
    }

    else{
    return b;}
}


int min(int a,int b){
    if(a>b){
        return b;
    }

    else{
    return a;}
}


int middleSchool(int a,int b){

    int arr_a[100];
    int arr_b[100];

    
    
    int i=2;
    int count_a=0;
    int count_b=0;
    while(a!=1){
        if(a%i==0){
            
            printf("%d ",i);
            arr_a[count_a]=i;
            count_a++;
            
            a=a/i;
        }
        else{
        i++;
        for(int k=2;k<i;k++){
            if(i%k==0){
                i++;
            }
        }
        
        }
        }

        printf("\n");

        i=2;

        while(b!=1){
        if(b%i==0){
            
            printf("%d ",i);
            arr_b[count_b]=i;
            count_b++;
            
            b=b/i;
        }
        else{
        i++;
        for(int k=2;k<i;k++){
            if(i%k==0){
                i++;
            }
        }
        
        }
    }

    printf("\n");

    int gcd=1;
    int arr_c[100];
    int k=0;
    for(i=0;i<count_b;i++){
        for(int j=0;j<count_a;j++){
            if(arr_a[j]==arr_b[i]){
                arr_c[k]=arr_a[j];
                k++;
                break;
            }
        }
    }

    for(i=0;i<k;i++){
        printf("%d ",arr_c[i]);
        gcd=gcd*arr_c[i];
    }
    printf("\n");


    return gcd;


}




int main(){
    printf("%d",middleSchool(48,36));
    printf("\n");
}
