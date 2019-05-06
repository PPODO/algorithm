#pragma once
#define SIZE 5

class Ma_ {
private:
	int Map[SIZE][SIZE];
	int Count,x,y;
	int xBefore, yBefore;
public:
	Ma_();
	void NextInput(bool);
	bool NextCheck();
	void Print();
	~Ma_();
};