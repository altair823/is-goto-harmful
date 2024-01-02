# Is GOTO really harmful?

## 개요

GOTO는 프로그래밍 언어에서 제공하는 제어문 중 하나이다. GOTO는 프로그램의 흐름을 원하는 위치로 이동시키는 역할을 한다. GOTO는 프로그래밍 언어에서 제공하는 제어문 중 가장 강력한 기능을 가지고 있다. 하지만 GOTO는 프로그램의 흐름을 이해하기 어렵게 만들고, 프로그램의 흐름을 예측하기 어렵게 만든다. 이러한 이유로 GOTO는 프로그래밍 언어에서 제공하는 제어문 중 가장 위험한 기능이라고 할 수 있다.

지난 1968년에 Edsger W. Dijkstra는 GOTO의 위험성에 대해 논문을 발표했다. 그는 프로그래밍 언어에서 제공하는 제어문 중 GOTO를 제외하고 나머지 제어문만을 사용하여 프로그램을 작성할 수 있다는 것을 증명했다. [Edgar Dijkstra: Go To Statement Considered Harmful](https://homepages.cwi.nl/~storm/teaching/reader/Dijkstra68.pdf)


## GOTO의 위험성

다른 제어문(i.e. for, while, if, switch, break, continue in C)과 달리 GOTO는 정해진 흐름을 따르지 않고 프로그램의 흐름을 원하는 위치로 이동시킬 수 있다. for나 while은 주어진 조건이 거짓될 때까지 블럭의 처음으로 돌아가고, if는 주어진 조건이 거짓이면 블럭을 건너뛴다. 이런 흐름은 비교적 읽기 쉽다. 반면 GOTO 자체에는 단지 어떤 곳으로 이동할지만 정의되어 있다. 이 GOTO가 특정 블럭을 반복하는 반복문인지, 조건에 따라 건너뛰는 조건문인지 알 수 없다. 이러한 이유로 GOTO는 프로그램의 흐름을 이해하기 어렵게 만든다. 

### GOTO의 예시

#### No GOTO(for)

```c
#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d %d\n", i, j);
        }
    }
    
    return 0;
}
```


#### With GOTO and if(no for)

```c
#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 0;

    i_label:
    j_label:
    printf("%d %d\n", i, j);
    j++;
    if (j < 10) {
        goto j_label;
    }
    i++;
    if (i < 10) {
        goto i_label;
    }

    return 0;
}
```

for문 예시는 어떤 부분이 반복되고 어떤 부분이 아닌지 확실히 알 수 있다. 하지만 GOTO를 사용한 예시는 단지 두 개의 레이블과 두 개의 if문으로만 이루어져 있어서 어떤 부분이 반복되고 어떤 부분이 아닌지 알기 어렵다. 


## 프로젝트 내용

이번 프로젝트에서는 C++로 해시맵을 구현한 뒤, 이를 GOTO를 사용해 다시 구현한다. 그리고 두 프로그램의 소스코드를 비교해 GOTO가 프로그램의 흐름을 이해하기 어렵게 만드는지 확인한다.
