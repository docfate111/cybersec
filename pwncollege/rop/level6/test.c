#include <stdio.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <errno.h>
int main(){
	int d = open("/flag", 0);
	printf("sendfile return value: %ld\n", sendfile(0, d, 0, 80));
	return 0;
}
