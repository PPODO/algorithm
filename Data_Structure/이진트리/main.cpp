#include <iostream>

typedef struct {
	int IndexNum;
	int Data;
}Node;

class BT {
private:
	Node arr[100];
	int Index;
public:
	BT();
	void AddNode(int Data);
	void DeleteNode();
	void ShowNode();
	int GetIndex() const { return Index; }
};

BT::BT() {
	Index = 1;
}

void BT::AddNode(int Data) {
	arr[Index].Data = Data;
	arr[Index].IndexNum = Index;
	Index++;
}

void BT::DeleteNode() {
	arr[Index].Data = 0;
	arr[Index].IndexNum = 0;
	Index--;
}

void BT::ShowNode() {
	for (int i = 1; i < Index; i++) {
		std::cout << "IndexNum : " << arr[i].IndexNum << '\t' << "Data : " << arr[i].Data << std::endl;
	}
}

int main() {
	BT Tree;

	Tree.AddNode(1);
	Tree.AddNode(5);
	Tree.AddNode(3);
	Tree.AddNode(2);
	Tree.AddNode(4);

	Tree.ShowNode();

	return 0;
}