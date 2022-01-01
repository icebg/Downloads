#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	if( (fp = fopen("hello.txt","r+")) == NULL)
	{
		perror("fopen hello.txt");
	}
	fseek(fp,0,SEEK_SET);
	printf("%ld\n", ftell(fp));
		exit(0);
}
