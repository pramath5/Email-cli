#ifndef EMAIL_H
#define EMAIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Email {
    int id;                         
    char sender[100];               
    char receiver[100];             
    char subject[200];             
    char body[2000];              
    char timestamp[30];      
    struct Email *next;         
} Email;

Email* create_email(const char* sender, const char* receiver, 
                    const char* subject, const char* body, int id);

void insert_email(Email** head, Email* new_email);

void display_emails(const Email* head);

void display_emails_by_receiver(const Email* head, const char* receiver);

void delete_email_by_id(Email** head, int id);

void free_all_emails(Email* head);

int get_next_email_id(const Email* head);

#endif

