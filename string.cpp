

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

