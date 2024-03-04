#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* createNode(int value){
    Node* node=(Node*)malloc(sizeof(Node));
    node->value=value;
    node->next=NULL;

    return node;
}

Node* insert(Node* head,int value,int key)
{
    if(head==NULL){
        return createNode(value);
    }
    while(head!=NULL){
        head=head->next;
    }

    

}

int main(){

    char* table;
    char text[100];
    int table_size,a,opcount;
    
    
    printf("enter table size ");
    scanf("%d",&table_size);

    table=(char*)calloc(table_size,sizeof(char));

    printf("enter string ");
    scanf("%s",text);

    for(int i=0;i<strlen(text);i++){
        table[text[i]-'a']++;
    }

    for(int j=0;j<table_size;j++){
        if(table[j]!=0){
            a=j+'a';
        printf("%c : %d\n",a,table[a-'a']);
    }
    }

    


return 0;





   

    
}