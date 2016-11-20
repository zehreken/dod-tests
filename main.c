#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
		/*
		char array[100];
		for (char i = 0; i < 100; ++i)
		{
				array[i] = i;
		}
		for (char i = 0; i < 100; ++i)
		{
				printf("%d\n", array[i]);
		}
		printf("%s\n", "Hello World");
		*/

		const char test[20] = "strong_password";
		printf("%s\n", "Enter Password");

		char pass[20];
		scanf("%s", pass);
		printf("%s\n", pass);

		if (strcmp(test, pass) == 0)
		{
				printf("%s\n", "Welcome Sir");
		}
		else
		{
				printf("%s\n", "Access Denied");
		}
		
		return 0;
}

