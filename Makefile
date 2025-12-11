NAME = lib_marvin.a
EXE = marvin
CC = cc
CFLAGS = -Wall -Wextra -Werror
DB = build/
DS = src/
DU = $(DS)utils/
DC = $(DS)commands/
SRC =   $(DU)printable.c \
        $(DU)warping.c \
        $(DU)alloc.c \
        $(DC)list_cmd.c \
        $(DC)cmd_help.c \
        $(DC)cmd_bbl.c

OBJ = $(patsubst $(DS)%.c,$(DB)%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	ar crs $(NAME) $(OBJ)

$(DB)%.o : $(DS)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

main : $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o $(EXE)

path :
	mv $(EXE) $(HOME)/.local/bin/

clean : 
	rm -Rf "./bin"

fclean : clean
	rm -f "$(NAME)"

remove : fclean
	rm  $(HOME)/.local/bin/$(EXE)

re : fclean all main path

build : re
	echo "You can enjoy now"

.PHONY: all clean fclean re
