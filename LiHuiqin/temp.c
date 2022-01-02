#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	if( (fp = fopen(argv[1],"r+")) == NULL)
	{
		perror("fopen ");
	}
	fseek(fp,0,SEEK_SET);

	char * str = malloc(sizeof(str));
	while(fgets(str,128,fp) != NULL )
	{
		printf("after a fgets, file position now is %ld\n",ftell(fp));
	}
	exit(0);
}
