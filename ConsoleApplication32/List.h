#include "pch.h"
#pragma once
using namespace std;
#include <iostream>


class List {
	int number;
	int data;
public:
	List *prev;
	List *next;


	List() {
		cout << "Created  empty node number " << endl;
		this->data = 0;;
		this->number = 0;
		this->prev = NULL;
		this->next = NULL;
	}

	List(int n, int d)
	{
		this->data = d;
		this->number = n;
		this->prev = NULL;
		this->next = NULL;
		cout << "Created node number " << n << " with data = " << d << endl;
	}


	~List() {
		cout << "Destructor is workind" << endl;
	}

	int getnumber(List *P) {
		if (P == NULL) {
			cout << "Incorrect adress of node" << endl;
			return 0;
		}
		else return P->number;

	}


	int getdata(List *P) {
		if (P == NULL) {
			cout << "Incorrect adress of node" << endl;
			return 0;
		}
		else return P->data;

	}

	void setdata(List *P, int M) {
		if (P == NULL) {
			cout << "Incorrect adress of node to load data" << endl;
			return;
		}
		else {
			P->data = M;
			cout << "New data  " << M << "is downloaded  in node  " << getnumber(P) << endl;
		};
	}

	List* makelist(int M);
	void show(List *P);
	void deletelist(List *P);
	List* sort1(List *P);
}   PP;







