BUILTINS_PATH = src/builtins

SRC +=	$(BUILTINS_PATH)/is_builtins_command.c \
		$(BUILTINS_PATH)/exec_builtins_command.c \

OUT_DIRS += $(OUTPUT_DIR)/$(BUILTINS_PATH)
