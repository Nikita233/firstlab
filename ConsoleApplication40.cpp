
#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <cctype>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <stdio.h>
using namespace std;
#include "Katalog.h"

#include <windows.h>






List *sort1(List *P);

void  makelist(List* L1, int M) {

	int radix = 10;
	char buffer[20];
	string p;
	string filen;
	string typ;
	string Types[3] = { "txt","doc","pdf" };
	char dStr[9], tStr[9];


	List  *P1, *P2, *P3, *head;
	int counter = 0, ind;
	if (M < 1) {
		cout << "Incorrect nummber of elements" << endl;
		//head = NULL;
		return;
	}

	//Створюємо голову списку

	counter++;
	int D = 1 + rand() % 99;

	filen = "File";
	p = (to_string)(D);

	filen = filen + p;


	ind = D % 3;
	typ = Types[ind];
	//head = new List(filen, typ);
	head = L1;
	head->filename = filen;
	head->type = typ;

	head->size = rand();
	_strdate_s(dStr);
	for (int i = 0; i <= 9; i++)
		head->dateStr[i] = dStr[i];
	//head->dateStr = dStr;
	_strtime_s(tStr);
	for (int i = 0; i <= 9; i++)
		head->timeStr[i] = tStr[i];
	P1 = head;
	//head->timeStr = tStr;
	cout << "\nCreated " << filen << "." << typ;

	cout << "   " << dStr << " " << tStr << "  " << head->size << endl;
	Sleep(1000);
	if (M == 1) {
		return;
	}
	else {
		counter++;
		int D = 1 + rand() % 99;
		filen = "File";
		p = (to_string)(D);

		filen = filen + p;

		//cout << "\n" << filen;
		ind = D % 3;
		typ = Types[ind];
		P2 = new List(filen, typ);
		head->next = P2;

		P2->size = rand();
		_strdate_s(dStr);
		for (int i = 0; i <= 9; i++)
			P2->dateStr[i] = dStr[i];
		//head->dateStr = dStr;
		_strtime_s(tStr);
		for (int i = 0; i <= 9; i++)
			P2->timeStr[i] = tStr[i];

		cout << "\nCreated " << filen << "." << typ;
		cout << "   " << dStr << " " << tStr << "  " << P2->size << endl;
		Sleep(1000);

	}
	//Створюємо список

	for (int i = 1; i < M - 1; i++)
	{
		counter++;
		int D = 1 + rand() % 99;
		filen = "File";
		p = (to_string)(D);

		filen = filen + p;

		ind = D % 3;
		typ = Types[ind];
		P3 = new List(filen, typ);

		P3->size = rand();
		_strdate_s(dStr);
		for (int ii = 0; ii <= 9; ii++)
			P3->dateStr[ii] = dStr[ii];
		//head->dateStr = dStr;
		_strtime_s(tStr);
		for (int i = 0; i <= 9; i++)
			P3->timeStr[i] = tStr[i];

		cout << "\nCreated " << filen << "." << typ << "  ";

		cout << dStr << " " << tStr << "  " << P3->size << endl;
		Sleep(1000);

		P2->next = P3;
		P3->prev = P2;
		P2->prev = P1;
		//cout << "The Node number " << counter << "    is created with data =" << D << endl;


		P1 = P2;
		P2 = P3;
	}
	P2->next = NULL; return;
}


List *sort1(List *P) {
	List  *P1, *P2, *P3, *P4, *P5, *head;

	string value;
	cout << "\n\n Sorting is startd" << endl;
	head = P;
	P1 = P;
	P2 = P->next;
	if (P2 == NULL) {

		cout << " \n\nOme mode list is regarded as sorted" << endl;
		return head;
	}


	while (P->getname(P1) < P->getname(P2))
	{
		cout << "Sort:  move P2" << endl;
		P1 = P2;
		P2 = P2->next;

		if (P2 == NULL) {
			cout << "Sorting is finished" << endl; return head;
		}
	}

	P3 = P1->prev;  value = P->getname(P2);
	P4 = P2->next;

	do {


		if (P->getname(P3) <= value)
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
			value = P->getname(P2);

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
		value = P->getname(P2);
		P3 = P3->prev;
	} while (true);




}

void List::show(const List *P) {

	if (P == NULL) {
		cout << "Incorrect adress of the list to show" << endl;
		return;

	}
	else {
		cout << "\n\n Show of the list:            P     P->prev   P->next           \n";
		while (P != NULL) {

			//		cout << "Node number  " << List::getnumber(P) << "  with data " << List::getdata(P) << endl;

			cout << " Name";
			cout.width(4); cout << List::getname(P);
			cout << "." << List::gettype(P);
			cout.width(4); cout << List::getdate(P);
			cout << "  " << List::gettime(P) << "  ";
			cout << List::getsize(P) << endl;
			P = P->next;
		}
	}
}








int main()
{

	List *LL;


	string KN = "";

	int M;

	//int counter = 0;
	cout << " Input the name of katalog" << endl;


	cin >> KN;

	Katalog *K1 = new Katalog(KN);
	Katalog *Beginning = K1;
	cout << " Input the qwantity of files" << endl;


	cin >> M;

	if (M < 1) {
		cout << "Incorrect nummber of files" << endl;
		//	head = NULL; 
		return 0;
	}
	LL = new List();
	K1->HeadFiles = LL;
	makelist(LL, M);
	//cout << "SORTING" << endl;
	//LL = sort1(LL);

	while (true) {
		cout << "\n\n One more katalog? Input the name or space" << endl;

		cin >> KN;
		if (KN == "@") break;

		Katalog *PrevKat = K1;
		Katalog *K1 = new Katalog(KN);
		PrevKat->Next = K1;
		cout << " Input the qwantity of files" << endl;


		cin >> M;

		if (M < 1) {
			cout << "Incorrect nummber of files" << endl;
			//	head = NULL; 
			break;;
		}
		LL = new List();
		K1->HeadFiles = LL;
		makelist(LL, M);


	}

	do {
		cout << "  \n\n\n              Possible actions:" << endl;
		cout << "      To sort  files in katalog      -  1" << endl;
		cout << "      To find  file in katalog       -  2" << endl;
		cout << "      To delete file from katalog    -  3" << endl;
		cout << "      To finish the work             -  0" << endl;
		cin >> M;
		if (M == 1) {
			cout << "Input the name of katalog" << endl;
			cin >> KN;

			cout << "     Input the type of sorting" << endl;
			cout << "     By name              -   1,  " << endl;
			cout << "     by time of creating  -   2 " << endl;
			cin >> M;
			K1 = Beginning;
			while (K1 != NULL) {
				if (K1->KatName == KN) {
					if (M == 1) sort1(K1->HeadFiles);
				} K1 = K1->Next;
			}

		}
		if (M == 0) return 0;
	} while (true);
}

