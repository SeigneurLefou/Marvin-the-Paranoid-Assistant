# === VARIABLES ===============================================================
MARV = .marvin/
PROJ = $(HOME)/$(MARV)
EXE = marvin
CC = cc
CFLAGS = -Wall -Wextra -w -g
INCLUDE = -Iincludes
BUILD = $(PROJ)build/
BIN = $(PROJ)bin/
USRBIN = $(PROJ)usr/bin/
DS = $(PROJ)src/
CMD = $(PROJ)cmd/
SRC =	$(DS)printable.c \
        $(DS)wraping.c \
        $(DS)alloc.c \
        $(DS)cmd_help.c \
        $(DS)cmd_update.c

CMD_PATH =	includes/cmd_path.h

CMD_LIST =	say

# =============================================================================

# === OBJECT RULES ============================================================
OBJ = $(patsubst $(DS)%.c,$(BUILD)%.o,$(SRC))

$(BUILD)%.o: $(DS)%.c
	@mkdir -p $(BUILD)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo -e "CC $<\n\t>$@\n"

# =============================================================================

# === UTILS RULES =============================================================

all: build

bin: $(CMD_LIST)

re: fclean all bin

# =============================================================================

# === CLEAN RULES =============================================================

clean: 
	@rm -Rf "$(BUILD)"
	@echo -e "DELETE $(BUILD) FOLDER\n"

fclean: clean
	@rm -f $(HOME)/.local/bin/$(EXE)
	@echo -e "DELETE $(EXE)\n"

uninstall: remove
	@rm -Rf $(PROJ)
	@echo -e "Good bye..."
	
# =============================================================================

# === INSTALL RULES ===========================================================

$(CMD_LIST):
	@mkdir -p $(BIN)
	@$(CC) $(CFLAGS) $(INCLUDE) "$(CMD)cmd_$@.c" $(OBJ) -o "$(BIN)$@"
	@echo -e "CC $(CMD)cmd_$@\n\t>$(BIN)$@\n"

$(EXE): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE)  main.c $(OBJ) -o $(EXE)
	@echo -e "CC $<\n\t>$@\n"

build: $(EXE) bin
	@mkdir -p $(USRBIN)
	@mv $(EXE) $(HOME)/.local/bin/
	@echo -e "You can enjoy now !"

update:
	@cd $(PROJ)
	@git pull
	@echo -e "PULL NEW DATA FROM THE PUBLIC REPO\n"
	@make -C $(PROJ) build

# =============================================================================

.PHONY: clean fclean uninstall re link build all
