/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */
void partprint(int *arr,int ind)
{
int i;
  printf("= %d",arr[0]);
  for(i = 1;i<ind;i++)
    {
       printf(" + %d",arr[i]);
    }
  printf("\n");
}
void all(int n,int * arr,int ind)
{
  int val;
  if(n == 0)
  {
    partprint(arr,ind);
  return; 
  }
for(val=1;val<=n;val++)
{

    arr[ind]=val;
    all(n-val,arr,ind+1);
}

}
void partitionAll(int value)
{
  printf("partitionAll %d\n", value);
  
  int * arr = malloc(value * sizeof(int));
  int ind = 0;
all(value,arr,ind);
free(arr);
}

/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void Increase(int n,int * arr,int ind)
{
  int val;
if(n == 0)
  {
  partprint(arr,ind);
  return;
  }

for(val=1;val<=n;val++)
  {
    arr[ind]=val;
    if(arr[ind]>arr[ind-1])
      {
    Increase(n-val,arr,ind+1);
      }
  }
}

void partitionIncreasing(int value)
{

   printf("partitionIncreasing %d\n", value);
  int * arr = malloc(value * sizeof(int));
  int ind = 0;
  Increase(value,arr,ind);
  free(arr);
  
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void Decrease(int n,int * arr,int ind)
{
  int val;
if(n == 0)
  {
  partprint(arr,ind);
  return;
  }

for(val=1;val<=n;val++)
  {
   arr[ind]=val;
   if (ind > 0 &&arr[ind-1]>arr[ind])
      {
    Decrease(n-val,arr,ind+1);
      }
if(ind ==0)
{
Decrease(n-val,arr,ind+1);
}
  }
}
void partitionDecreasing(int value)
{
  printf("partitionDecreasing %d\n", value);
  int * arr = malloc(value * sizeof(int));
  int ind = 0;
  Decrease(value,arr,ind);
  free(arr);
  

}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void Odd(int n,int * arr,int ind)
{
 int val;
 if(n == 0)
  {
  partprint(arr,ind);
  return;
  }

for(val=1;val<=n;val++)
  {
    arr[ind]=val;
   if(arr[ind]%2==1)
     {
    Odd(n-val,arr,ind+1);
     }
  }
}

void partitionOdd(int value)
{
 printf("partitionOdd %d\n",value);
 int * arr = malloc(value * sizeof(int));
 int ind = 0;
 Odd(value,arr,ind);
 free(arr);
}
/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */
void Even(int n,int * arr,int ind)
{
  int val;
  if(n == 0)
  {
  partprint(arr,ind);
  return;
  }

  for(val=1;val<=n;val++)
  {
    arr[ind]=val;
    if(arr[ind]%2==0)
      {
    Even(n-val,arr,ind+1);
      }
  }
}

void partitionEven(int value)
{
  printf("partitionEven %d\n", value);
  int * arr = malloc(value * sizeof(int));
  int ind = 0;
  Even(value,arr,ind);
  free(arr);
}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void OddEven(int n,int * arr,int ind,int max)
{
  int val;
  if(n == 0)
  {
  partprint(arr,ind);
  return;
  }

  for(val=1;val<=n;val++)
  {
if(val == max&&val%2==0)
{return;}
  arr[ind]=val;
if(arr[0]%2 == 1)
{
    if(ind > 0 && ((arr[ind]+arr[ind-1])%2 == 1))
      { 
    OddEven(n-val,arr,ind+1,max);
      }
}
    if(ind == 0)
     OddEven(n-val,arr,ind+1,max);
  }
}


void partitionOddAndEven(int value)
{

  printf("partitionOddAndEven %d\n", value);
  int * arr = malloc(value * sizeof(int));
  int ind = 0;
  OddEven(value,arr,ind,value);
  free(arr);
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

int isprime(int *arr,int ind)
{
 int i;
if (arr[ind]==1)
{
return 0;
}
if(arr[ind]==2)
{
return 1;
}
  for(i = 2; i <= arr[ind];i++)
  {
   if ((arr[ind] % i ==0) && (i != arr[ind]))
    {
      return 0;
    }
   
  }
return 1;
}
void Prime(int n,int * arr,int ind)
{
  int val;
  if(n == 0)
  {
  partprint(arr,ind);
  return;
  }

  for(val=1;val<=n;val++)
  {
    arr[ind]=val;
    if(isprime(arr,ind))
      {
       Prime(n-val,arr,ind+1);
      }
  }
}

void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);
  int * arr = malloc(value * sizeof(int));
  int ind = 0;
  Prime(value,arr,ind);
  free(arr);
}
