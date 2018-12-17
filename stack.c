/* stack.c */
/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str)
{
	char buffer[24];
	char in1;
	char in2;
	memset(buffer, 0x1111, sizeof(buffer));
	/* The following statement has a buffer overflow problem */
	scanf("%c", &in1);
	strcpy(buffer, str);
	scanf(" %c", &in2);
	return 1;
}

int main(int argc, char **argv)
{
	char str[517];
	FILE *badfile;
	printf("pid = %d\n", getpid());
	badfile = fopen("badfile", "r");
	fread(str, sizeof(char), 517, badfile);
	bof(str);
	printf("Returned Properly\n");
	return 1;
}

