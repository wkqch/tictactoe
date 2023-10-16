#include <stdio.h>
#include <stdlib.h>

void Print();
void Input();
void Update();
void Check();
char arr[3][3] = { { '_','_' ,'_' },{ '_' ,'_' ,'_' },{ '_' ,'_' ,'_' } };
int a, b;
int count = 0;
int main() {
	printf("틱택토게임\n");
	printf("시작\n");

	while (1) {
		Print();
		Input();
		
		count++;
		Update();
		Check();
	}
}

void Print(){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
}
void Input() {
	printf("원하는 곳의 좌표를 입력해주세요 : ");
		scanf("%d %d", &a, &b);
		if (arr[a][b] == 'O' || arr[a][b] == 'X') {
			printf("이미 한 위치입니다. 다시 시도해주세요.");
			Input();
		}
}
void Update() {
	if (count % 2 == 1) {
		arr[a][b] = 'O';
	}
	else arr[a][b] = 'X';
}
void wincheck(int win, char target) {
		if (win == 1 && target != '_') {
			if (target == 'O') printf("O가");
			else if (target == 'X') printf("X가");
			printf(" 승리했습니다!\n게임이 끝났습니다.\n"); 
			exit(1);
		}
}




void widthcheck() {
	for (int j = 0; j < 3; j++) {
		char target = arr[j][0];
		int win = 1;

		for (int i = 0; i < 3; i++) {
			if (target != arr[j][i]) {
				win = 0; break;
			}
		}
		wincheck(win, target);
	}
 }
void heightcheck() {
	for (int j = 0; j < 3; j++) {
		char target = arr[0][j];
		int win = 1;

		for (int i = 0; i < 3; i++) {
			if (target != arr[i][j]) {
				win = 0; break;
			}
		}
	wincheck (win, target);

	}
}
void diagonal1check() {
	char target = arr[0][0];
	int win = 1;
	for (int i = 0; i < 3; i++) {
		if (target != arr[i][i]) {
			win = 0; break;
		}
	}
	wincheck(win, target);
}
void diagonal2check() {
	char target = arr[0][2];
	int win = 1;
	for (int i = 0; i < 3; i++) {
		if (target != arr[i][2 - i]) {
			win = 0; break;
		}
	}
	wincheck(win, target);
}

void Check() {
	widthcheck();
	heightcheck();
	diagonal1check();
	diagonal2check();
}

