//字符串排序从小到大
#include <stdio.h>
#include <string.h>
void sorc(int num,char arry[][20])//由冒泡排序改变而来
{
	for(int i=1;i < num;i++)
	{
		for(int j=0;j < num-i;j++)
		{
            for (int z = 0; z < 20; z++)//关键区别,对比字符串和相邻字符串中每一个字母的大小,以实现排序
            {
                if(arry[j][z] > arry[j+1][z])//对比每一个字符,若前一个字符不满足条件,会自动比较下一个字符
			    {
            	    char temp[20];
		    	    strcpy(temp,arry[j]);
			    	strcpy(arry[j],arry[j+1]);
				    strcpy(arry[j+1],temp);
                    break;
                }
				if (arry[j][z] < arry[j+1][z])
				{
					break;
				}
				
            }
		}
	}
}
int main()
{
	char arr[][20] = {"C","Visual Basic","VC++", "Java"};
	sorc(4,arr);
	for(int i=0;i<4;i++)
	{
		printf("%s\n",arr[i]);
	}
}