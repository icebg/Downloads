#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]) 
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	if (argc < 2) 
	{
		fprintf(stderr, "Usage:%s <filename>\n", argv[0]);
		exit(1);
	}
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL) 
	{
		perror("open() first time");
		exit(1);
	}
	fp2 = fopen(argv[1], "r+");
	if (fp2 == NULL) 
	{
		perror("open() second time");
		exit(1);
	}
	int count = 1;
	char * str = malloc(sizeof(str));
	long pos11,pos10;
	while( fgets(str,256,fp2) != NULL )
	{
		++count;
		if( count == 10 )
		{
			pos10=ftell(fp2); //record 10th line's start
			break;
		}
	}

	fseek(fp1,pos10,SEEK_CUR);
	fgets(str,256,fp1); //let fp1 goes to 11th line's start
	pos11=ftell(fp1);//record 11th line's start

	while( fgets(str,256,fp1) != NULL ) //at the beginning, str is the conten of 11th line
	{
		fputs(str,fp2);  //rewrite the 10th line
	}

	long lossSize = pos10-pos11,posEND;
	fseek(fp2,0,SEEK_END);
	posEND=ftell(fp2);
	ftruncate(fileno(fp2),posEND+lossSize);
	//---------------------------------------------------------------------------------------
	fclose(fp1);
	fclose(fp2);
	exit(0);
}
