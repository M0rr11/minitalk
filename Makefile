CC = cc -Wall -Wextra -Werror
AR = ar rs
RM = rm -f
CLIENT = client
SERVER = server

CFILES =  ./utils/ft_atoi.c \
          ./utils/check.c \
          ./utils/ft_putchar_fd.c \
          ./utils/ft_putnbr_fd.c \
          ./utils/ft_putstr_fd.c \
          ./utils/ft_strlen.c

S_CLIENT = client.c
S_SERVER = server.c

O_FILES = $(CFILES:.c=.o)
O_CLIENT = $(S_CLIENT:.c=.o)
O_SERVER = $(S_SERVER:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(O_CLIENT) $(O_FILES)
	$(CC) $(O_CLIENT) $(O_FILES) -o $(CLIENT) 

$(SERVER): $(O_SERVER) $(O_FILES)
	$(CC) $(O_SERVER) $(O_FILES) -o $(SERVER)

clean: 
	$(RM) $(O_CLIENT) $(O_SERVER) $(O_FILES) 

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: re clean fclean all
