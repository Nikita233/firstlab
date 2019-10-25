#include "pch.h"
#pragma once
using namespace std;
#include <iostream>
#include "List.h"




List* List::makelist(int M) {

	List  *P1, *P2, *P3, *head;
	int counter = 0;
	if (M < 1) {
		cout << "Incorrect nummber of elements" << endl;
		//head = NULL;
		return NULL;
	}

	//Створюємо голову списку

	counter++;
	int D = 1 + rand() % 99;
	head = new List(counter, D);
	P1 = head;
	P2 = head;

	if (M == 1) {


		cout << "The head of the list is created with data =" << D << endl; return head;
	}
	else {
		counter++;
		int D = 1 + rand() % 99;
		P2 = new List(counter, D);
		head->next = P2;
		cout << "The Node number " << counter << "    is created with data =" << D << endl;

	}
	//Створюємо список

	for (int i = 1; i < M; i++)
	{
		counter++;
		int D = 1 + rand() % 99;
		P3 = new List(counter, D);
		P2->next = P3;
		P3->prev = P2;
		P2->prev = P1;
		cout << "The Node number " << counter << "    is created with data =" << D << endl;


		P1 = P2;
		P2 = P3;
	}
	P2->next = NULL; return head;
}







void List::show(List *P) {

	if (P == NULL) {
		cout << "Incorrect adress of the list" << endl;
		return;

	}
	else {
		cout << "\n\n Show of the list:            P     P->prev   P->next           \n";
		while (P != NULL) {

			//		cout << "Node number  " << List::getnumber(P) << "  with data " << List::getdata(P) << endl;

			cout << " number";
			cout.width(4); cout << List::getnumber(P);
			cout << " data ";
			cout.width(4); cout << List::getdata(P);
			cout << "     " << P << "  " << P->prev << "  " << P->next << endl;
			P = P->next;
		}
	}
}

void List::deletelist(List *P) {
	List *P1;

	while (P != NULL) {
		P1 = P;
		P = P->next;

		cout << "Node  " << P1->number << "  is deleted" << endl;
		delete P1;
	}
}

List* List::sort1(List *P) {
	List  *P1, *P2, *P3, *P4, *P5, *head;

	int value;
	cout << "\n\n Sorting is startd" << endl;
	head = P;
	P1 = P;
	P2 = P->next;
	if (P2 == NULL) {

		cout << " \n\nOme mode list is regarded as sorted" << endl;
		return head;
	}


	while (List::getdata(P1) < List::getdata(P2))
	{
		cout << "Sort:  move P2" << endl;
		P1 = P2;
		P2 = P2->next;

		if (P2 == NULL) {
			cout << "Sorting is finished" << endl; return head;
		}
	}

	P3 = P1->prev;  value = List::getdata(P2);
	P4 = P2->next;

	do {


		if (List::getdata(P3) <= value)
			//Вставляємо  Р2 на нове місце 
		{

			cout << "Sort:  incert P2" << endl;
			// Р2 стає перед Р3
			P1->next = P4;
			P5 = P3->next;
			if (P4 != NULL) {
				P4->prev = P1;
			}
			P2->next = P3->next;
			P3->next = P2;
			P2->prev = P3;
			P5->prev = P2;
			P2 = P1->next;
			P3 = P1;
			value = List::getdata(P2);

			PP.show(head);
		}


		else	  if (P3 == head) {
			cout << "\n\nSort:   P2 is new head\n" << endl;

			// Р2 стає новою головою
			P1->next = P4;

			if (P4 != NULL) {
				P4->prev = P1;
			}
			P2->next = P3;
			P2->prev = NULL;
			P3->prev = P2;
			head = P2;
			//if (counter) P1->prev = P2;
			P2 = P1->next;
			PP.show(head);
			P3 = P1;
		}


		if (P2 == NULL) {

			cout << "Sorting is finished\n" << endl; return head;

		}
		else P4 = P2->next;
		value = List::getdata(P2);
		P3 = P3->prev;
	} while (true);




}





















int main()
{


	int M;
	List   *head;
	//int counter = 0;

	cout << " Input the qwantity of nodes" << endl;

	cin >> M;

	if (M < 1) {
		cout << "Incorrect nummber of elements" << endl;
		head = NULL; return 0;
	}

	head = PP.makelist(M);
	PP.show(head);

	head = PP.sort1(head);
	PP.show(head);
	cout << "\n\n  Clean the memory\n" << endl;
	PP.deletelist(head);
}












