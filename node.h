#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

/*����������� ������ ���������������� ������ ��������� ���������������� ������. 
������� ������ �������� �����. 
���������� ������
����������� ��������� ������� �����:
* ����� � ������ ��� �����, ������� ���������� �� ��������� �����, �������� �������;
* ���� ����� ����� ����, ������������ �� ��� ����� ������.*/

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
		return String::Format("����� = {0}", Word);
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
	Node^ DelLast();//�� ������������
	void Look(System::Windows::Forms::DataGridView^);
	void Find(My_List^ f, Node^ f_el);
	bool operator == (My_List^ l);//�� ������������
	void Swap_first(My_List^ l);//�� ������������
	void Clear();
};
