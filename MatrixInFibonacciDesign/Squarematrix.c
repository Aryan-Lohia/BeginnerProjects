//PROGRAM TO INPUT A SQUARE MATRIX AND PRINT IT IN FIBONACCI DESIGN
#include<stdio.h>
#include<stdlib.h>
#define sizealloc(a) calloc(a,sizeof(int))
#define print(a,j,k) printf("%d,", a[j][k]);

void main()
{
  int **matrix, order, i, j;

#if 1 //To input order and matrix via a file
  
  char s[10];
  FILE *ptr = NULL;
  ptr = fopen("square_matrix.txt", "r");

  //Reading Matrix Order from File
  fseek(ptr, 8, SEEK_SET);
  fscanf(ptr, "%s", s);
  order = atoi(s);
  printf("\n\nOrder of matrix : %d\n\n", order);

  //Allocating memory for matrix array
  matrix = sizealloc(order);
  for (i = 0; i < order;i++)
    matrix[i] = sizealloc(order);

 
  //Reading Matrix from File
  for (i = 0; i < order;i++)
  { 
    for (j = 0; j < order;j++)
      {fscanf(ptr,"%s", s);
        matrix[i][j] = atoi(s);
      }
    
  }

  fclose(ptr);

#else //To input order and matrix manually
  
  printf("\nEnter order of Square Matrix\n");
  scanf("%d", &order);
  printf("\n\nOrder of matrix : %d\n\n", order);

  //Allocating memory for matrix array
  matrix = sizealloc(order);
  for (i = 0; i < order;i++)
    matrix[i] = sizealloc(order);

  //Inputting Matrix
  printf("\nEnter values of Square Matrix\n");
  for (i = 0; i < order;i++)
  {  printf("Row %d\n",i+1);
    for (j = 0; j < order;j++)
      scanf("%d",a[i][j]);
  }

#endif

  printf("The Matrix you have entered is:\n\n");
  for (i = 0; i < order;i++)
  {
    for (j = 0; j < order;j++)
      {
        
        printf("%d\t",matrix[i][j]);
      }
      printf("\n");
  }
  printf("\n");

  int b = order - 1;
  printf("The Final output is:\n\n");
  for (i = 0; i <= (order / 2);i++)
  {
    int f = 0,t=b;
    j = i;
    do
    {
     if(j==b)
      {
        for (int k = b; k >=i ;k--)
          print(matrix,j,k);
        f = 1;
        t = i;
      }
     else if(j==i)
      { 
	  for (int k = i; k <=b;k++)
          print(matrix,j,k);
	}
     else
         print(matrix,j,t);

     (f == 0) ? j++ : j--;
    } while (j > i&&i<order/2);
		
		b--;
    
  }
  free(matrix);
} 
