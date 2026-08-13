//查找子串
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);

int main(void)
{
    char str[100];
    char substr[100];
    const char *find;
    const char *sub_find;
    printf("Enter a string, entering a empty line to quit: ");
    while(s_gets(str, 100) != 0 && str[0] != '\0')//获取第一个字符串
    {
        printf("Enter a substring to find, entering a empty line to quit: ");
        while(s_gets(substr, 100) != 0 && substr[0] != '\0')//获取要查找的子串
        {
            find = str;
            sub_find = substr;
            while(*find != '\0')
            {
                while(*find == *sub_find)
                {
                    sub_find++;
                    find++;
                    if(*sub_find == '\0')//情况1：找到子串   
                    {
                        printf("Found: %s\n", substr);
                        printf("Enter an another string to find, entering a empty line to quit: ");   
                        break;
                    }
                    if(*find == '\0')//情况2：有部分相同，遍历完字符串都未找到子串,注意主串结束但子串未结束的情况
                    {
                        printf("Not found: %s\n", substr);
                        printf("Enter a another string to find, entering a empty line to quit: ");
                        break;
                    }
                }
                if(*find == '\0')//遍历完都未找到子串继续查找下一组字符串
                    break;
                if(*sub_find == '\0')//找到子串后继续查找下一个子串
                    break;
                sub_find = substr;//情况3：有部分相同，重置子串指针到子串开始的位置继续查找
                find++;//继续查找主串的下一个字符
                if(*find == '\0')//情况2及情况4：完全没有相同的部分，注意find++后主串结束的情况
                {
                    printf("Not found: %s\n", substr);
                    printf("Enter a another string to find, entering a empty line to quit: ");
                    break;
                }               
            }
        if(*find == '\0' || *sub_find == '\0')//情况1，2，4退出到最外面的循环
        break; 
        }    
    }
    printf("Bye:)\n");
    return 0;
}

char * s_gets(char * st, int n)//从输入流中读取字符串，并替换换行符为空字符(安全输入函数)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
                i++;
        if (st[i] == '\n')
                st[i] = '\0';
        else
            while (getchar() != '\n')//清除输入行超长部分，在缓存区中的剩余字符
                continue;
        }
    return ret_val;
}