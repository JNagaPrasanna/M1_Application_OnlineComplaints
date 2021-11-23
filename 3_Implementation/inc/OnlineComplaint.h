#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct complaint
{
	char number[6];
	char name[15];
    char problem[15];
	int complaint_num;
	char local_address[15];
	struct complaint *following;
}
*begin, *stream;
struct complaint *dummy;


void main()
{
	void reserve(int x), cancel(), display(), savefile();
	int choice;
	begin = stream = NULL;
	int num = 1;
	do
	{

		printf("\n\n\t***********************");
		printf("\n\t                  ONLINE COMPLAINT                 ");
		printf("\n\t***********************");
		printf("\n\n\n\t\t Please enter your choice from below (1-4):");
		printf("\n\n\t\t 1. Complaint");
		printf("\n\n\t\t 2. Cancel");
		printf("\n\n\t\t 3. Records");
		printf("\n\n\t\t 4. EXIT");
		printf("\n\n\t\t Enter your choice :");



		scanf("%d", &choice); fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			cancel();
			break;
		case 3:
			display();
			break;
		case 4:
		{
				  savefile();
				  break;
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-4");
			printf("\n\n\t Do not forget to chose from 1-4");
		}
	} while (choice != 4);
}

void details()
{
	
	gets(stream->number); fflush(stdin);
	printf("\n\t Enter your name:");
	gets(stream->name); fflush(stdin);
	printf("\n\t Enter your Local address:");
	gets(stream->local_address); fflush(stdin);
    printf("\n\t Enter the Problem: ");
    gets(stream->problem); fflush(stdin);
}



void details();

void reserve(int x)
{
	stream = begin;
	if (begin == NULL)
	{
		// first user
		begin = stream = (struct complaint*)malloc(sizeof(struct complaint));
		details();
		stream->following = NULL;
		printf("\n\t Your Complaint Register successful!");
		printf("\n\t your Complaint number is: %d", x);
		stream->complaint_num = x;
		return;
	}
	else if (x > 15) 
	{
		printf("\n\t\t complaints Full.");
		return;
	}
	else
	{

		while (stream->following)
			stream = stream->following;
		stream->following = (struct complaint *)malloc(sizeof(struct complaint));
		stream = stream->following;
		details();
		stream->following = NULL;
		printf("\n\t Your Complaint Register succesful!");
		printf("\n\t your Complaint number is:  A-%d", x);
		stream->complaint_num = x;
		return;
	}
}


void savefile()
{
	FILE *fpointer = fopen("complaints_records", "w");
	if (!fpointer)
	{
		printf("\n Error in opening file!");
		return;
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-6s", stream->number);
		fprintf(fpointer, "%-15s", stream->name);
		fprintf(fpointer, "%-15s", stream->local_address);
        fprintf(fpointer, "%-15s", stream->problem);
        fprintf(fpointer, "\n");
		stream = stream->following;
	}
	printf("\n\n\t Details have been saved to a file");
	fclose(fpointer);
}


void display()
{
	stream = begin;
	while (stream)
	{
		printf("\n\n\t  Number : %-6s", stream->number);
		printf("\n         name : %-15s", stream->name);
		printf("\n      Local address: %-15s", stream->local_address);
		printf("\n      Complaint number: A-%d", stream->complaint_num);
        printf("\n     Problem:%-15s", stream->problem);
		printf("\n\n++=====================================================++");
		stream = stream->following;
	}

}


void cancel()
{
	stream = begin;
	
	char number[6];
	
	gets(number); fflush(stdin);
	if (strcmp(begin-->number,number) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf(" booking has been deleted");
		return;

	}

	while (stream->following)
	{
		if (strcmp(stream->following->number, number) == 0)
		{
			dummy = stream->following;
			stream->following = stream->following->following;
			free(dummy);
			printf("has been deleted ");
			return;
		}
		stream = stream->following;
	}
	

}
