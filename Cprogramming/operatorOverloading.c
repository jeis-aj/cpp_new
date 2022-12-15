#include <stdio.h>

void new();
void new(char);
void main()
{
	char word[] = "hello world";
	printf("%s",word);
	new();
}

void new()
{
	char word[] = "hello world";
	printf("%s",word);
}

void new(char ch)
{
	char word[] = "hello world";
	printf("%s",word);
}
