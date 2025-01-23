#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUES_LEN 200
#define MAX_OPTION_LEN 100
#define PINK_COLOR "\033[1;35m"
#define GREY_COLOR "\033[1;30m"
#define BLUE_COLOR "\033[1;34m"
#define YELLOW_COLOR "\033[1;33m"
#define AQUA_COLOR "\033[1;36m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define COLOR_END "\033[0m"

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
void clearBuffer();
void playGame(Questions *, int);
int useLifeline(Questions* , int *);

int main()
{
    srand(time(NULL));

    printf("\t\t%slet's play Kaun Banega Crorepati %s", AQUA_COLOR, COLOR_END);
    // declaring structure pointer to dynamically allocate memory further in the code
    Questions *question;

    int noOfQuestions = loadQuestions("questions.txt", &question);
    playGame(question, noOfQuestions);

    return 0;
}

void clearBuffer () {
    while(getchar() != '\n');
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
    printf("\n%s%s%s", YELLOW_COLOR, question.question, COLOR_END);

    printf("\n%s", AQUA_COLOR);
    for (int i = 0; i < 4; i++)
    {
        printf("\n%c. %s", ('A' + i), question.options[i]);
    }
    printf("%s", COLOR_END);
    printf("\n\n%sHurry up you have only %d seconds to answer %s", YELLOW_COLOR, question.time, COLOR_END);

    printf("\n%s Enter your answer (A , B , C or D) or L for Lifeline %s", GREEN_COLOR, COLOR_END);
}

void fixStringInput(char *string)
{
    string[strcspn(string, "\n")] = '\0';
}

void playGame(Questions *questions, int noOfQuestions)
{
    int moneyWon = 0;
    int lifeline[] = {1, 1};
    for (int i = 0; i < noOfQuestions; i++)
    {
        printFormattedQuestion(questions[i]);
        char ch = getchar();
        clearBuffer();
        ch = toupper(ch);
        if (ch == 'L')
        {
            int returned = useLifeline(&questions[i], lifeline);
            if(returned != 2) {
                i--;
            }
            continue;
        }

        if (ch == questions[i].correctOption)
        {
            printf("%sCorrect Answer%s", GREEN_COLOR, COLOR_END);
            moneyWon = questions[i].prizeMoney;
            printf("\n%sYou have won %d ruppees. %s", BLUE_COLOR, moneyWon, COLOR_END);
        }
        else
        {
            printf("\n%sWrong Answer. Correct Answer is %c.%s", RED_COLOR, questions[i].correctOption, COLOR_END);
            break;
        }
    }
    printf("%s\nGame Over. Your total Winings are %d. %s", RED_COLOR, moneyWon, COLOR_END);
}

int useLifeline(Questions *question, int *lifeline)
{
    printf("\nAvailable Lifelines ");
    if (lifeline[0])
        printf("\n1. Fifty/Fifty (50/50) ");
    if (lifeline[1])
        printf("\n2. Skip the question ");
    printf("Choose a lifeline or 0 to return ");
    char ch = getchar();
    clearBuffer();
    switch(ch) {
        case '1':
        if(lifeline[0]){
        lifeline[0] = 0;
        int removed = 0;
        while(removed < 2) {
        int num  = rand() % 4;
        if( (num + 'A' ) != question->correctOption && question->options[num][0] != '\0'){
            question->options[num][0] = '\0';
            removed++;
        }
        }
        return 1;
        }
        break;
        case '2':
        if(lifeline[1]){
        lifeline[1] = 0;
        return 2;
        }
        break;
        default:
        printf("\nReturning to the question ");
    }
        return 0;

}