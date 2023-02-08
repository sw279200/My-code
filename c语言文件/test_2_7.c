#include<stdio.h>
int main()
{
    int i,r,w;
    int j=0;
    int num =0;
    scanf("%d %d %d",&i,&r,&w);
    int count[r-i];
    for(j =i;j<=r;j++ )
    {
        if(w%j==0)
        {
            count[num++] = w/j;

        }
     }
     if(num<2)
     {
        printf("unsolvable");

    }
      else
     {
        printf("%d %d",count[num],count[0]);
     }


    return 0;
}
