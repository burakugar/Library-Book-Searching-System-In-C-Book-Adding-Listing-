	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	typedef struct Book{ /* structure holds the information of the books */
		char *title;
		char *author;
		char *subject;
		int iden;
		int year;
	}Book;
	void addBook(Book* Books,int x,int i){ /* function that adds the books to the structure */
		Books[i].title= (char*) calloc(x,sizeof(char)); /* declaration of the char* in the struct */
		Books[i].author= (char*) calloc(x,sizeof(char));
		Books[i].subject= (char*) calloc(x,sizeof(char));
		printf("Please enter the book title\n");
		scanf(" %[^\n]%*c", Books[i].title);
		printf("Please enter the book author\n");
		//scanf("%s",Books[i].author);
		scanf(" %[^\n]%*c", Books[i].author);
		printf("Please enter the book subject\n");
		scanf(" %[^\n]%*c", Books[i].subject);
		printf("Please enter the book year\n");
		scanf("%d",&Books[i].year);
	}
	
	void listBook(Book* Books,int x,int i){  /* function that list the elements */
		int n,j,flag=0;
		char* title=(char*)calloc(x,sizeof(char)); /* dinamically declaring the char*'s */
		char* author=(char*)calloc(x,sizeof(char));
		char* subject=(char*)calloc(x,sizeof(char));
		int year;
		printf("SUBMENU\n");
		printf("1.Get by the Title\n"); /* getting the menu choise */
		printf("2.Get by the Author\n");
		printf("3.Get by the Subject\n");
		printf("4.Sorted list by year\n");
		printf("5.List All Books\n");
		printf("6.Exit Submenu\n");
		printf("Choose:");
		scanf("%d",&n);
		if(n==1){
			printf("Enter a book title:\n");
			scanf("%[^\n]%*c", title);
			for(j=0;j<i;j++){
				if(strcmp(title,Books[j].title)==0){ /* compare the titles with books */
					printf("Title: %s\n",Books[j].title);
					printf("Author: %s\n",Books[j].author);
					printf("Subject: %s\n",Books[j].subject);
					printf("Year: %d\n",Books[j].year);
					flag=1;
				}
			}
			
			if(flag=0){
				printf("Book is not found!"); /* if flag=0 means book is not found */
			}
		}
		else if(n==2){ 
			printf("Enter a book author:\n"); /* compare the author names with books */
			scanf("%[^\n]%*c", author);
			for(j=0;j<i;j++){
				if(strcmp(author,Books[j].author)==0){
					printf("Book Found!");
					printf("Title: %s\n",Books[j].title);
					printf("Author: %s\n",Books[j].author);
					printf("Subject: %s\n",Books[j].subject);
					printf("Year: %d\n",Books[j].year);
					flag=1;
				}
			}
			if(flag=0){
				printf("Book is not found!");
			}
		}
		else if(n==3){
			printf("Enter a book subject:\n");
			scanf("%[^\n]%*c", subject);	/* compare the subjects with books */
			for(j=0;j<i;j++){
				if(strcmp(subject,Books[j].subject)==0){
					printf("Book Found!");
					printf("Title: %s\n",Books[j].title);
					printf("Author: %s\n",Books[j].author);
					printf("Subject: %s\n",Books[j].subject);
					printf("Year: %d\n",Books[j].year);
					flag=1;
				}
			}
			if(flag=0){
				printf("Book is not found!");
			}
		}
		else if(n==4){
			printf("Enter a book year:\n"); /* compare the years with books */
			scanf("%d",&year);
			for(j=0;j<i;j++){
				if(year==Books[j].year){
					printf("Book Found!");
					printf("Title: %s\n",Books[j].title);
					printf("Author: %s\n",Books[j].author);
					printf("Subject: %s\n",Books[j].subject);
					printf("Year: %d\n",Books[j].year);
					flag=1;
				}
			}
			if(flag=0){
				printf("Book is not found!");
			}
		else if(n==5){ /* function that lists all the elements that user enters */
			for(j=0;j<i;j++){
					printf("Title's of %d'th book : %s\n",j,Books[j].title);
					printf("Author's of %d'th book :%s\n",j,Books[j].author);
					printf("Subject's of %d'th book : %s\n",j,Books[j].subject);
					printf("Year's of %d'th book :%d\n",j,Books[j].year);
				}
				}
			}
		else if(n==6){
			goto t; /* exitting */
			}
		t:;
		}
	
	void printMenu(Book* Books,int x){
		int n,k=10,z,i;
		for(i=0;i<k;i++){
		printf("MENU\n");/* printing the menu */
		printf("1.Add new books\n");
		printf("2.List Books \n");
		printf("3.Exit\n");
		printf("Choose:");
		scanf("%d",&n);
		if(n==1){
			addBook(Books,x,i);
		}
		else if(n==2){
			listBook(Books,x,i);
		}
		else if(n==3){
			exit(1);
			}
		if(n==k-1){
			printf("Do you want to continue yes: 1 no: 0\n");
			scanf("%d",&z); /* ask user to if they want to continue or not */
			if(z==1){
				k++;
				}
			}	
		}
	}
	int main(){
		int x=20;
		Book* Books= (Book*) calloc(x,sizeof(Book));  /* realloccing */
		Book* Books1= (Book*) calloc(x*2,sizeof(Book));
		Books=Books1;
		printMenu(Books,x);
		free(Books);
		return 0;
	}
