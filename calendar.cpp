#include<stdio.h>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int year[2300];
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string Day[7] = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };
int day_check(int Year, int Month, int Day)
{
	int day = Day;
	if (year[Year] == 1)
	{
		if (Month == 2)
		{
			if (month[Month] < day - 1)
				return -1;
			else
			{
				if (month[Month] < day)
					return -1;
				else 
					return 0;
			}
		}
		else
		{
			if (month[Month] < day)
				return -1;
			else
				return 0;
		}
	}
	else
	{
		if (month[Month] < day)
			return -1;
		else return 0;
	}
}
int check(int Year, int Month, int Week, string d_Day)
{
	int day = 0;
	int i = 0;
	int j = 0;
	for (int i = 1; i < Year; i++)
	{
		if (year[i] == 1)
			day = day + 366;
		else
			day = day + 365;
	}
	for (int i = 1; i < Month; i++)
		day = day + month[i];
	if (Month > 3)
	{
		if (year[Year]==1)
			day = day + 1;
	}
	day++;
	string value;
	if (day % 7 == 1)
		value = "Mon";
	else if (day % 7 == 2)
		value = "Tue";
	else if (day % 7 == 3)
		value = "Wed";
	else if (day % 7 == 4)
		value = "Thu";
	else if (day % 7 == 5)
		value = "Fri";
	else if (day % 7 == 6)
		value = "Sat";
	else
		value = "Sun";
	for (i = 0; i < 7; i++)
	{
		if (value.compare(Day[i])==0)
			break;
	}
	for (j = 0; j < 7; j++)
	{
		if (d_Day.compare(Day[j])==0)
			break;
	}
	if (i > j)
	{
		day = 7 - i + j + 1;
		day = day + 7 * (Week - 1);
		if (day > month[Month])
			return -1;
		else
			return day;
	}
	else
	{
		day = 1 + j - i;
		day = day + 7 * (Week-1);
		if (day > month[Month])
			return -1;
		else
			return day;
	}
}
int main()
{
	freopen("calendar.inp", "r", stdin);
	freopen("calendar.out", "w", stdout);
	int type;
	int f_year;
	int f_month;
	int f_day;
	int s_year;
	int s_month;
	int s_day;
	int day = 0;
	char c; // - ¹Þ¾ÆÁÙ º¯¼ö 
	string s_Day;
	string f_Day;
	for (int i = 0; i < 2300; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0 )|| i % 400 == 0)
			year[i] = 1;
	}
	while (1)
	{
		day = 0;
		scanf("%d", &type);
		if (type == 0)
		{
			scanf("%d-%d-%d %d-%d-%d\n", &f_year, &f_month, &f_day, &s_year, &s_month, &s_day);
			int flag = day_check(f_year, f_month, f_day);
			int flag2 = day_check(s_year, s_month, s_day);
			if (flag == -1 || flag2 == -1)
				printf("-1\n");
			else
			{
				if (f_year > s_year)
				{
					for (int j = f_year - 1; j >= s_year + 1; j--)
					{
						if (year[j] == 1)
							day = day + 366;
						else
							day = day + 365;
					}
					if (s_month < 3)
					{
						if (year[s_year] == 1)
							day = day + 1;
					}
					if (f_month >= 2)
					{
						if (year[f_year] == 1)
							day = day + 1;
					}
					for (int j = 1; j < f_month; j++)
						day = day + month[j];
					for (int j = s_month + 1; j <= 12; j++)
						day = day + month[j];
					day = day + f_day;
					day = day + month[s_month] - s_day;
					printf("%d\n", day);
				}
				else if (f_year < s_year)
				{
					for (int j = s_year - 1; j >= f_year + 1; j--)
					{
						if (year[j] == 1)
							day = day + 366;
						else
							day = day + 365;
					}
					if (f_month < 3)
					{
						if (year[f_year] == 1)
							day = day + 1;
					}
					if (s_month >= 2)
					{
						if (year[s_year] == 1)
							day = day + 1;
					}
					for (int j = 1; j < s_month; j++)
						day = day + month[j];
					for (int j = f_month + 1; j <= 12; j++)
						day = day + month[j];
					day = day + s_day;
					day = day + month[f_month] - f_day;
					printf("%d\n", day);
				}
				else // f_year==s_year
				{
					if (f_month > s_month)
					{
						if (year[f_year] == 1)
						{
							if (s_month > 3)
							{
								day = day + month[s_month] - s_day;
								day = day + f_day;
								for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
							}
							else
							{
								day = day + month[s_month] - s_day;
								day = day + f_day;
								day = day + 1; // À±³âÇ¥½Ã
								for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
							}
						}
						else
						{
							day = day + month[s_month] - s_day;
							day = day + f_day;
							for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
						}
					}
					else if (f_month < s_month)
					{
						if (year[f_year] == 1)

							if (f_month > 3)
							{
								day = day + month[f_month] - f_day;
								day = day + s_day;
								for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
							}
							else
							{
								day = day + month[f_month] - f_day;
								day = day + s_day;
								day = day + 1; // À±³âÇ¥½Ã
								for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
							}
						else
						{
							day = day + month[f_month] - f_day;
							day = day + s_day;
							for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
						}
					}
					else
					{
						if (f_day > s_day)
							day = f_day - s_day;
						else
							day = s_day - f_day;
					}
					printf("%d\n", day);
				}
			}
		}
		else if (type == 1)
		{
		cin >> f_year >> c >> f_month >> c >> f_day;
		cin >> s_year >> c >> s_month >> c >> s_day >> c >> s_Day;
			int flag = day_check(f_year, f_month, f_day);
			int value = check(s_year, s_month, s_day, s_Day);
			if (value == -1 || flag==-1)
				printf("-1\n");
			else
			{
				s_day = value;
				if (f_year > s_year)
				{
					for (int j = f_year - 1; j >= s_year + 1; j--)
					{
						if (year[j] == 1)
							day = day + 366;
						else
							day = day + 365;
					}
					if (s_month < 3)
					{
						if (year[s_year] == 1)
							day = day + 1;
					}
					if (f_month >= 2)
					{
						if (year[f_year] == 1)
							day = day + 1;
					}
					for (int j = 1; j < f_month; j++)
						day = day + month[j];
					for (int j = s_month + 1; j <= 12; j++)
						day = day + month[j];
					day = day + f_day;
					day = day + month[s_month] - s_day;
					printf("%d\n", day);
				}
				else if (f_year < s_year)
				{
					for (int j = s_year - 1; j >= f_year + 1; j--)
					{
						if (year[j] == 1)
							day = day + 366;
						else
							day = day + 365;
					}
					if (f_month < 3)
					{
						if (year[f_year] == 1)
							day = day + 1;
					}
					if (s_month >= 2)
					{
						if (year[s_year] == 1)
							day = day + 1;
					}
					for (int j = 1; j < s_month; j++)
						day = day + month[j];
					for (int j = f_month + 1; j <= 12; j++)
						day = day + month[j];
					day = day + s_day;
					day = day + month[f_month] - f_day;
					printf("%d\n", day);
				}
				else // f_year==s_year
				{
					if (f_month > s_month)
					{
						if (year[f_year] == 1)
						{
							if (s_month > 3)
							{
								day = day + month[s_month] - s_day;
								day = day + f_day;
								for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
							}
							else
							{
								day = day + month[s_month] - s_day;
								day = day + f_day;
								day = day + 1; // À±³âÇ¥½Ã
								for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
							}
						}
						else
						{
							day = day + month[s_month] - s_day;
							day = day + f_day;
							for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
						}
					}
					else if (f_month < s_month)
					{
						if (year[f_year] == 1)

							if (f_month > 3)
							{
								day = day + month[f_month] - f_day;
								day = day + s_day;
								for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
							}
							else
							{
								day = day + month[f_month] - f_day;
								day = day + s_day;
								day = day + 1; // À±³âÇ¥½Ã
								for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
							}
						else
						{
							day = day + month[f_month] - f_day;
							day = day + s_day;
							for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
						}
					}
					else
					{
						if (f_day > s_day)
							day = f_day - s_day;
						else
							day = s_day - f_day;
					}
					printf("%d\n", day);
				}
			}
		}
		else if (type == 2)
		{
			cin >> f_year >> c >> f_month >> c >> f_day >> c >> f_Day;
			cin >> s_year >> c >> s_month >> c >> s_day;
			int value = check(f_year, f_month, f_day, f_Day);
			int flag2 = day_check(s_year, s_month, s_day);
			if (value == -1 || flag2 == -1)
				printf("-1\n");
			else
			{
				f_day = value;
				if (f_year > s_year)
				{
					for (int j = f_year - 1; j >= s_year + 1; j--)
					{
						if (year[j] == 1)
							day = day + 366;
						else
							day = day + 365;
					}
					if (s_month < 3)
					{
						if (year[s_year] == 1)
							day = day + 1;
					}
					if (f_month >= 2)
					{
						if (year[f_year] == 1)
							day = day + 1;
					}
					for (int j = 1; j < f_month; j++)
						day = day + month[j];
					for (int j = s_month + 1; j <= 12; j++)
						day = day + month[j];
					day = day + f_day;
					day = day + month[s_month] - s_day;
					printf("%d\n", day);
				}
				else if (f_year < s_year)
				{
					for (int j = s_year - 1; j >= f_year + 1; j--)
					{
						if (year[j] == 1)
							day = day + 366;
						else
							day = day + 365;
					}
					if (f_month < 3)
					{
						if (year[f_year] == 1)
							day = day + 1;
					}
					if (s_month >= 2)
					{
						if (year[s_year] == 1)
							day = day + 1;
					}
					for (int j = 1; j < s_month; j++)
						day = day + month[j];
					for (int j = f_month + 1; j <= 12; j++)
						day = day + month[j];
					day = day + s_day;
					day = day + month[f_month] - f_day;
					printf("%d\n", day);
				}
				else // f_year==s_year
				{
					if (f_month > s_month)
					{
						if (year[f_year] == 1)
						{
							if (s_month > 3)
							{
								day = day + month[s_month] - s_day;
								day = day + f_day;
								for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
							}
							else
							{
								day = day + month[s_month] - s_day;
								day = day + f_day;
								day = day + 1; // À±³âÇ¥½Ã
								for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
							}
						}
						else
						{
							day = day + month[s_month] - s_day;
							day = day + f_day;
							for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
						}
					}
					else if (f_month < s_month)
					{
						if (year[f_year] == 1)

							if (f_month > 3)
							{
								day = day + month[f_month] - f_day;
								day = day + s_day;
								for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
							}
							else
							{
								day = day + month[f_month] - f_day;
								day = day + s_day;
								day = day + 1; // À±³âÇ¥½Ã
								for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
							}
						else
						{
							day = day + month[f_month] - f_day;
							day = day + s_day;
							for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
						}
					}
					else
					{
						if (f_day > s_day)
							day = f_day - s_day;
						else
							day = s_day - f_day;
					}
					printf("%d\n", day);
				}
			}

		}
		else if (type == 3)
		{
		cin >> f_year >> c >> f_month >> c >> f_day >> c >> f_Day;
		cin >> s_year >> c >> s_month >> c >> s_day >> c >> s_Day;
			int value = check(f_year, f_month, f_day, f_Day);
			int value2 = check(s_year, s_month, s_day, s_Day);
			if (value == -1 || value2 == -1)
				printf("-1\n");
			else
			{
				f_day = value;
				s_day = value2;
				if (f_year > s_year)
				{
					for (int j = f_year - 1; j >= s_year + 1; j--)
					{
						if (year[j] == 1)
							day = day + 366;
						else
							day = day + 365;
					}
					if (s_month < 3)
					{
						if (year[s_year] == 1)
							day = day + 1;
					}
					if (f_month >= 2)
					{
						if (year[f_year] == 1)
							day = day + 1;
					}
					for (int j = 1; j < f_month; j++)
						day = day + month[j];
					for (int j = s_month + 1; j <= 12; j++)
						day = day + month[j];
					day = day + f_day;
					day = day + month[s_month] - s_day;
					printf("%d\n", day);
				}
				else if (f_year < s_year)
				{
					for (int j = s_year - 1; j >= f_year + 1; j--)
					{
						if (year[j] == 1)
							day = day + 366;
						else
							day = day + 365;
					}
					if (f_month < 3)
					{
						if (year[f_year] == 1)
							day = day + 1;
					}
					if (s_month >= 2)
					{
						if (year[s_year] == 1)
							day = day + 1;
					}
					for (int j = 1; j < s_month; j++)
						day = day + month[j];
					for (int j = f_month + 1; j <= 12; j++)
						day = day + month[j];
					day = day + s_day;
					day = day + month[f_month] - f_day;
					printf("%d\n", day);
				}
				else // f_year==s_year
				{
					if (f_month > s_month)
					{
						if (year[f_year] == 1)
						{
							if (s_month > 3)
							{
								day = day + month[s_month] - s_day;
								day = day + f_day;
								for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
							}
							else
							{
								day = day + month[s_month] - s_day;
								day = day + f_day;
								day = day + 1; // À±³âÇ¥½Ã
								for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
							}
						}
						else
						{
							day = day + month[s_month] - s_day;
							day = day + f_day;
							for (int j = s_month + 1; j <= f_month - 1; j++) day = day + month[j];
						}
					}
					else if (f_month < s_month)
					{
						if (year[f_year] == 1)

							if (f_month > 3)
							{
								day = day + month[f_month] - f_day;
								day = day + s_day;
								for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
							}
							else
							{
								day = day + month[f_month] - f_day;
								day = day + s_day;
								day = day + 1; // À±³âÇ¥½Ã
								for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
							}
						else
						{
							day = day + month[f_month] - f_day;
							day = day + s_day;
							for (int j = f_month + 1; j <= s_month - 1; j++) day = day + month[j];
						}
					}
					else
					{
						if (f_day > s_day)
							day = f_day - s_day;
						else
							day = s_day - f_day;
					}
					printf("%d\n", day);
				}
			}
		}
		else if (type == -1)
			return 0;
	}
}