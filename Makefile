NAME = fdf

SRCS_LIST_ACT := key_button.c change_camera.c rotation.c zoom.c translate.c
DIR_ACT = ./srcs/actions
SRCS_LIST_PROJ := model.c projection.c dot_cross.c proj_utils.c
DIR_PROJ = ./srcs/projection
SRCS_LIST_PAR :=	params.c max_size.c
DIR_PAR = ./srcs/params
SRCS_LIST_DRAW := render.c  primitives.c color.c
DIR_DRAW = ./srcs/draw
SRCS_LIST_IN_EXIT := init.c input.c free_map.c destroy.c bad_alloc_exit.c
DIR_IN_EXIT = ./srcs/Input_Exit
SRCS_LIST_ITER =	iter.c copy_reset.c plus_minus_inplace.c find_min_max.c
DIR_ITER = ./srcs/iter
SRCS_ACT = $(addprefix ${DIR_ACT}/,${SRCS_LIST_ACT})
SRCS_PROJ = $(addprefix ${DIR_PROJ}/,${SRCS_LIST_PROJ})
SRCS_PAR = $(addprefix ${DIR_PAR}/,${SRCS_LIST_PAR})
SRCS_DRAW = $(addprefix ${DIR_DRAW}/,${SRCS_LIST_DRAW})
SRCS_IN_EXIT = $(addprefix ${DIR_IN_EXIT}/,${SRCS_LIST_IN_EXIT})
SRCS_ITER = $(addprefix ${DIR_ITER}/,${SRCS_LIST_ITER})
SRCS = ${SRCS_ACT} ${SRCS_PROJ} ${SRCS_DRAW} ${SRCS_IN_EXIT} ${SRCS_ITER} ${SRCS_PAR}
SRCS_LIST = ${SRCS_LIST_ACT} ${SRCS_LIST_PROJ} ${SRCS_LIST_DRAW} ${SRCS_LIST_IN_EXIT} ${SRCS_LIST_ITER} ${SRCS_LIST_PAR}
OBJS_LIST = ${SRCS_LIST:.c=.o}
OBJS_DIR = ./objs
OBJS = $(addprefix ${OBJS_DIR}/,${OBJS_LIST})
DIRS = ${DIR_ACT} ${DIR_DRAW} ${DIR_IN_EXIT} ${DIR_ITER} ${DIR_PAR} ${DIR_PROJ}
DEPS = ${OBJS:.o=.d}


SCREEN_WIDTH = 2048
SCREEN_HEIGHT = 1152

MLX_DIR = ./libmlx
LIBFT = libft.a
LIBFT_DIR = ./libft

CC = gcc
CFLAGS := -g -Wall -Wextra -Werror -fsanitize=address
LDFLAGS := -L${LIBFT_DIR} -L${MLX_DIR}

OS = $(shell uname -s)
ifeq ($(OS), Darwin)
MLX = libmlx.a
LIBRARIES = ${MLX_DIR}/${MLX} ${LIBFT_DIR}/${LIBFT}
FRAMEWORK = -framework OpenGl -framework Appkit
INCLUDE = -I/opt/X11/inlcude/X11 -I${LIBFT_DIR} -I./includes
CFLAGS += -DMACOS ${INCLUDE}
endif
ifeq ($(OS), Linux)
MLX = libmlx_Linux.a
LIBRARIES = ${MLX_DIR}/${MLX} ${LIBFT_DIR}/${LIBFT} -L/usr/lib -lXext -lX11 -lm -lz 
INCLUDE = -I${LIBFT_DIR} -I/usr/include/X11 -I./includes
CFLAGS += -DLINUX ${INCLUDE}
endif
TEST_LINKS = https://projects.intra.42.fr/uploads/document/document/5974/maps.zip

all : ${LIBFT} ${NAME}

${LIBFT} : ${LIBFT_DIR}
	make -C $^

${NAME} : srcs/main.c ${OBJS}
	${CC} ${CFLAGS} ${LDFLAGS} $^ -o $@ ${LIBRARIES} ${FRAMEWORK}

${OBJS_DIR}/%.o : ${DIR_ACT}/%.c
	${CC} ${CFLAGS} -c $< -DSCREEN_WIDTH=${SCREEN_WIDTH} -DSCREEN_HEIGHT=${SCREEN_HEIGHT} -o $@
${OBJS_DIR}/%.o : ${DIR_PROJ}/%.c
	${CC} ${CFLAGS} -c $< -DSCREEN_WIDTH=${SCREEN_WIDTH} -DSCREEN_HEIGHT=${SCREEN_HEIGHT} -o $@
${OBJS_DIR}/%.o : ${DIR_PAR}/%.c
	${CC} ${CFLAGS} -c $< -DSCREEN_WIDTH=${SCREEN_WIDTH} -DSCREEN_HEIGHT=${SCREEN_HEIGHT} -o $@
${OBJS_DIR}/%.o : ${DIR_ITER}/%.c
	${CC} ${CFLAGS} -c $< -DSCREEN_WIDTH=${SCREEN_WIDTH} -DSCREEN_HEIGHT=${SCREEN_HEIGHT} -o $@
${OBJS_DIR}/%.o : ${DIR_IN_EXIT}/%.c
	${CC} ${CFLAGS} -c $< -DSCREEN_WIDTH=${SCREEN_WIDTH} -DSCREEN_HEIGHT=${SCREEN_HEIGHT} -o $@
${OBJS_DIR}/%.o : ${DIR_DRAW}/%.c
	${CC} ${CFLAGS} -c $< -DSCREEN_WIDTH=${SCREEN_WIDTH} -DSCREEN_HEIGHT=${SCREEN_HEIGHT} -o $@

launch_tests : ${NAME}
	curl -L ${TEST_LINKS} --output maps.zip
	unzip -j maps.zip  -x __MACOSX/*/* -d maps
	for i in $(addprefix maps/,$(shell ls maps)); do echo $$i; ./${NAME} $$i; done
	#rm -rf maps maps.zip

${OBJS} : | ${OBJS_DIR}

${OBJS_DIR} :
	mkdir -p $@

clean :
	make clean -C ${LIBFT_DIR}
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re : fclean all

-include ${DEPS}

.PHONY : all clean fclean re launch_tests
