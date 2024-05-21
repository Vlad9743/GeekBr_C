// Задание 1. Поиск первого и последнего слова

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 2000

typedef struct list
{
    char* word;
    struct list *next;
}list;

list* insert_end(list *head, char* value)
{
    list *new = (list*)calloc(1,sizeof(list));
    int len = strlen(value);
    new->word = malloc(len+1);
    strcpy(new->word, value);

    if( head == NULL )
    {
        return new;
    }
    else
    {
        list *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = new;
        return head;
    }
}

void print_list(list * head)
{
    for (list* i = head; i != NULL; i = i->next)
        printf("%s ", i->word);
    putchar('\n');
}


int main(void)
{
    list *w_list = NULL;
    char word[STR_SIZE] = "";
    int ch = ' ';
    int i=0;
    while((ch = getchar()) != EOF)
    {
        switch(ch)
        {
            case '.':
            case ' ':
                word[i] = '\0';
                w_list  = insert_end(w_list, word);
                i=0; break;
            default:
                word[i++] = ch;
                if(i >= STR_SIZE)
                    i=0;
        }
        if('.' == ch)
            break;
    }

    printf("First word: %s\n", w_list->word);

    while(w_list->next != NULL)
            w_list = w_list->next;
    printf("Last word: %s\n", w_list->word);
}