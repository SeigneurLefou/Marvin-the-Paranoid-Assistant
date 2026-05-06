# === VARIABLES ===============================================================
NAME = marvin
CXX = g++
CFLAGS = -Wall -Wextra -g
INCLUDE = -Iincludes

ifndef $(MARV)
	export MARV=$(PWD)
endif

BUILD = $(MARV)/build
DS = $(MARV)/src
SRC = $(DS)/main.cpp

# =============================================================================

# === OBJECT RULES ============================================================
OBJ = $(patsubst $(DS)/%.c,$(BUILD)/%.o,$(SRC))

$(BUILD)%.o: $(DS)%.c
	@mkdir -p $(BUILD)
	@$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo -e "CC $<\n\t>$@\n"

# =============================================================================

# === UTILS RULES =============================================================

all: build

re: fclean all

# =============================================================================

# === CLEAN RULES =============================================================

clean: 
	@rm -Rf "$(BUILD)"
	@echo -e "DELETE $(BUILD) FOLDER\n"

fclean: clean
	@echo -e "DELETE $(NAME)\n"

remove:
	@rm -Rf $(MARV)
	@echo -e "Good bye..."
	
# =============================================================================

# === INSTALL RULES ===========================================================

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)
	@echo -e "CC $<\n\t>$@\n"

build: $(NAME)
	@cp $(MARV)/$(NAME) $(HOME)/.local/bin/
	@echo -e "You can enjoy now !"

update:
	@cd $(MARV)
	@git pull
	@./install.sh
	@echo -e "PULL NEW DATA FROM THE PUBLIC REPO\n"
	@make -C $(MARV) build

# =============================================================================

.PHONY: clean fclean remove re build all
