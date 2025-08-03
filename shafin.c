// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Patient
// {
//     int id;
//     char name[50];
//     char address[100];
//     char disease[200];
//     char date[15];
// };

// struct Doctor
// {
//     int id;
//     char name[50];
//     char address[100];
//     char specialization[50];
// };

// struct Bill
// {
//     int patient_id;
//     double service_cost;
//     double medication_cost;
//     double other_charges;
//     double total;
// };

// void add_patient();
// void list_patient();
// void search_patient();
// void discharge_patient();
// void add_doctor();
// void list_doctors();
// void search_doctors();
// void add_bill();
// void search_bill();
// void generate_revenue_report();

// int main()
// {
//     int choice;

//     while (1)
//     {
//         printf("\n* Hospital Management System Menu *\n");
//         printf("01. Add Patient\n");
//         printf("02. List Patient\n");
//         printf("03. Search Patient\n");
//         printf("04. Discharge Patient\n");
//         printf("05. Add Doctor\n");
//         printf("06. List Doctors\n");
//         printf("07. Search Doctor\n");
//         printf("08. Add Bill\n");
//         printf("09. Search Bill\n");
//         printf("10. Generate Revenue Report\n");
//         printf("00. Exit\n");
//         printf("Enter your choice: ");
//         if(scanf("%d", &choice) != 1)  // Check if valid integer input is entered
//         {
//             printf("Invalid input. Please enter a number.\n");
//             while (getchar() != '\n');  // Clear the input buffer
//             continue;  // Continue the loop to show the menu again
//         }

//         switch (choice)
//         {
//             case 1:
//                 add_patient();
//                 break;
//             case 2:
//                 list_patient();
//                 break;
//             case 3:
//                 search_patient();
//                 break;
//             case 4:
//                 discharge_patient();
//                 break;
//             case 5:
//                 add_doctor();
//                 break;
//             case 6:
//                 list_doctors();
//                 break;
//             case 7:
//                 search_doctors();
//                 break;
//             case 8:
//                 add_bill();
//                 break;
//             case 9:
//                 search_bill();
//                 break;
//             case 10:
//                 generate_revenue_report();
//                 break;
//             case 0:  // Exit condition
//                 printf("Exiting...\n");
//                 return 0; // Exit the program and break the loop
//             default:
//                 printf("Invalid choice. Please enter a number from 0 to 10.\n");
//         }
//     }
// }

// void add_patient()
// {
//     FILE *file = fopen("patient.txt", "a");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     struct Patient patient;
//     printf("Enter patient ID: ");
//     scanf("%d", &patient.id);
//     printf("Enter patient Name: ");
//     scanf("%s", patient.name);
//     printf("Enter patient Address: ");
//     scanf("%s", patient.address);
//     printf("Enter patient Disease: ");
//     scanf("%s", patient.disease);
//     printf("Enter Admission Date (DD-MM-YYYY): ");
//     scanf("%s", patient.date);

//     fprintf(file, "%d %s %s %s %s\n", patient.id, patient.name, patient.address, patient.disease, patient.date);
//     printf("Patient added successfully.\n");

//     fclose(file);
// }

// void list_patient()
// {
//     FILE *file = fopen("patient.txt", "r");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     struct Patient patient;
//     printf("\n* Patient List *\n");
//     printf("ID\tName\t\tAddress\t\tDisease\t\tAdmission Date\n");

//     while (fscanf(file, "%d %s %s %s %s", &patient.id, patient.name, patient.address, patient.disease, patient.date) != EOF)
//     {
//         printf("%d\t%s\t\t%s\t\t%s\t\t%s\n", patient.id, patient.name, patient.address, patient.disease, patient.date);
//     }

//     fclose(file);
// }

// void search_patient()
// {
//     FILE *file = fopen("patient.txt", "r");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     int id;
//     printf("Enter Patient ID to search: ");
//     scanf("%d", &id);

//     struct Patient patient;
//     int found = 0;

//     while (fscanf(file, "%d %s %s %s %s", &patient.id, patient.name, patient.address, patient.disease, patient.date) != EOF)
//     {
//         if (patient.id == id)
//         {
//             printf("\n* Patient Details *\n");
//             printf("ID: %d\nName: %s\nAddress: %s\nDisease: %s\nAdmission Date: %s\n", patient.id, patient.name, patient.address, patient.disease, patient.date);
//             found = 1;
//             break;
//         }
//     }

//     if (!found)
//     {
//         printf("Patient with ID %d not found.\n", id);
//     }

//     fclose(file);
// }

// void discharge_patient()
// {
//     FILE *file = fopen("patient.txt", "r");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     int id;
//     printf("Enter Patient ID to discharge: ");
//     scanf("%d", &id);

//     FILE *tempFile = fopen("temp.txt", "w");
//     if (tempFile == NULL)
//     {
//         printf("Error opening temporary file!\n");
//         fclose(file);
//         return;
//     }

//     struct Patient patient;
//     int found = 0;

//     while (fscanf(file, "%d %s %s %s %s", &patient.id, patient.name, patient.address, patient.disease, patient.date) != EOF)
//     {
//         if (patient.id != id)
//         {
//             fprintf(tempFile, "%d %s %s %s %s\n", patient.id, patient.name, patient.address, patient.disease, patient.date);
//         }
//         else
//         {
//             found = 1;
//         }
//     }

//     fclose(file);
//     fclose(tempFile);

//     remove("patient.txt");
//     rename("temp.txt", "patient.txt");

//     if (found)
//     {
//         printf("Patient with ID %d discharged successfully.\n", id);
//     }
//     else
//     {
//         printf("Patient with ID %d not found.\n", id);
//     }
// }

// void add_doctor()
// {
//     FILE *file = fopen("doctors.txt", "a");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     struct Doctor doctor;
//     printf("Enter Doctor ID: ");
//     scanf("%d", &doctor.id);
//     printf("Enter Doctor Name: ");
//     scanf("%s", doctor.name);
//     printf("Enter Doctor Address: ");
//     scanf("%s", doctor.address);
//     printf("Enter Doctor Specialization: ");
//     scanf("%s", doctor.specialization);

//     fprintf(file, "%d %s %s %s\n", doctor.id, doctor.name, doctor.address, doctor.specialization);
//     printf("Doctor added successfully.\n");

//     fclose(file);
// }

// void list_doctors()
// {
//     FILE *file = fopen("doctors.txt", "r");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     struct Doctor doctor;
//     printf("\n*** Doctors List ***\n");
//     printf("ID\tName\t\tAddress\t\tSpecialization\n");

//     while (fscanf(file, "%d %s %s %s", &doctor.id, doctor.name, doctor.address, doctor.specialization) != EOF)
//     {
//         printf("%d\t%s\t\t%s\t\t%s\n", doctor.id, doctor.name, doctor.address, doctor.specialization);
//     }

//     fclose(file);
// }

// void search_doctors()
// {
//     FILE *file = fopen("doctors.txt", "r");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     int id;
//     printf("Enter Doctor ID to search: ");
//     scanf("%d", &id);

//     struct Doctor doctor;
//     int found = 0;

//     while (fscanf(file, "%d %s %s %s", &doctor.id, doctor.name, doctor.address, doctor.specialization) != EOF)
//     {
//         if (doctor.id == id)
//         {
//             printf("\n*** Doctor Details ***\n");
//             printf("ID: %d\nName: %s\nAddress: %s\nSpecialization: %s\n", doctor.id, doctor.name, doctor.address, doctor.specialization);
//             found = 1;
//             break;
//         }
//     }

//     if (!found)
//     {
//         printf("Doctor with ID %d not found.\n", id);
//     }

//     fclose(file);
// }

// void add_bill()
// {
//     FILE *file = fopen("bills.txt", "a");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     struct Bill bill;
//     printf("Enter Patient ID for billing: ");
//     scanf("%d", &bill.patient_id);
//     printf("Enter Service cost: ");
//     scanf("%lf", &bill.service_cost);
//     printf("Enter Medication cost: ");
//     scanf("%lf", &bill.medication_cost);
//     printf("Enter Other Charges: ");
//     scanf("%lf", &bill.other_charges);
//     bill.total = bill.service_cost + bill.medication_cost + bill.other_charges;

//     fprintf(file, "%d %.2f %.2f %.2f %.2f\n", bill.patient_id, bill.service_cost, bill.medication_cost, bill.other_charges, bill.total);
//     printf("Bill added successfully.\n");

//     fclose(file);
// }

// void search_bill()
// {
//     FILE *file = fopen("bills.txt", "r");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     int patient_id;
//     printf("Enter Patient ID to search bills: ");
//     scanf("%d", &patient_id);

//     struct Bill bill;
//     int found = 0;
//     printf("\n* Bills for Patient ID %d *\n", patient_id);

//     while (fscanf(file, "%d %lf %lf %lf %lf", &bill.patient_id, &bill.service_cost, &bill.medication_cost, &bill.other_charges, &bill.total) != EOF)
//     {
//         if (bill.patient_id == patient_id)
//         {
//             printf("Service Cost: %.2f\nMedication Cost: %.2f\nOther Charges: %.2f\nTotal: %.2f\n", bill.service_cost, bill.medication_cost, bill.other_charges, bill.total);
//             found = 1;
//         }
//     }

//     if (!found)
//     {
//         printf("No bills found for Patient ID %d.\n", patient_id);
//     }

//     fclose(file);
// }

// void generate_revenue_report()
// {
//     FILE *file = fopen("bills.txt", "r");
//     if (file == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     struct Bill bill;
//     double total_revenue = 0;

//     while (fscanf(file, "%d %lf %lf %lf %lf", &bill.patient_id, &bill.service_cost, &bill.medication_cost, &bill.other_charges, &bill.total) != EOF)
//     {
//         total_revenue += bill.total;
//     }

//     printf("Total revenue: %.2f\n", total_revenue);

//     fclose(file);
// }


#include <stdio.h>

int main() {
    FILE *file;
    char filename[50];
    int ch, charCount = 0;

    // Step 1: Get the file name from the user
    printf("Enter the files name: ");
    scanf("%s", filename);

    // Step 2: Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Step 3: Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        charCount++;  // Increment character count
    }

    // Step 4: Close the file
    fclose(file);

    // Step 5: Print the total number of characters
    printf("The total number of characters in the file is: %d\n", charCount);

    return 0;
}

