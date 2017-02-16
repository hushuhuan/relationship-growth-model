#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 500
main()
    {
    double x,y,u,r;
    double rands();
    int n[N][N]={0};//定义一个正方形格子
    long int i,l,m,k;
    FILE *p;
    p=fopen("10.dat","w");
	n[N/2][N/2]=1;
	for(i=0;i<10000;i++)
	{
		x=2*rands()-1;//抽取起始点的坐标
		y=2*rands()-1;
		r=sqrt(x*x+y*y);
		if(r<=1)
		{
			x=x/r*130+N/2;
			y=y/r*130+N/2;
		}
		else continue;
		l=(long int)x;
		m=(long int)y;
		for(k=0;;k++)//随机行走，直到碰到粒子为止，并把此时此点的值改为1
		{
			if(n[l][m]==0&&n[l+1][m+1]==0&&n[l+1][m-1]==0&&n[l-1][m+1]==0&&n[l-1][m-1]==0)
			{
		      u=rands();
		      if(u<0.25)m=m+1;
		      else if(u<0.5)m=m-1;
		      else if(u<0.75)l=l+1;
		      else l=l-1;
			}
			else
			{
				n[l][m]=1;
				break;
			}
			if((m-N/2)*(m-N/2)+(l-N/2)*(l-N/2)>240*240||m<0||n<0)break;//离中心位置太远，舍去
		}
	}
	for(i=130;i<370;i++)
	{
		for(k=130;k<370;k++)
		{
			printf("%d\t",n[i][k]);
			fprintf(p,"%d\t",n[i][k]);
		}
		printf("\n");
		fprintf(p,"\n");
	}
	fclose(p);
}
double rands()                    /* 产生随机数 */
  {     
	static long int z,i=0;
        double x;
        if(i==0){
       time_t rawtime;                  /* 调用此函数时需要加上头文件#include<time.h> */
        time(&rawtime);               /* 取当前时间为种子值 */
       z=rawtime;
        i++;}    /* z为static变量，只在第一次调用时初始化 */
      z=16807*(z%127773)-2836*(z/127773);
      if(z<0) z=z+2147483647;
      x=(double)z/2147483647;
      return(x);

   }
