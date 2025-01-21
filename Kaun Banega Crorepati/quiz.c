#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUES_LEN 200
#define MAX_OPTION_LEN 100

typedef struct
{
    char question[MAX_QUES_LEN];
    char options[4][MAX_OPTION_LEN];
    char correctOption;
    int time;
    int prizeMoney;

} Questions;

int loadQuestions(char *, Questions **);
void printFormattedQuestion(Questions);
void fixStringInput(char *);

int main()
{

    // declaring structure pointer to dynamically allocate memory further in the code
    Questions *question;

    int noOfQuestions = loadQuestions("questions.txt", &question);
    for (int i = 0; i < noOfQuestions; i++)
    {
        printFormattedQuestion((question)[i]);
    }

    return 0;
}

int loadQuestions(char *fileName, Questions **questions)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening the file!");
        exit(0);
    }

    char str[MAX_QUES_LEN];
    int numberOfLines = 0;

    while (fgets(str, MAX_QUES_LEN, file))
    {
        numberOfLines++;
    }

    int noOfQuestions = numberOfLines / 8;
    *questions = (Questions *)malloc(noOfQuestions * sizeof(Questions));

    rewind(file);
    for (int i = 0; i < noOfQuestions; i++)
    {
        fgets((*questions)[i].question, MAX_QUES_LEN, file);
        fixStringInput((*questions)[i].question);
        for (int j = 0; j < 4; j++)
        {
            fgets((*questions)[i].options[j], MAX_OPTION_LEN, file);
            fixStringInput((*questions)[i].options[j]);
        }
        char option[10];
        fgets(option, 10, file);
        (*questions)[i].correctOption = option[0];

        char timeout[10];
        fgets(timeout, 10, file);
        (*questions)[i].time = atoi(timeout); // casting string into number

        char prizeMoney[10];
        fgets(prizeMoney, 10, file);
        (*questions)[i].prizeMoney = atoi(prizeMoney); // casting string into number
    }

    fclose(file);
    return noOfQuestions;
}

void printFormattedQuestion(Questions question)
{
    printf("\n%s\n%s\n%s\n%s\n%s", question.question, question.options[0], question.options[1], question.options[2], question.options[3]);

    printf("\n%c\n%d\n%d", question.correctOption, question.time, question.prizeMoney);
}

void fixStringInput(char *string)
{
    string[strcspn(string, "\n")] = '\0';
}