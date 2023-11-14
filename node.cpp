#include "node.h"

void My_List::Add(Node^ new_el) {
	Node^ old_el = head;
	head = new_el;
	new_el->next = old_el;
}

Node^ My_List::DelLast() {
	Node^ el = nullptr;
	if (head == nullptr)
		return head;
	else {
		el = head;
		head = head->next;
		return el;
	}
}

void My_List::Look(System::Windows::Forms::DataGridView^ DGV) {
	DGV->RowCount = 1;
	Node^ el;
	List<Node^>^ Listt = gcnew List<Node^>();
	for (el = head; el != nullptr; el = el->next) {
		Listt->Add(el);
	}
	Listt->Reverse();
	for each (el in Listt) {
		DGV->Rows->Add(el->getWord);
	}
}

void My_List::Find(My_List^ f, Node^ f_el) {
	Node^ el;
	String^ W = f_el->Word;
	for (el = head; el != nullptr; el = el->next) {
		if ((el->Word != "") && (W != "")) {
			if (el->Word->ToLower()[0] == W->ToLower()[0]) { // совпадает ли первая буква слова с заданной буквой
				f->Add(gcnew Node(el));
			}
		}
	}
}

inline bool My_List::operator==(My_List^ l) {
	Node^ a = head;
	Node^ b = l->head;
	while ((a != nullptr) && (b != nullptr)) {
		if (a->Word != b->Word) {
			return false;
		}
		a = a->next;
		b = b->next;
	}
	if (a == nullptr && b == nullptr) {
		return true;
	}
	return false;
}

void My_List::Swap_first(My_List^ l) {
	Node^ a = gcnew Node(l->head);
	Node^ b = gcnew Node(head);
	a->next = head->next;
	b->next = l->head->next;
	head = a;
	l->head = b;
}

void My_List::Clear() {
	while (head != nullptr) {
		Node^ temp = head;
		head = head->next;
		delete temp;
	}
}