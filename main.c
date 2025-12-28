#include "email.h"

int main() {
    Email* email_list = NULL;
    Email* new_email = NULL;
    int next_id;

    printf("=== CLI Email Client - Linked List Example ===\n\n");

    next_id = get_next_email_id(email_list);
    new_email = create_email(
        "alice@example.com",
        "bob@example.com",
        "Meeting Tomorrow",
        "Hi Bob, let's meet tomorrow at 2 PM to discuss the project.",
        next_id
    );
    if (new_email != NULL) {
        insert_email(&email_list, new_email);
        printf("Email #%d created and inserted.\n", next_id);
    }

    next_id = get_next_email_id(email_list);
    new_email = create_email(
        "charlie@example.com",
        "diana@example.com",
        "Project Update",
        "Diana, here's the latest update on the project status.",
        next_id
    );
    if (new_email != NULL) {
        insert_email(&email_list, new_email);
        printf("Email #%d created and inserted.\n", next_id);
    }

    next_id = get_next_email_id(email_list);
    new_email = create_email(
        "eve@example.com",
        "frank@example.com",
        "Quick Question",
        "Frank, can you clarify the requirements for the new feature?",
        next_id
    );
    if (new_email != NULL) {
        insert_email(&email_list, new_email);
        printf("Email #%d created and inserted.\n", next_id);
    }

    next_id = get_next_email_id(email_list);
    new_email = create_email(
        "alice@example.com",
        "bob@example.com",
        "Follow-up on Meeting",
        "Bob, just a reminder about our meeting tomorrow.",
        next_id
    );
    if (new_email != NULL) {
        insert_email(&email_list, new_email);
        printf("Email #%d created and inserted.\n", next_id);
    }
    printf("\n");
    display_emails(email_list);

    printf("Searching for emails sent to bob@example.com...\n");
    display_emails_by_receiver(email_list, "bob@example.com");

    printf("Searching for emails sent to unknown@example.com...\n");
    display_emails_by_receiver(email_list, "unknown@example.com");

    printf("\nDeleting email with ID 2...\n");
    delete_email_by_id(&email_list, 2);
    printf("Email #2 deleted (if it existed).\n");

    printf("\n");
    display_emails(email_list);

    printf("Freeing all emails...\n");
    free_all_emails(email_list);
    email_list = NULL;

    printf("\n");
    display_emails(email_list);

    printf("Attempting to delete from empty list...\n");
    delete_email_by_id(&email_list, 1);
    printf("Delete operation completed (no error on empty list).\n");

    printf("\n=== Example Complete ===\n");
    return 0;
}