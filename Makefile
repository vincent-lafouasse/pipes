NAME = pipex

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = src

SRCS = $(shell find "$(SRC_DIR)" -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC        = cc
CFLAGS    = -Wall -Wextra -g3
#CFLAGS   += -Werror
CPPFLAGS  = -I$(INCLUDE_DIR)
CPPFLAGS += -MMD -MP

LIBFT_PATH = ./lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_MAKE_PATH = $(LIBFT_PATH)
LIBFT_INCLUDE_PATH = $(LIBFT_PATH)
LIBFT_LIB_PATH = $(LIBFT_PATH)

CPPFLAGS += -I$(LIBFT_PATH)/include
LDFLAGS = -L$(LIBFT_LIB_PATH)
LDLIBS = -lft
LIBS = $(LIBFT)

.PHONY: all
all: build

.PHONY: run
run: build
	./$(NAME) Makefile "grep build" "grep test" local_out

.PHONY: build
build: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

# Compilation
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_MAKE_PATH)


.PHONY: re
re: fclean build

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	make clean -C $(LIBFT_MAKE_PATH)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_MAKE_PATH)

# VERBOSITY = --verbose

# LSP stuff, don't worry about it
.PHONY: update
update: fclean
	mkdir -p $(BUILD_DIR)
	bear $(VERBOSITY) --output $(BUILD_DIR)/compile_commands.json -- make build

.PHONY: test
test: $(LIBFT)
	cmake -S test -B build/test
	cmake --build build/test
	GTEST_COLOR=1 ctest --test-dir build/test

.PHONY: vtest
vtest: $(LIBFT)
	cmake -S test -B build/test
	cmake --build build/test
	GTEST_COLOR=1 ctest --test-dir build/test -V

CPPCHECKFLAGS  = --language=c
# not available on distant server CPPCHECKFLAGS += --check-level=exhaustive
CPPCHECKFLAGS += --cppcheck-build-dir=build
CPPCHECKFLAGS += --project=build/compile_commands.json
.PHONY: check
check: update
	cppcheck $(CPPCHECKFLAGS)
	# norminette $(SRC_DIR)

# aliases
.PHONY: b c u r t vt
b: build
c: clean
u: update
r: run
t: test
vt: vtest

-include $(DEPS)
