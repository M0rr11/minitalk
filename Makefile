CC = cc -Wall -Wextra -Werror
AR	= ar rs
RM	= rm -f

FILES = 
		
BFILES =


OBJ = $(FILES:.c=.o)
BOBJ = $(BFILES:.c=.o)
NAME =

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $(NAME) 


bonus: 

clean: 
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: re clean fclean bonus all
