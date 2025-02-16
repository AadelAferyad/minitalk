NAME := server client
BONUS := server_bonus client_bonus
CC := cc
CFLAGS := -Wall -Wextra -Werror

server_src = server.c 
minitalk = minitalk_util.c
client_src = client.c 

client_src_bonus = client_bonus.c 
server_src_bonus = server_bonus.c

OBJUTIL = ${minitalk:.c=.o} 

OBJSERVER = ${server_src:.c=.o}  
OBJCLIENT = ${client_src:.c=.o} 

OBJSERVER_BONUS = ${server_src_bonus:.c=.o}
OBJCLIENT_BONUS = ${client_src_bonus:.c=.o}

all: $(NAME)

server: $(OBJSERVER) $(OBJUTIL)
	$(CC) $(CFLAGS) $(OBJSERVER) $(OBJUTIL) -o $@

clien: $(OBJCLIENT) $(minitalk_util.c)
	$(CC) $(CFLAGS) $(OBJCLIENT) minitalk_util.c -o $@

clean: $(NAME)
	rm -rf $(NAME)

bonus: $(BONUS)

server_bonus: $(OBJSERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJSERVER_BONUS) -o server

client_bonus: $(OBJCLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJCLIENT_BONUS) -o client 

fclean:
	clean
re: fclean all
