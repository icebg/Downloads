#include <unistd.h>
#include <stdio.h>
int main()
{
	uid_t uid = getuid(), euid = geteuid();
	uid_t gid = getgid(), guid = geteuid();
	printf("uid: %d; euid: %d\n", uid, euid );
	printf("gid: %d; guid: %d\n", uid, euid );

	return 0;
}
