#include "email.h"

Email* create_email(const char* sender, const char* receiver, 
                    const char* subject, const char* body, int id) {
    if (sender == NULL || receiver == NULL || subject == NULL || body == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to create_email\n");
        return NULL;
    }
    Email* new_email = (Email*)malloc(sizeof(Email));
    if (new_email == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for new email\n");
        return NULL;
    }
    new_email->id = id;
    
    strncpy(new_email->sender, sender, sizeof(new_email->sender) - 1);
    new_email->sender[sizeof(new_email->sender) - 1] = '\0';
    
    strncpy(new_email->receiver, receiver, sizeof(new_email->receiver) - 1);
    new_email->receiver[sizeof(new_email->receiver) - 1] = '\0';
    
    strncpy(new_email->subject, subject, sizeof(new_email->subject) - 1);
    new_email->subject[sizeof(new_email->subject) - 1] = '\0';
    
    strncpy(new_email->body, body, sizeof(new_email->body) - 1);
    new_email->body[sizeof(new_email->body) - 1] = '\0';

    time_t raw_time;
    struct tm* time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(new_email->timestamp, sizeof(new_email->timestamp), 
             "%Y-%m-%d %H:%M:%S", time_info);
    new_email->next = NULL;

    return new_email;
}

void insert_email(Email** head, Email* new_email) {
    if (new_email == NULL) {
        fprintf(stderr, "Error: Cannot insert NULL email\n");
        return;
    }

    if (head == NULL) {
        fprintf(stderr, "Error: Invalid head pointer\n");
        return;
    }
    new_email->next = *head;
    *head = new_email;
}

void display_emails(const Email* head) {
    if (head == NULL) {
        printf("No emails in the list.\n");
        return;
    }

    const Email* current = head;
    int count = 0;

    printf("\n=== Email List ===\n");
    while (current != NULL) {
        count++;
        printf("\n--- Email #%d ---\n", count);
        printf("ID: %d\n", current->id);
        printf("From: %s\n", current->sender);
        printf("To: %s\n", current->receiver);
        printf("Subject: %s\n", current->subject);
        printf("Body: %s\n", current->body);
        printf("Timestamp: %s\n", current->timestamp);
        
        current = current->next;
    }
    printf("\nTotal emails: %d\n", count);
    printf("==================\n\n");
}

void display_emails_by_receiver(const Email* head, const char* receiver) {
    if (head == NULL) {
        printf("No emails in the list.\n");
        return;
    }

    if (receiver == NULL) {
        fprintf(stderr, "Error: NULL receiver address provided\n");
        return;
    }

    const Email* current = head;
    int count = 0;
    int found = 0;

    printf("\n=== Emails sent to: %s ===\n", receiver);
    
    while (current != NULL) {
        if (strcmp(current->receiver, receiver) == 0) {
            found++;
            count++;
            printf("\n--- Email #%d ---\n", count);
            printf("ID: %d\n", current->id);
            printf("From: %s\n", current->sender);
            printf("To: %s\n", current->receiver);
            printf("Subject: %s\n", current->subject);
            printf("Body: %s\n", current->body);
            printf("Timestamp: %s\n", current->timestamp);
        }
        current = current->next;
    }

    if (found == 0) {
        printf("No emails found for receiver: %s\n", receiver);
    } else {
        printf("\nTotal emails found: %d\n", found);
    }
    printf("===========================\n\n");
}

void delete_email_by_id(Email** head, int id) {
    if (head == NULL || *head == NULL) {
        return; 
    }

    Email* current = *head;
    Email* previous = NULL;

    if (current->id == id) {
        *head = current->next;
        free(current);
        return;
    }

    previous = current;
    current = current->next;

    while (current != NULL) {
        if (current->id == id) {
            previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

}

void free_all_emails(Email* head) {
    Email* current = head;
    Email* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int get_next_email_id(const Email* head) {
    if (head == NULL) {
        return 1;
    }

    int max_id = 0;
    const Email* current = head;
    while (current != NULL) {
        if (current->id > max_id) {
            max_id = current->id;
        }
        current = current->next;
    }

    return max_id + 1;
}