#include<stdio.h>

int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }

}


int findGCD(int a, int b){
    int c=min(a,b);

    while(1){
        if(a%c==0 && b%c==0){
            return c;
        }

        else{
            c=c-1;
        }
        
    }

    
}

int main(){
int m,n;
printf("Enter the two numbers whose GCD has to be calculated");
scanf("%d", &m);
scanf("%d", &n);
printf("GCD of two numbers using consecutive integer checking is %d",findGCD(m,n));



    return 0;
}

