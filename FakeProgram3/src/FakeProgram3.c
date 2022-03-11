#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void combine_sort(int *,int,int);
void combine(int *,int,int,int);
int main()
{
   int *arr, *ans, index = 0, temp;
    arr = (int *)malloc(100000 * sizeof(int));
   ans = (int *)malloc(100000 * sizeof(int));
   while(1)
   {
       scanf("%d", &temp);
       if(temp == -1)
       {
         break;
       }

       arr[index++] = temp;
   }

   combine_sort(arr, 0, index - 1);
   int i, ind = 0;
   i = 0;
   while( i < index )
   {
       ans[ind++] = arr[i];
       int x = arr[i];
       i++;

       while( i < index && x == arr[i])
       {
         i++;
       }
   }
   printf("\n\n");
   for( i = 0 ; i < ind ; i++ )
   {
     printf("%d\n", ans[i]);
   }
}
void combine_sort(int *arr,int p,int r)
{
   if(p<r)
   {
       int q=(p+r)/2;
       combine_sort(arr,p,q);
       combine_sort(arr,q+1,r);
       combine(arr,p,q,r);
   }
}
void combine(int *arr,int p,int q,int r)
{
   int n1=q-p+1;
   int n2=r-q;
   int *left,*right,i,j,k;

   left=(int *)malloc((n1+1)*sizeof(int));
   right=(int *)malloc((n2+1)*sizeof(int));

   for(i=0;i<n1;i++)
   {
     left[i]=arr[p+i];
   }
   for(i=0;i<n2;i++)
   {
     right[i]=arr[q+i+1];
   }

   left[n1]=INT_MAX;
   right[n2]=INT_MAX;
   i=0;
   j=0;

   for(k=p;k<=r;k++)
   {
       if(left[i]<=right[j])
       {
           arr[k]=left[i];
           i++;
       }
       else
       {
           arr[k]=right[j];
           j++;
       }
   }
}
