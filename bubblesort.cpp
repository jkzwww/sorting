
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void bubbleSort(int row[], int size, int direction);
bool ascending(int left, int right);
bool descending(int left, int right);
void swap(int* left, int* right);

int main()
{
    srand(time(NULL));

    const int SIZE = 10;

    int vector1[SIZE], vector2[SIZE];
    char inputString1[100];

    for(int i = 0; i < SIZE ; i++)
    {
        vector1[i] = rand()%9;
        vector2[i] = rand()%9;
    }

    printf("Before sorting: \n");


    for(int i = 0; i < SIZE ; i++)
    {
       printf("\t %d \t %d \n",vector1[i],vector2[i]);
    }

    bubbleSort(vector1,SIZE,0);
    bubbleSort(vector2,SIZE,0);

    printf("After sorting: (ascending) \n");

    for(int i = 0; i < SIZE ; i++)
    {
       printf("\t %d \t %d \n",vector1[i],vector2[i]);
    }

    bubbleSort(vector1,SIZE,1);
    bubbleSort(vector2,SIZE,1);

    printf("After sorting: (descending) \n");
    
    for(int i = 0; i < SIZE ; i++)
    {
       printf("\t %d \t %d \n",vector1[i],vector2[i]);
    }

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Enter string to sort: ");
    scanf("%s",inputString1);

    printf("Before sorting: %s \n",inputString1);

    int n = strlen(inputString1);

    for (int i = 0; i < n-1; i++) 
    {
      for (int j = i+1; j < n; j++) 
      {
         if (inputString1[i] > inputString1[j]) {
            char temp = inputString1[i];
            inputString1[i] = inputString1[j];
            inputString1[j] = temp;
         }
      }
    }

    printf("After sorting: %s \n",inputString1);
    

    return 0;
}


void bubbleSort(int row[], int size, int direction)
{
    //array of pointer to function
    bool(*asc_dec[2])(int left,int right) = {ascending,descending};

    //bubble sort , loop size-1 time
    //loop each element through
    for (int sortIndex = 0; sortIndex < size-1 ; sortIndex++)
    {
        //loop current sort index through current array
        for(int comparePass = 0; comparePass < size-1; comparePass++)
        {
            //decide which comparison func to use
            if(asc_dec[direction](row[comparePass],row[comparePass+1]))
            {
                swap(&row[comparePass],&row[comparePass+1]);
            }
    
        }
    }
}

//true if need to swap
bool ascending(int left, int right)
{
    return left > right;
}

bool descending(int left, int right)
{
    return left < right;
}

void swap(int* left, int* right)
{
    int temp;
    temp = *left;
    *left = *right;
    *right = temp;
}