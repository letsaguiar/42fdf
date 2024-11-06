#!/bin/sh
export ROOT_DIR=$(pwd)

#Compile Dependencies
export LIBFT_DIR="${ROOT_DIR}/libft"
make -C ${LIBFT_DIR} bonus

export PRINTF_DIR="${ROOT_DIR}/printf"
make -C ${PRINTF_DIR}

export GNL_DIR="${ROOT_DIR}/gnl"
make -C ${GNL_DIR}

#Compile and Run Tests
export CC="gcc"
export CFLAGS="-Wall -Wextra -Werror -g -fsanitize=address"
export CLIBS="-L${LIBFT_DIR} -lft \
-L${PRINTF_DIR} -lftprintf \
-L${GNL_DIR} -lgnl \
-lX11 -lXext -lm -lmlx"

export CINCLUDES="-I${LIBFT_DIR} \
-I${PRINTF_DIR}/src \
-I${PRINTF_DIR}/fstring/src \
-I${GNL_DIR}/src \
-I${ROOT_DIR}/src"

export SRC_DIR="${ROOT_DIR}/src"
export SRC_FILES=$(find ${SRC_DIR} -name "*.c")

export RUNNER="${ROOT_DIR}/runner"
${CC} ${CFLAGS} ${SRC_FILES} ${FILE} -o ${RUNNER} ${CLIBS} ${CINCLUDES}
${RUNNER}
rm -f ${RUNNER}