#include<stdio.h>
#include<stdlib.h>
#include <dirent.h>
int main()
{
	DIR * dirp; //pointer to directory
	struct dirent *p; //pointer to struct dirent

	if( (dirp = opendir("."))==NULL )
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}

	while( (p=readdir(dirp))!=NULL ) // read  a directory file
	{
		printf("%s\n",p->d_name);
	}
	closedir(dirp);
	return 0;
}
