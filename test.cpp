#define _CRT_SECURE_NO_WARNINGS
#define списка_нет 	\
			{printf("\n\x1b[1;4;34mСписка не существует. Создайте сначала список\n");\
			printf("\n\x1b[0m");\
			_getch();}\

#include <stdio.h>
#include <iostream>
#include <conio.h>

struct list {
	char value;
	struct list* next;
	struct list* previos;
};

int check_for_empty(struct list*);

int end_ptr(struct list*, struct list**);

void start(struct list** head) {
	while ((*head)->previos != NULL) {
		(*head) = (*head)->previos;
	}
}

int print(struct list* head, struct list* work) {
	struct list* helper = (struct list*)malloc(sizeof(struct list));
	if (helper == NULL) {
		printf("\x1b[1;4;34mNot memmory added.\n");
		printf("\x1b[0m");
		return 0;
	}
	if (head == NULL) {
		printf("\x1b[1;4;34mСписок пуст.\n");
		return 0;
	}

	helper = head;
	while (helper != NULL) {
		if (helper == work) {
			printf("\x1b[5;1;4;31m");
			printf("%c", helper->value);
			printf("\x1b[0m");
		}
		else printf("%c", helper->value);

		helper = helper->next;
	}
	printf("\n");
	return 1;
}

int print_previos(struct list* head, struct list** work) {
	struct list* helper = (struct list*)malloc(sizeof(struct list)), * hel = *work;
	if (helper == NULL) {
		printf("\x1b[1;4;34mNot memmory added.\n");
		printf("\x1b[0m");
		return 0;
	}
	if (head == NULL) {
		printf("\x1b[1;4;34mСписок пуст.\n");

		return 0;
	}
	end_ptr(head, work);
	helper = *work;
	*work = hel;
	while (helper != NULL) {
		if (helper == *work) {
			printf("\x1b[5;1;4;31m");
			printf("%c", helper->value);
			printf("\x1b[0m");
		}
		else printf("%c", helper->value);

		helper = helper->previos;
	}
	printf("\n");

	return 1;
}

struct list* added(struct list* head, struct list** work) {
	char element;
	if (head == NULL) {
		head = (struct list*)malloc(sizeof(struct list));
		if (head == NULL) {
			printf("\x1b[1;4;34mNot memmory added.\n");
			printf("\x1b[0m");
			return 0;
		}
		printf("Введите элемент: ");
		while (getchar() != '\n');
		scanf("%c", &element);

		head->value = element;
		head->next = NULL;
		head->previos = NULL;
		*work = head;

	}
	else if ((*work)->next == NULL) {
		struct list* helper = (struct list*)malloc(sizeof(struct list)), * workd = *work;
		if (helper == NULL) {
			printf("\x1b[1;4;34mNot memmory added.\n");
			printf("\x1b[0m");
			return 0;
		}
		printf("Введите элемент: ");
		while (getchar() != '\n');
		scanf("%c", &element);
		helper->next = workd->next;
		helper->previos = workd;

		workd->next = helper;
		helper->value = element;

	}
	else {
		struct list* helper = (struct list*)malloc(sizeof(struct list)), * workd = *work;
		if (helper == NULL) {
			printf("\x1b[1;4;34mNot memmory added.\n");
			printf("\x1b[0m");
			return 0;
		}
		printf("Введите элемент: ");
		while (getchar() != '\n');
		scanf("%c", &element);
		helper->next = workd->next;
		helper->previos = workd;
		(workd->next)->previos = helper;
		workd->next = helper;
		helper->value = element;


	}


	return head;
}

struct list* added_previos(struct list** head, struct list** work) {
	char element;
	if ((*head) == NULL) {
		*head = (struct list*)malloc(sizeof(struct list));
		if (*head == NULL) {
			printf("\x1b[1;4;34mNot memmory added.\n");
			printf("\x1b[0m");
			return 0;
		}
		printf("Введите элемент: ");
		while (getchar() != '\n');
		scanf("%c", &element);

		(*head)->value = element;
		(*head)->next = NULL;
		(*head)->previos = NULL;
		*work = *head;


	}
	else if ((*work)->previos == NULL) {
		struct list* helper = (struct list*)malloc(sizeof(struct list)), * workd = *work;
		if (helper == NULL) {
			printf("\x1b[1;4;34mNot memmory added.\n");
			printf("\x1b[0m");
			return 0;
		}
		printf("Введите элемент: ");
		while (getchar() != '\n');
		scanf("%c", &element);
		helper->previos = workd->previos;
		helper->next = workd;
		workd->previos = helper;
		helper->value = element;

	}
	else {
		struct list* helper = (struct list*)malloc(sizeof(struct list)), * workd = *work;
		if (helper == NULL) {
			printf("\x1b[1;4;34mNot memmory added.\n");
			printf("\x1b[0m");
			return 0;
		}
		printf("Введите элемент: ");
		while (getchar() != '\n');
		scanf("%c", &element);
		helper->previos = workd->previos;
		helper->next = workd;
		workd->previos->next = helper;
		workd->previos = helper;
		helper->value = element;
	}
	start(head);
	return *head;


}

int start_ptr(struct list* head, struct list** work) {
	if (check_for_empty(head)) {
		return 0;
	}
	while ((*work)->previos != NULL) {
		*work = (*work)->previos;
	}

}

int check_for_recent(struct list* head, struct list* work) {
	struct list* helper = head;
	if (check_for_empty(head)) {
		printf("\x1b[1;4;34mСписок пуст. Заполните сначала список\n");
		printf("\x1b[0m");
		return 0;
	}
	while (helper->next != NULL) {
		helper = helper->next;
	}
	if (helper == work) {
		return 1;
	}
	else return 0;
}

int check_for_start(struct list* head, struct list* work) {
	struct list* helper = head;
	if (check_for_empty(head)) {
		printf("\x1b[1;4;34mСписок пуст. Заполните сначала список\n");
		printf("\x1b[0m");
		return 0;
	}
	while (helper->previos != NULL) {
		helper = helper->previos;
	}
	if (helper == work) {
		return 1;
	}
	else return 0;
}

int mouve_ptr_next(struct list* head, struct list** work) {
	if (head == NULL) {
		return 0;
	}
	struct list* helper = *work;
	if (helper->next != NULL) {
		helper = helper->next;
	}
	else printf("\x1b[1;4;34mРабочий указатель в конце списка.\n");
	printf("\x1b[0m");
	*work = helper;

}

int mouve_ptr_previos(struct list* head, struct list** work) {
	if (head == NULL) {
		return 0;
	}
	struct list* helper = *work;
	if (helper->previos != NULL) {
		helper = helper->previos;
	}
	else printf("\x1b[1;4;34mРабочий указатель в начале списка.\n");
	printf("\x1b[0m");
	*work = helper;

}

char show_next_element(struct list* head, struct list* word) {
	if (word->next != NULL) {

		return word->next->value;
	}
	else {
		printf("\x1b[1;4;34mУказатель находится в конце списка");
		printf("\x1b[0m");
		return 0;
	}

}

char show_previos_element(struct list* head, struct list* word) {
	if (word->previos != NULL) {

		return word->previos->value;
	}
	else {
		printf("\x1b[1;4;34mУказатель находится в начале списка");
		printf("\x1b[0m");
		return 0;
	}

}

char delete_for_ptr(struct list* head, struct list** work) {
	char a;
	if (head == NULL) {
		printf("\x1b[1;4;34mСписок пуст.\n");
		printf("\x1b[0m");
		return NULL;
	}
	if ((*work)->next == NULL) {
		printf("\x1b[1;4;34mЭто последний элемент.\n");
		printf("\x1b[0m");
		return NULL;
	}
	struct list* helper;// = (struct list*)malloc(sizeof(struct list));
	helper = (*work)->next;
	(*work)->next = helper->next;
	a = helper->value;
	free(helper);
	return a;
}

char delete_previos_ptr(struct list** head, struct list** work) {
	char a;
	if (*head == NULL) {
		printf("\x1b[1;4;34mСписок пуст.\n");
		printf("\x1b[0m");
		return NULL;
	}
	if ((*work)->previos == NULL) {
		printf("\x1b[1;4;34mЭто первый элемент.\n");
		printf("\x1b[0m");
		return NULL;
	}
	if ((*work)->previos == *head) {
		free(*head);
		*head = *work;
		a = (*head)->value;
		return a;
	}
	else {
		struct list* helper;// = (struct list*)malloc(sizeof(struct list));
		helper = (*work)->previos;
		(*work)->previos = helper->previos;
		helper->previos->next = *work;//1 2 3
		a = helper->value;
		free(helper);
		return a;
	}
}

struct list* removeall(struct list* head)
{
	while (head != NULL)
	{
		struct list* p = head;
		head = head->next;
		free(p);
	}
	return NULL;
}

struct list* change_value_for_PTR(struct list* head, struct list** work) {
	struct list* helper;// =(struct list*)malloc(sizeof(struct list));
	char letter;
	if ((check_for_empty(head))) {
		printf("\x1b[1;4;34mСписок пуст.\n");
		printf("\x1b[0m");
		return NULL;

	}
	if (check_for_recent(head, *work)) {
		printf("\x1b[1;4;34mУказатель в конце.\n");
		printf("\x1b[0m");
		return NULL;
	}

	helper = (*work)->next;

	printf("Введите символ на который хотите заменить.\nсимбол: ");
	while (getchar() != '\n');
	scanf("%c", &letter);
	(helper->value) = letter;
	return head;
}

struct list* change_value_previos_PTR(struct list* head, struct list** work) {
	struct list* helper;// =(struct list*)malloc(sizeof(struct list));
	char letter;
	if ((check_for_empty(head))) {
		return NULL;
	}
	if (check_for_start(head, *work)) return NULL;

	helper = (*work)->previos;

	printf("Введите символ на который хотите заменить.\nсимбол: ");
	while (getchar() != '\n');
	scanf("%c", &letter);

	(helper->value) = letter;
	return head;
}


int main()
{
	bool flag = 1;
	struct list* lst = NULL, * work = NULL;
	setlocale(LC_ALL, "Russian");
	char c, c49, c50, c51;

	while (true)
	{
		printf("\t Меню:\n |1| Ввод списка\n |2| Переместить указатель\n |3| Добавить элемент \n |4| Удалить текущий элемент \n |5| Удaлить все и освободить память \n |6| Задача \n |7| Вывод списка в обратном порядке \n |8| Поменять m и n");
		char c = _getch();
		switch (c)
		{
		case 49://1
			printf("\nВвод списка:");
			printf("\n |1| С клавиатуры \n |2| Из файла");
			c49 = _getch();
			switch (c49)
			{
			case 49:
				break;
			case 50:
				break;
			default:
				printf("\nMisclick!");
				_getch();
				break;
			}
			break;
		case 50://2
			if (lst != NULL) {
				printf("\n |1| Переместить вперед \n |2| Переместить назад \n |3| Переместить в начало списка \n |4| Переместить в конец");
				c50 = _getch();
				switch (c50)
				{
				case 49:
					mouve_ptr_next(lst, &work);
					break;
				case 50:
					mouve_ptr_previos(lst, &work);
					break;
				case 51:
					start_ptr(lst, &work);
					break;
				case 52:
					end_ptr(lst, &work);
					break;
				default:
					break;
				}
			}
			else списка_нет
			break;
		case 51://3
			printf("\n|%c|", c);
			if (lst != NULL) {
				printf("\n |1| Добавить элемент в список после указателя \n |2| Добавить элемент в список перед указателем");
				c51 = _getch();
				switch (c51) {
				case 49:
					lst = added(lst, &work);
					break;
				case 50:
					lst = added_previos(&lst, &work);
					break;
				default:
					printf("\nMisclick!");
					_getch();
					break;
				}
			}
			else списка_нет
			break;
		case 52://4
			printf("\n|%c|", c);
			if (lst != NULL) {
				lst = removeall(lst); // |4|
				work = NULL;
			}
			else списка_нет
			break;
		case 53://5
			printf("\n|%c|", c);
			if (lst != NULL) {
				lst = removeall(lst);
				work = NULL;
			}
			else списка_нет
			break;
		case 54:
			printf("\n|%c|", c);
			if (lst != NULL) {
				lst = removeall(lst); // |6|
				work = NULL;
			}
			else списка_нет
			break;
		case 55:
			printf("\n|%c|", c);
			if (lst != NULL) {
				flag = 0;
				break;
			}
			else списка_нет
			break;
		case 56:
			printf("\n|%c|", c);
			if (lst != NULL) {
				lst = removeall(lst); // |8|
				work = NULL;
			}
			else списка_нет
			break;
		default:
			printf("\nMisclick!");
			_getch();
			break;
		}
		system("cls");
	}
}




int check_for_empty(struct list* head) {
	if (head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int end_ptr(struct list* head, struct list** work) {
	if (check_for_empty(head)) {
		return 0;
	}
	while ((*work)->next != NULL) {
		*work = (*work)->next;
	}
}