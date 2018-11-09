/**
 * @brief  拼接两个字符串，实现strcat()的功能
 * 
 * @param str 
 * @param str1 
 * @param str2 
 */
#include<bits/stdc++.h>

/*https://blog.csdn.net/chenxun_2010/article/details/21721419
关于strcat()实现的几种版本
*/
void contact(char *str,const char *str1,const char *str2)//不加const也可以通过
{
    int i,j;
    for(i=0;str1[i]!='\0';i++)
    {
        str[i]=str1[i];
    }
    for(j=0;str2[j]!='\0';j++)
    {
        str[i+j]=str2[j];
    }
    str[i+j]='\0';
}
/**
 * @brief 不建议使用 以下这种方法，
 * 此种方法传入两个已经存在的字符串，运行出现出错，只要包含这一句： （*s1++ = *s2++）,基本会有内存错误，
 * 这种方法传入的参数不一样，一般s1为一个新开辟的空间，此时，此方法运行正常。
 * reference:
 * @param s1 http://www.techiedelight.com/implement-strcat-function-c/
 * @param s2 
 * @return char* 
 */
char * merge(char * s1, char * s2)
{
	assert(s1 != nullptr && s2 != nullptr);
	char * temp = s1;
	while (*s1) //不能采用  while (*str++ !='\0')
		s1++;
	while ('\0' != (*s1++ = *s2++))//vs2015中与clion2018.2版本中，运行到这一句均出错，好像不能对‘\0’的内存进行写操作
		;
		return  temp;
}
/**
 * @brief 以下方法经过验证，推荐使用，
 *  此种方法传入两个已经存在的字符串，将它们合并到一个新的heap上的内存空间中。
 * @param a 
 * @param b 
 * @return char* 
 */
char *cat(char *a, char *b) {
    int i = 0, j = 0;
    int cont = 0;
    int h = strlen(a) + strlen(b) + 1;

    char *result = (char*)malloc(h * sizeof(char));

    for(i = 0; i < strlen(a); i++) {
        result[i] = a[i];
    }

    for(j = i; j < strlen(b)+ strlen(a); j++) {
        result[j] = b[cont++];
    }

    // append null character
    result[h - 1] = '\0';
    return result;
}
/**
 * @brief 可以看出拼接两个字符串的方法基本是通过新开辟一段内存。
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char * mycat(const char*s1, const char *s2)
{
	int len1 = 0, len2 = 0;
	char *rt;
	while (s1[len1])
		++len1;//求出s1字符串的长度
	while (s2[len2])
		++len2;//求出s2字符串的长度
	rt = new char[len1 + len2 + 1]; //新建一个有len1+len2+1个char元素的数组,多出来的个元素用于保存字符串结束标志
	for (int i = 0; i < len1; i++)
	{
		rt[i] = s1[i];  //s1字符串复制到新建的rt数组中
	}
	for (int i = 0; i < len2; i++)
	{
		rt[i + len1] = s2[i];   //将s2字符串也复制到rt数组中,并保存到上面复制进来的s1字符串的后面
	}
	rt[len1 + len2] = '\0';//写入字符串结束标志
	return rt;//返回连接后的字符串首地址.

}
int main()
{
   const  char * str="0123456";
    /**
     * @brief 下面这种写法，str会指向'\0'的后一个字符
     * 
     */
    while (*str++ !='\0')
    {
        printf("*str=%c\n",*str);
        printf("%p\n",str);
    }//也就是在这句之后，str指向的是‘\0’的后一个字符，
    //所以要像指向字符串最后一个字符，必须减减两次
    printf("---------");
    str--;
    str--;
    printf("*str=%c\n",*str);



    return 0;
}