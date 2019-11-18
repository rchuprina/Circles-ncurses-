NAME = circ

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses -lm
SRCS = src/main.c src/list.c src/scene.c
RSRCS = $(SRCS:src/%=%)
INC = inc/header.h
RINC = $(INC:inc/%=%)

all: install clean

install: 
	@cp $(INC) $(SRCS) .
	@clang $(FLAGS) $(RSRCS) -I $(RINC) -o $(NAME)

uninstall: 
	@rm -f $(NAME)

clean: 
	@rm -f $(RSRCS) $(RINC)

reinstall: uninstall all
