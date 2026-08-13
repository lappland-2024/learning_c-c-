//字符串反转（指针）
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);

int main(void)
{
char str[100];
char * start, * end, temp;
printf("Enter a string, entering a empty line to quit: ");
while((s_gets(str, 100)) != 0 && str[0] != '\0')
{
    start = str;
    end = str + strlen(str) - 1;
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
printf("Reversed string: %s\n", str);
printf("Enter a another string, entering a empty line to quit: ");
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