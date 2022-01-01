#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
// 向临时文件中写入数据
int WriteToTempFile( char * buffer, size_t length )
{
	// 创建临时文件，“XXXXXX”将在生成时被替换，以保证文件名唯一性
	char temp_filename[] = "/tmp/temp_file.XXXXXX";
	int fd = mkstemp( temp_filename );
	// 取消文件链接，不显示该临时文件；关闭文件描述符后，临时文件被删除
	unlink( temp_filename );
	// 向临时文件中写入数据
	write( fd, &length, sizeof(length) );
	write( fd, buffer, length );
	// 返回临时文件的文件描述符
	return fd; }
	// 从临时文件中读取数据
char * ReadFromTempFile( int fd, size_t  length )
{
	// 定位到文件开头
	lseek( fd, 0, SEEK_SET );
	// 读取数据
	read( fd, &length, sizeof(length) );
	char * buffer = new char[length];
	read( fd, buffer, length );
	// 关闭文件描述符，临时文件将被删除
	close( fd );
	return buffer;
}
int main()
{
	char str[] = "hello,temp file\n";
	int fd;
	fd = WriteToTempFile(str,8);
	printf(ReadFromTempFile( fd, 8 ) );
	printf("\n");
	return 0;
}
