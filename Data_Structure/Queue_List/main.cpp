#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Queue.h"

#define CUS_COME_TIME 15

#define CHE_BER 0
#define BUL_BER 1
#define DUB_BER 2

#define CHE_TIME 12
#define BUL_TIME 15
#define DUB_TIME 24

int main() {
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec = 0;

	Queue queue;
	
	QInit(&queue);
	srand(time(NULL));

	for (sec = 0; sec < 3600; sec++) {
		if (sec % CUS_COME_TIME == 0) {
			switch (rand() % 3) {
			case CHE_BER:
				EnQueue(&queue, CHE_TIME);
				cheOrder++;
				break;
			case BUL_BER:
				EnQueue(&queue, BUL_TIME);
				bulOrder++;
				break;
			case DUB_BER:
				EnQueue(&queue, DUB_TIME);
				dubOrder++;
				break;
			}
		}
		if (makeProc <= 0 && !QIsEmpty(&queue)) {
			makeProc = DeQueue(&queue);
		}
		makeProc--;
	}
	puts("Simulation Report!!");
	printf(" - Cheese Buerger : %d\n", cheOrder);
	printf(" - Bulgogi Buerger : %d\n", bulOrder);
	printf(" - Double Buerger : %d\n", dubOrder);
	printf(" - Waiting room size : %d\n", 100);

	return 0;
}