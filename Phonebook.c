/* Program: This is a simple project in c which implements the use of functions,
file handling and data structures using methods to add, list, modify, edit, search
and delete data to and from a file
Author: Mohammed Kadiri
Date: 01/03/2018
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Function prototype to display the main menu
void menu();
//Function prototype to call the menu function
void start();
//Function prototype this function is used to return to the start function
void back();
//Function prototype this function is used to add a new record to the phone book
void add_record();
//Function prototype this function is used to display the list of records in the phone book
void list_record();
//Function prototype to search records in the phone book
void search_record();
//Function prototype to modify records in the phone book
void modify_record();
//Function prototype to delete records in the phone book
void delete_record();
//Function prototype to check if the user entered a word
int word_check(char word[]);
//Function prototype
void got(char *name);


//use typedef to create my own string
typedef char string;


//Structure for the personal information
struct person
{
    string name[36];
    string address[50];
    string father_name[35];
    string mother_name[30];
    long int phone_number;
    string gender[15];
    string email[100];
    string citizen_number[20];

};

//Start of the main function
int main()
{
    //Change the background to light-yellow and the text to black
    system("COLOR E0");
    //Invoke the start function
    start();


    getch();
    return 0;
}//End of the main function

//Display the menu to the console
void menu()
{
    printf("\t\t\t\t\t\t\t\t\tYELLOW PAGES");
    printf("\n\t\t\t\t---------------------------"
           "-------------------------------------------------------");
    printf("\n\n\t\t\t\t\t\t\t\t\tMenu");
    printf("\n\n\t\t\t\t1.Add New\t\t\t\t2.List\t\t\t\t3.Exit"
           "\n\n\t\t\t\t4.Modify\t\t\t\t5.Search\t\t\t6.Delete\n\n");

//Switch cases which waits to get input from the user
    switch(getch())
    {
        case '1': add_record();
                 break;
        case '2': list_record();
                  break;
        case '3': exit(0);
                  break;
        case '4': modify_record();
                  break;
        case '5': search_record();
                  break;
        case '6': delete_record();
                  break;
        default:
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();
    }
}

//Function to call the menu function
void start()
{
    menu();
}

//Function to return to the start function
void back()
{
    start();
}

//Function to add a new record to the phone book
void add_record()
{
    system("cls");
    struct person p;
    FILE *fp;

    //Test if file is equal to NULL
    if((fp = fopen("project", "ab+")) == NULL)
    {
        printf("Error failed to include p into file");
    }
    else
    {
        //Get name
        printf("Enter name: ");
        got(p.name);
        //Check each character to check if the word is a name
            while(word_check(p.name) == 1)
            {
                printf("\nSorry this is not a name.");
                printf("\nPlease enter a name: ");
                got(p.name);
                word_check(p.name);
            }
        //Get address
        printf("\nEnter Address: ");
        got(p.address);
        //Get Father's name
        printf("\nEnter father name: ");
        got(p.father_name);
        //Check each character to check if the word is a name
            while(word_check(p.father_name) == 1)
            {
                printf("\nSorry this is not a name.");
                printf("\nPlease enter a name: ");
                got(p.father_name);
                word_check(p.father_name);
            }
        //Get mothers name
        printf("\nEnter mother name: ");
        got(p.mother_name);
           //Check each character to check if the word is a name
            while(word_check(p.mother_name) == 1)
            {
                printf("\nSorry this is not a name.");
                printf("\nPlease enter a name: ");
                got(p.mother_name);
                word_check(p.mother_name);
            }
        //Get phone number
        printf("\nEnter Phone no. : ");
        scanf("%ld",&p.phone_number);
        fflush(stdin);
        //Get the sex
        printf("\nEnter sex: ");
        got(p.gender);
        //Check each character to check if the word is a name
            while(word_check(p.gender) == 1)
            {
                printf("\nSorry this is not a gender");
                printf("\nPlease enter a gender: ");
                got(p.gender);
                word_check(p.gender);
            }
        //Get email
        printf("\nEnter e-mail: ");
        got(p.email);
        //Get citizen number
        printf("\nEnter citizen no: ");
        got(p.citizen_number);
        fwrite(&p,sizeof(p),1,fp);
        fflush(stdin);

        printf("\nrecord saved\n");

        fclose(fp);
        printf("Enter any key");
        getch();
        system("cls");
        menu();
    }

}
//Function to display a list of records of ps
void list_record()
{
    struct person p;
    FILE *fp;

    //Open the file for reading in binary
    if((fp = fopen("project","rb")) == NULL)
    {
        printf("Error opening file for listings");
        exit(1);
    }
    else
    {
        //Loop to read the file project and display user profile
        while((fread(&p,sizeof(p),1,fp)== 1))
        {
            printf("\n\nRECORD");
            printf("\nName=%s\nAdress=%s\nFather name=%s\nMother name=%s\
                   \nMobile no=%ld\nSex=%s\nE-mail=%s\nCitizen no=%s"
                   ,p.name,p.address,p.father_name,p.mother_name,
                   p.phone_number,p.gender,p.email,p.citizen_number);

            getch();
            system("cls");
        }

        fclose(fp);
        printf("\n Enter any key");
        getch();
        system("cls");
        menu();
    }
}
//Function to search for the users record
void search_record()
{
    struct person p;
    FILE *fp;
    char check_name[100];

    //Open file project for reading in binary
    if( (fp = fopen("project", "rb")) == NULL)
    {
        printf("Error opening file for searching");
    }
    printf("Enter name of person to search: ");
    got(check_name);
    //Loop to read file and display users record
    while(fread(&p,sizeof(p),1,fp)== 1)
    {
        if (strcmp(p.name,check_name)==0)
        {
            printf("\n\tDetail Information About %s",check_name);
            printf("\nName=%s\nAdress=%s\nFather name=%s\nMother name=%s\
               \nMobile no=%ld\nSex=%s\nE-mail=%s\nCitizen no=%s"
               ,p.name,p.address,p.father_name,p.mother_name,
               p.phone_number,p.gender,p.email,p.citizen_number);
        }
    }
    fclose(fp);
    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}
//Function to change user's record
void modify_record()
{
    char check_name[26];
    FILE *fp;

    struct person p, n;
    int flag = 0;

    //Open the project file for both reading and updating using binary
    if( (fp = fopen("project", "rb+")) == NULL)
    {
        printf("profile does not exist yet");
        exit(1);
    }
    else
    {
      system("cls");
      printf("\n Enter profile name to modify : ");
      got(check_name);
      //Loop to read file and display and change users record
        while(fread(&p,sizeof(p),1,fp)==1)
        {
            if(strcmp(p.name,check_name)==0)
            {
                    printf("\nEnter name: ");
                    got(n.name);
                    printf("\nEnter Address: ");
                    got(n.address);
                    printf("\nEnter father name: ");
                    got(n.father_name);
                    printf("\nEnter mother name: ");
                    got(n.mother_name);
                    printf("\nEnter Phone no. : ");
                    scanf("%ld",&n.phone_number);
                    printf("\nEnter sex: ");
                    got(n.gender);
                    printf("\nEnter e-mail: ");
                    got(n.email);
                    printf("\nEnter citizen no: ");
                    got(n.citizen_number);
                    //Check in the file starting from the current position
                    fseek(fp,-sizeof(p),SEEK_CUR);
                    //Write to the file the new records
                    fwrite(&n,sizeof(p),1,fp);
                    flag=1;
                    break;
            }
            fflush(stdin);
        }
        if(flag==1)
        {
            printf("\n your data id modified");

        }
        else
        {
            printf(" \n data is not found");

        }
        fclose(fp);
    }
    printf("\n Enter any key");
    getch();
    system("cls");
	menu();

}
//This is a function used to delete all records
void delete_record()
{
    //Declaration of variables
    struct person p;
    FILE *fp_in, *fp_out;
    int flag = 0;
    string check_name[100];

    //Open the file for reading
    if ((fp_in = fopen("project","rb")) == NULL)
    {
        printf("p not included yet");
    }
    else
    {
        //Open a new file for writing and updating
        if( (fp_out = fopen("bin", "wb+")) == NULL )
        {
            printf("Errror in opening file");
        }
        else
        {
            printf("Enter profile name: ");
            got(check_name);
            //read the file to check if the users record exist
            while(fread(&p,sizeof(p),1,fp_in)==1)
            {
                if(strcmp(p.name,check_name)!=0)
                {
                    fwrite(&p,sizeof(p),1,fp_out);
                }
                if(strcmp(p.name,check_name)==0)
                {
                    flag = 1;
                }
            }
            fclose(fp_in);
            fclose(fp_out);
            if(flag!= 1)
            {
                printf("No profile record to delete");
                remove("bin.txt");
            }
            //Delete records by removing and renaming new files
            else
            {
                remove("project");
                rename("bin.txt","project");
                printf("\nRecord deleted successfully");
            }
        }
    }

    printf("\n Enter any key");
    getch();
    system("cls");
    menu();
}

//Function to check if the user enters a word
int word_check(char word[])
{
    int i = 0;
    int flag = 0;

    while(word[i] != '\0')
    {
        if(isdigit(word[i]) != 0)
        {
            flag = 1;
            break;
        }
        i++;
    }

    return flag;
}
//Function to get users word and store
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
