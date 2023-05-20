start:program calistir

program:cppler main
	g++ ./lib/dosya.o ./lib/satirDugum.o ./lib/satirListe.o ./lib/yoneticiDugum.o ./lib/yoneticiListe.o ./lib/ekran.o ./lib/main.o -o ./bin/program
cppler:
	g++ -I "./include" -c ./src/dosya.cpp -o ./lib/dosya.o
	g++ -I "./include" -c ./src/satirDugum.cpp -o ./lib/satirDugum.o
	g++ -I "./include" -c ./src/satirListe.cpp -o ./lib/satirListe.o
	g++ -I "./include" -c ./src/yoneticiDugum.cpp -o ./lib/yoneticiDugum.o
	g++ -I "./include" -c ./src/yoneticiListe.cpp -o ./lib/yoneticiListe.o
	g++ -I "./include" -c ./src/ekran.cpp -o ./lib/ekran.o
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
calistir:
	./bin/program.exe