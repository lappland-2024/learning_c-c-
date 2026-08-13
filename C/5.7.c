/* swap1.c -- 第1个版本的交换函数 */
#include <stdio.h>
int interchange(int u, int v); /* 声明函数 */
int main(void)
{
int x = 5, y = 10;
int *a;
printf("Originally x = %d and y = %d.\n", x, y);
a = interchange(x, y);
x = *a;
y = *(a + 1);
printf("Now x = %d and y = %d.\n", x, y);
return 0;
}

int interchange(int u, int v) /* 定义函数 */
{
int temp;
int a[2];
int *t;
temp = u;
u = v;
v = temp;
a[0] = u;
a[1] = v;
t = &a[0];
return t;
}