# System programming assignment #1
## 1. 과제 개요
virtual box를 이용한 ubuntu를 사용하였습니다.

---

## 2. 리눅스 배포판
리눅스 배포판은 리눅스 커널을 중심으로 사용 목적과 실행 환경에 따라 여러 시스템 소프트웨어나 사용자 프로그램이 포함되어 구성된 운영체제입니다. 

### 데비안 (Debian)
`데비안`은 데비안 프로젝트에서 개발된 오픈소스 운영체제로 최초 버전 출시일인 1993년 이후로 지금까지 자유 컴퓨터 운영체제로써 현재까지도 최신 버전 개발이 진행되고있는 리눅스 배포판입니다.   

데비안은 가장 영향력이 있는 오픈소스 프로젝트 중 하나로 안정성과 보안에 중점을 두며 패키지 설치와 업데이트가 간편하다는 특징을 가지고 있습니다.

### 우분투(Ubuntu)
`우분투`는 데비안에 기반하여 오픈소스 소프트웨어로 구성된 리눅스 배포판입니다. 우분투는 사용자가 손쉽게 운영체제를 설치하고 사용할 수 있도록 설계되어 개인용 데스크탑과 노트북에서 가장 인기있는 리눅스 배포판 중 하나입니다.

### 안드로이드(Android)
삼성의 갤럭시 시리즈를 포함한 많은 스마트폰의 운영체제로 쓰이는 `안드로이드`는 리눅스 커널에 기반한다는 점에서 넓은 의미에서의 리눅스 배포판이라고 할 수 있습니다. 

애플사의 iOS를 제외한 거의 대부분의 스마트폰의 운영체제로 쓰이는 안드로이드는 가장 대표적인 오픈 소스 플랫폼입니다.

### 페도라 리눅스(Fedora Linux)
`페도라 리눅스`는 페도라 프로젝트가 레드햇의 후원과 개발 공동체의 지원을 받아 개발된 리눅스 배포판입니다. 페도라의 주요 기능인 보안 기능의 집합인 SELinux가 내장되어 있습니다.

---

## 3. 개발 환경
- 운영체제
>Windows 10 Home
- 프로세서(CPU)
>AMD Ryzen 5 5600X
- 메모리(RAM)
>32GB DDR4 3200MHz
- 가상 환경
>VirtualBox

---

## 4. 실습
![image](https://user-images.githubusercontent.com/103945439/190895924-ed0b43ea-f6c7-495e-90e7-a6b9bd11fa57.png)

- 우분투 터미널에서 위 명령어로 hello.c 작성 시작

### vi를 이용한 hello.c 작성

![image](https://user-images.githubusercontent.com/103945439/190895977-afb7d231-c40e-4fa0-86a5-2513943c416c.png)

### 컴파일 시스템 정리

**1. Preprocessing phase (전처리 단계)**
> 이 단계에서는 #include와 같은 구문을 처리하여 헤더 파일을 소스코드에 직접 삽입하고 매크로 구문을 처리합니다.   

![image](https://user-images.githubusercontent.com/103945439/190896275-3a8f8605-308b-45d2-b00a-3db19d35a9b0.png)

*$gcc -E hello.c -o hello.i -P 로 전처리를 진행해 vi editor로 파일을 열어본 모습.*   


**2. Compilation phase (컴파일 단계)**
> 이 단계에서는 전처리 된 소스 코드를 어셈블리 언어로 번역하는 작업을 수행합니다

![image](https://user-images.githubusercontent.com/103945439/190896368-e4711fb0-caf4-492a-ac0f-6eed171baeb3.png)

*$gcc -S hello.c 로 컴파일 단계를 거친 hello.s를 vi editor로 열어본 모습.*   

**3. Assembly phase (어셈블리 단계)**
> 이 단계에서는 어셈블리 언어로 된 파일을 기계어로 번역하는 절차를 거칩니다.

![image](https://user-images.githubusercontent.com/103945439/190896465-48583420-e5a9-47fb-a241-820ed833a844.png)

*$gcc -c hello.c 이후 $objdump -d hello.o를 통해 살펴본 모습.*

### vi 및 gcc 옵션 실습
*Vi editor(Vim)에 대하여...*
```
vi에는 사용자의 코드 작성의 편의를 위한 다양한 명령어들이 있습니다.   
최초 진입시 command mode로 시작하며 i,a, o를 눌러 insert mode로 진입해 작성이 가능합니다. 다시 command mode로의 진입은 ESC키를 눌러 가능하고 이 상태에서 :, /, ?를 눌러 Last-line mode로 진입할 수 있습니다. Last-line 모드에서는 파일을 저장하거나 vi editor를 종료하는 등의 파일 관리가 가능합니다.
```

## 5. $whoami 명령어 수행
![image](https://user-images.githubusercontent.com/103945439/190896787-7e7d8b4a-6347-4cd7-ba1a-bd27e72eae04.png)


## 6. 요약 및 느낀점
   
과제를 하기 전에는 사실 linux라는 운영체제에 대해서 잘 몰랐고 윈도우 운영체제 위의 ide 환경에서만 프로그래밍하는데 익숙하고 CLI 환경에는 친숙하지 않았습니다. 이번 실습을 통해 linux와 gcc를 이용한 다양한 컴파일 실행과정을 알게 되어 프로그래밍 견문을 넓히게 되었고 vi editor라는 새로운 작성 프로그램을 통해 코드 작성에 있어서의 새로운 방식을 알게 되어 많은 경험을 했음을 느꼈습니다.