#### 201901669_김현승

<br>

# 목차
<ol>
<li>머리글</li>
<li>데이터 정하기 및 수학적 모형 정하기</li>
<li>모수값 추정</li>
<li>소감</li>
</ol>
<br>

---

<br>

# 머리글

<br>

기말시험이 어느정도 정리되고, 지금 이 과제를 하기 위해 책상에 앉은 06월 15일에 나는 문제에 봉착했다.  
과제의 주제가 정확히 이해되지 않는다.

<br>

어떤 데이터에 대한 변수를 가장 잘 설명할 수 있는 수학적 모형을 가정한 다음에, 유전 알고리즘 또는 모의 담금질 기법을 이용하여 에러를 최소화 하는 모수 값을 추정하라.  
수학적 모형을 랜덤으로 만듬 다음 데이터 값에 따라 에러값이 달라지기 때문에 그 값이 최소화되는 수학적 모형을 만들면 되는 과제인가?  
그게 아니라면 모수 값조차 랜덤인가?  
애초에 회귀식과 모수값은 정확히 무엇인가?  
마지막 남은 기말과제를 끝내기 위해 책상에 앉았을 때 나는 이 과제에 대해서 정확히 이해한 것이 없었다.

<br>

때문에 이 보고서는 3일의 시간동안 내가 목차의 순서대로 공부하는 것을 차례로 풀어보는 '노트'와도 같은 모습이 될 것이다.  
소감이라는 목차까지 빠르게 가보자.

<br>

---

<br>

# 데이터 정하기 및 수학적 모형 정하기

<br>

우선 데이터를 정해야 그 데이터를 분석해서 수학적 모형을 만들 것이다.  
나는 아직 이와 같은 일에 익숙하지 않기 때문에 데이터를 정할 때 기준을 확실히 정할 필요가 있었고, 그 기준은 되도록이면 분석하기 쉬워야 했다.  
때문에 내가 정한 데이터의 기준은 다음과 같다.
<ol>
<li>데이터값이 방대하지 않을 것</li>
<li>이미 어느정도 분석되어 있을 것</li>
<li>되도록 1차식으로 표현할 수 있을 것</li>
</ol>
이에따른 기준 하에 내가 정한 데이터는 '2006년 부터 2010년까지의 ARPU추세'이다.  
ARPU란 '유저당 평균 결제액'으로 흔히 모바일게임 영역에서 많이 쓰이는 말이다.  
지금 우리나라는 인구수가 줄어듬에 따라 고령화가 진행되고 있는대, 이에 따라 흔히 게임플레이 가능 인구라 불리는 '9세~49세'인 인구비율이 줄어들고 있다.  
원래는 이에 따라 게임 이용자수와 시장규모 또한 같이 떨어져야 했으나, 이용자수는 유지되고 시장규모는 계속 상승곡선을 보여주고 있다.  
이에 따른 장르별 유저수를 매출과 대비한 ARPU또한 증가하고 있으니, 데이터값이 많지 않고, 이미 어느정도 분석되어 있으며, 되도록 1차식으로 표현할 수 있는 이것을 데이터값으로 정하기로 했다.

<br>
<br>

![데이터값](https://t1.daumcdn.net/cfile/tistory/112F5E3C4F210BA90A)

<br>
<br>

나는 이 과제에서 수학적모형을 랜덤으로 잡아보려 한다.  
하지만 이 랜덤에도 기준이 있어야하기 때문에 위 데이터값에 대한 수학적모형의 기준을 잡으려 한다.  
기준은 데이터값이 많지 않으며, 일정하게 증가하는 추세이기에 간단하게 잡을 수 있다.  
우선 2006년을 기준으로 두고 0이라 했을 때, x값이 0일때 y값이 1이 나오며 기울기는 최대 0.75 최소 0.1이 나오기 때문에 식은 아마 다음과 같을 것이다.

```
y = x * a + 1
(a = 0.75 ~ 0.10)
```

그럼 이제 기준을 정했으니 최적화된 수학적모형을 만들어보도록 하자.  
나는 수학적모형을 유전알고리즘을 통해 구해볼 생각이며, 그 기준은 에러값의 총 합이 가장 작은 것이다.  
에러값은 위의 수학적모형의 x에 값을 넣었을 때 데이터값과의 차이를 기준으로 둔다.(ex) x = 1 이라고 할 때, y = x * a + 1에서 y = a + 1이 나오고 데이터값에서 x = 1 일 때는 2007년 이기에 a + 1과 1.1의 차이를 에러값이라고 한다. (더 높은 값에서 더 낮은 값을 뺀다.))  
이 유전알고리즘의 기준은 다음과 같다.  
<ol>
<li>기울기의 최대값은 0.75, 최소값은 0.1</li>
<li>1세대에 5마리가 태어난다. 그 중 적합도가 가장 높은(error값의 총 합이 가장 낮은) 둘을 이용하여 다음 세대를 만든다.</li>
<li>돌연변이 확률은 각 개체마다 1%의 확률로 나타난다. (각 개체마다의 확률이기에 5개체 모두 돌연변이가 일어날 수 있다. 이는 0.00000001%의 확률이다. 하지만 5개체중 돌연변이가 하나라도 일어날 확률은 5%로 적절하다 생각된다.)</li>
<li>되물림은 만 회 이루어지며, 이를 20회 반복한다. 이후 마지막 되물림은 십만 회 이루어진다.</li>
<li>적합도가 가장 높은 수학적모형은 역사에 위인으로 남겨놓는다.</li>
<li>이후 마지막세대가 생성되었다해도 적합도가 위인보다 낮다면 위인을 베스트로서 출력한다.</li>
</ol>
이와같은 기준은 3차이상의 수학적모형이 아닌 1차식을 사용하기에 가능한 기준이라 생각하였고, 이를 기준으로 더 명확한 최적화된 수학적모형을 만들 수 있다고 생각하였다.

<br>
<br>

사용한 코드는 다음과 같다. (허접해보일 수 있다.)

<br>

```

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

```

<br>

돌연변이 확률이 적긴 하나 각 개체마다 발생할 수 있기에 확률은 적절할 것이라 생각된다.  
각 개체는 구조체를 이용하여 표현하였으며, 구조체에는 a값과 error값의 합이 들어간다.
아직 유전알고리즘이 익숙하지 않기 때문에 룰렛은 이용하지 않았으며, 삽입정렬을 이용하여 가장 적합도가 높은 개체 두개를 선택할 수 있도록하여 단순화시켰다.

<br>

![error값이_낮아진다는_증거](https://github.com/JackAhrnag/finalexam/blob/main/error%EA%B0%92%EC%9D%B4%20%EB%82%AE%EC%95%84%EC%A7%84%EB%8B%A4%EB%8A%94%20%EC%A6%9D%EA%B1%B0.jpg?raw=true)

<br>

위는 코드를 완성한 다음 컴토를 해본 결과값에서 따왔다.  
9977번째 세대의 Best는 error값이 0.650904인 0.370452이나, 9988번째 세대의 Best는 에러값이 0.650384인 0.370192로 error값이 낮아지고 있는 것을 육안으로 볼 수 있다. 이는 세대가 지남에 따라 적합도가 높아지고 있다는 것을 의미한다.  
추가적으로 이때의 마지막 Best값은 0.370192로 어느정도 시간이 지나면 값이 고착되는 것 또한 알 수 있다.

<br>

이후 결과값은 다음의 그림과 같이 측정되었다.

<br>

![a값과_error값_총정리](https://github.com/JackAhrnag/finalexam/blob/main/a%EA%B0%92%EA%B3%BC%20error%EA%B0%92.jpg?raw=true)

<br>

error값이 낮으면 낮을수록 최적화된 값에 부합한다고 할 수 있으며, 10000회와 100000회 모두 error값이 가장 낮을때의 a값은 0.37이었기에 가장 최적화된 수학적모형은 'y = 0.37 * x + 1'이라 할 수 있다.

<br>

```

y = 0.37 * x + 1

```

<br>

가장 최적화된 수학적모형도 찾았으니, 그렇다면 이제 모수값을 알아보도록 하자.

<br>

---

<br>

# 모수값 추정

<br>

이 데이터값의 최적화된 수학적모형은 'y = 0.37 * x + 1' 이다.  
그리고 이 데이터값에서 데이터의 개수는 5개이다.  
수학적모형이 단순하고 데이터의 값이 적기 때문에 모수값을 쉽게 구할 수 있다.

<br>

모수값은 아마도 1.74일 것이다.

<br>

---

<br>

# 소감

<br>

2학년 1학기 마지막 기말과제이다.  
복학이후 처음으로 맞은 학기인 만큼 머리가 굳은 것인지 공부가 되지 않는다.  
다행이도 코딩은 이전부터 재밌어했기에 어느정도 손에 익는것 같으나 공업수학, 전자계산기구조와 같은 것은 머릿속에 잘 들어오지 않는다. 회로이론도 어느정도 머릿속에 들어오나 잘한다고 말하기에는 부족하다.  
지금 이 기말과제도 위와 같은 상황이다.

<br>

![error값이_낮아진다는_증거](https://github.com/JackAhrnag/finalexam/blob/main/error%EA%B0%92%EC%9D%B4%20%EB%82%AE%EC%95%84%EC%A7%84%EB%8B%A4%EB%8A%94%20%EC%A6%9D%EA%B1%B0.jpg?raw=true)

<br>

위와같은 그림을 통해 유전알고리즘은 잘 구현했을 것이라 생각한다.  
결과값또한 어느정도 일정한 수준에서 움직여주기 때문에 유전알고리즘을 통한 수작적모형은 아마도 잘 만들었을 것이다.  
하지만 모수값이 문제였다.  
모수값이 뭔지 이해는 되지만 어떻게 구할지는 도저히 생각이 나지 않아 인터넷에서 공부한 결과, 아직도 잘 모르겠다.  
때문에 위에 있는 모수값이 적절한지에 대한 검증 또한 지금의 나는 하지 못한다.

<br>

이번 학기는 내가 정말로 많이 부족해졌고, 공부를 확실히 마음먹고 해야 한다는 것을 깨닫게 해준 학기였다.  

<br>

---

<br>

####참고

<br>

* https://gameqa.tistory.com/104 (온라인게임 이용자 감소와 ARPU 증가 추이 - 게임QA 시장 조사 피드백)
* https://ssung-22.tistory.com/42 (모수를 왜 추정하고, 어떻게 추정하는거지?)
* https://www.is.com/ko/community/blog/mobile-dictionary-part-4/ ([알아두면 쓸모있는 모바일 마케팅 용어사전] Part 4. 유저 및 유저 관련 지표 용어)
