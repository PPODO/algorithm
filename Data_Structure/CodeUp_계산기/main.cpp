#include<iostream>
#include<cstdlib>
#include<cctype>

typedef struct _node {
	_node* Next;
	int Data;
}Node;

class StackList {
private:
	Node * Head;
public:
	StackList();
	void Push(int);
	int Pop();
	int Peek();
	bool IsEmpty();
	~StackList();
};

StackList::StackList() {
	Head = nullptr;
}

bool StackList::IsEmpty() {
	if (!Head) {
		return true;
	}
	return false;
}

void StackList::Push(int Data) {
	Node* NewNode = new Node;
	NewNode->Next = nullptr, NewNode->Data = Data;
	NewNode->Next = Head;
	Head = NewNode;
}

int StackList::Pop() {
	if (IsEmpty()) {
		std::cout << "Stack is Empty!!";
		exit(-1);
	}
	Node* rpos = Head;
	int BData = rpos->Data;
	Head = Head->Next;
	free(rpos);
	return BData;
}

int StackList::Peek() {
	if (IsEmpty()) {
		std::cout << "Stack is Empty!!";
		exit(-1);
	}
	return Head->Data;
}

StackList::~StackList() {
	if (!IsEmpty()) {
		while (!IsEmpty()) {
			Pop();
		}
	}
	Head = nullptr;
}

int Calculator(const char[]);

int main() {
	char str[200] = "\0";

	std::cin.getline(str, 200, '\n');

	std::cout << Calculator(str);

	return 0;
}

int Calculator(const char str[]) {
	StackList Stack;
	char tok = 0;
	int Op1 = 0, Op2 = 0, Count = 0;
	for (int i = 0; i < strlen(str); i++) {
		tok = str[i];
		if (isdigit(tok)) {
			if (isdigit(str[i + 1])) {
				Count++;
			}
			else {
				int Value = 0, Sum = 1;
				for (int j = Count; j > 0; j--) {
					for (int k = 0; k < j; k++) {
						Sum *= 10;
					}
					Sum *= (str[i - j] - '0');
					Value += Sum;
					Sum = 1;
				}
				Value += (str[i] - '0');
				Stack.Push(Value);
				Count = 0;
			}
		}
		else {
			if (tok != ' ') {
				Op2 = Stack.Pop();
				Op1 = Stack.Pop();
				switch (tok) {
				case '+':
					Stack.Push(Op1 + Op2);
					break;
				case '-':
					Stack.Push(Op1 - Op2);
					break;
				case '*':
					Stack.Push(Op1 * Op2);
					break;
				case '/':
					Stack.Push(Op1 / Op2);
					break;
				}
			}
		}
	}
	return Stack.Pop();
}