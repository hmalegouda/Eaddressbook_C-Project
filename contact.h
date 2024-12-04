#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

int createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
//void populateAddressBook(AddressBook* addressBook);
void Displaycontact(AddressBook *addressBook);
void editcontact(AddressBook *addressBook);
void deletecontact(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveAndExit(AddressBook *addressBook);

#endif
