#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<netdb.h>

int main(int argc, char*argv[]){

int socket_desc, new_socket, c;
struct sockaddr_in server, client;
char*message;
char client_reply[2000]={0};
//create socket

socket_desc = socket(AF_INET, SOCK_STREAM, 0);
if(socket_desc == -1){
printf("Could not create a socket \n");
}

//prepare sockaddr_in structure
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons(8888);

//bind
if(bind(socket_desc, (struct sockaddr*)&server, sizeof(server))<0){

puts("Bind Failed \n");
return 1;
}

puts("bind done \n");

//lsiten
listen(socket_desc, 3);

//accept and incoming connection
puts("Waiting for incoming connections. . . ");
c = sizeof(struct sockaddr_in);
while((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))){

puts("Connection accepted \n");

if(recv(socket_desc, client_reply,2000, 0),0){
puts("Cant receive from client.. \n");
}

//printf("Activity : %s \n ", client_reply);
puts("Boskiut tgh buat: \n");
puts(client_reply);

message = "Buat apa tu boskiut?! \n";
write(new_socket, message, strlen(message));
}
//recieve reply from client
/*if(recv(socket_desc, client_reply,2000, 0)<0){
puts("Cant receive from client.. \n");
}

puts("Activity : ");
printf("%s", client_reply);
*/



if(new_socket < 0){
perror("Accept Failed");
return 1;
}
return 0;
}
