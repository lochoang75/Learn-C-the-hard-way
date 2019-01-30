#include <stdio.h>
#include "stdlib.h"

// this function print all value of array 
void print_array(int* ages, char**name, int size)
{

	if(ages == NULL)
	{
		printf("Pointer not allocated.\n");
		return;
	}
	for(int i = 0; i < size; i++)
	{
		printf("%s is %d years old. \n",name[i],ages[i]);
	}
}

int main(int argc, char *argv[])
{
	// create two arrays we care about
	int ages[] = {23, 43, 12, 89, 2};
	char *name[] = {
		"Alan", "Frank",
		"Marry", "John", "Lisa"
	};
	int test_arr[]={};
	char* test_char_array[]={};
	int *test_int;
	char **test_char;
	
	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	
	//first way using indexing
	for(i = 0; i < count; i++){
		printf("%s has %d years alive. \n", name[i], ages[i]);
		printf("Array allocated at %p and %p. \n",&name[i],&ages[i]);
	}

	printf("---\n");
	
	// setup the pointer to the start of the arrays
	int*cur_age = ages;
	char **cur_name = name;

	// seccond way using pointers
	for(i = 0; i < count; i++){
		printf("%s is %d years old. \n",
			*(cur_name+i), *(cur_age+i));
		printf("Memory allocated at: %p and %p. \n",cur_name+i,cur_age+i);
	}

	printf("-----\n");
 
	// third way, pointers are just arrays
	for(i = 0; i < count; i++){
		printf("%s is %d years old again. \n",cur_name[i],cur_age[i]);
	}

	printf("----\n");
	
	// fourth way with pointers in a stupid complex way
	for(cur_name = name, cur_age = ages;
		(cur_age - ages) < count;
		cur_name++,cur_age++)
	{
		printf("%s lived %d years so far.\n",
			*cur_name, *cur_age);
	}
	
	printf("---\n");

	// Fifth way using function with same syntax
	print_array(ages,name,count);

	return 0;
} 

	

