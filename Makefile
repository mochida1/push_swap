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
SRC_LIST = add_to_mv_list.c \
check_arguments.c \
check_invalid_chars.c \
check_repeated_numbers.c \
count_splits.c \
create_moves_array.c \
create_stack.c \
free_list.c \
free_moves_array.c \
free_pin.c \
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
get_stack_index.c \
ifreexit.c \
init_data.c \
lcs.c \
mv_px.c \
mv_rrx.c \
mv_rx.c \
mv_sx.c \
mv_wrapper.c \
print_moves.c \
populate_stack.c \
push_swap.c \
set_pin.c \
sort_lut.c \
sort_radix.c \
sort_radix_utils.c \
sort_vb.c \
sort_vb_utils01.c \
sort_vb_utils02.c \
sort_vb_utils03.c \
sort_vb_utils04.c \
sort_three.c \
sort_two.c \
update_stacks_data.c \
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
RUN_ARGS = "170 -184 69 11 -16 -222 -136 123 -69 116 -80 -158 -97 13 -179 -18 -142 -81 -146 -108 120 248 -56 91 -168 -239 -4 41 130 95 54 -230 63 6 31 52 204 -138 -215 -178 -172 124 187 23 -62 26 27 -121 229 -231 106 192 -79 128 67 38 -243 -165 -75 185 121 -244 242 -47 51 -203 -123 -27 -64 -116 -83 161 -38 -61 89 212 -120 110 237 -34 190 -229 -242 156 -19 -197 -60 56 -91 96 231 169 165 83 -94 -96 215 -237 225 -15 125 65 227 158 -246 183 210 16 -45 -227 -102 -119 39 -241 -148 -141 37 -95 -139 -20 -7 -31 239 -67 230 20 103 104 -127 -89 73 86 -1 -130 160 152 -144 -129 0 240 -117 12 -125 -26 175 147 -112 132 -17 -22 136 181 -160 -149 -194 -57 -87 180 -126 -23 -107 -54 -98 -156 -219 -66 -109 -100 -70 -207 236 -140 -217 -200 238 -92 -105 -63 3 -37 -118 182 -223 112 233 -236 99 211 137 -170 118 -115 -198 -51 92 -113 -181 241 201 -13 -29 224 122 -211 -216 -174 90 14 88 -220 -171 129 55 -182 249 -169 -103 177 -25 53 -135 166 59 -53 200 -72 -177 19 -101 171 -232 -151 -161 -44 -213 -114 -21 -40 -188 -205 -35 209 188 -82 34 206 194 -52 -238 -124 226 250 -24 -221 50 98 -152 36 -84 21 143 74 -3 -133 102 203 107 5 -185 -59 109 172 57 -189 66 82 32 184 202 -167 245 -137 -2 -48 -192 214 150 9 68 208 -10 -196 -78 -106 -88 -147 -235 -11 -173 222 -6 -49 75 -14 29 196 77 -132 10 149 -93 -99 4 80 219 198 113 2 159 179 162 -187 -183 246 -247 186 -128 47 155 -58 81 -157 -85 -249 -36 111 221 -50 -43 -228 93 44 138 7 -65 -166 40 -176 -122 35 -32 -76 223 220 -90 -46 79 -180 60 135 -71 -12 -30 168 193 -5 114 22 -248 167 -175 -150 85 189 115 87 -33 -55 33 -195 -41 1 197 -209 -202 -214 -104 -193 -42 -8 247 213 -110 105 235 -212 49 178 195 61 -245 -201 62 -86 84 15 -39 154 217 -143 -234 76 72 -73 -233 146 94 25 -77 145 -190 64 127 100 243 58 -225 117 176 142 133 28 -240 -74 134 216 -68 -111 174 -131 -164 108 42 45 141 191 48 205 199 126 244 -191 78 232 -210 -218 -153 119 163 97 173 46 -224 30 144 234 -186 43 218 207 -204 140 139 -226 101 151 17 153 -145 164 -9 8 -154 -206 71 -208 24 -199 131 228 -159 -163 70 18 -28 -134 148 -162 157 -155"

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
