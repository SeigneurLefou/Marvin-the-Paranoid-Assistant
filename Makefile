# === VARIABLES ===============================================================

NAME = marvin
CXX = g++
CFLAGS = -Wall -Wextra -g
INCLUDE = -Iincludes

ifndef $(MARV)
	export MARV=$(PWD)
endif

BUILD_DIR = $(MARV)/build
SRC_DIR = $(MARV)/src
OUT_DIRS := $(BUILD_DIR)/$(SRC_DIR)
SRC = $(SRC_DIR)/main.cpp

# =============================================================================

# === INCLUDES ================================================================

include $(SRC_DIR)/builtins/builtins.make

# =============================================================================

# === OBJECT RULES ============================================================

OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

$(BUILD)%.o: $(SRC_DIR)%.c
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo -e "CC $<\n\t>$@\n"

# =============================================================================

# === UTILS RULES =============================================================

all: build

re: fclean all

# =============================================================================

# === CLEAN RULES =============================================================

clean: 
	@rm -Rf "$(BUILD_DIR)"
	@echo -e "DELETE $(BUILD_DIR) FOLDER\n"

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
