

Inbox
417


Starred


Snoozed


Sent


Drafts
17

More


Hangouts













More
1 of 1,116







Fwd: labs
Inbox
x




Bo Yu

3:34 PM (1 hour ago)



to me






This is the COMPLETE LAB including AVL tree

---------- Forwarded message ---------
From: Bo Yu <byuacc866@gmail.com>
Date: Fri, May 3, 2019 at 11:00 AM
Subject: labs
To: Bo Yu <byuacc866@gmail.com>








29 Attachments









Reply
Forward






















#include<stdlib.h>
#include<ctype.h>
#include "my_string.h"

int get_string_size(char*);
struct my_string
{
    int size;
    int max;
    char* letters;
};

typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
    My_string* pstring;
    pstring= (My_string*)malloc(sizeof(My_string));
    if(pstring!=NULL)
    {
        pstring->size=0;
        pstring->max=7;
        pstring->letters = (char*)malloc(sizeof(char)*7);
        if(pstring->letters==NULL)
            return NULL;
    }
    return pstring;
}
MY_STRING my_string_init_c_string(char* temp)
{
    My_string* pstring;
    pstring= (My_string*)malloc(sizeof(My_string));
    if(pstring!=NULL)
    {
        pstring->size=get_string_size(temp);
        pstring->max=get_string_size(temp)+1;
        pstring->letters = malloc(sizeof(char)*pstring->max);
        for(int i=0;i<=(pstring->size);i++)
        {
            pstring->letters[i]=temp[i];
        }
    }
    return pstring;
}
int my_string_get_capacity(MY_STRING hMystring)
{
    My_string* pstring =(My_string*) hMystring;
    return pstring->max;
}
int my_string_get_size(MY_STRING hMystring)
{
    My_string* pstring =(My_string*) hMystring;
    return pstring->size;
}
int get_string_size(char*temp)
{
    int i=0;
    while(temp[i]!='\0')
    {
        i++;
    }
    return i;
}

int my_string_compare(MY_STRING str1, MY_STRING str2)
{
    int i=0;
    My_string* first = str1;
    My_string* second = str2;
    while(i<first->size &&(first->letters[i]==second->letters[i]))
    {
        i++;
    }
    if(i>=first->size)
    {
      return 0;
    }
    return (int)first->letters[i]-(int)second->letters[i];
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
    My_string* temp = (My_string*) hMy_string;
    char* string;
    int i=0;
    temp->size=0;
    if(fp==NULL||feof(fp))
    {
        return false;
    }
    char c=getc(fp);
    while(isspace(c))
    {
        c=getc(fp);
    }
    if(c==EOF)
    {
        return false;
    }
    while(!feof(fp)&&!isspace(c))
    {
        temp->letters[i]=c;
        temp->size++;
        i++;
        if(temp->size>=temp->max)
        {
            string = realloc(temp->letters,(temp->max)*2+1);
            if(string==NULL)
            {
                return false;
            }
            temp->letters=string;
            temp->max=(temp->max)*2+1;
        }
        c=getc(fp);
    }
    ungetc(c,fp);
    return true;
}

Status my_string_insertion(MY_STRING hMy_string, FILE * fp)
{
    My_string* temp = (My_string*)hMy_string;

    for(int i =0;i<temp->size;i++)
    {
        fprintf(fp,"%c",temp->letters[i]);
    }
    return true;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
    My_string* temp = (My_string*)hMy_string;
    char*string;
    if(temp->size+1>=temp->max)
    {
        string = realloc(temp->letters,(temp->max)*2+1);
        if(string==NULL)
        {
            return false;
        }
        temp->letters=string;
        temp->max=(temp->max)*2+1;
    }
    temp->letters[temp->size]=item;
    temp->size++;
    return true;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
    My_string* temp = (My_string*)hMy_string;
    if(temp->size==0||temp->max==0)
    {
        return false;
    }
    temp->size--;
    return true;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
    My_string* temp = (My_string*)hMy_string;
    if(index<0||index>=temp->size)
    {
        return NULL;
    }
    return &(temp->letters[index]);
}

char* my_string_c_str(MY_STRING hMy_string)
{
    My_string* temp = (My_string*)hMy_string;
    char*string;
    temp->letters[(temp->size)]='\0';
    temp->size++;
    if(temp->size>=temp->max)
    {
        string = realloc(temp->letters,(temp->max)*2+1);
        if(string==NULL)
        {
            return false;
        }
        temp->letters=string;
        temp->max=(temp->max)*2+1;
    }
    return (temp->letters);
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
    My_string* temp = (My_string*)hResult;
    My_string* temp2 = (My_string*)hAppend;
    char*string;
    if((temp->size==0) && (temp2->size==0))
    {
        return true;
    }
    if((temp->size+temp2->size)>=temp->max)
    {
        string = realloc(temp->letters,(temp->max+temp2->max));
        if(temp==NULL)
        {
            return false;
        }
        temp->letters=string;
        temp->max =temp->max+temp2->max;

    }
    for(int i =0;i<=temp2->size;i++)
    {

        temp->letters[temp->size]=temp2->letters[i];
        temp->size++;
    }
    return true;

}

Status my_string_isempty(MY_STRING hMy_string)
{
    My_string* string = hMy_string;
    return (string->size=0)?true:false;
}
void my_string_destroy(Item * phMy_string)
{
    My_string* pstring = (My_string*)*phMy_string;
    free(pstring->letters);
    free(pstring);
    *phMy_string=NULL;
}

void my_string_assignment(Item* pLeft, Item Right)
{
    My_string * string = (My_string*)*pLeft;
    My_string * temp= Right;
    int i;
    if(string!=NULL)
    {
        my_string_destroy(pLeft);
    }
    string = my_string_init_default();
    for(i=0;i<(temp->size);i++)
    {
        my_string_push_back(string,temp->letters[i]);
    }
    *pLeft=string;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
    My_string* cwf = (My_string*)current_word_family;
    My_string* nk = (My_string*)new_key;
    My_string* pWord = (My_string*)word;
    char* temp;
    int i;
    if(nk->max < cwf->max)
    {
        temp = (char*) malloc(sizeof(char)* cwf->max);
        if(temp == NULL)
        {
            printf("Failed to reallocate memory for new_key");
            return false;
        }
        nk->max = cwf->max;
        free(nk->letters);
        nk->letters = temp;
    }
    nk->size = pWord->size;
    for(i=0; i< nk->size; i++)
    {
        if(tolower(pWord->letters[i]) == tolower(guess))
        {
            nk->letters[i] = tolower(guess);
        }
        else
        {
            nk->letters[i] = cwf->letters[i];
        }
    }
    return true;
}

//safe to assume their size is identical
Status is_key(MY_STRING pString,MY_STRING pString2)
{
    int i;
    My_string* first = pString;
    My_string* second = pString2;
    for(i=0;i<second->size;i++)
    {
        if(second->letters[i]!='-'&&(first->letters[i]!=second->letters[i]))
        {
            return false;
        }
    }
    return true;
}

Status continue_key(MY_STRING key)
{
    My_string * temp =key;
    int i ;
    for(i=0;i<my_string_get_size(key);i++)
    {
        if(temp->letters[i]=='-')
        {
            return true;
        }
    }
    return false;
}

