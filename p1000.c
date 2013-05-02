    #include<stdio.h>

    void fun(int x)
    {
        int a[1000]={0},b[1000]={0},sum[1000]={0};
      char c;
      int la=0,lb=0;
      scanf("%c",&c);
      while (c!=' ')
      {la++;
      a[la]=c-'0';
      scanf("%c",&c);
      }
      scanf("%c",&c);
      while (c!='\n')
      {
          lb++;
      b[lb]=c-'0';
      scanf("%c",&c);
      }
      int la1=la,lb1=lb;
    int i;
      for (i=la;i>=1;i--)
      {
          sum[la-i+1]+=a[i];
      }

      for (i=lb;i>=1;i--)
      {
          sum[lb-i+1]+=b[i];
      }
    if (lb>la) {la=lb;}
      for (i=1;i<la;i++)
      {
          if (sum[i]>=10){sum[i+1]++;sum[i]-=10;}
      }
      if (sum[la]>10){
      sum[la]-=10;
      la++;
      sum[la]++;
      }

      printf("Case%d:\n",x);
      i=1;
      while (i<=la1)
      {
          printf("%d",a[i]);
        i++;
      }
      printf("+");
       i=1;
      while (i<=lb1)
      {
          printf("%d",b[i]);
      i++;
      }
      printf("=");

        for (i=la;i>=1;i--)
        printf("%d",sum[i]);
        printf("\n");
        return ;
    }
    int main()
    {
        int n;
        scanf("%d",&n);
        char ch;

        scanf("%c",&ch);
        int o;
        for (o=1;o<=n;o++)
        {
            fun(o);
        }

    return 0;
    }
