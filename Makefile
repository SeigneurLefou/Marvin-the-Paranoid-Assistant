# === VARIABLES ===============================================================

NAME = marvin.a
MARV = .marvin
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
        $(DC)cmd_update.c \
        $(DC)cmd_bbl.c

# =============================================================================

# === OBJECT RULES ============================================================
OBJ = $(patsubst $(DS)%.c,$(DB)%.o,$(SRC))

$(NAME) : $(OBJ)
	ar crs $(NAME) $(OBJ)

$(DB)%.o : $(DS)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# === CLEAN RULES =============================================================

clean : 
	rm -Rf "./bin"

fclean : clean
	rm -f "$(NAME)"

remove : fclean
	rm -f $(HOME)/.local/bin/$(EXE)

desintall : remove
	rm -Rf $(HOME)/$(MARV)
	echo "Good bye"
	
# =============================================================================

# === INSTALL RULES ============================================================

main : $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o $(EXE)

path :
	mv $(EXE) $(HOME)/.local/bin/


build : re
	export PATH=$PATH:$HOME/.local/bin/
	echo "You can enjoy now"

update :
	cd $(HOME)/$(MARV)
	git pull
	make -C $(HOME)/$(MARV) build

# =============================================================================

all : $(NAME)

re : fclean all main path build

.PHONY: all clean fclean re
