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
PRINT_LIST.c \
check_arguments.c \
check_invalid_chars.c \
count_splits.c \
create_stack.c \
free_list.c \
freedom.c \
freexit.c \
ft_atolong.c \
ft_isnumber.c \
ft_putstr_fd.c \
ft_split.c \
ft_strdup.c \
ft_strlen.c \
get_lut.c \
ifreexit.c \
init_data.c \
populate_stack.c \
push_swap.c \
validate_inputs.c \
validate_splits.c \

# Names sources
SOURCES = $(addprefix $(SOURCEDIR)/,$(SRC_LIST))

# Names objects
OBJS := $(subst $(SOURCEDIR),$(BUILDDIR),$(SOURCES:.c=.o))

# Compiler
CC = gcc
CF = -Wall -Wextra -Werror
GDB = -ggdb
VAL = valgrind --trace-children=yes --leak-check=full --track-origins=yes ./$(NAME)

# Arguments to test the program with
RUN_ARGS = 1 12 123 1234 12345 1235456 1234567 12345678 123456789 1234567890

$(NAME): $(OBJS)
	@$(CC) $(CF) $(OBJS) $(INCLUDES) -o $(NAME)

objs/%.o: src/%.c
	@mkdir -p objs
	@$(CC) $(CF) $(GDB) $(INCLUDES) -c $< -o $@

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
	$(VAL) $(RUN_ARGS)

#make teste:


git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
