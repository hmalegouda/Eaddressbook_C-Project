#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void Displaycontact(AddressBook *addressBook)
{
    int choise;
    printf("Enter choise...\n1. Contact names\n2. Phone numaber\n3. Email\n4. Total contact Table\n");
    scanf("%d",&choise);
    switch(choise)
    {
        case 1:
            printf("Contact Names..\n");
            for (int i = 0; i < addressBook->contactCount ; ++i) 
            {
                printf("%d\t%-20s\n",i+1,addressBook->contacts[i].name);
            }
            break;
        case 2:
            printf("Contact phone numbers..\n");
            for (int i = 0; i < addressBook->contactCount ; ++i) 
            {
                printf("%d\t%-20s\n",i+1,addressBook->contacts[i].phone);
            }
            break;
        case 3:
            printf("Contact Emails..\n");
            for (int i = 0; i < addressBook->contactCount ; ++i) 
            {
                printf("%d\t%-20s\n",i+1,addressBook->contacts[i].email);
            }
            break;
        case 4:
             printf("-------------------------------------------------------------------------------\n");
             printf("slno.\tName\t\t\tPh.no\t\t\tEmaili'd\n");
             printf("-------------------------------------------------------------------------------\n");
            for (int i = 0; i < addressBook->contactCount ; ++i) 
            {
                printf("%d.\t%-20s\t%-20s\t%-20s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
            printf("-------------------------------------------------------------------------------\n");
            break;
        default:
            printf("Enter the correct choise...");
            break;
    }
   
}
    

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
   // exit(EXIT_SUCCESS); // Exit the program
}


int createContact(AddressBook *addressBook) 
{
    /* Define the logic to create a Contacts */

    if(addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address book is full.\n");
        return 0;
    }
    
    Contact contactnew;
    int flag = 0,true=0,phoneflag=0,emailflag=0;
    printf("Enter the contact name: ");
    scanf(" %[^\n]", contactnew.name);
    for(int k=0;k<addressBook->contactCount;k++)
    {
        flag=0;
        for(int j=0;contactnew.name[j]!='\0';j++)
        {
            if(addressBook->contacts[k].name[j] == contactnew.name[j])
            {
                ++flag;
                true=0;
            }
        }
        if(strlen(contactnew.name) == flag)
        {
            true=1;
            break;
        }
    }
    if(true)
    {
        printf("'%s' already existed enter new name....\n",contactnew.name);
        return 1;
    }

    printf("Enter the 10 Digits phone number: ");
    scanf(" %s", contactnew.phone);

    if(strlen(contactnew.phone) == 10)
    {
        for(int k=0;k<addressBook->contactCount;k++)
        {
            flag=0;
            for(int j=0;contactnew.phone[j]!='\0';j++)
            {
                if(addressBook->contacts[k].phone[j] == contactnew.phone[j])
                {
                    ++flag;
                    true=0;
                }
            }
            if(strlen(contactnew.phone) == flag)
            {
                true=1;
                break;
            }
        }
        if(true)
        {
            printf("'%s' already existed enter new number....\n",contactnew.phone);
            return 1;
        }
        for(int i = 0; contactnew.phone[i] != '\0'; i++)
        {
            if(contactnew.phone[i] < '0' || contactnew.phone[i] > '9' || contactnew.phone[i] >= 'a' || contactnew.phone[i]>'A')
            {
                phoneflag = 1;
                break;
            }
        }
    }
    else
    {
        phoneflag = 1;
    }

    if(phoneflag == 1)
    {
        printf("You entered '%ld' digits. Please enter a valid number.\n", strlen(contactnew.phone));
        return 0;
    }

    printf("Enter the email id: ");

    scanf("%s", contactnew.email);
    
    if(strchr(contactnew.email, '@') == NULL || strchr(contactnew.email, '.') == NULL)
    {
        emailflag = 1;
    }

    if(emailflag)
    {
        printf("Please enter a valid email.\n");
        return 0;
    }
    for(int k=0;k<addressBook->contactCount;k++)
    {
        flag=0;
        for(int j=0;contactnew.email[j]!='\0';j++)
        {
            if(addressBook->contacts[k].email[j] == contactnew.email[j])
            {
                ++flag;
                true=0;
            }
        }
        if(strlen(contactnew.email) == flag)
        {
            true=1;
            break;
        }
    }
    if(true)
    {
        printf("'%s' already existed enter new Email....\n",contactnew.email);
        return 1;
    }
    addressBook->contacts[addressBook->contactCount++] = contactnew;
    printf("\nContact saved successfully...%dth slno..\n", addressBook->contactCount);
    return 1;
}

int searchContact(AddressBook *addressBook) 
{
    int choise,i,flag=0,A=1;
    char name[50];
    printf("\n\n1. Enter contact name\n2. Enter phone number\n3. Enter Email i'd\n\n");
    printf("Enter the choise:- ");
    scanf("%d",&choise);
    if(choise>3)
    {
        printf("Enter the correct choise...\n");
        return 1;
    }
    switch(choise)
    {
        case 1:
            printf("\nEnter the name : \n");
            scanf(" %[^\n]",name);
            printf("-------------------------------------------------------------------------------\n");
            printf("slno.\tName\t\t\tPh.no\t\t\tEmaili'd\n");
            printf("-------------------------------------------------------------------------------\n");
            for (i = 0; i < addressBook->contactCount ; ++i) 
            {
                int count=0;
                for(int j=0;name[j]!='\0';j++)
                {
                    if(name[j]==addressBook->contacts[i].name[j])
                    {
                        count++;
                    }
                }
                if(strlen(name)==count)
                {
                    printf("%d.\t%-20s\t%-20s\t%-20s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    A=0;
                }
            }
            printf("-------------------------------------------------------------------------------\n");
            if(A == 1)
            {
                printf("No contact found.......Enter valid\n");
                 printf("-------------------------------------------------------------------------------\n");
                return 1;
            }
            break;
        case 2:
            printf("\nEnter the phone number : \n");
            scanf(" %s",name);
            printf("-------------------------------------------------------------------------------\n");
            printf("slno.\tName\t\t\tPh.no\t\t\tEmaili'd\n");
            printf("-------------------------------------------------------------------------------\n");
            for (i = 0; i < addressBook->contactCount ; ++i) 
            {
                int count=0;
                for(int j=0;name[j]!='\0';j++)
                {
                    if(name[j]==addressBook->contacts[i].phone[j])
                    {
                        count++;
                    }
                }
                if(strlen(name)==count)
                {
                    printf("%d.\t%-20s\t%-20s\t%-20s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    A=0;
                }
            }
            printf("-------------------------------------------------------------------------------\n");
            if(A)
            {
                printf("No contact found.......Enter valid\n");
                 printf("-------------------------------------------------------------------------------\n");
                return 1;
            }
            break;
        case 3:
             printf("\nEnter the Email : \n");
            scanf(" %[^\n]",name);
            printf("-------------------------------------------------------------------------------\n");
            printf("slno.\tName\t\t\tPh.no\t\t\tEmaili'd\n");
            printf("-------------------------------------------------------------------------------\n");
            for (i = 0; i < addressBook->contactCount ; ++i) 
            {
                int count=0;
                for(int j=0;name[j]!='\0';j++)
                {
                    if(name[j]==addressBook->contacts[i].email[j])
                    {
                        count++;
                    }
                }
                if(strlen(name)==count)
                {
                    printf("%d.\t%-20s\t%-20s\t%-20s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    A=0;
                }
            }
            printf("-------------------------------------------------------------------------------\n");
            if(A)
            {
                printf("No contact found.......Enter valid\n");
                 printf("-------------------------------------------------------------------------------\n");
                return 1;
            }
            break;
    }
}


void editcontact(AddressBook *addressBook)
{
	    /* Define the logic for Editcontact */
    int slno,i,flag=0,choise;      
    char str[50];
    printf("\n\nEnter the serial number of contact : \n");

    scanf("%d",&slno);

    if(slno > addressBook->contactCount)
    {
        printf("Enter only the diplay contacts...\n");
        return;
    }
    slno=slno-1;
    printf("1. Edit contact name\n2. Edit phone number\n3. Edit Email i'd\n");
    printf("Enter the choise:- ");
    scanf("%d",&choise);
    switch(choise)
    {
        case 1:
            printf("Enter the New name : ");
            scanf(" %[^\n]",str);
            for(i=0;str[i]!='\0';i++)
            {
                addressBook->contacts[slno].name[i]=str[i];
            }
            addressBook->contacts[slno].name[i]='\0';
            printf("Updated successfully......\n");
            break;
        case 2:
            printf("Enter the New phone number : ");
            scanf("%s",str);
            if(strlen(str) == 10)
            {
                for(int i = 0; str[i] != '\0'; i++)
                {
                    if(str[i] < '0' || str[i] > '9')
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else
            {
                flag = 1;
            }

            if(flag == 1)
            {
                printf("You entered '%ld' digits. Please enter a valid number.\n", strlen(str));
                break;
            }

            for(i=0;str[i]!='\0';i++)
            {
                addressBook->contacts[slno].phone[i]=str[i];
            }
            addressBook->contacts[slno].phone[i]='\0';
            printf("Updated successfully......\n");
            break;
        case 3:
            printf("Enter the New Email : ");
            scanf("%s",str);
            if (strchr(str, '@') == NULL || strstr(str, ".com") == NULL)
            {
                flag = 1;
            }
            if (flag == 1) 
            {
                printf("\n..Please enter a valid email..\n");
                break;;
            }
            for(int i=0;str[i]!='\0';i++)
            {
                addressBook->contacts[slno].email[i]=str[i];
            }
            addressBook->contacts[slno].email[i]='\0';
            printf("Updated successfully......\n");
            break;
        default :
            printf("Enter the correct choise..\n");
            break;
    }
    
}

void deletecontact(AddressBook *addressBook)
{
	    /* Define the logic for deletecontact */
    int i,j,A,flag,true;
    char search[30];
    printf("Enter the serial number : ");
    scanf("%d",&i);
    i=i-1;
    if(i <= addressBook->contactCount)
    {
        for(int j=i;j<addressBook->contactCount;j++)
        {
            addressBook->contacts[(j)]=addressBook->contacts[j+1];
        }
        addressBook->contactCount--;
        printf("Successfully deleted....\n");
    }
    else
        printf("You enter exceed serial number...\n");     
}
