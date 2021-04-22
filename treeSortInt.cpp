
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode
{
    struct treeNode* left;
    int data;
    struct treeNode* right;
};

void insertNode(treeNode** treePtr, int value);
void inOrder(treeNode* treePtr);
void preOrder(treeNode* treePtr);
void postOrder(treeNode* treePtr);

int main()
{
    char fileName[50];
    treeNode* root = NULL;

    printf("\nEnter filename to sort: ");
    scanf("%s",fileName);

    FILE* fptr = fopen(fileName,"r");

    int data;

    if(fptr == NULL)
    {
        printf("Error, can't open the input file %s \n", fileName);
    }
    else
    {
        printf( "The numbers being placed in the tree are:\n" ); 
        while(!feof(fptr))
        {
            fscanf(fptr,"%d",&data);
            insertNode(&root,data);
            printf("%3d",data);
        }
    }

    //traverse the tree preorder
    printf( "\n\nThe preOrder traversal is:\n" );
    preOrder(root);

    //traverse the tree in order
    printf( "\n\nThe inOrder traversal is:\n" );
    inOrder(root);

    //traverse the tree post order
    printf( "\n\nThe postOrder traversal is:\n" );
    postOrder(root);

    return 0;
}


void insertNode(treeNode** treePtr,int value)
{
    if(*treePtr == NULL)
    {
        *treePtr = (treeNode*) malloc(sizeof(treeNode));

        if( *treePtr != NULL)
        {
            (*treePtr)->data = value;
            (*treePtr)->left = NULL;
            (*treePtr)->right = NULL;
        }
        else
        {
            printf( "%d not inserted. No memory available.\n", value );
        }
    }
    else
    {
        if(value < (*treePtr)->data)
        {
            insertNode(&((*treePtr)->left),value);
        }
        else if ( value > (*treePtr)->data)
        {
            insertNode(&((*treePtr)->right),value);
        }
        else
        {
            printf("  dup  "); //duplicated data
        }
    }

}


void preOrder(treeNode* treePtr)
{
    if( treePtr != NULL)
    {
        printf("%3d",treePtr->data);
        preOrder(treePtr->left);
        preOrder(treePtr->right);
    }
}


void inOrder(treeNode* treePtr)
{
    if(treePtr != NULL)
    {
        inOrder(treePtr->left);
        printf("%3d",treePtr->data);
        inOrder(treePtr->right);
    }
}

void postOrder(treeNode* treePtr)
{
    if(treePtr != NULL)
    {
        postOrder(treePtr->left);
        postOrder(treePtr->right);
        printf("%3d",treePtr->data);
    }
}