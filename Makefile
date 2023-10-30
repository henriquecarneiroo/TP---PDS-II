CC=g++
CFLAGS=-std=c++11 -Wall
TARGET = tp_execution

BUILD = ./build
INCLUDE = ./include
SRC = ./src

${TARGET} : ${BUILD}/Apartamento.o ${BUILD}/Encomendas.o ${BUILD}/Evento.o ${BUILD}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD}/Apartamento.o ${BUILD}/Encomendas.o ${BUILD}/Evento.o ${BUILD}/main.o

${BUILD}/Apartamento.o : ${INCLUDE}/apartamento.hpp ${SRC}/apartamento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/apartamento.cpp -o ${BUILD}/Apartamento.o

${BUILD}/Encomendas.o : ${INCLUDE}/encomendas.hpp ${SRC}/encomendas.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/encomendas.cpp -o ${BUILD}/Encomendas.o

${BUILD}/Evento.o : ${INCLUDE}/evento.hpp ${SRC}/evento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/evento.cpp -o ${BUILD}/Evento.o

${BUILD}/main.o : ${INCLUDE}/apartamento.hpp ${INCLUDE}/encomendas.hpp ${INCLUDE}/evento.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD}/main.o

clean:
	rm -f ${BUILD}/*