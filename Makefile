NAME = push_swap
NAME_FS = push_swap_fs
SOURCEDIR = src
BUILDDIR = objs
LIBS = libs


# Makes make look for source in this dir
#VPATH = $(SOURCEDIR)

# headers
INCLUDES = -I /headers

# Lists sources. Manually because of norm...
SRC_LIST = PRINT_LIST.c \
add_to_mv_list.c \
check_arguments.c \
check_invalid_chars.c \
check_repeated_numbers.c \
count_splits.c \
create_moves_array.c \
create_stack.c \
free_list.c \
free_moves_array.c \
free_print_list.c \
freedom.c \
freexit.c \
ft_atolong.c \
ft_isnumber.c \
ft_isspace.c \
ft_putstr_fd.c \
ft_split.c \
ft_strdup.c \
ft_strlen.c \
get_lut.c \
ifreexit.c \
init_data.c \
mv_px.c \
mv_rrx.c \
mv_rx.c \
mv_sx.c \
mv_wrapper.c \
print_moves.c \
populate_stack.c \
push_swap.c \
sort_lut.c \
sort_two.c \
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
FSF = -fsanitize=address

# Arguments to test the program with
RUN_ARGS = "01234567 012345678 0123456789 01234567890" "0 01 012 0123 01234 012345 " " -1 -12 -123 -1234 -12345 -1235456" "-1234567890 -123456789 -12345678 -1234567"

$(NAME): $(OBJS)
	@$(CC) $(CF) $(OBJS) $(INCLUDES) -o $(NAME)

$(NAME_FS): $(OBJS)
	@$(CC) $(CF) $(FSF) $(OBJS) $(INCLUDES) -o $(NAME_FS)

objs/%.o: src/%.c
	@mkdir -p objs
	@$(CC) $(CF) $(GDB) $(INCLUDES) -c $< -o $@

all: $(NAME)

fs: $(NAME_FS)

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_FS)

re: fclean all

# maybe if bonus.
bonus:

# from here on shit ain't mandatory or bonus
run: all
	$(VAL) $(RUN_ARGS)

make teste: $(NAME_FS)
	./$(NAME_FS) $(RUN_ARGS)



git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
