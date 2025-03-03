AS				:=	nasm
ASFLAGS			:=	-felf64

CC				:=	cc
CFLAGS			:=	-Wall -Werror -Wextra
LFLAGS			:=	

SRC_DIR			:=	src
BIN_DIR			:=	bin

SOURCES			:=	ft_strlen ft_strcpy
OBJECTS			:=	$(SOURCES:%=$(BIN_DIR)/%.o)

TEST_SRC_DIR	:=	test
TEST_BIN_DIR	:=	test_bin

TEST_SOURCES	:=	main
TEST_OBJECTS	:=	$(TEST_SOURCES:%=$(TEST_BIN_DIR)/%.o)

LIBASM			:=	libasm.a
TEST_BIN		:=	tester

all: test

lib: $(LIBASM)

test: $(TEST_BIN)

$(TEST_BIN): $(LIBASM) $(TEST_OBJECTS)
	$(CC) -o $@ $(TEST_OBJECTS) $(LIBASM) $(LFLAGS)

$(LIBASM): $(OBJECTS)
	$(AR) rcs $(LIBASM) $(OBJECTS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(@D)
	$(AS) -o $@ $< $(ASFLAGS)

$(TEST_BIN_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)
