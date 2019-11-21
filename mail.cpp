#include<stdio.h>
#pragma warning(disable:4996)
char a[7] = { "000000" };
char b[7] = { "001111" };
char c[7] = { "010011" };
char d[7] = { "011100" };
char e[7] = { "100110" };
char f[7] = { "101001" };
char g[7] = { "110101" };
char h[7] = { "111010" };
char print[1000];
int main()
{
	freopen("mail.inp", "r", stdin);
	freopen("mail.out", "w", stdout);
	char arr[1000];
	int Test;
	int length;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		int a_c = 0;
		int b_c = 0;
		int c_c = 0;
		int d_c = 0;
		int e_c = 0;
		int f_c = 0;
		int g_c = 0;
		int h_c = 0;
		scanf("%d", &length);
		scanf("%s", &arr);
		for (int j = 0; j <= length * 6; j++)
		{
			if (j != 0 && j % 6 == 0)
			{
				if (a_c >= 5 && b_c != 5 && c_c != 5 && d_c != 5 && e_c != 5 && f_c != 5 && g_c != 5 && h_c != 5)
					printf("A");
				else if (a_c != 5 && b_c >= 5 && c_c != 5 && d_c != 5 && e_c != 5 && f_c != 5 && g_c != 5 && h_c != 5)
					printf("B");
				else if (a_c != 5 && b_c != 5 && c_c >= 5 && d_c != 5 && e_c != 5 && f_c != 5 && g_c != 5 && h_c != 5)
					printf("C");
				else if (a_c != 5 && b_c != 5 && c_c != 5 && d_c >= 5 && e_c != 5 && f_c != 5 && g_c != 5 && h_c != 5)
					printf("D");
				else if (a_c != 5 && b_c != 5 && c_c != 5 && d_c != 5 && e_c >= 5 && f_c != 5 && g_c != 5 && h_c != 5)
					printf("E");
				else if (a_c != 5 && b_c != 5 && c_c != 5 && d_c != 5 && e_c != 5 && f_c >= 5 && g_c != 5 && h_c != 5)
					printf("F");
				else if (a_c != 5 && b_c != 5 && c_c != 5 && d_c != 5 && e_c != 5 && f_c != 5 && g_c >= 5 && h_c != 5)
					printf("G");
				else if (a_c != 5 && b_c != 5 && c_c != 5 && d_c != 5 && e_c != 5 && f_c != 5 && g_c != 5 && h_c >= 5)
					printf("H");
				else
					printf("X");
				a_c = 0;
				b_c = 0;
				c_c = 0;
				d_c = 0;
				e_c = 0;
				f_c = 0;
				g_c = 0;
				h_c = 0;
			}
			if (arr[j] == a[j % 6])
				a_c++;
			if (arr[j] == b[j % 6])
				b_c++;
			if (arr[j] == c[j % 6])
				c_c++;
			if (arr[j] == d[j % 6])
				d_c++;
			if (arr[j] == e[j % 6])
				e_c++;
			if (arr[j] == f[j % 6])
				f_c++;
			if (arr[j] == g[j % 6])
				g_c++;
			if (arr[j] == h[j % 6])
				h_c++;
		}
		printf("\n");
	}
}