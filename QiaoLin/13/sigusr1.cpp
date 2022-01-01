#include <signal.h> // 处理信号的头文件
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
sig_atomic_t sigusr1_count = 0;
extern "C" { void OnSigUsr1( int signal_number ) { ++sigusr1_count; } }
int main ()
{
	std::cout << "pid: " << (int)getpid() << std::endl;
	struct sigaction sa;
	memset( &sa, 0, sizeof(sa) );
	sa.sa_handler = &OnSigUsr1;
	sigaction( SIGUSR1, &sa, NULL );
	sleep( 60 ); // 在终端中输入kill –s SIGUSR1 pid，信号计数器将递增
	std::cout << "SIGUSR1 counts: " << sigusr1_count << std::endl;
	return 0;
}
