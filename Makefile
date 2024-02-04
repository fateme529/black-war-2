all: compile link 

compile:
	g++ -Isfml/include -c src/main.cpp  src/app.cpp src/game.cpp src/enemy.cpp src/heli.cpp src/shoot.cpp

link:
	g++ main.o app.o game.o enemy.o heli.o shoot.o -o  app -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio