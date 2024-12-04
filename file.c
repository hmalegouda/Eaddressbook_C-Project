#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *save;
    save=fopen("contact.csv","w+");
    if(save == NULL)
    {
        printf("File doesn't exsits...\n");
        return;
    }
    fprintf(save,"#%d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(save, "%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(save);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *load;
    int i;
    load = fopen("contact.csv","r");
     if(load == NULL)
    {
        printf("File doesn't exsits...\n");
        return;
    }
    fscanf(load,"#%d\n",&addressBook->contactCount);

    for(i=0;i<addressBook->contactCount;i++)
    {
        fscanf(load, "%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    addressBook->contactCount=i;
    
    fclose(load);  
}
