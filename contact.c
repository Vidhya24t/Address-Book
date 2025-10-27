/*Name-Vidhya
description-WAP the address book to save the contacts
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

//create contact
int validate_name(AddressBook *addressBook,char *name)
{
    //step1:fetch one by one character till null character
     for(int i=0;name[i]!='\0';i++)
    {
        if(!(isalpha(name[i])) && name[i]!=' ') // Ensure the character is either an alphabet or a space
          {
            return 1;
          }
    }
   return 0; 

}
int validate_phone(AddressBook *addressBook,char *phoneno)
{
   
   int length = strlen(phoneno); // Get the length of the phone number
    if (length != 10) 
    {
        printf("Invalid phone number: Phone number must be exactly 10 digits long.\n");
        return 1;
    }
    // Check that all characters are digits
    for (int i = 0; i < length; i++) 
        {
         if (phoneno[i] < '0' || phoneno[i] > '9')
             {
                printf("Invalid phone number: Phone number must contain only digits.\n");
                return 1;
             }
        }
        // Check if the phone number already exists in the address book
         for(int i = 0; i < addressBook->contactCount; i++) 
     {
        if (strcmp(addressBook->contacts[i].phone, phoneno) == 0)
         {
            printf("Phone number already exists in the address book \n");
            return 1;
         }
     }

    return 0; 
}
   // Function to validate the email address
    int validate_email(AddressBook *addressBook,char *emailid)
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].email,emailid) == 0)
        {
        printf("Email Id already exists in contacts\n");
        return 1;
        }
    }
    // Validate the format of the email
    if(!strstr(emailid,"@") || !strstr(emailid,".com") )
    {
        printf("Invalid Email address,Please try again.\n");
        return 1;
    }
    return 0;
}

void createContact(AddressBook *addressBook)
{
    char name1[30];
    //Step1:read a name from user
    printf("Enter the name:");
   // __fpurge(stdin);
   //gtchar();
    scanf(" %[^\n]",name1);
    //validate the name->alphabets and space
   while(validate_name(addressBook,name1)==1)
 {
    printf("INFO:Name validation not done,please enter valid name...\n");
    printf("Enter the name:");
    scanf(" %[^\n]",name1);
 }
    char phoneno[20];
    printf("Enter the number:\n");
    scanf(" %[^\n]",phoneno);
  // Validate the phone number
    while(validate_phone(addressBook,phoneno)==1)
 {
    printf("INFO:Number validation not done,please enter valid phone...\n");
    printf("Enter the phone:\n");
    scanf(" %[^\n]",phoneno);
 }
 char emailid[30];
    printf("Enter the email id:\n");
    scanf(" %[^\n]",emailid);
  // Validate the email
    while(validate_email(addressBook,emailid)==1)
 {
    printf("INFO:Email validation not done,please enter valid email...\n");
    printf("Enter the email:\n");
    scanf(" %[^\n]",emailid);
 }
 // Check if the address book is full
   if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }
    strcpy(addressBook->contacts[addressBook->contactCount].name, name1);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phoneno);
    strcpy(addressBook->contacts[addressBook->contactCount].email, emailid);
    addressBook->contactCount++;
}




//search contact
// Function to search for a contact by phone number
int name2_display1(AddressBook *addressBook)
{
    char name2[30];
    int flag=0;
    printf("Enter the search name:");
       scanf(" %[^\n]",name2);
       // Iterate through contacts to find a match
       for(int i=0;i<addressBook->contactCount;i++)
       {
        if((strcasestr(addressBook->contacts[i].name,name2)!=NULL))
        {
            printf("contact found\n");
            printf("Name:%s\n ",addressBook->contacts[i].name);
            printf("Phone:%s\n ",addressBook->contacts[i].phone);
            printf("Email:%s\n ",addressBook->contacts[i].email);
            flag=1;// Contact found
        }
       }
       if(flag==0)
       {
        printf("Contacts Details not found\n");
        return -1;// Contact not found
       }
}
// Function to search for a contact by phone number
int phone2_display2(AddressBook *addressBook)
{
    char phone2[30];
    int flag=0;
    printf("Enter the search number:");
       scanf(" %[^\n]",phone2);
       for(int i=0;i<addressBook->contactCount;i++)
       {
         // Iterate through contacts to find a match
        if(strcmp(addressBook->contacts[i].phone,phone2)==0)
        {
            printf("contact found\n");
            printf("Name:%s\n ",addressBook->contacts[i].name);
            printf("Phone:%s\n ",addressBook->contacts[i].phone);
            printf("Email:%s\n",addressBook->contacts[i].email);
            flag=1;// Contact found
        }
       }
       if(flag==0)
       {
        printf("Contacts Details not found\n");
        return -1;// Contact not found
       }
}
// Function to search for a contact by Email
int email2_display3(AddressBook *addressBook)
{
    char email2[30];
    int flag=0;
    printf("Enter the search mail:");
       scanf(" %[^\n]",email2);
       for(int i=0;i<addressBook->contactCount;i++)
       {
         // Iterate through contacts to find a match
        if(strcmp(addressBook->contacts[i].email,email2)==0)
        {
            printf("contact found\n");
            printf("Name:%s\n ",addressBook->contacts[i].name);
            printf("Phone:%s\n ",addressBook->contacts[i].phone);
            printf("Email:%s\n ",addressBook->contacts[i].email);
            flag=1;// Contact found
        }
       }
       if(flag==0)
       {
        printf("Contacts Details not found\n");
        return -1;// Contact not found
       }
}



//Edit contact
// Function to edit a contact's name
void name_edit1(AddressBook *addressBook)
{
    char old_name[20];
    char new_name[20];
    printf("Enter the old name to be searched:");
    scanf(" %[^\n]",old_name);
    // Find the contact by old name
    for(int i=0;i<addressBook->contactCount;i++)
    {
      if(strcmp(addressBook->contacts[i].name,old_name)==0)
      {
     // Validate the new name
       printf("Enter the new name :");
       scanf(" %[^\n]",new_name);
          while(validate_name(addressBook,new_name)==1)
          {
        printf("Enter the valid new number:\n");
        scanf(" %[^\n]",new_name);   
          }
    strcpy(addressBook->contacts[i].name,new_name);
    printf("Name %s edited successfully.\n",new_name);
   return;
    }
   } 
   printf("old name not found.\n");
}

// Function to edit a contact's phone number
void phone_edit2(AddressBook *addressBook)
{
  char old_number[20];
    char new_number[20];
    printf("Enter the old number to be searched:");
    scanf(" %[^\n]",old_number);
    // Find the contact by old number
    for(int i=0;i<addressBook->contactCount;i++)
    {
       if(strcmp(addressBook->contacts[i].phone,old_number)==0)
       {
         printf("Enter the new number :");
         scanf(" %[^\n]",new_number);
         while(validate_phone(addressBook,new_number)==1)
          {
        printf("Enter the valid new number:\n");
        scanf(" %[^\n]",new_number);   
          }
           
    strcpy(addressBook->contacts[i].phone,new_number) ;
    printf("number %s edited successfully.\n",new_number);
       
      return;// Exit the function
       }
    }
     printf("old number not found.\n"); 
}
// Function to edit a contact by email
void email_edit3(AddressBook *addressBook)
{
   char old_email[20];
    char new_email[20];
    printf("Enter the old email to be searched:");
    scanf(" %[^\n]",old_email);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].email,old_email)==0)
       {
         printf("Enter the new email: ");
         scanf(" %[^\n]",new_email);
         while(validate_email(addressBook,new_email)==1)
         {
            printf("Enter the valid Email ID : ");
            scanf(" %[^\n]",new_email);
         }
          strcpy(addressBook->contacts[i].email,new_email) ;
          printf("Email %s edited successfully.\n",new_email);
          return; // Exit the function
        }
       }
       printf("old Email not found.\n");
}
void searchContact(AddressBook *addressBook) 
{
    int choose,flag=0;
    printf("Enter Search Contact Menu:\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.E-mail\n");
    printf("Enter your choice (1 or 2 or 3): \n");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:name2_display1(addressBook);
    break;
    case 2:phone2_display2(addressBook);
    break;
    case 3:email2_display3(addressBook);
    break;
    default :printf("Invalid choice. Please enter 1 or 2 or 3 \n");
    break;
    }
    }
   


void editContact(AddressBook *addressBook)
{
    int choose,i;
    printf("Enter Search Contact Menu\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.E-mail\n");
    printf("Enter your choice (1 or 2 or 3):\n ");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:i = name2_display1(addressBook);
    break;
    case 2:i = phone2_display2(addressBook);
    break;
    case 3:i = email2_display3(addressBook);
    break;
    default :printf("Invalid choice. Please enter 1 or 2 or 3 \n");
    break;
    }
     if(i<0)
       {
            return;
       }
	/* Define the logic for Editcontact */
    int to_edit;
    printf("Enter Edit Contact Menu:\n");
    printf("1. Edit the Name\n");
    printf("2. Edit the Phone Number\n");
    printf("3. Edit the e-mail\n");
    printf("Enter your choice (1 or 2 or 3): \n");
    scanf("%d",&to_edit);
    switch(to_edit)
    {
        case 1:name_edit1(addressBook);
        break;
        case 2:phone_edit2(addressBook);
        break;
        case 3:email_edit3(addressBook);
        break;
    }
}

void deleteContact(AddressBook *addressBook)
{
    int choose,i;
    printf("Enter Search Contact Menu:\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.E-mail\n");
    printf("Enter your choice (1 or 2 or 3):\n ");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:i = name2_display1(addressBook);
    break;
    case 2:i = phone2_display2(addressBook);
    break;
    case 3:i = email2_display3(addressBook);
    break;
    default :printf("Invalid choice. Please enter 1 or 2 or 3 \n");
    break;}
     if(i<0)
       {
            return;// Exit if invalid
       }


 int to_del,flag=-2;
    printf("Enter Delete Contact Menu:\n");
    printf("1. Delete by Name\n");
    printf("2. Delete by Phone Number\n");
    printf("3. Delete by e-mail\n");
    printf("Enter your choice (1 or 2 or 3):\n ");
    scanf("%d",&to_del);
    switch(to_del)
    {
        char name_del[20];
        case 1:
        printf("Enter the name to delete\n");
        scanf(" %[^\n]",name_del);
        for(int i=0;i<addressBook->contactCount;i++)
        {
        if(strcmp(addressBook->contacts[i].name,name_del)==0)
        {
            flag=i;// Found the contact
            break;
        }
        }
        break;
        char phone_del[10];
        case 2:
        printf("Enter the number to delete\n");
        scanf(" %[^\n]",phone_del);
        for(int i=0;i<addressBook->contactCount;i++)
        {
        if(strcmp(addressBook->contacts[i].phone,phone_del)==0)
        {
            flag=i;// Found the contact
            break;
        }
        }
        break;
          char mail_del[10];
        case 3:
        printf("Enter the mail to delete\n");
        scanf(" %[^\n]",mail_del);
        for(int i=0;i<addressBook->contactCount;i++)
        {
        if(strcmp(addressBook->contacts[i].email,mail_del)==0)
        {
            flag=i;// Found the contact
            break;
        }
        }
        break;
            default :printf("Inavlid choice...");
            return;// Exit if invalid
    }
     if (flag != -2) 
     {
        // Shift the contacts up one position to remove the contact
        for (int i = flag; i < addressBook->contactCount - 1; i++) 
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }

        // Decrement contact count
        addressBook->contactCount--;

        printf("Contact deleted successfully.\n");
         } 
        else
        {
            printf("Contact not found.\n");
        }
}
void listContacts(AddressBook *addressBook) 
{
    int i,j;
   // Sort contacts based on the chosen criteria and alsosorting based on names
   for(i=0;i<addressBook->contactCount-1;i++)
   {
    for(j=0;j<addressBook->contactCount-i-1;j++)
    {
        if(strcasecmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
        {
            Contact temp = addressBook->contacts[j];
            addressBook->contacts[j] = addressBook->contacts[j+1];
            addressBook->contacts[j+1] = temp;
        }
    }
   }

     // Sort contacts based on the chosen criteria
    for(int i=0;i<addressBook->contactCount;i++)
       {
        printf("Name:%s  Phone:%s  Email:%s\n", addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
       }


}
