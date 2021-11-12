//PROGRAM TO INPUT A SQUARE MATRIX AND PRINT IT IN FIBONACCI DESIGN
#include<stdio.h>
#include<stdlib.h>
#define mem(a) calloc(a,sizeof(int))
#define print(a,j,k) printf("%d,", a[j][k]);

void main()
{
  int **a, n, i, j;

#if 1 //To input order and matrix via a file
  
  char s[10];
  FILE *ptr = NULL;
  ptr = fopen("square_matrix.txt", "r");

  //Reading Matrix Order from File
  fseek(ptr, 8, SEEK_SET);
  fscanf(ptr, "%s", s);
  n = atoi(s);
  printf("\n\nOrder of matrix : %d\n\n", n);

  //Allocating memory for matrix array
  a = mem(n);
  for (i = 0; i < n;i++)
    a[i] = mem(n);

 
  //Reading Matrix from File
  for (i = 0; i < n;i++)
  { 
    for (j = 0; j < n;j++)
      {fscanf(ptr,"%s", s);
        a[i][j] = atoi(s);
      }
    
  }

  fclose(ptr);

#else //To input order and matrix manually
  
  printf("\nEnter order of Square Matrix\n");
  scanf("%d", &n);
  printf("\n\nOrder of matrix : %d\n\n", n);

  //Allocating memory for matrix array
  a = mem(n);
  for (i = 0; i < n;i++)
    a[i] = mem(n);

  //Inputting Matrix
  printf("\nEnter values of Square Matrix\n");
  for (i = 0; i < n;i++)
  {  printf("Row %d\n",i+1);
    for (j = 0; j < n;j++)
      scanf("%d",a[i][j]);
  }

#endif

  printf("The Matrix you have entered is:\n\n");
  for (i = 0; i < n;i++)
  {
    for (j = 0; j < n;j++)
      {
        
        printf("%d\t",a[i][j]);
      }
      printf("\n");
  }
  printf("\n");

  int b = n - 1;
  printf("The Final output is:\n\n");
  for (i = 0; i <= (n / 2);i++)
  {
    int f = 0,t=b;
    j = i;
    do
    {
     if(j==b)
      {
        for (int k = b; k >=i ;k--)
          print(a,j,k);
        f = 1;
        t = i;
      }
     else if(j==i)
      { 
				for (int k = i; k <=b;k++)
          print(a,j,k);
			}
     else
         print(a,j,t);

     (f == 0) ? j++ : j--;
    } while (j > i&&i<n/2);
		
		b--;
    
  }
  
} 
