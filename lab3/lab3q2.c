#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringMatch(char text[],char pattern[]){
    int count=0;
    int opcount=0;
    int temp;
    
    for(int i=0;i<strlen(text);i++){
        
        temp=i;
        for(int j=0;j<strlen(pattern);j++){
            opcount++;
            if(count==strlen(pattern)){
                    break;
                }
            else if(text[i]==pattern[j]){
                count++;
                i++;
                // printf("Count =%d",count);
                
            }
            else{
                count=0;
                i=temp;
                break;
            }
        }
    }
    printf("opcount =%d",opcount);
    
    if(count==strlen(pattern)){
        printf("found");
    }
    else{
        printf("not found ");
       
    }
   
}

int main(){
    char text[100];
    char pattern[100];
    
    

    printf("enter text ");
    fflush(stdin);
    scanf("%s",text);
    fflush(stdin);

    printf("enter pattern ");
    scanf("%s",pattern);
    fflush(stdin);
    
    stringMatch(text,pattern);
    



    return 0;


}
