# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o Game.o Player.o Room.o Room1.o Room2.o Feature.o Object.o
	$(CXX) $(CXXFLAGS) -o main main.o Game.o Player.o Room.o Room1.o Room2.o Feature.o Object.o

# The main.o target can be written more simply

main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.h Player.h Room.h Room1.h Room2.h Object.h

Player.o: Player.h

Room.o: Room.h Feature.h

Room1.o: Room1.h Room.h

Room2.o: Room2.h Room.h

Feature.o: Feature.h

Object.o: Object.h

clean:
	rm main *.o
