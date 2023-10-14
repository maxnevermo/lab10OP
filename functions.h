#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define countOfMarks 5

struct marks {
	int marks[5];
};

struct birthday {
	int day;
	int month;
	int year;
};

struct SInfo {
	char surname[30];
	char name[30];
	struct birthday birth;
	struct marks mark;
};

struct SList {
	struct SInfo students;
	struct SList* next;
};

struct SList* createList(struct SList** pHead, int countOfStudents);

void printList(struct SList* pHead);

void sortList(struct SList* pHead);

void sheet();

int countOfStudent(struct SList* pHead);

void swap(struct SList** pos1, struct SList** pos2);

struct SList* ifAutumn(struct SList** pHead);

struct SList* deleteWithoutOne(struct SList** pHead);

struct SList* addNewSt(struct SList** pHead);

void freemem(struct SList* pHead);