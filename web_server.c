#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>


#define PORT 8080
#define BUFFER_SIZE 1024
#define FILENAME_SIZE 100


// Function to handle the client request
void send_file(in client_socket, const char* filename);

int main() {
	int server_fd, new_socket;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[BUFFER_SIZE] = {0};
	char filename[FILENAME_SIZE] = {0};

	// Create socket
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))==0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	while (1) {
		printf("Waiting for a connection");

		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
			perror("accept failed");
			exit(EXIT_FAILURE);
		
		}

		read(new_socket, buffer, BUFFER_SIZE);
		printf("Received request: \n%s\n", buffer);

		// Parse the HTTP request to get the file name
		sscanf(buffer, "GET /%s", flename);
		if (strlen(filename) == 0) {
			strcpy(filename, "index.html");
		}

	}
}
