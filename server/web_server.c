#include <stdio.h>
#include <sys/socket.h>

int main() {
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (server_fd == -1) {
		printf("Error creating socket\n");
		return 1;
	}
	printf("Socket created successfully\n");
	return 0;
}
