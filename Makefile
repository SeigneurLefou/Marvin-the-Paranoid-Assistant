# === VARIABLES ===============================================================
MARV = .marvin/
EXE = marvin
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iincludes
BUILD = build/
BIN = bin/
DS = src/
CMD = cmd/
SRC =   $(DS)printable.c \
        $(DS)warping.c \
        $(DS)alloc.c \
        $(DS)list_cmd.c \
        $(DS)cmd_help.c \
        $(DS)cmd_update.c \

CMD_LIST =	bbl

CMD_SRC = $(addprefix $(CMD)cmd_,$(addsuffix .c,$(CMD_LIST)))

CMD_EXE = $(addprefix $(BIN),$(CMD_LIST))

# =============================================================================

# === OBJECT RULES ============================================================
OBJ = $(patsubst $(DS)%.c,$(BUILD)%.o,$(SRC))

$(BUILD)%.o : $(DS)%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# === CLEAN RULES =============================================================

clean : 
	rm -Rf "$(HOME)/$(MARV)$(BUILD)"

fclean : clean
	rm -f $(HOME)/.local/bin/$(EXE)

uninstall : remove
	rm -Rf $(HOME)/$(MARV)
	echo "Good bye"
	
# =============================================================================

# === INSTALL RULES ============================================================

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE)  main.c $(OBJ) -o $(EXE)

$(CMD_EXE) : $(CMD_SRC)
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(INCLUDE) $< $(OBJ) -o $@

build : $(EXE) $(CMD_EXE)
	mv $(EXE) $(HOME)/.local/bin/
	export PATH=$(PATH):$(HOME)/.local/bin/
	@echo "You can enjoy now"

update :
	cd $(HOME)/$(MARV)
	git pull
	make -C $(HOME)/$(MARV) build

# =============================================================================

all : $(EXE) $(addprefix $(BIN),$(EXTRA_CMDS)) build

re : fclean all

.PHONY: all clean fclean re uninstall build
