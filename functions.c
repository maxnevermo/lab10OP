#include "functions.h"

//---------------------------------------------------------------------------
//Функція для створення однозв'язного списку студентів із файлу zhurnal.txt

struct SList* createList(struct SList** pHead, int countOfStudents) {

	FILE* studentsList;
	studentsList = fopen("zhurnal.txt", "r");

	if (!studentsList) {
		printf("\nError! Incorrect file name\n\n");
		return *pHead;
	}

	char date[20];
	char marks[20];
	char* iterates;
	char* iterates2;
	char* stopSymbs = "/*-+!@#$%^&*()_+~`:?><";

	struct SList* p = (struct SList*)malloc(sizeof(struct SList));

	for (int i = 0; i < countOfStudents; i++) {
		int l = 0, o = 0, j = 0, k = 0, b = 0, v = 0;
		fscanf(studentsList, "%s", p->students.surname);
		fscanf(studentsList, "%s", p->students.name);
		fscanf(studentsList, "%s", date);

		while (date[j] != '\0') {
			while (stopSymbs[l] != '\0') {
				if (date[j] == stopSymbs[l] && stopSymbs[l] != '.') {
					printf("\nError. Student's birthday contains wrong char\n\n");
					return *pHead;
				}
				++l;
			}
			++j;
			l = 0;
		}

		if (j > 10) {
			printf("\nError. Date contains more than 10 symbs\n");
			return *pHead;
		}
		else if (j < 10) {
			printf("\nError. Date contains less then 10 symbs\n\n");
			return *pHead;
		}

		iterates = strtok(date, ".");

		p->students.birth.day = atoi(iterates);
		if (p->students.birth.day < 1 || p->students.birth.day > 31) {
			printf("\n\nIncorrect day of birth\n\n");
			return *pHead;
		}
		iterates = strtok(NULL, ".");
		p->students.birth.month = atoi(iterates);
		if (p->students.birth.month < 1 || p->students.birth.month > 12) {
			printf("\n\nIncorrect month of birth\n\n");
			return *pHead;
		}
		iterates = strtok(NULL, ".");
		p->students.birth.year = atoi(iterates);
		if (p->students.birth.year < 1 || p->students.birth.year > 2023) {
			printf("\n\nIncorrect year of birth\n\n");
			return *pHead;
		}

		fscanf(studentsList, "%s", marks);

		while (marks[b] != '\0') {
			v = marks[b];
			if ((v < 49 || v > 53) && v != 46) {
				printf("\nError. Student's mark contains wrong char\n\n");
				return *pHead;
			}
			++b;
		}

		if (b < 9) {
			printf("\nError. Student's mark field is filled incorrect\n\n");
			return *pHead;
		}


		iterates2 = strtok(marks, ".");
		for (int j = 0; j < countOfMarks; j++) {
			p->students.mark.marks[j] = atoi(iterates2);
			iterates2 = strtok(NULL, ".");
			if (p->students.mark.marks[j] < 1 || p->students.mark.marks[j] > 5) {
				printf("\nError. Incorrect student's mark. Check your list\n\n");
				return *pHead;
			}
		}

		while (p->students.surname[o] != '\0') {
			while (stopSymbs[l] != '\0') {
				if (p->students.surname[o] == stopSymbs[l]) {
					printf("Error. Student's surname contains wrong char\n\n");
					return *pHead;
				}
				++l;
			}
			++o;
			l = 0;
			if (o > 30) {
				printf("\nError. Surname contains more than 30 symbs\n\n");
				return *pHead;
			}
		}
	while (p->students.name[k] != '\0') {
		while (stopSymbs[l] != '\0') {
			if (p->students.name[k] == stopSymbs[l]) {
				printf("\nError. Student's name contains wrong char\n\n");
				return *pHead;
			}
			++l;
		}
		++k;
		l = 0;
		if (k > 30) {
			printf("\nError. Student's name contains more than 30 symbs\n\n");
			return *pHead;
		}
	}

	if (p->students.birth.day < 1 || p->students.birth.day > 31) {
		printf("Error. Student's birth day contains wrong number\n\n");
		return *pHead;
	}


	if (p->students.birth.month < 1 || p->students.birth.month > 12) {
		printf("Error. Student's birth month contains wrong number\n\n");
		return *pHead;
	}

	if (p->students.birth.year < 1 || p->students.birth.year > 2023) {
		printf("Error. Student's birth year contains wrong number\n\n");
		return *pHead;
	}



		p->next = NULL;

		if (!*pHead) {
			(*pHead) = p;
		}

		struct SList* pp = (struct SList*)malloc(sizeof(struct SList));
		p->next = pp;

		if (i < countOfStudents - 1) {

			p = pp;
		}
	}
	p->next = NULL;
	fclose(studentsList);

	return (*pHead);

}

//---------------------------------------------------------------------------
//Функція для виведення списку студентів на екран

void printList(struct SList* pHead) {

	struct SList* pElem = pHead;
	sheet();

	for (int i = 0; i < countOfStudent(pHead); i++) {
		if (pElem != NULL) {
			printf("\n|%-15s | %-15s |%-2d %-2d %-4d|", pElem->students.surname, pElem->students.name, pElem->students.birth.day, pElem->students.birth.month, pElem->students.birth.year);
			for (int j = 0; j < countOfMarks; j++) {
				printf("%d ", pElem->students.mark.marks[j]);
			}
			printf("|\n");
			pElem = pElem->next;
			sheet();
		}
	}


	printf("\n");
}

//---------------------------------------------------------------------------
//Функція для сортування списку в алфавітному порядку (за прізвищем)

void sortList(struct SList* pHead) {
	int counter = (countOfStudent(pHead) - 1);
	struct SList* temp = pHead;

	for (int i = 0; i < counter; i++) {
		for (int j = 0; j < counter; j++) {
			if ((strcmp(pHead->students.surname, pHead->next->students.surname)) > 0) {
				swap(&pHead, &(pHead->next));
			}
			pHead = pHead->next;
		}
		pHead = temp;
	}

}

//---------------------------------------------------------------------------
//Функція для побудови таблиці

void sheet() {
	for (int i = 0; i < 58; i++) {
		printf("=");
	}
}

//---------------------------------------------------------------------------
//Функція для підрахунку кількості студентів

int countOfStudent(struct SList* pHead) {
	int counter = 0;

	while (pHead != NULL) {
		pHead = pHead->next;
		counter++;
	}

	return counter;
}

//---------------------------------------------------------------------------
//Функція swap для сортування списку (викликається у функції sortList)

void swap(struct SList** a, struct SList** b) {

	struct SInfo temp;

	temp = (*b)->students;
	(*b)->students = (*a)->students;
	(*a)->students = temp;
}

//---------------------------------------------------------------------------
//Функція для видалення студентів зі списку, які не народилися восени

struct SList* ifAutumn(struct SList** pHead) {
	struct SList* pbefore = NULL;
	struct SList* p = (*pHead);
	struct SList* pnext = NULL;

	while (p) {
		if (p->students.birth.month < 9 || p->students.birth.month > 11) {
			if (pbefore) {
				pbefore->next = p->next;
			}
			else {
				(*pHead) = p->next;
			}
			pnext = p->next;
			free(p);
			p = pnext;
		}
		else {
			pbefore = p;
			p = p->next;
		}
	}

	if ((*pHead) == NULL) {
		free(*pHead);
		*pHead = NULL;
	}

	return (*pHead);
}



//---------------------------------------------------------------------------
//Функція для додавання нового студента

struct SList* addNewSt(struct SList** pHead) {
		struct SList* pBefore = (*pHead), * pBefBef = (*pHead), * tmp = (*pHead), *newElem = (struct SList*)malloc(sizeof(struct SList));
		printf("Enter surname and name: ");
		scanf("%s %s", newElem->students.surname, newElem->students.name);

		printf("Enter birthbay date: ");
		scanf("%d %d %d", &(newElem->students.birth.day), &(newElem->students.birth.month), &(newElem->students.birth.year));

		printf("Enter marks: \n");
		for (int i = 0; i < countOfMarks; i++) {
			scanf("%d", &(newElem->students.mark.marks[i]));
		}

		while (pBefore != newElem) {
			if ((strcmp((tmp)->students.surname, (newElem)->students.surname)) > 0 && pBefore == (*pHead)) {

				newElem->next = pBefore;
				(*pHead) = newElem;
				break;
			}
			else if ((strcmp((tmp)->students.surname, (newElem)->students.surname)) > 0 && pBefore != (*pHead)) {

				newElem->next = pBefore;
				pBefBef->next = newElem;
				break;
			}
			else if ((strcmp((tmp)->students.surname, (newElem)->students.surname)) < 0 && pBefore->next == NULL) {

				pBefore->next = newElem;
				newElem->next = NULL;
				break;
			}
			pBefBef = pBefore;
			pBefore = pBefore->next;
			tmp = tmp->next;

		}
	return (*pHead);

}

//---------------------------------------------------------------------------
//Функція для видалення студента з оцінками 2,3,4,5

struct SList* deleteWithoutOne(struct SList** pHead) {
	struct SList* pbefore = NULL;
	struct SList* p = (*pHead);
	struct SList* pnext = NULL;

	while (p) {
		if ((p->students.mark.marks[0] == 2 && p->students.mark.marks[1] == 3 &&
			p->students.mark.marks[2] == 4 && p->students.mark.marks[3] == 5) ||
			(p->students.mark.marks[1] == 2 && p->students.mark.marks[2] == 3 &&
				p->students.mark.marks[3] == 4 && p->students.mark.marks[4] == 5)) {
			if (pbefore) {
				pbefore->next = p->next;
			}
			else {
				(*pHead) = p->next;
			}
			pnext = p->next;
			free(p);
			p = pnext;
		}
		else {
			pbefore = p;
			p = p->next;
		}
	}

	if ((*pHead) == NULL) {
		free(*pHead);
		*pHead = NULL;
	}

	return (*pHead);
}


//---------------------------------------------------------------------------
//Функція для звільнення пам'яті

void freemem(struct SList* pHead) {

	for (int i = 0; i < countOfStudent(pHead); i++) {
		struct SList* pTemp = pHead;
		pHead = pHead->next;
		free(pTemp);
	}
}