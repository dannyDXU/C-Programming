#include<stdio.h>
#include<stdlib.h>
#include "my_vector.h"

typedef struct my_vector{
    int size;
    int capacity;
    Item*data;
}Vector;

VECTOR my_vector_init_default(void)
{
    Vector* pVector;
    int i;
    pVector = (Vector*)malloc(sizeof(Vector));
    if (pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = malloc(sizeof(Item)*pVector->capacity);
        if (pVector->data == NULL)
        {
            free(pVector);
            return NULL;
        }
        for(i=0;i<pVector->capacity;i++)
        {
            pVector->data[i]=NULL;
        }
    }
    return (VECTOR)pVector;
}

int my_vector_get_size(VECTOR hVector)
{
    Vector* pVector = hVector;
    return pVector->size;
}

int my_vector_get_capcity(VECTOR hVector)
{
    Vector* pVector = hVector;
    return pVector->capacity;
}

Status my_vector_push(VECTOR hVector,Item hItem)
{
    Vector* pVector = (Vector*)hVector;
    Item* temp;
    int i;
    //check if need resize
    if(pVector->size >= pVector->capacity)
    {
        temp = (Item*)malloc(sizeof(Item)
                             *(((pVector->capacity*4)/3)+1));
        //check malloc failed
        if(temp == NULL)
        {
            return false;
        }
        //if temp successfully malloc, NULL out all elements
        for(i=0; i<((pVector->capacity*4)/3)+1; i++)
        {
            temp[i] = NULL;
        }
        //copy elements from previous array to new one
        for(i=0; i<pVector->size; i++)
        {
            my_string_assignment(&temp[i], pVector->data[i]);
            //check if assignment failed
            if(temp[i]==NULL)
            {
                free(temp);
                printf("Assignment failed\n");
                return false;
            }
        }
        pVector->capacity = ((pVector->capacity*4)/3)+1;
        //destroy previous array
        for(i=0; i<pVector->size; i++)
        {
            my_string_destroy(&pVector->data[i]);
        }
        free(pVector->data);
        //set previous array pointer = current array
        pVector->data = temp;
    }
    my_string_assignment(&pVector->data[pVector->size], hItem);
    pVector->size++;
    return true;
}

Status my_vector_pop(VECTOR hVector)
{
    Vector* pVector = hVector;
    if (pVector->size <= 0)
    {
        return false;
    }
    my_string_destroy(&(pVector->data[pVector->size - 1]));
    pVector->size--;
    return true;
}
void my_vector_destory(VECTOR * temp)
{
    int i;
    Vector * pVector = *temp;
    for (i = 0; i < pVector->size; i++)
    {
        my_string_destroy(&pVector->data[i]);
    }
    free(pVector->data);
    free(pVector);
    *temp=NULL;
}

Item* my_vector_at(VECTOR hVector, int index)
{
    Vector* pVector =hVector;
    if (index < 0 || index >= pVector->size)
    {
        return NULL;
    }
    return &(pVector->data[index]);
}

VECTOR my_vector_copy_key(VECTOR pVector,MY_STRING pString)
{
    int i ;
    MY_STRING key = pString;
    Vector * temp = pVector;
    Vector * new_list = my_vector_init_default();
    for(i =0;i<temp->size;i++)
    {
        if(is_key(temp->data[i],key))
        {
            my_vector_push(new_list,temp->data[i]);
        }
    }
    return new_list;
}

void my_vector_toString(VECTOR pVector)
{
    Vector*temp = pVector;
    int i;
    for(i=0;i<temp->size;i++)
    {
        my_string_insertion(temp->data[i],stdout);
        printf("\n" );
    }
}
