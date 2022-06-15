#### 201901669_김현승

<br>

# 목차
<ol>
<li>머리글</li>
<li>데이터 정하기 및 수학적 모형 정하기</li>
<li>모수 값 추정</li>
<li>분석</li>
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
내가 정한 데이터의 기준은 다음과 같다.
<ol>
<li>데이터값이 방대하기 않을 것</li>
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
우선 2006년은 기준으로 두고 0이라 했을 때, x값이 0일때 y값이 1이 나오며 기울기는 최대 0.75 최소 0.1이 나오기 때문에 식은 아마 다음과 같을 것이다.

```
y = x * a + 1
(a = 0.75 ~ 0.10)
```

그럼 이제 기준을 정했으니 최적화된 수학적모형을 만들어보도록 하자.  
나는 수학적모형을 유전알고리즘을 통해 구해볼 생각이며, 그 기준은 에러값의 총 합이 가장 작은 것이다.



















































































