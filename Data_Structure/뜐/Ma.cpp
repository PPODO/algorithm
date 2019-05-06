#include<iostream>
#include"Ma.h"

Ma_::Ma_() {
	for (int i = 0; i < SIZE; i++) {
		memset(Map[i], 0, sizeof(int)*SIZE);
	}
	y = 0;
	x = SIZE / 2;
	Count = 1;
	Map[y--][x++] = Count;
}

void Ma_::NextInput(bool Check) {
	if (Check) {
		Map[++yBefore][xBefore] = ++Count;
		x = xBefore + 1, y = yBefore - 1;
	}
	else {
		xBefore = x, yBefore = y;
		Map[y--][x++] = ++Count;
	}
}

bool Ma_::NextCheck() {
	if (Map[(y < 0 ? y = SIZE - 1 : y = y)][(x > SIZE - 1 ? x = 0 : x = x)] != 0) {
		return true;
	}
	return false;
}

void Ma_::Print() {
	for (int i = 0; i < SIZE; i++) {
		int sum = 0, sum2 = 0;
		for (int j = 0; j < SIZE; j++) {
			sum += Map[i][j], sum2 += Map[j][i];
			std::cout << Map[i][j] << '\t';
		}
		std::cout << "HResult : " << sum << "\tVResult : " << sum2 << std::endl;
	}
	std::cout << std::endl;
}

Ma_::~Ma_() {

}