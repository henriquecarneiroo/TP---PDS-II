all: obj/apartamento.o obj/encomendas.o obj/evento.o obj/funcoes_auxiliares.o 

obj/funcoes_auxiliares.o: funcoes_auxiliares.cpp funcoes_auxiliares.h apartamento.h
	c++ -c src/funcoes_auxiliares.cpp -I include -o obj/funcoes_auxiliares.o

obj/apartamento.o: apartamento.cpp funcoes_auxiliares.cpp apartamento.h funcoes_auxiliares.h
	c++ -c src/apartamento.cpp -I include -o obj/apartamento.obj

obj/evento.o: 