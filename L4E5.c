/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 4. Considerando a estrutura abaixo para representar um vetor, implemente um programa que calcule a 
soma de dois vetores, sabendo que: A + B = < (a1 + a2), (b1 + b2), (c1 + c2) >
struct vetor{
int a;
int b;
int c;
};
*/

// !LIBRARIES _________________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! STRUCTS ___________________________________________________________________________________________________
struct A
{
    int a;
    int b;
    int c;
};

struct B
{
    int a;
    int b;
    int c;
};

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();


//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput(int size);
void messageConfirmExit();
void messageExit();
void messageName(struct A *a, struct B *b);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
int functionNumberInput();
void functionInputNumbers(struct A *a, struct B *b);


int main()
{
    int option, quantityOfError = 0, size;
    struct A a;
    struct B b;
    bool validation = false, exitValidation = false;

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
            functionInputNumbers(&a, &b);
            break;

        case 2:
            system("cls");
            quantityOfError = 0;
            messageName(&a, &b);
            break;

        case 3:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    case 3:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM N\351MERO V\265LIDO\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA FORMATAR OS NOMES\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("---------------------------------\n");
    printf("[1] ENTRADA DOS N\351MEROS\n");
    printf("[2] SA\326DA DOS DADOS DOS CARROS\n");
    printf("[3] SAIR DO PROGRAMA\n");
    printf("---------------------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int i)
{
    printf("DIGITE O N\351MERO %d: ", i);
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(struct A *a, struct B *b)
{
   int x = (a->a) + (b->a);
   int y = (a->b) + (b->b);
   int z = (a->c) + (b->c);

   printf("a1 + a2 = %d\n", x);
   printf("b1 + b2 = %d\n", y);
   printf("c1 + c2 = %d\n", z);
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION NUMBER INPUT
int functionNumberInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputNumbers(struct A *a, struct B *b)
{
    messageNameInput(1);
    a->a = functionNumberInput();
    system("cls");

    messageNameInput(2);
    a->b = functionNumberInput();
    system("cls");

    messageNameInput(3);
    a->c = functionNumberInput();
    system("cls");

    messageNameInput(1);
    b->a = functionNumberInput();
    system("cls");

    messageNameInput(2);
    b->b = functionNumberInput();
    system("cls");

    messageNameInput(3);
    b->c = functionNumberInput();
    system("cls");
}