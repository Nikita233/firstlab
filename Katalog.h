#pragma once
#include "pch.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <stdio.h>
using namespace std;


class List {


public:
	string filename;
	string type;

	int size;

	char dateStr[9];
	char timeStr[9];
	List* next;
	List* prev;




	List() {
		this->filename = "";
		this->type = "";
		this->size = 0;
		this->prev = NULL;
		this->next = NULL;
	}
	List(const string &N, const string T) {
		this->filename = N;
		this->type = T;
		//cout << "\nCreated  empty node  name " << this->filename << "  with type " << T << endl;



		this->size = 0;
		this->prev = NULL;
		this->next = NULL;
	}




	~List() {
		cout << "Destructor is workind" << endl;
	}

	int getsize(const List *P) {
		if (P == NULL) {
			cout << "Incorrect adress of file" << endl;
			return 0;
		}
		else return P->size;

	}


	char* getdate(const List *P) {


		if (P == NULL) {
			cout << "Incorrect adress of file" << endl;
			return 0;
		}
		else

			return &dateStr[9];

	}

	string gettime(const List *P) {
		if (P == NULL) {
			cout << "Incorrect adress of file" << endl;
			return 0;
		}
		else

			return &timeStr[9];

	}

	const	string getname(const List *P) {
		if (P == NULL) {
			cout << "Incorrect adress of file" << endl;
			return "";
		}
		else return P->filename;
	}

	const   string gettype(const List *P) {
		if (P == NULL) {
			cout << "Incorrect adress of file" << endl;
			return "";
		}
		else return P->type;

	}

	/*void setdata(List *P, int M) {
		if (P == NULL) {
			cout << "Incorrect adress of node to load data" << endl;
			return;
		}
		else {
			P->data = M;
			cout << "New data  " << M << "is downloaded  in node  " << getnumber(P) << endl;
		};*/


	void makelist(List* L1, int M);
	void show(const List *P);
	//void deletelist(List *P);
	List *sort1(List *P);
	//List *sort2(List *P);
	//string getDateTime(List *P);
} PP;



class Katalog
{
public:
	string  KatName;
	List  *HeadFiles;
	Katalog* Next;
	//Katalog* Down;
	int NumberOfFiles;

	string getKatName(const Katalog* P) {
		if (P == NULL) {
			cout << "Incorrect adress of katalog" << endl;
			return "";
		}
		else return P->KatName;
	}
	Katalog() {
		KatName = ""; HeadFiles = NULL;
		Next = NULL;
		NumberOfFiles = 0;
		cout << "\nThe empty katalog  is created" << endl;
	}  //Створили пустий каталог ;
	Katalog(string N) {
		KatName = N; HeadFiles = NULL;
		Next = NULL;
		NumberOfFiles = 0;
		cout << "\nThe  katalog " << N << " is created" << endl;
	}  //Створили каталог  
	~Katalog();


	void showKatalog(Katalog *P);
	void deleteKatalog(Katalog *P);
	void sortKatalog(Katalog *P, int typeSort); //Сортувати каталог

	void addFile(Katalog *P, string fn, string tp, int sz); // Додати файл в заданий каталог
	void deleteFile(Katalog *P, string fn); // Видалити файл з каталогу
	Katalog*  findFile(string fn);//Пошук файла в усіх каталогах
	List* findFile(char* KatName, char* fn); //Пошук файла в конкретному каталозі

};
ostream &operator <<(ostream&, const string &V) {
	for (int i = 0; V[i]; i++) cout << V[i];
	return cout;
}
