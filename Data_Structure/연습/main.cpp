#include<iostream>
#include<cstdlib>

typedef struct _Node {
	int Data;
	_Node* Next;
	_Node* Prev;
}Node;

class List_ {
private:
	Node * Head;
	Node* Cur;
	Node* Tail;
public:
	List_();
	void Insert(int);
	bool First(int&);
	bool Next(int&);
	bool Before(int&);
	void Remove();
	~List_();
};

List_::List_() {
	Head = new Node;
	Tail = new Node;
	Head->Prev = Tail->Next = Cur = nullptr;
	Head->Next = Tail, Tail->Prev = Head;
}

void List_::Insert(int Data) {
	Node* NewNode = new Node;
	NewNode->Data = Data;
	NewNode->Prev = NewNode->Next = nullptr;
	if (Head->Next == Tail) {
		Head->Next = NewNode;
		NewNode->Prev = Head;
		Tail->Prev = NewNode;
		NewNode->Next = Tail;
	}
	else {
		Tail->Prev->Next = NewNode;
		NewNode->Prev = Tail->Prev;
		Tail->Prev = NewNode;
		NewNode->Next = Tail;
	}
}

bool List_::First(int& Data) {
	if (Head->Next == Tail) {
		return false;
	}
	Cur = Head->Next;
	Data = Cur->Data;
	return true;
}

bool List_::Next(int& Data) {
	if (Cur->Next == Tail) {
		return false;
	}
	Cur = Cur->Next;
	Data = Cur->Data;
	return true;
}

bool List_::Before(int& Data) {
	if (Cur->Prev == Head) {
		return false;
	}
	Cur = Cur->Prev;
	Data = Cur->Data;
	return true;
}

void List_::Remove() {
	Node* rpos = Cur;
	Cur->Prev->Next = Cur->Next;
	Cur->Next->Prev = Cur->Prev;
	Cur = Cur->Prev;
	delete rpos;
}

List_::~List_() {
	delete Head;
}

int main() {
	List_ list;

	list.Insert(1);
	list.Insert(2);
	list.Insert(3);
	list.Insert(4);
	list.Insert(5);

	int Data = 0;

	if (list.First(Data)) {
		std::cout << Data << '\t';
		while (list.Next(Data)) {
			std::cout << Data << '\t';
		}
	}

	if (list.First(Data)) {
		list.Remove();
		while (list.Next(Data)) {
			list.Remove();
		}
	}

	return 0;
}