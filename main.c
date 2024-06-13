#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Structure for Candidate
typedef struct Candidate_Info
{
    char name[50];
    char NID[20];
    int age;
    char symbol;
    int votes;
    struct Candidate_Info *next;
} Candidate;

// Structure for Voter
typedef struct Voter_Info
{
    char name[50];
    char NID[20];
    int age;
    struct Voter_Info *next;
} Voter;

// Function prototypes
void addCandidate(Candidate **head);
void updateCandidate(Candidate *head);
void deleteCandidate(Candidate **head);
void displayCandidates(Candidate *head);
void addVoter(Voter **head);
void updateVoter(Voter *head);
void giveVote(Candidate *candidates, Voter *voters);
void displayResult(Candidate *candidates);
void candidateOptions(Candidate **candidateHead);
void voterOptions(Voter **voterHead);

int main()
{
    Candidate *candidateHead = NULL;
    Voter *voterHead = NULL;
    int choice = 0;

    while (1)
    {
        system("cls");
        printf("\n\n\t\t\t\t=== Online Voting System ===");
        printf("\n\t\t\t\t============================\n\n");
        printf("\t\t\t\t    1.Candidate Options\n");
        printf("\t\t\t\t    2.Voter Options\n");
        printf("\t\t\t\t    3.Poll\n");
        printf("\t\t\t\t    4.Display Result\n");
        printf("\t\t\t\t    5.Exit\n");
        printf("\n\t\t\t\t    Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            candidateOptions(&candidateHead);
            break;
        case 2:
            voterOptions(&voterHead);
            break;
        case 3:
            giveVote(candidateHead, voterHead);
            break;
        case 4:
            displayResult(candidateHead);
            break;
        case 5:
        {
            printf("Exiting...\n");
            exit(5);
            break;
        }
        default:
        {
            system("cls");
            printf("\n\n\t\t\tInvalid choice\n");
            printf("\n\t\t\tPress Only 0 To 5\n");
            printf("\n\n\t\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
        }
        }
    }

    return 0;
}

// Function for Candidate Options
void candidateOptions(Candidate **candidateHead)
{
    int subChoice = 0;
    while (1)
    {
        system("cls");
        printf("\n\n\t\t\t\t Candidate Options");
        printf("\n\t\t\t       ====================\n\n");
        printf("\t\t\t\t1.Add Candidate\n");
        printf("\t\t\t\t2.Update Candidate\n");
        printf("\t\t\t\t3.Delete Candidate\n");
        printf("\t\t\t\t4.Display Candidates\n");
        printf("\t\t\t\t5.Back to Main Menu\n");
        printf("\n\n\t\t\tEnter your choice: ");
        scanf("%d", &subChoice);
        switch (subChoice)
        {
        case 1:
            addCandidate(candidateHead);
            break;
        case 2:
            updateCandidate(*candidateHead);
            break;
        case 3:
            deleteCandidate(candidateHead);
            break;
        case 4:
            displayCandidates(*candidateHead);
            break;
        case 5:
            return;
        default:
        {
            system("cls");
            printf("\n\n\t\t\tInvalid choice\n");
            printf("\n\t\t\tPress Only 0 To 5\n");
            printf("\n\n\t\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
        }
        }
    }
}

// Function for Voter Options
void voterOptions(Voter **voterHead)
{
    int subChoice = 0;
    while (1)
    {
        system("cls");
        printf("\n\n\t\t\t\t Voter Options");
        printf("\n\t\t\t       =================\n\n");
        printf("\t\t\t\t1.Add Voter\n");
        printf("\t\t\t\t2.Update Voter\n");
        printf("\t\t\t\t3.Back to Main Menu\n");
        printf("\n\t\t\t\tEnter your choice: ");
        scanf("%d", &subChoice);
        switch (subChoice)
        {
        case 1:
            addVoter(voterHead);
            break;
        case 2:
            updateVoter(*voterHead);
            break;
        case 3:
            return;
        default:
        {
            system("cls");
            printf("\n\n\t\t\tInvalid choice\n");
            printf("\n\t\t\tPress Only 0 To 3\n");
            printf("\n\n\t\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
        }

        }
    }
}

// Function to add a new candidate
void addCandidate(Candidate **head)
{
    system("cls");
    printf("\n\n\t\t\t\tADD CANDIDATE");
    printf("\n\t\t\t      =================\n");
    Candidate *newCandidate = (Candidate *)malloc(sizeof(Candidate));
    printf("\n\n\t\t\tEnter candidate name: ");
    fflush(stdin);
    scanf("%s", newCandidate->name);
    printf("\n\t\t\tEnter candidate NID: ");
    fflush(stdin);
    scanf("%s", newCandidate->NID);
    printf("\n\t\t\tEnter candidate age: ");
    scanf("%d", &newCandidate->age);
    printf("\n\t\t\tEnter candidate symbol: ");
    fflush(stdin);
    scanf(" %c", &newCandidate->symbol);
    newCandidate->votes = 0;
    newCandidate->next = *head;
    *head = newCandidate;
    printf("\n\n\t\t\tCandidate added successfully!\n");
    printf("\n\n\t\t\tEnter Any Key To Continue. . .");
    getch();
    system("cls");
}

// Function to update candidate information
void updateCandidate(Candidate *head)
{
    system("cls");
    printf("\n\n\t\t\t\tUPDATE CANDIDATE INFO");
    printf("\n\t\t\t     =========================\n");
    char searchNID[20];
    printf("\n\t\t\tEnter NID of the candidate to update: ");
    fflush(stdin);
    scanf("%s", searchNID);
    Candidate *current = head;
    while (current != NULL)
    {
        if (strcmp(current->NID, searchNID) == 0)
        {
            printf("\n\t\t\tEnter new candidate name: ");
            fflush(stdin);
            scanf("%s", current->name);
            printf("\n\t\t\tEnter new candidate age: ");
            fflush(stdin);
            scanf("%d", &current->age);
            printf("\n\t\t\tEnter new candidate symbol: ");
            fflush(stdin);
            scanf(" %c", &current->symbol);
            printf("\n\n\t\t\tCandidate information updated successfully!\n");
            printf("\n\n\t\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            return;
        }
        current = current->next;
    }
    printf("\n\t\t\tCandidate with NID %s not found\n", searchNID);
    printf("\n\t\tEnter Any Key To Continue. . .");
    getch();
    system("cls");
}

// Function to delete a candidate
void deleteCandidate(Candidate **head)
{
    system("cls");
    printf("\n\n\t\t\t\tDELETE CANDIDATE");
    printf("\n\t\t\t     =====================\n");
    char searchNID[20];
    printf("\n\n\t\t\tEnter NID of the candidate to delete: ");
    fflush(stdin);
    scanf("%s", searchNID);
    Candidate *current = *head;
    Candidate *prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->NID, searchNID) == 0)
        {
            if (prev == NULL)
            {
                *head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("\n\n\t\t\tCandidate deleted successfully!\n");
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("\n\n\t\t\tCandidate with NID %s not found\n", searchNID);
    printf("\n\t\tEnter Any Key To Continue. . .");
    getch();
    system("cls");
}

// Function to display the list of candidates
void displayCandidates(Candidate *head)
{
    system("cls");
    printf("\n\n\t\t\t\tDISPLAY ALL CANDIDATES");
    printf("\n\t\t\t     ===========================\n");
    printf("\n\t\t\tName\tNID\tAge\tSymbol");
    printf("\n\t\t\t--------------------------------\n");
    Candidate *current = head;
    int flag=0;
    while (current != NULL)
    {
        flag=1;
        printf("\n\t\t\t%s\t%s\t%d\t%c\n", current->name, current->NID, current->age, current->symbol);
        current = current->next;
    }
    if(flag==0)
    {
        printf("\n\t\t\tList Is Empty\n");
    }
    printf("\n\t\tEnter Any Key To Continue. . .");
    getch();
    system("cls");
}

// Function to add a new voter
void addVoter(Voter **head)
{
    system("cls");
    printf("\n\n\t\t\t\tADD NEW VOTER");
    printf("\n\t\t\t     ==================\n");
    Voter *newVoter = (Voter *)malloc(sizeof(Voter));
    printf("\n\t\t\tEnter voter name: ");
    fflush(stdin);
    scanf("%s", newVoter->name);
    printf("\n\t\t\tEnter voter NID: ");
    fflush(stdin);
    scanf("%s", newVoter->NID);
    printf("\n\t\t\tEnter voter age: ");
    scanf("%d", &newVoter->age);
    if (newVoter->age >= 18)
    {
        newVoter->next = *head;
        *head = newVoter;
        printf("\n\n\t\t\tVoter added successfully!\n");
    }
    else
    {
        printf("\n\n\t\t\tYou are not eligible for voting.\n");
        free(newVoter);
    }
    printf("\n\t\tEnter Any Key To Continue. . .");
    getch();
    system("cls");
}

// Function to update voter information
void updateVoter(Voter *head)
{
    system("cls");
    printf("\n\n\t\t\t\tUPDATE VOTER INFO");
    printf("\n\t\t\t     =====================\n");
    char searchNID[20];
    printf("\n\t\t\tEnter NID of the voter to update: ");
    scanf("%s", searchNID);
    Voter *current = head;
    while (current != NULL)
    {
        if (strcmp(current->NID, searchNID) == 0)
        {
            printf("\n\n\t\t\tEnter new voter name: ");
            fflush(stdin);
            scanf("%s", current->name);
            printf("\n\t\t\tEnter new voter age: ");
            fflush(stdin);
            scanf("%d", &current->age);
            printf("\n\n\t\t\tVoter information updated successfully!\n");
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            return;
        }
        current = current->next;
    }
    printf("\n\n\t\t\tVoter with NID %s not found\n", searchNID);
    printf("\n\t\tEnter Any Key To Continue. . .");
    getch();
    system("cls");
}

// Function to allow a voter to give vote
void giveVote(Candidate *candidates, Voter *voters)
{
    system("cls");
    printf("\n\n\t\t\t\t POLLING. . .");
    printf("\n\t\t\t     ==================\n");
    char voterNID[20], candidateSymbol;
    printf("\n\t\t\tEnter your NID: ");
    fflush(stdin);
    scanf("%s", voterNID);

    // Display candidates with symbols
    printf("\n\n\t\t\tCandidates List:\n");
    printf("\n\t\t\tName\tSymbol");
    printf("\n\t\t\t--------------------\n");
    Candidate *currentCandidate = candidates;
    while (currentCandidate != NULL)
    {
        printf("\n\t\t\t%s\t%c\n", currentCandidate->name, currentCandidate->symbol);
        currentCandidate = currentCandidate->next;
    }

    printf("\n\t\t\tEnter the symbol of the candidate you want to vote for: ");
    scanf(" %c", &candidateSymbol);

    // Check if the voter exists
    Voter *currentVoter = voters;
    while (currentVoter != NULL)
    {
        if (strcmp(currentVoter->NID, voterNID) == 0)
        {
            // Check if the candidate with the given symbol exists
            Candidate *currentCandidate = candidates;
            while (currentCandidate != NULL)
            {
                if (currentCandidate->symbol == candidateSymbol)
                {
                    currentCandidate->votes++;
                    printf("\n\n\t\t\tVote cast successfully!\n");
                    printf("\n\t\tEnter Any Key To Continue. . .");
                    getch();
                    system("cls");
                    return;
                }
                currentCandidate = currentCandidate->next;
            }
            printf("Candidate with symbol %c not found\n", candidateSymbol);
            printf("\n\t\tEnter Any Key To Continue. . .");
            getch();
            system("cls");
            return;
        }
        currentVoter = currentVoter->next;
    }
    printf("Voter with NID %s not found\n", voterNID);
    printf("\n\t\tEnter Any Key To Continue. . .");
    getch();
    system("cls");
}

// Function to display the current result
void displayResult(Candidate *candidates)
{
    system("cls");
    printf("\n\n\t\t\t\t POLL RESULT");
    printf("\n\t\t\t     ==================\n");
    printf("\n\t\t\tCandidate\tVotes");
    printf("\n\t\t\t----------------------\n");
    Candidate *current = candidates;
    int flag=0;
    while (current != NULL)
    {
        flag=1;
        printf("\n\t\t\t%s\t\t%d\n", current->name, current->votes);
        current = current->next;
    }
    if(flag==0)
        printf("\n\t\t\tNO Polling Result\n");
    printf("\n\t\tEnter Any Key To Continue. . .");
    getch();
    system("cls");
}

