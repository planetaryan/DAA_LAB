#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));

    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return node;
}

Node* insertKey(Node* root,int key){
    if(root==NULL){
        createNode(key);
        
    }

    else if(root->data==key){
        printf("key found\n");
        return root;
    }

    else if(root->data>key){
        root->left=insertKey(root->left,key);
        return root;
    }

    else if(root->data<key){
        root->right=insertKey(root->right,key);
        return root;
    }

    


}

void inOrder(Node* root){
    if(root!=NULL){

        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(Node* root){
    if(root!=NULL){
        printf("%d ",root->data);

        preOrder(root->left);
        
        preOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root!=NULL){

        postOrder(root->left);
       
        postOrder(root->right);

        printf("%d ",root->data);
    }
}

int main(){
    int key;
    Node* root=NULL;


    while(1){
        printf("enter element ");
        scanf("%d",&key);

        if(key==-1){
            break;
        }

        root=insertKey(root,key);
    }

    printf("Inorder: ");
    inOrder(root);
    
    printf("\n");
    printf("Preorder: ");
    preOrder(root);
    printf("\n");
    printf("Postorder: ");
    postOrder(root);

return 0;
}

