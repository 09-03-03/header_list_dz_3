#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

/*Разработать полную функциональность класса «Линейный однонаправленный список». 
Данными списка являются слова. 
Прикладные задачи
Разработать процедуры решения задач:
* найти в списке все слова, которые начинаются на некоторую букву, заданную заранее;
* если такие слова есть, сформировать из них новый список.*/

public ref class Node {
public:
	String^ Word;
	Node^ next;
public:
	Node() {
		Word = gcnew String("");
		next = nullptr;
	}
	Node(String^ A) {
		Word = gcnew String(A);
		next = nullptr;
	}
	Node(Node^ Tmp) {
		Word = gcnew String(Tmp->Word);
		next = nullptr;
	}
	virtual String^ ToString() override {
		return String::Format("Слово = {0}", Word);
	}
	property String^ getWord {
		String^ get() {
			return Word;
		}
	};
};

public ref class My_List
{
	Node^ head;
public:
	My_List(void) {
		head = nullptr;
	}
	void Add(Node^ new_el);
	Node^ DelLast();//не используется
	void Look(System::Windows::Forms::DataGridView^);
	void Find(My_List^ f, Node^ f_el);
	bool operator == (My_List^ l);//не используется
	void Swap_first(My_List^ l);//не используется
	void Clear();
};
