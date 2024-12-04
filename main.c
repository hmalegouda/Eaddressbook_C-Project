#include <stdio.h>
#include "contact.h"

int main() 
{
   int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. list all contacts\n");
        printf("6. Save Contacts To File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                if(searchContact(&addressBook) != 1)
                    editcontact(&addressBook);
                break;
            case 4:
                searchContact(&addressBook);
                deletecontact(&addressBook);
                break;
            case 5:
                Displaycontact(&addressBook);
                break;
            case 6:
                saveAndExit(&addressBook);
                printf("successfully saved..\n");
                break;
            case 7:
                printf("Saving and Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}
