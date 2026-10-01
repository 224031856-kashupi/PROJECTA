#include <stdio.h>
#include <string.h>
#include "suppliers.h"

void supplierManagement(void)
{
    char supplierID[MAX_SUPPLIERS][20];
    char supplierName[MAX_SUPPLIERS][100];
    char supplierEmail[MAX_SUPPLIERS][100];
    char telephone[MAX_SUPPLIERS][20];
    char town[MAX_SUPPLIERS][50];

    int totalSuppliers = 0;
    int choice;
    int i;
    int found;

    char searchValue[100];
    int supplierPosition;
    char description[250];

    do
    {
        printf("\n");
        printf("=================================================\n");
        printf("          SUPPLIER MANAGEMENT MODULE\n");
        printf("=================================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Update Supplier\n");
        printf("5. Exit\n");
        printf("=================================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("\n");
                printf("------------- ADD SUPPLIER -------------\n");

                if (totalSuppliers < MAX_SUPPLIERS)
                {
                    printf("Enter Supplier ID: ");
                    scanf(" %19[^\n]", supplierID[totalSuppliers]);

                    printf("Enter Supplier Name: ");
                    scanf(" %99[^\n]", supplierName[totalSuppliers]);

                    printf("Enter Supplier Email: ");
                    scanf(" %99[^\n]", supplierEmail[totalSuppliers]);

                    printf("Enter Telephone Number: ");
                    scanf(" %19[^\n]", telephone[totalSuppliers]);

                    printf("Enter Town / Location: ");
                    scanf(" %49[^\n]", town[totalSuppliers]);

                    totalSuppliers++;

                    printf("\nSupplier added successfully!\n");
                }
                else
                {
                    printf("\nSupplier storage is full.\n");
                }

                break;


            case 2:

                printf("\n");
                printf("------------- ALL SUPPLIERS -------------\n");

                if (totalSuppliers == 0)
                {
                    printf("No suppliers have been added yet.\n");
                }
                else
                {
                    for (i = 0; i < totalSuppliers; i++)
                    {
                        printf("\n");
                        printf("---------------------------------------------\n");

                        printf("Supplier ID       : %s\n",
                               supplierID[i]);

                        printf("Supplier Name     : %s\n",
                               supplierName[i]);

                        printf("Email             : %s\n",
                               supplierEmail[i]);

                        printf("Telephone Number  : %s\n",
                               telephone[i]);

                        printf("Town / Location   : %s\n",
                               town[i]);

                        printf("Name Length       : %d characters\n",
                               (int)strlen(supplierName[i]));

                        strcpy(description, "Supplier: ");

                        strcat(description, supplierName[i]);

                        strcat(description, "\nContact: ");

                        strcat(description, telephone[i]);

                        strcat(description, "\nEmail: ");

                        strcat(description, supplierEmail[i]);

                        strcat(description, "\nLocation: ");

                        strcat(description, town[i]);

                        printf("\nSupplier Description:\n");
                        printf("%s\n", description);
                    }
                }

                break;


            case 3:

                printf("\n");
                printf("--------- SEARCH SUPPLIER INFORMATION ---------\n");

                if (totalSuppliers == 0)
                {
                    printf("No suppliers have been added yet.\n");
                }
                else
                {
                    printf("Enter Supplier ID, Name, Email,\n");
                    printf("Telephone Number, or Town / Location: ");

                    scanf(" %99[^\n]", searchValue);

                    found = 0;

                    for (i = 0; i < totalSuppliers; i++)
                    {
                        if (strcmp(supplierID[i], searchValue) == 0 ||
                            strcmp(supplierName[i], searchValue) == 0 ||
                            strcmp(supplierEmail[i], searchValue) == 0 ||
                            strcmp(telephone[i], searchValue) == 0 ||
                            strcmp(town[i], searchValue) == 0)
                        {
                            printf("\nSupplier Found!\n");
                            printf("---------------------------------------------\n");

                            printf("Supplier ID       : %s\n",
                                   supplierID[i]);

                            printf("Supplier Name     : %s\n",
                                   supplierName[i]);

                            printf("Email             : %s\n",
                                   supplierEmail[i]);

                            printf("Telephone Number  : %s\n",
                                   telephone[i]);

                            printf("Town / Location   : %s\n",
                                   town[i]);

                            printf("Name Length       : %d characters\n",
                                   (int)strlen(supplierName[i]));

                            supplierPosition = i;

                            found = 1;

                            break;
                        }
                    }

                    if (found == 0)
                    {
                        printf("\nNo supplier information matched your search.\n");
                    }
                }

                break;


            case 4:

                printf("\n");
                printf("------------- UPDATE SUPPLIER -------------\n");

                if (totalSuppliers == 0)
                {
                    printf("No suppliers have been added yet.\n");
                }
                else
                {
                    printf("Enter Supplier ID of supplier to update: ");

                    scanf(" %99[^\n]", searchValue);

                    found = 0;

                    for (i = 0; i < totalSuppliers; i++)
                    {
                        if (strcmp(supplierID[i], searchValue) == 0)
                        {
                            found = 1;
                            supplierPosition = i;
                            break;
                        }
                    }

                    if (found == 1)
                    {
                        printf("\nSupplier found.\n");

                        printf("\nCurrent Supplier Name: %s\n",
                               supplierName[supplierPosition]);

                        printf("Enter New Supplier Name: ");

                        scanf(" %99[^\n]",
                              supplierName[supplierPosition]);


                        printf("\nCurrent Email: %s\n",
                               supplierEmail[supplierPosition]);

                        printf("Enter New Email: ");

                        scanf(" %99[^\n]",
                              supplierEmail[supplierPosition]);


                        printf("\nCurrent Telephone Number: %s\n",
                               telephone[supplierPosition]);

                        printf("Enter New Telephone Number: ");

                        scanf(" %19[^\n]",
                              telephone[supplierPosition]);


                        printf("\nCurrent Town / Location: %s\n",
                               town[supplierPosition]);

                        printf("Enter New Town / Location: ");

                        scanf(" %49[^\n]",
                              town[supplierPosition]);


                        printf("\nSupplier information updated successfully!\n");

                        printf("\n");
                        printf("------------- UPDATED SUPPLIER -------------\n");

                        printf("Supplier ID       : %s\n",
                               supplierID[supplierPosition]);

                        printf("Supplier Name     : %s\n",
                               supplierName[supplierPosition]);

                        printf("Email             : %s\n",
                               supplierEmail[supplierPosition]);

                        printf("Telephone Number  : %s\n",
                               telephone[supplierPosition]);

                        printf("Town / Location   : %s\n",
                               town[supplierPosition]);

                        printf("Name Length       : %d characters\n",
                               (int)strlen(
                                   supplierName[supplierPosition]
                               ));

                        strcpy(description, "Supplier: ");

                        strcat(description,
                               supplierName[supplierPosition]);

                        strcat(description, "\nContact: ");

                        strcat(description,
                               telephone[supplierPosition]);

                        strcat(description, "\nEmail: ");

                        strcat(description,
                               supplierEmail[supplierPosition]);

                        strcat(description, "\nLocation: ");

                        strcat(description,
                               town[supplierPosition]);

                        printf("\nSupplier Description:\n");
                        printf("%s\n", description);
                    }
                    else
                    {
                        printf("\nSupplier ID not found.\n");
                    }
                }

                break;


            case 5:

                printf("\n");
                printf("Exiting Supplier Management Module...\n");
                printf("Thank you.\n");

                break;


            default:

                printf("\nInvalid choice.\n");
                printf("Please select a number from 1 to 5.\n");

                break;
        }

    } while (choice != 5);
}