#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int spawn( char * program, char ** args );
int main ()
{
	char * args[] = { "ls", "-l", "/", NULL };
	spawn( "ls", args );
	cout << "Done!\n";
	return 0;
}

// 创建一个子进程运行新程序
// program为程序名，arg_list为程序的参数列表；返回值为子进程id
int spawn( char * program, char ** args ) 
{
	pid_t child_pid = fork(); // 复制进程
	if( child_pid != 0 ) // 此为父进程
		return child_pid;
	else // 此为子进程
	{
		execvp( program, args ); // 执行程序，按路径查找
		// 只有发生错误时，该函数才返回
		std::cerr << "Error occurred when executing execvp.\n";
		abort ();
	} 
}
