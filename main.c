#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>












typedef struct person
{
	char name[50];
	long long int number;
	int group;
	struct person* next;

} Person;

typedef struct phonebook
{
	char name[50];
	struct person * groups[4];
} Phonebook;

Phonebook my_phonebook;


Person * create_contact(); //DONE
void delete_contact(); //DONE
void view_contacts(int group_number); //DONE
bool ask_command(); //todo
void edit_contact(); //todo

int main(void)
{
	my_phonebook.groups[0] == NULL;
	strcpy(my_phonebook.name, "My phonebook");
	printf("Phonebook name: %s", my_phonebook.name);

	

	while(ask_command())
	{
		
	}


	return 0;
}

Person * create_contact()
{
	system("cls");
	bool valid_number = true;
	long long int temp_number;
	char temp_name[50];
	
	Person * new_person = malloc(sizeof(Person));
	if (new_person == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;  // Indicate failure
	}
	printf("\nContact Name: ");
	scanf("%s", temp_name);
	strncpy(new_person->name, temp_name, sizeof(new_person->name));
	new_person->name[sizeof(new_person->name) - 1] = '\0';
	printf("\nNumber: ");
	while (valid_number)
	{
		scanf("%lld", &temp_number);//USE LONG LONG INT FOR LARGE NUMBERS!
		if (temp_number < 10000000000 && temp_number > 100000000) //&& temp_number > 100000000
		{
			valid_number = false;
		}
		else
		{
			printf("\nType valid number: ");
			valid_number = true;
		}
		
	}
	new_person->number = temp_number;
	int temp_num = -1;

	printf("\nGroup number: 0-3\n");
	while (temp_num < 0 || temp_num > 3)
	{
		scanf("%d", &temp_num);
	}


	new_person->group = temp_num;

	new_person->next = my_phonebook.groups[new_person->group];
	my_phonebook.groups[new_person->group] = new_person;
	
	system("cls");


}

void delete_contact()
{
	system("cls");
	int group;
	char name[50];
	int position = 0;
	Person* ptr = my_phonebook.groups[0];
	Person* previous = NULL;

	if (ptr == NULL)
	{
		printf("Contacts empty!\n");
		return;
	}
	
	
	view_contacts(0);
	printf("Please enter the person you want to delete: \n");
	scanf("%s", name);


	
	
	while (strcmp(ptr->name, name) != 0)
	{
		previous = ptr;
		
		ptr = ptr->next;
		if (ptr == NULL)
		{
			printf("Could not find name.\n");
			return;
		}
		position++;
	}
	if (position == 0)
	{
		my_phonebook.groups[0] = ptr->next;
		free(ptr);
		ptr = NULL;
	}
	else
	{
		previous->next = ptr->next;
		free(ptr);
		ptr = NULL;
	}
	

	view_contacts(0);
	
	
	


}

void view_contacts(int group_number)
{
	system("cls");
	Person* temp;
	temp = my_phonebook.groups[group_number];
	printf("----- Contacts ------\n");
	while (temp != NULL)
	{
		printf("%s: %lld\n", temp->name, temp->number);
		
		temp = temp->next;
	}
	printf("---------------------\n");
}
		
bool ask_command()
{
	
	int answer;
	printf("Choose what you want to do: \n");
	printf("[1] View Contacts \n");
	printf("[2] Add Contact \n");
	printf("[3] Delete Contact \n");
	printf("[4] Quit \n");

	scanf("%d", &answer);

	switch (answer)
	{
	case 1:
		view_contacts(0);
		return true;
		break;
	case 2:
		create_contact();
		return true;
		break;
	case 3:
		delete_contact();
		return true;
		break;
	case 4:
		return false;
	default: 
		return true;
	}

}