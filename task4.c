
/*task4.
Напишіть програму, яка містить:
1) процедуру putEl(), яка приймає на вхід індекс елемента масиву, його значення і вставляє в потрібну
комірку масиву;
2) функцію getEl(), яка приймає на вхід індекс елемента масиву і повертає значення,
 що відповідає даному індексу.
Примітка: обидві функції повинні перевіряти, чи не виходить вказаний індекс за межі розмірності масиву!!!
В цілому програма повинна виконувати таку послідовність дій (в циклі!):
- початкове обнулення всього масиву;
- введення з клавіатури індексу елемента і самого елемента, який потрібно вставити в масив;
- вставку елемента в масив;
- виведення масиву на екран для перевірки;
- введення з клавіатури індексу елемента, який потрібно знайти в масиві;
- виведення на екран елемента, знайденого за введеним індексом;
- запит користувачу на повторення перелічених дій, або припинення роботи.
Примітка: кожну перелічену дію реалізувати як окрему процедуру (функцію)!
Модифікуйте програму на випадок двовимірного масиву.
*/
#include <stdio.h>
#include<stdlib.h>
#define N 20

void input(int* mas, int *index, int *number){//Введення даних
       do{
        printf("Input index: ");
        scanf("%i",index);
        printf("Input number: ");
        scanf("%i",number);
    }
    while(!(*index >=0 && *index <N));
}
//приймає на вхід індекс елемента масиву, його значення і вставляє в потрібну
//комірку масиву, якщо в даній комірці є запис, підтвердження на перезапис;
void putEl(int *mas, int index, int number){
    while(1){
        //input(mas, index, number);
        if(mas[index] != 0){
            printf("The cell is not empty, rewrite it?(y/n) ");
            char answ;
            scanf("%s", &answ);
            getchar();
            switch (answ) {
                case 'Y':
                case 'y': mas[index]=number;
                          //printf("\n%i ", mas[index]);
                          return 0;
                    break;
                case 'N':
                case 'n':break;
                default: printf("\nTeam is wrong");
                    break;
            }
        }
        else {
           mas[index]=number;
           //printf("\n%i ", mas[index]);
           return 0;
        }

    }
}
//процедура getEl(), яка приймає на вхід індекс елемента масиву і повертає значення,
// що відповідає даному індексу. перевіряє, чи не виходить вказаний індекс за межі розмірності масиву!!!
void getEl(int* mas, int *index){

    do{
        printf("Find Input index: ");
        scanf("%i",index);
    }
    while(!(*index >=0 && *index <N));
    printf("\nFind number: %i\n",mas[*index]);
}
//вивід на екран масив
void printArr(int *mas){
    printf("\nYour array: ");
    for(int i = 0; i< N; i++){
        printf("%i ",mas[i]);
    }
    printf("\n");
}
//Функція запиту на повторення дій
int repeatPr()
{
    printf("\nRepeat? (y/n) ");
    char answ;

    scanf("%s", &answ);
    getchar();

    switch (answ) {
        case 'Y':
        case 'y': return 1;
            break;
        case 'N':
        case 'n': return 0;
        break;
        default: printf("\nTeam is wrong"); return 0;
            break;
    }
}

int main()
{
    int mas[N]={};
    int *pmas = mas;
    int p=1;

    while(p){
        int index=0, number=0;
        input(mas, &index, &number);
        putEl(pmas, index, number);
        printArr(pmas);
        getEl(pmas, &index);
        system("pause");
        p = repeatPr();
    }

    return 0;
}
