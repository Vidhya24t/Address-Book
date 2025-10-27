#include <stdio.h>
#include <string.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    //logic to sort
    for (int i = 0; i < addressBook->contactCount - 1; i++) 
    {
        for (int j = 0; j < addressBook->contactCount - i - 1; j++) 
        {
            if (strcasecmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0)
             {
                // Swap the contacts if they are in the wrong order
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
    FILE *fp;// file pointer initialization
    int i;
    fp = fopen("contact.csv","w");// open the file
    for(i=0;i<addressBook->contactCount;i++)// load the contacts to save it in the file
    {
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fp);//close file
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;// intialize count to zero
    FILE *fp;// file pointer
    fp = fopen("contact.csv", "r");// open required file
    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n", 
    
            addressBook->contacts[addressBook->contactCount].name,
            addressBook->contacts[addressBook->contactCount].phone,
            addressBook->contacts[addressBook->contactCount].email) == 3)// load contacts to the program
    {
        addressBook->contactCount++;// increment count
    }
    fclose(fp);   // close file 
}
