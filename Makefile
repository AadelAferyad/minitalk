NAME := server
BONUS := client 
CC := cc
CFLAGS := -Wall -Wextra -Werror

server_src = server.c 
minitalk = minitalk_util.c
minitalk1 = minitalk_util.c
client_src = client.c 

client_src_bonus = client_bonus.c 
server_src_bonus = server_bonus.c


OBJSERVER = ${server_src:.c=.o} 
OBJCLIENT = ${client_src:.c=.o} 

OBJSERVER_BONUS = ${server_src_bonus:.c=.o}
OBJCLIENT_BONUS = ${client_src_bonus:.c=.o}

all: $(NAME)

server: $(OBJSERVER) $(OBJCLIENT) $(minitalk)
	$(CC) $(CFLAGS) $(OBJSERVER) $(minitalk) -o server
	$(CC) $(CFLAGS) $(OBJCLIENT) $(minitalk) -o client

clean: 
	rm -rf server.o client.o server_bonus.o client_bonus.o

fclean: clean
	rm -rf server client

bonus: $(BONUS)

client: $(OBJSERVER_BONUS) $(OBJCLIENT_BONUS) $(minitalk1)
	$(CC) $(CFLAGS) $(OBJCLIENT_BONUS) $(minitalk1) -o client 
	$(CC) $(CFLAGS) $(OBJSERVER_BONUS) $(minitalk1) -o server

re: fclean all
