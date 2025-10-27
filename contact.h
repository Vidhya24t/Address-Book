#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

//creating a contact structure
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

//creating array of contacts structure
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

//function declaration for creating contact
void createContact(AddressBook *addressBook);
//function declaration for searching the contact
void searchContact(AddressBook *addressBook);
//function declaration for edit the contact
void editContact(AddressBook *addressBook);
//function declaration for delete the contact
void deleteContact(AddressBook *addressBook);
//function declaration for list all the contact
void listContacts(AddressBook *addressBook);
//function declaration for initialize the contacts to structure
void initialize(AddressBook *addressBook);
//void saveContactsToFile(AddressBook *AddressBook);
void saveContactsToFile(AddressBook *AddressBook);

void loadContactsFromFile(AddressBook *addressBook);
#endif