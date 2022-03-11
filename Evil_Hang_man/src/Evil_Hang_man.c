#include<stdio.h>
#include<stdlib.h>
#include"my_string.h"
#include "my_vector.h"
#include "my_tree.h"

void clear_keyboard_buffer();
#define SIZE 30
int main(int argc, char* argv[])
{

  int i;
    VECTOR arr[SIZE];
    VECTOR temp;
    FILE* fp;
    MY_STRING hMy_string;
    MY_STRING key;
    MY_STRING new_key;
    TREE_NODE hRoot;
    int numOfSameKey = 0;
    int wordSize = 0;
    int numTries = 0;
    int count = 0;
    int sizeOfVector = 0;
    char guess;

    fp = fopen("dictionary.txt", "r");
    if(fp==NULL)
    {
      printf("Failed to open file!\n");
      exit(1);
    }

    hMy_string = my_string_init_default();
    for(i=0; i<SIZE; i++)
    {
      arr[i] = my_vector_init_default();
    }

    //extract, take in the words from the file save to array based on size
    while(my_string_extraction(hMy_string, fp))
    {
      if(my_string_get_size(hMy_string)>=0 && my_string_get_size(hMy_string)<30)
      {
        my_vector_push(arr[my_string_get_size(hMy_string)],hMy_string);
      }
    }

    my_string_destroy(&hMy_string);

    //user input word size
    printf("How many letter do you want (1-29)?");
    scanf("%d", &wordSize);
    clear_keyboard_buffer();
    printf("How many tries do you want?");
    scanf("%d", &numTries);
    clear_keyboard_buffer();

    while(wordSize<=0 || wordSize>=30)
    {
      scanf("%d", &wordSize);
      clear_keyboard_buffer();
      if(wordSize<=0 || wordSize>=30)
      {
        printf("Please enter a valid number: ");
      }
    }

    //key
    key = my_string_init_default();
    new_key = my_string_init_default();
    for(i = 0; i<wordSize; i++)
    {
      my_string_push_back(key,'-');
      my_string_push_back(new_key,'-');
    }

    //copy everything to temp with same key
    temp = my_vector_copy_key(arr[wordSize],key);
    sizeOfVector = my_vector_get_size(temp);
    printf("initial size of vector = %d\n", sizeOfVector);

    printf("start---------\n");
    while(continue_key(key) && count<numTries && sizeOfVector!=0)
    {
      printf("Please enter your guess: ");
      scanf("%c",&guess);
      clear_keyboard_buffer();
      hRoot = my_tree_init_defult();

      for(i=0; i<sizeOfVector; i++)
      {
        get_word_key_value(key, new_key, *my_vector_at(temp,i), guess);
        hRoot = my_tree_insert(hRoot, new_key, *my_vector_at(temp,i));
      }

      printf("Print in order: \n");
      //print_in_order(hRoot);
      numOfSameKey = 0;
  	my_string_assignment(&new_key, key);
  	printf("size = %d\n", my_vector_get_size(temp));
      swap_vector(hRoot, &numOfSameKey, &new_key, &temp);
  	printf("size = %d\n", my_vector_get_size(temp));
  	sizeOfVector = my_vector_get_size(temp);
      printf("newkey before compare = ");
      my_string_insertion(new_key, stdout);
      printf("\n");
      //printf("size of k = %d  ", my_string_get_size(key));
      //printf("size of nk = %d\n", my_string_get_size(new_key));
      if(my_string_compare(new_key,key)==0)
      {
          printf("Sorry, the letter you entered is not in the word!\n");
      }else{
          printf("Congrats, the letter you entered is in the word!\n");
          my_string_assignment(&key, new_key);
  		printf("The new key is:   ");
  		my_string_insertion(key,stdout);
  		printf("\n");
      }

      my_tree_destory(&hRoot);

      count++;

      printf("After %d times: The key is ", count);
  	my_string_insertion(key, stdout);
  	printf("\n\n");

      if(count>= numTries && sizeOfVector != 1)
      {
        printf("Sorry, You failed!\n");
        printf("The word is: ");
        my_string_insertion(*my_vector_at(temp, 0),stdout);
      }else if(!continue_key(key)){
        printf("Congratualtion! You got it!\n");
        my_string_insertion(key,stdout);
      }
    }
    if (sizeOfVector == 0)
    {
  	  printf("There is no word with %d length!\n", wordSize);
    }
  // destory array with all words
    for(i=0; i<SIZE; i++)
    {
      my_vector_destory(&arr[i]);

    }
    my_string_destroy(&key);
    my_string_destroy(&new_key);
    my_vector_destory(&temp);
    fclose(fp);
    return 0;
  }

  void clear_keyboard_buffer(void)
  {
    char c;
    scanf("%c", &c);
    while(c!='\n')
    {
      scanf("%c", &c);
    }
  }
