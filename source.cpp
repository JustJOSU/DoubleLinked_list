#include<iostream>
using namespace std;
class dlnode {
public:
	dlnode(int d, dlnode *p = 0, dlnode *n = 0) {
		prev_ = p;
		next_ = n;
		data_ = d;
	}
	dlnode * prev_;
	dlnode * next_;
	int data_;
};

class dllist {
public:
	dllist() { head_ = 0; tail_ = 0; }
	int GetSize();
	void Insert(int item);
	void Delete(int value);
	int GetAt(int position);
	int Index(int value);
	void Print();
	void PrintReverse();
private:
	dlnode * head_;
	dlnode * tail_;
};
/*int dllist::GetSize() {
	
}*/
void dllist::Insert(int item) {
	dlnode *insertNode = new dlnode(item);
	dlnode *scan;
	if (head_ != 0) {
		if (head_->data_ > item) {		//head앞 부분에 올 때
			insertNode->prev_ = NULL;
			insertNode->next_ = head_;
			head_->prev_ = insertNode;
			head_ = insertNode;
		}
		else if (tail_->data_ < item) {	//tail 뒷 부분에 올 때
			insertNode->prev_ = tail_;
			insertNode->next_ = NULL;
			tail_->next_ = insertNode;
			tail_ = insertNode;
		}
		else {							//어느 값 중간에 들어갈 때
			scan = head_;
			while (scan->next_->data_ < insertNode->data_)
			{
				scan = scan->next_;
			}
			insertNode->next_ = scan->next_;
			insertNode->prev_ = scan;
			scan->next_ = insertNode;
		}
	}
	else {								//아무것도 없는 빈 상태일 때
		head_ = insertNode;
		tail_ = insertNode;
	}
}
void dllist::Delete(int value) {
	dlnode *delNode = new dlnode(value);
	dlnode *scan = head_;
	if (scan == 0) {
		return;
	}
	if (value == scan->data_) {

	}
}
/*int dllist::GetAt(int position) {

}
int dllist::Index(int value) {

}*/
void dllist::Print() {
	dlnode *scan = head_;
	while (scan != NULL) {
		cout << scan->data_ <<" ";
		scan = scan->next_;
	}
	cout << endl;
}
void dllist::PrintReverse() {
	dlnode *scan = tail_;
	while (scan != NULL) {
		cout << scan->data_ << " ";
		scan = scan->prev_;
	}
}
int main() {
	dllist lst;
	int v;

	for (int i = 0; i<7; i++) {
		cin >> v;
		lst.Insert(v);
	}
	/*for (int i = 0; i<3; i++) {
		cin >> v;
		lst.Delete(v);
	}*/
	lst.Print();
	lst.PrintReverse();
}