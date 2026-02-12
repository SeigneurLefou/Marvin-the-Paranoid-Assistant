# === VARIABLES ===============================================================
MARV = .marvin/
PROJ = $(HOME)/$(MARV)
EXE = marvin
CC = cc
CFLAGS = -Wall -Wextra
INCLUDE = -Iincludes
BUILD = $(PROJ)build/
BIN = $(PROJ)bin/
USRBIN = $(PROJ)usr/bin/
DS = $(PROJ)src/
CMD = $(PROJ)cmd/
SRC =	$(DS)printable.c \
        $(DS)warping.c \
        $(DS)alloc.c \
        $(DS)cmd_help.c \
        $(DS)cmd_update.c

CMD_PATH = includes/cmd_path.h

CMD_LIST =	bubble

# =============================================================================

# === OBJECT RULES ============================================================
OBJ = $(patsubst $(DS)%.c,$(BUILD)%.o,$(SRC))

$(BUILD)%.o: $(DS)%.c
	@mkdir -p $(BUILD)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "CC $<\n\t>$@"

# =============================================================================

# === UTILS RULES =============================================================

all: build

bin: $(CMD_LIST)

re: fclean all bin

# =============================================================================

# === CLEAN RULES =============================================================

clean: 
	@rm -Rf "$(BUILD)"
	@echo "DELETE $(BUILD) FOLDER"

fclean: clean
	@rm -f $(HOME)/.local/bin/$(EXE)
	@echo "DELETE $(EXE)"

uninstall: remove
	@rm -Rf $(PROJ)
	@echo "Good bye"
	
# =============================================================================

# === INSTALL RULES ===========================================================

$(CMD_LIST):
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(INCLUDE) "$(CMD)cmd_$@.c" $(OBJ) -o "$(BIN)$@"

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE)  main.c $(OBJ) -o $(EXE)

build: $(EXE) bin
	mkdir -p $(USRBIN)
	mv $(EXE) $(HOME)/.local/bin/
	@echo "You can enjoy now"

update:
	cd $(PROJ)
	git pull
	make -C $(PROJ) build

# =============================================================================

.PHONY: clean fclean uninstall re link build all
