#include "functions.h"

int main() {
	struct SList* pHead = NULL;
	char choice;
	int countOfStudents;
	printf("Enter count of students in your file: ");
	scanf("%d", &countOfStudents);

	pHead = createList(&pHead, countOfStudents);
	printf("Input list\n");
	printList(pHead);

	printf("\n");

	sortList(pHead);
	printf("Sorted list\n");
	printList(pHead);

	printf("\n");

	printf("\n\n");

	printf("Autumn-sorted\n");
	pHead = ifAutumn(&pHead);
		if (pHead == NULL) {
			printList(pHead);
			freemem(pHead);
		return 0;
	}
	printList(pHead);

	printf("\nYour list with deleted students\n");
	deleteWithoutOne(&pHead);
	printList(pHead);

	printf("\n\n");

	printf("Do you want to add a new student? (+ = yes, - = no) ");
	getchar();
	scanf("%c", &choice);
	getchar();

	if (choice == '+') {
		do {
			pHead = addNewSt(&pHead);
			printf("Do you want to add a new student again? ");
			getchar();
			scanf("%c", &choice);
		} while (choice == '+');
	}

	if (choice == '-') {
		printf("\n");
		printf("Your list:\n");
		printList(pHead);
	}
	else {
		printf("Incorrect option! Try again!");
	}

	freemem(pHead);
	return 0;
}
