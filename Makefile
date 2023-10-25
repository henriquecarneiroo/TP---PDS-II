all: obj/apartamento.o obj/evento.o obj/encomendas.o

obj/apartamento.o: apartamento.cpp apartamento.h
	c++ -c src/apartamento.cpp -I include -o obj/apartamento.o

obj/evento.o: evento.h evento.cpp apartamento.h
	c++ -c src/evento.cpp -I include -o obj/evento.o

obj/encomendas.o: encomendas.h encomendas.cpp apartamento.h
	c++ -c src/encomendas.cpp -I include -o obj/encomendas.o

debug: obj/apartamento.o obj/evento.o obj/encomendas.o
	c++ -g obj/apartamento.o obj/evento.o obj/encomendas.o -o main

clean:
	rm -f main obj/*