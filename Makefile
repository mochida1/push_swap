NAME = push_swap
SOURCEDIR = src
BUILDDIR = objs
LIBS = libs


# Makes make look for source in this dir
#VPATH = $(SOURCEDIR)

# headers
INCLUDES = -I /headers

# Lists sources. Manually because of norm...
SRC_LIST = me.c \
push_swap.c \


# Names sources
SOURCES = $(addprefix $(SOURCEDIR)/,$(SRC_LIST))

# Names objects
OBJS := $(subst $(SOURCEDIR),$(BUILDDIR),$(SOURCES:.c=.o))

# Compiler
CC = gcc
CF = -Wall -Wextra -Werror
GDB = -ggdb
VAL = valgrind ./$(NAME)

# Arguments to test the program with
RUN_ARGS = 1 3 2 5 4

$(NAME): $(OBJS)
	@$(CC) $(CF) $(OBJS) $(INCLUDES) -o $(NAME)

objs/%.o: src/%.c
	@mkdir -p objs
	@$(CC) $(CF) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

# maybe if bonus.
bonus:

# from here on shit ain't mandatory or bonus
run: all
	$ARGS='8 5 6 3 2 4 7 10 -5 -8'
	./$(NAME) $ARGS

#make teste:


git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
