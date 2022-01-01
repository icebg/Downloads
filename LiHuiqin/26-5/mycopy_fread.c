/*
 * 用fread，fwrite实现复制文件
 * zhanghexie
 * 2020-12-12
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 1024 //BUFFSIZE actually means member_nums in function fread
// the real buffersize should be [items * member_nums]

int main(int argc, char* argv[]) {
	FILE *fps, *fpd;
	char buf[BUFFSIZE];
	int num; // 保存读到字节数。

	if(argc < 3) {
		fprintf(stderr,"Usage:%s <src_file> <dst_file>\n",argv[0]);
		exit(1);
	}

	fps = fopen(argv[1], "r");
	if (NULL == fps) {
		perror("fopen(fps)");
		exit(1);
	}

	fpd = fopen(argv[2], "w");
	if (NULL == fpd) {
		// 不关闭会导致内存泄漏。
		fclose(fps);
		perror("fopen(fpd)");
		exit(1);
	}

	while ((num = fread(buf,1,BUFFSIZE,fps)) > 0) {//num charactes each time (num might be 1024 or less)
		//in the loop, the FREAD reads 1*BUFFSIZE bytes or less each time. Return Value:the number of items actually read or written. 
		fwrite(buf,1,num,fpd); //how much read,how much to write
	}

	puts("well down!");
	fclose(fpd);
	fclose(fps);
	exit(0);
}
