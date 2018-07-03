# 3. 코딩 스타일

## 3.1 보기 좋은 코드의 중요성

* 시간이 지났을 때
* 유지보수
* 다른 사람과 협업

* 좋은 스타일의 구성요소
  * 문서
  * 분할
  * 네이밍
  * 언어의 사용 형태
  * 포매팅

## 3.2 코드의 문서화

* 프로그래밍의 문서화라 함은 소스 코드 안에 작성된 주석을 의미
* 당연하게 알 수 있는 내용은 피하는 것이 좋음

### 3.2.1 주석을 사용해야 하는 이유

#### 3.2.1.1 사용법을 설명하기 위한 주석

* 좋지 않은 주석

  ```c++
  /*
  * saveRecord() 
  *
  * Saves the given record to the database. 
  *
  * This method will throw a "DatabaseNotOpenedException"
  * if the openDatabase() method was not called first. 
  */
  ```

* 좋은 주석

  ```c++
  /* 
  * saveRecord()
  *
  * Saves the given record to the database.
  *
  * Parameters:
  *   Record& rec: the record to save to the database.
  *
  * Returns: int
  *   An integer representing the ID of the saved record.
  *
  * Throws:
  *   DatabaseNotOpenedException if the openDatabase() method was not called first.
  */
  ```

* 주석 템플릿

  ```c++
  /*
  * func()
  * 
  * Description of the function.
  *
  * Parameters:
  *   int param1: parameter 1.
  * Returns: int
  *   An integer representing...
  * Throws:
  *   Exception1 if...
  * Notes:
  *   Additional notes...
  */
  ```

#### 3.2.1.2 복잡한 코드를 설명하기 위한 주석

* 복잡한 코드

  ```c++
  void sort(int inArray[], int inSize)
  {
        for (int i = 1; i < inSize; i++) {
            int element = inArray[i];
            int j = i – 1;
            while (j >= 0 && inArray[j] > element)
            {
                inArray[j+1] = inArray[j];
                j--;
            }
            inArray[j+1] = element;
        }
  }
  ```

* 복잡한 코드의 주석

  ```c++
  /*
  * Implements the "insertion sort" algorithm. The algorithm separates the
  * array into two parts--the sorted part and the unsorted part. Each
  * element, starting at position 1, is examined. Everything earlier in the
  * array is in the sorted part, so the algorithm shifts each element over
  * until the correct position is found for the current element. When the
  * algorithm finishes with the last element, the entire array is sorted.
  */
  void sort(int inArray[], int inSize)
  {
        // Start at position 1 and examine each element.
        for (int i = 1; i < inSize; i++) {
            // Invariant: All elements in the range 0 to i-1 (inclusive) are sorted.
            int element = inArray[i];
            // j marks the position in the sorted part of the array.
            int j = i – 1;
            // As long as the current slot in the sorted array is higher than 
            // the element, shift the slot over and move backwards.
            while (j >= 0 && inArray[j] > element) {
                inArray[j+1] = inArray[j];
                j--; 
            }
            // At this point the current position in
            // is *not* greater than the element, so
            inArray[j+1] = element;
        }
  }

  ```

#### 3.2.1.2 메타정보를 제공하기 위한 주석

```c++
/*
* Author: marcg
* Date: 110412
* Feature: PRD version 3, Feature 5.10 
*/
int saveRecord(Record& rec)
{
    if (!mDatabaseOpen) {
        throw DatabaseNotOpenedException();
    }

    int id = getDB()->saveRecord(rec);
    if (id == -1) return -1; // Added to address bug #142 – jsmith 110428
    rec.setId(id);
    // TODO: What if setId() throws an exception? – akshayr 110501
    return id;
}
```

### 3.2.2 주석 작성 스타일

#### 3.2.2.1 모든 라인마다 주석 달기

* 피해야 할 라인 주석
    ```c++
    int result;                     // Declare an integer to hold the result.
    result = doodad.getResult();    // Get the doodad's result.
    if (result % 2 == 0) {          // If the result mod 2 is 0 ...
        logError();                 // then log an error,
    } else {                        // otherwise ...
        logSuccess();               // log success.
    }                               // End if/else
    return result;                  // Return the result
    ```

* 수정
    ```c++
    if (result % 2 == 0) {          // If the result is even ...
    ```

* 과도하지만 좋은 예
    ```c++
    // Calculate the doodad. The start, end, and offset values come from the
    // table on page 96 of the "Doodad API v1.6".
    result = doodad.calculate(kStart, kEnd, kOffset);
    // To determine success or failure, we need to bitwise AND the result with
    // the processor-specific mask (see "Doodad API v1.6", page 201).
    result &= getProcessorMask();
    // Set the user field value based on the "Marigold Formula."
    // (see "Doodad API v1.6", page 136)
    setUserField((result + kMarigoldOffset) / MarigoldConstant + MarigoldConstant);
    ```

#### 3.2.2.2 머리말 주석

* 최종 수정 날짜
* 원저작자(개발자)
* 변경 이력
* 이 파일에서 구현하고 있는 기능의 관리ID(Feature ID)
* 저작권 정보
* 파일 또는 클래스 개요
* 미구현 기능
* 알려진 버그

    ```c++
    /*
    * $Id: Watermelon.cpp,123 2004/03/10 12:52:33 marcg $
    *
    * Implements the basic functionality of a watermelon. All units are expressed
    * in terms of seeds per cubic centimeter. Watermelon theory is based on the
    * white paper "Algorithms for Watermelon Processing."
    *
    * The following code is (c) copyright 2011, FruitSoft, Inc. ALL RIGHTS RESERVED
    */
    ```

#### 3.2.2.3 고정 양식 주석

* Java 의 JavaDoc이나 C++ 의 Doxygen을 위한 주석
    ```c++
    /**
    * Implements the basic functionality of a watermelon
    * TODO: Implement updated algorithms!
    */
    class Watermelon {
        public:
            /**
            * @param initialSeeds The starting number of seeds
            */
            Watermelon(int initialSeeds); 
            /**
            * Computes the seed ratio, using the Marigold algorithm.
            * @param slowCalc Whether or not to use long (slow) calculations
            * @return The Marigold ratio
            */
            double calcSeedRatio(bool slowCalc);
    };
    ```

## 3.3 코드 분할

* 파일 하나 몇 라인으로 할 것인가?
* 밀집도는 어떻게 할 것 인가?

### 3.3.1 리팩토링을 통한 코드 분할

* 추상화를 더욱 강화하는 방법
  * 필드(멤버변수)를 캡슐화 한다. : getter/setter 사용으로 전환
  * 타입을 일반화한다. : interfacing화
* 코드를 더 논리적으로 분할하는 방법
  * 메서드를 추출한다.
  * 클래스를 추출한다.
* 네이밍과 코드 위치를 개선하는 방법
  * 메서드나 필드를 이동시킨다.
  * 메서드나 필드의 이름을 변경한다.
  * 풀업: 상위 클래스로 이동
  * 풀다운: 하위 클래스로 이동

* 코딩을 하기 전에 디자인부터 해야 한다.
  * *이쁜코드보다 유지보수가 좋은 코드 선호*

## 3.4 네이밍

* 조직에서 이미 사용하고 있다면 following 하는 것이 좋음
* 도메인 및 비지니스 따라서 정하는 경우가 많음
* 어쨌든 답은 없음

## 3.5 스타일이 있는 언어의 활용

* 상수 이용
* 참조형으로 포인터 대체
* 커스텀 익셉션의 활용

## 3.6 포매팅

* 조직에서 이미 정해 두었다면 그대로 따라라

### 3.6.1 중괄호 정렬 위치

```c++
// 7라인
void someFunction() {
    if (condition()) {
        cout << "condition was true" << endl;
    } else {
        cout << "condition was false" << endl;
    }
}
```

```c++
// 11라인
void someFunction()
{
    if (condition())
    {
        cout << "condition was true" << endl;
    }
    else
    {
        cout << "condition was false" << endl;
    }
}
```

### 3.6.1 괄호 사이 공백

```c++
if (i == 2) {
    j = i + (k / m);
}
```

```c++
if( i == 2 ) {
    j = i + k / m;
}
```

### 3.6.1 탭과 공백

* 탭 사이즈
* 탭 대신 공백
* SCM 시스템에서는 매우 치명적일 수 있음
