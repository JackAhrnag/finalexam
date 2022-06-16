#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#define genetic_re_max 10000
#define genetic_n_max 5
#define slope_max 0.75
#define slope_min 0.1
#define point 5

struct _genetic
{
	double a;
	double suitability;
};

struct _genetic genetic[genetic_n_max];
struct _genetic genetic_chack_temp[genetic_n_max];
struct _genetic genetic_best_chack;
double y_point[point] = { 1, 1.1, 1.74, 1.98, 2.73 };

void insert_sort(_genetic* genetic, int size) //삽입정렬
{
	struct _genetic key;
	int j;

	for (int i = 1; i < size; i++)
	{
		key = genetic[i];

		for (j = i - 1; j >= 0 && genetic[j].suitability > key.suitability; j--)
		{
			genetic[j + 1] = genetic[j];
		}

		genetic[j + 1] = key;
	}
}

void genetic_select_first() //아담과 이브들
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < genetic_n_max; i++)
	{
		genetic[i].a = (double)(rand() % 650000) / 100000 + 0.1;
	}
}

void genetic_select_twise() //교미
{
	srand((unsigned int)time(NULL));

	int random;
	struct _genetic temp[genetic_n_max];

	for (int i = 0; i < genetic_n_max; i++)
	{
		temp[i] = genetic[i];
	}

	for (int i = 0; i < genetic_n_max; i++)
	{
		random = rand() % 100 + 1;
		if (i == 0)
		{
			if (random == 1)
			{
				temp[i].a = (double)(rand() % 650000) / 100000 + 0.1;
			}
			else
			{
				temp[i].a = (genetic[0].a + genetic[1].a) * 0.6;
			}
		}
		else if (i == 1)
		{
			if (random == 1)
			{
				temp[i].a = (double)(rand() % 650000) / 100000 + 0.1;
			}
			else
			{
				temp[i].a = (genetic[0].a + genetic[1].a) * 0.55;
			}
		}
		else if (i == 2)
		{
			if (random == 1)
			{
				temp[i].a = (double)(rand() % 650000) / 100000 + 0.1;
			}
			else
			{
				temp[i].a = (genetic[0].a + genetic[1].a) * 0.5;
			}
		}
		else if (i == 3)
		{
			if (random == 1)
			{
				temp[i].a = (double)(rand() % 650000) / 100000 + 0.1;
			}
			else
			{
				temp[i].a = (genetic[0].a + genetic[1].a) * 0.45;
			}
		}
		else if (i == 4)
		{
			if (random == 1)
			{
				temp[i].a = (double)(rand() % 650000) / 100000 + 0.1;
			}
			else
			{
				temp[i].a = (genetic[0].a + genetic[1].a) * 0.4;
			}
		}
	}

	for (int i = 0; i < genetic_n_max; i++)
	{
		genetic[i] = temp[i];
	}
}

void genetic_check() //유전 적합도(에러값)체크 후 정렬
{
	double y;
	double all_error[genetic_n_max] = { 0 };

	for (int i = 0; i < genetic_n_max; i++)
	{
		for (int j = 0; j < point; j++)
		{
			y = genetic[i].a * j + 1;
			if (y > y_point[j])
			{
				all_error[i] = all_error[i] + (y - y_point[j]);
			}
			else if (y < y_point[j])
			{
				all_error[i] = all_error[i] + (y_point[j] - y);
			}
		}
	}

	for (int i = 0; i < genetic_n_max; i++)
	{
		genetic[i].suitability = all_error[i];
	}

	insert_sort(genetic, genetic_n_max);
}

void genetic_argorithm() // 유전 알고리즘 메인
{
	genetic_select_first();

	for (int i = 0; i < genetic_re_max; i++)
	{
		printf("[%d]번째\n\n", i);

		if (i < genetic_re_max-1)
		{
			genetic_check();
			for (int j = 0; j < genetic_n_max; j++)
			{
				printf("[%d] a = %lf   error = %lf\n\n", j, genetic[j].a, genetic[j].suitability);
			}
			if (i == 0)
			{
				for (int i = 0; i < genetic_n_max; i++)
				{
					genetic_chack_temp[i] = genetic[i];
				}
				genetic_best_chack = genetic[0];
			}
			else
			{
				if (genetic_chack_temp[0].suitability < genetic[0].suitability)
				{
					genetic_chack_temp[1] = genetic[0];
					genetic[0] = genetic_chack_temp[0];
					genetic[1] = genetic_chack_temp[1];
				}
			}

			for (int i = 0; i < genetic_n_max; i++)
			{
				genetic_chack_temp[i] = genetic[i];
			}

			if (genetic_best_chack.suitability > genetic[0].suitability)
			{
				genetic_best_chack = genetic[0];
			}
			genetic_select_twise();
		}
		else
		{
			genetic_check();
			for (int j = 0; j < genetic_n_max; j++)
			{
				printf("[%d] a = %lf   error = %lf\n\n", j, genetic[j].a, genetic[j].suitability);
			}
		}
	}
}

int main()
{
	genetic_argorithm();
	printf("final best\na = %lf, error = %lf", genetic_best_chack.a, genetic_best_chack.suitability);

	return 0;
}
