#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    loadContactsFromFile(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        
        switch (choice) 
		{
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                listContacts(&addressBook);
                break;
            case 6:
                saveContactsToFile(&addressBook);
                printf("Saving and Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
       return 0;
}


/*
✅ Why use a pointer in the first place?
Because in C, when you pass a struct to a function:

If you pass it by value (like AddressBook addressBook), you're passing a copy — changes won’t affect the original.

If you pass it by pointer (like AddressBook *addressBook), you're passing a reference to the original — changes made inside the function affect the original object.

✳️ Side-by-side Example:
c
Copy
Edit
// Non-pointer version (copy)
void clearAddressBook(AddressBook addressBook) {
    addressBook.contactCount = 0; // changes only the copy
}

// Pointer version (reference)
void clearAddressBookPtr(AddressBook *addressBook) {
    addressBook->contactCount = 0; // changes the original
}
🧠 Rule of Thumb:
Use . when working with a struct variable.

Use -> when working with a pointer to a struct.

Functions that modify the struct (like loading from a file) typically take a pointer, so changes persist outside the function.

Let me know if you’d like help writing both versions of the function — one that takes a struct directly and one that takes a pointer!



You said:
can we use without * in this function

ChatGPT said:
Great question! Let's tackle it head-on:

🧩 Can we use the function without * (pointer) in this case?
Yes, technically, you can rewrite the function to not use a pointer, like this:

❌ Non-pointer version:
c
Copy
Edit
void loadContactsFromFile(AddressBook addressBook)
{
    addressBook.contactCount = 0;

    FILE *fp = fopen("contact.csv", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }

    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n",
                  addressBook.contacts[addressBook.contactCount].name,
                  addressBook.contacts[addressBook.contactCount].phone,
                  addressBook.contacts[addressBook.contactCount].email) == 3)
    {
        addressBook.contactCount++;
    }

    fclose(fp);
}
But here's the problem:

⚠️ Problem: This won’t modify the original AddressBook
When you pass a struct by value in C (like above), a copy is made. Any changes to addressBook inside the function (like filling contacts) will be lost after the function ends.

✅ So the original AddressBook in main() or wherever you called the function stays unchanged.
✅ Correct version — with pointer
c
Copy
Edit
void loadContactsFromFile(AddressBook *addressBook)
This lets you modify the original struct.

You pass the address: loadContactsFromFile(&myAddressBook);

And inside the function, you use -> to access fields.

🔁 Summary:
Function Type	Modifies original?	Syntax inside function	How to call it
void f(AddressBook ab)	❌ No (copy only)	ab.contactCount	f(myAddressBook);
void f(AddressBook *ab)	✅ Yes (modifies)	ab->contactCount	f(&myAddressBook);
*/