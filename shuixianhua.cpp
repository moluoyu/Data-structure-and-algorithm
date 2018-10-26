/*https://www.nowcoder.com/practice/dc943274e8254a9eb074298fb2084703?tpId=85&tqId=29894&tPage=4&rp=4&ru=%2Fta%2F2017test&qru=%2Fta%2F2017test%2Fquestion-ranking


*/
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int m, n;
    int flag = 0;
    //检测多行输入
    //100 120
    //123 321
    //311 231
/*  或者
   while(~scanf("%d %d",&m,&n))
   { 
     //code 
   }
   或者
    while (cin >> m >> n)
  { 
     //code 
  }
  1.“输入数据有多组，每组占一行“
后来明白还有个东西叫"~scanf"。把代码嵌入到while(~scanf("%d",&n)){//代码段}中就行了。它的原理是：
    a.正常输入的时候，scanf返回输入的数字如1,2,3等等，对这些数字取非，不会成为0，就会执行循环；
    b.错误输入，就是没有输入的时候，scanf返回的是EOF（End Of File），
    EOF=-1，对EOF取非，即对-1取非得到0，就会跳出循环。
    **********************************************
  //输出格式要求，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开;
  example:223 123 121 327
  1 将第一个数作为单独处理
 */  
 if (flag == 1)
                    printf("%d", i);
                else
                    printf(" %d", i);//这里有个空格

    while (cin >> m >> n)
    {
        for (int i = m; i <= n; i++)
        {
            if (i == pow(i % 10, 3) + pow(i / 10 % 10, 3) + pow(i / 100, 3))
            {
                flag++;
                if (flag == 1)
                    printf("%d", i);
                else
                    printf(" %d", i);
            }
        }
        if (flag == 0)
        {
            printf("no");
        }
    }
    printf("\n");

    return 0;
}