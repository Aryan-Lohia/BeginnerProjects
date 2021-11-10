#include<stdio.h>
#include<stdlib.h>

#define memory(a) malloc(sizeof(int)*a)



void print(int r, int c, int **m)
{
 for (int i = 0; i < r;i++)
            {
                for (int j = 0; j < c;j++)
                 printf("%d\t",m[i][j]);
                printf("\n");
            }
}


void input(int r, int c, int **m,int p)
{
    char e;
    n: printf("Enter elements for Matrix %d\n",p);
    for (int i = 0; i < r;i++)
    {
     printf("\nRow %d\n", i + 1);
     printf("Enter %d elements.\n", c);
     for (int j = 0; j < c; j++)
        {
         scanf("%d", &m[i][j]);
         getchar();
        }
    }
    printf("\nMatrix %d is\n",p);
         print(r, c, m);
          printf("To Reenter Matrix %d, press 1. \nTo continue, press any other key.\n",p);
          e = getchar();
          if(e=='1')
          {
              
              printf("Re");
              goto n;
          }
}

int main()
{
    printf("\n\nPROGRAM FOR MULTIPLICATION OF 2 MATRICES\n\n");
    int  r1, r2, c1, c2;
e:
    //INPUTTING NUMBER OF ROWS AND COLUMNS
    printf("Enter number of Rows and Columns in the 1st Matrix\n");
    printf("Rows:");
    scanf("%d", &r1);
    printf("Columns:");
    scanf("%d", &c1);
    printf("\nEnter number of Rows and Columns in the 2nd Matrix\n");
    printf("Rows:");
    scanf("%d", &r2);
    printf("Columns:");
    scanf("%d", &c2);
    printf("\n");
    if(c1!=r2)
    {
        printf("\nYour matrices cannot be multiplied.\n Please enter valid rows and columns\n(For valid input, Columns of matrix 1 must be equal to Rows of matrix 2)\n\n");
        goto e;
    }
    else
    {
        int i, j;
    
        int **a, **b, **c;
        //ALLOCATING SIZE FOR MATRICES
        a = memory(r1);

        for (i = 0; i <= r1;i++)
            a[i] = memory(c1);
        
         b = memory(r2);

         for (i = 0; i <= r2;i++)
             b[i] = memory(c2);
        
         c = memory(r1);

        for ( i = 0; i <= r1;i++)
            c[i] = memory(c2);

        
     //INPUTTING MATRICES
       
        input(r1, c1, a,1);
        input(r2, c2, b,2);
          
          //MULTIPLYING BOTH MATRICES
          for (i = 0; i < r1; i++)
          {
              for (j = 0; j < c2; j++)
              {
                  int s = 0;
                  for (int k = 0; k < c1; k++)
                      s = s + (a[i][k] * b[k][j]);
                  c[i][j] = s;
              }
            }


     //PRINTING FINAL ANSWER
            printf("\nYour First Matrix is:\n");
            print(r1, c1, a);
            printf("\nYour Second Matrix is:\n");
            print(r2, c2, b);
            printf("\nYour Final Output Matrix is:\n");
            print(r1, c2, c);


            free(a);
            free(b);
            free(c);
        }
    }   
   

    

