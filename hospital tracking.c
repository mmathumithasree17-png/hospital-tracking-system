#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Patient Node in Doubly Linked List
typedef struct Patient {
    int patientID;
    char name[50];
    int age;
    char department[50];
    char doctor[50];
    char status[20];  // Admitted, Under Treatment, Discharged, Critical
    struct Patient *prev;
    struct Patient *next;
} Patient;

// Global head pointer
Patient *head = NULL;

// Function Prototypes
void initializeSampleData();
void addPatient();
void displayAllPatients();
void searchPatient();
void updatePatientStatus();
void deletePatient();
void displayByDepartment();
void displayCriticalPatients();
void displayForward();
void displayBackward();
void freeAllPatients();
void displayMenu();

// Main Function
int main() {
    int choice;
    
    printf("\n");
    printf("========================================================\n");
    printf("     HOSPITAL PATIENT TRACKING SYSTEM\n");
    printf("     Using Doubly Linked List Data Structure\n");
    printf("========================================================\n");
    
    // Initialize with sample data
    initializeSampleData();
    printf("\n[System Initialized with 8 Sample Patient Records]\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline
        
        switch(choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayAllPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                updatePatientStatus();
                break;
            case 5:
                deletePatient();
                break;
            case 6:
                displayByDepartment();
                break;
            case 7:
                displayCriticalPatients();
                break;
            case 8:
                displayForward();
                break;
            case 9:
                displayBackward();
                break;
            case 0:
                printf("\n[Exiting System...]\n");
                freeAllPatients();
                printf("Thank you for using Hospital Patient Tracking System!\n\n");
                break;
            default:
                printf("\n[Invalid choice! Please try again.]\n");
        }
    } while(choice != 0);
    
    return 0;
}

// Display Menu
void displayMenu() {
    printf("\n========================================================\n");
    printf("                    MAIN MENU\n");
    printf("========================================================\n");
    printf("1.  Add New Patient\n");
    printf("2.  Display All Patients\n");
    printf("3.  Search Patient by ID\n");
    printf("4.  Update Patient Status\n");
    printf("5.  Delete Patient Record\n");
    printf("6.  Display Patients by Department\n");
    printf("7.  Display Critical Patients\n");
    printf("8.  Display Patients (Forward Traversal)\n");
    printf("9.  Display Patients (Backward Traversal)\n");
    printf("0.  Exit System\n");
    printf("========================================================\n");
}

// Initialize Sample Data
void initializeSampleData() {
    Patient *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;
    
    // Patient 1
    p1 = (Patient*)malloc(sizeof(Patient));
    p1->patientID = 1001;
    strcpy(p1->name, "Rajesh Kumar");
    p1->age = 45;
    strcpy(p1->department, "Cardiology");
    strcpy(p1->doctor, "Dr. Sharma");
    strcpy(p1->status, "Under Treatment");
    p1->prev = NULL;
    p1->next = NULL;
    head = p1;
    
    // Patient 2
    p2 = (Patient*)malloc(sizeof(Patient));
    p2->patientID = 1002;
    strcpy(p2->name, "Priya Patel");
    p2->age = 32;
    strcpy(p2->department, "Orthopedics");
    strcpy(p2->doctor, "Dr. Verma");
    strcpy(p2->status, "Admitted");
    p2->prev = p1;
    p2->next = NULL;
    p1->next = p2;
    
    // Patient 3
    p3 = (Patient*)malloc(sizeof(Patient));
    p3->patientID = 1003;
    strcpy(p3->name, "Amit Singh");
    p3->age = 28;
    strcpy(p3->department, "Neurology");
    strcpy(p3->doctor, "Dr. Reddy");
    strcpy(p3->status, "Critical");
    p3->prev = p2;
    p3->next = NULL;
    p2->next = p3;
    
    // Patient 4
    p4 = (Patient*)malloc(sizeof(Patient));
    p4->patientID = 1004;
    strcpy(p4->name, "Sneha Iyer");
    p4->age = 55;
    strcpy(p4->department, "Cardiology");
    strcpy(p4->doctor, "Dr. Sharma");
    strcpy(p4->status, "Under Treatment");
    p4->prev = p3;
    p4->next = NULL;
    p3->next = p4;
    
    // Patient 5
    p5 = (Patient*)malloc(sizeof(Patient));
    p5->patientID = 1005;
    strcpy(p5->name, "Vikram Desai");
    p5->age = 40;
    strcpy(p5->department, "Gastroenterology");
    strcpy(p5->doctor, "Dr. Mehta");
    strcpy(p5->status, "Admitted");
    p5->prev = p4;
    p5->next = NULL;
    p4->next = p5;
    
    // Patient 6
    p6 = (Patient*)malloc(sizeof(Patient));
    p6->patientID = 1006;
    strcpy(p6->name, "Ananya Nair");
    p6->age = 22;
    strcpy(p6->department, "Dermatology");
    strcpy(p6->doctor, "Dr. Gupta");
    strcpy(p6->status, "Discharged");
    p6->prev = p5;
    p6->next = NULL;
    p5->next = p6;
    
    // Patient 7
    p7 = (Patient*)malloc(sizeof(Patient));
    p7->patientID = 1007;
    strcpy(p7->name, "Mohammed Ali");
    p7->age = 62;
    strcpy(p7->department, "Pulmonology");
    strcpy(p7->doctor, "Dr. Khan");
    strcpy(p7->status, "Critical");
    p7->prev = p6;
    p7->next = NULL;
    p6->next = p7;
    
    // Patient 8
    p8 = (Patient*)malloc(sizeof(Patient));
    p8->patientID = 1008;
    strcpy(p8->name, "Kavya Menon");
    p8->age = 35;
    strcpy(p8->department, "Pediatrics");
    strcpy(p8->doctor, "Dr. Rao");
    strcpy(p8->status, "Under Treatment");
    p8->prev = p7;
    p8->next = NULL;
    p7->next = p8;
}

// Add New Patient
void addPatient() {
    Patient newPatient = (Patient)malloc(sizeof(Patient));
    Patient *temp = head;
    
    printf("\n--- Add New Patient ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &newPatient->patientID);
    getchar();
    
    printf("Enter Patient Name: ");
    fgets(newPatient->name, 50, stdin);
    newPatient->name[strcspn(newPatient->name, "\n")] = 0;
    
    printf("Enter Age: ");
    scanf("%d", &newPatient->age);
    getchar();
    
    printf("Enter Department: ");
    fgets(newPatient->department, 50, stdin);
    newPatient->department[strcspn(newPatient->department, "\n")] = 0;
    
    printf("Enter Doctor Name: ");
    fgets(newPatient->doctor, 50, stdin);
    newPatient->doctor[strcspn(newPatient->doctor, "\n")] = 0;
    
    printf("Enter Status (Admitted/Under Treatment/Critical/Discharged): ");
    fgets(newPatient->status, 20, stdin);
    newPatient->status[strcspn(newPatient->status, "\n")] = 0;
    
    newPatient->next = NULL;
    
    if(head == NULL) {
        newPatient->prev = NULL;
        head = newPatient;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
        newPatient->prev = temp;
    }
    
    printf("\n[Patient Added Successfully!]\n");
}

// Display All Patients
void displayAllPatients() {
    Patient *temp = head;
    
    if(temp == NULL) {
        printf("\n[No patients in the system!]\n");
        return;
    }
    
    printf("\n========================================================\n");
    printf("              ALL PATIENTS RECORDS\n");
    printf("========================================================\n");
    
    while(temp != NULL) {
        printf("\nPatient ID    : %d\n", temp->patientID);
        printf("Name          : %s\n", temp->name);
        printf("Age           : %d\n", temp->age);
        printf("Department    : %s\n", temp->department);
        printf("Doctor        : %s\n", temp->doctor);
        printf("Status        : %s\n", temp->status);
        printf("--------------------------------------------------------\n");
        temp = temp->next;
    }
}

// Search Patient by ID
void searchPatient() {
    int id;
    Patient *temp = head;
    
    printf("\n--- Search Patient ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &id);
    
    while(temp != NULL) {
        if(temp->patientID == id) {
            printf("\n[Patient Found!]\n");
            printf("--------------------------------------------------------\n");
            printf("Patient ID    : %d\n", temp->patientID);
            printf("Name          : %s\n", temp->name);
            printf("Age           : %d\n", temp->age);
            printf("Department    : %s\n", temp->department);
            printf("Doctor        : %s\n", temp->doctor);
            printf("Status        : %s\n", temp->status);
            printf("--------------------------------------------------------\n");
            return;
        }
        temp = temp->next;
    }
    
    printf("\n[Patient with ID %d not found!]\n", id);
}

// Update Patient Status
void updatePatientStatus() {
    int id;
    Patient *temp = head;
    char newStatus[20];
    
    printf("\n--- Update Patient Status ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &id);
    getchar();
    
    while(temp != NULL) {
        if(temp->patientID == id) {
            printf("\nCurrent Status: %s\n", temp->status);
            printf("Enter New Status: ");
            fgets(newStatus, 20, stdin);
            newStatus[strcspn(newStatus, "\n")] = 0;
            
            strcpy(temp->status, newStatus);
            printf("\n[Status Updated Successfully!]\n");
            return;
        }
        temp = temp->next;
    }
    
    printf("\n[Patient with ID %d not found!]\n", id);
}

// Delete Patient
void deletePatient() {
    int id;
    Patient *temp = head;
    
    printf("\n--- Delete Patient Record ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &id);
    
    while(temp != NULL) {
        if(temp->patientID == id) {
            if(temp->prev == NULL) {  // Deleting head
                head = temp->next;
                if(head != NULL) {
                    head->prev = NULL;
                }
            } else if(temp->next == NULL) {  // Deleting tail
                temp->prev->next = NULL;
            } else {  // Deleting middle node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            
            free(temp);
            printf("\n[Patient Record Deleted Successfully!]\n");
            return;
        }
        temp = temp->next;
    }
    
    printf("\n[Patient with ID %d not found!]\n", id);
}

// Display Patients by Department
void displayByDepartment() {
    char dept[50];
    Patient *temp = head;
    int found = 0;
    
    printf("\n--- Display Patients by Department ---\n");
    printf("Enter Department Name: ");
    fgets(dept, 50, stdin);
    dept[strcspn(dept, "\n")] = 0;
    
    printf("\n========================================================\n");
    printf("         PATIENTS IN %s DEPARTMENT\n", dept);
    printf("========================================================\n");
    
    while(temp != NULL) {
        if(strcmp(temp->department, dept) == 0) {
            printf("\nPatient ID    : %d\n", temp->patientID);
            printf("Name          : %s\n", temp->name);
            printf("Age           : %d\n", temp->age);
            printf("Doctor        : %s\n", temp->doctor);
            printf("Status        : %s\n", temp->status);
            printf("--------------------------------------------------------\n");
            found = 1;
        }
        temp = temp->next;
    }
    
    if(!found) {
        printf("\n[No patients found in %s department!]\n", dept);
    }
}

// Display Critical Patients
void displayCriticalPatients() {
    Patient *temp = head;
    int found = 0;
    
    printf("\n========================================================\n");
    printf("              CRITICAL PATIENTS\n");
    printf("========================================================\n");
    
    while(temp != NULL) {
        if(strcmp(temp->status, "Critical") == 0) {
            printf("\nPatient ID    : %d\n", temp->patientID);
            printf("Name          : %s\n", temp->name);
            printf("Age           : %d\n", temp->age);
            printf("Department    : %s\n", temp->department);
            printf("Doctor        : %s\n", temp->doctor);
            printf("--------------------------------------------------------\n");
            found = 1;
        }
        temp = temp->next;
    }
    
    if(!found) {
        printf("\n[No critical patients at the moment!]\n");
    }
}

// Display Forward Traversal
void displayForward() {
    Patient *temp = head;
    
    printf("\n========================================================\n");
    printf("         FORWARD TRAVERSAL (Head to Tail)\n");
    printf("========================================================\n");
    
    if(temp == NULL) {
        printf("\n[No patients in the system!]\n");
        return;
    }
    
    printf("\nPatient IDs: ");
    while(temp != NULL) {
        printf("%d", temp->patientID);
        if(temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Display Backward Traversal
void displayBackward() {
    Patient *temp = head;
    
    printf("\n========================================================\n");
    printf("         BACKWARD TRAVERSAL (Tail to Head)\n");
    printf("========================================================\n");
    
    if(temp == NULL) {
        printf("\n[No patients in the system!]\n");
        return;
    }
    
    // Move to last node
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("\nPatient IDs: ");
    while(temp != NULL) {
        printf("%d", temp->patientID);
        if(temp->prev != NULL) {
            printf(" <-> ");
        }
        temp = temp->prev;
    }
    printf(" -> NULL\n");
}

// Free All Patients (Memory Cleanup)
void freeAllPatients() {
    Patient *temp = head;
    Patient *next;
    
    while(temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}