#include <iostream>
#include <Windows.h>

typedef int LData;

typedef struct _Node {
	_Node* Next, *Before;
	LData Data;
}Node;

class List {
private:
	Node* Head, *Cur, *Before;

public:
	List();
	void Insert(LData Data);
	bool First(LData&);
	bool Next(LData&);
	LData Remove();
	~List();
};

List::List() {
	Head = Cur = Before = nullptr;
}

void List::Insert(LData Data) {
	Node* NewNode = new Node;
	NewNode->Data = Data;
	if (!Head) {
		NewNode->Next = NewNode->Before = NewNode;
	}
	else {
		NewNode->Next = Head->Next;
		Head->Next->Before = Head->Next = NewNode;
		NewNode->Before = Head;
	}
	Head = NewNode;
}

bool List::First(LData& Data) {
	if (!Head) {
		return false;
	}
	Cur = Head;
	Before = Head->Before;
	Data = Cur->Data;
	return true;
}

bool List::Next(LData& Data) {
	if (!Cur) {
		return false;
	}
	Before = Cur;
	Cur = Cur->Next;
	Data = Cur->Data;
	return true;
}

LData List::Remove() {
	Node* TempNode = Cur;
	LData SaveData = TempNode->Data;

	if (Head == Cur) {
		if (Head->Next == Head) {
			Cur = Before = Head = nullptr;
		}
		else {
			Cur->Before->Next = Cur->Next;
			Cur->Next->Before = Cur->Before;
			Head = Cur = Before;
		}
	}
	else {
		Cur->Next->Before = Cur->Before;
		Cur->Before->Next = Cur->Next;
		Cur = Before;
	}

	delete TempNode;
	return SaveData;
}

List::~List() {

}

int main() {
	List list;

	list.Insert(1);
	list.Insert(2);
	list.Insert(3);
	list.Insert(4);
	list.Insert(5);

	LData Data;
	if (list.First(Data)) {
		std::cout << Data << std::endl;
		for (int i = 0; i < 7; i++) {
			list.Next(Data);
			std::cout << Data << std::endl;
		}
	}

	if (list.First(Data)) {
		list.Remove();
		while (list.Next(Data)) {
			list.Remove();
		}
	}

	if (list.First(Data)) {
		std::cout << Data << std::endl;
		while (list.Next(Data)) {
			std::cout << Data << std::endl;
			Sleep(100);
		}
	}
	return 0;
}