# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o Game.o Player.o Room.o Room1.o Room2.o Room3.o Feature.o Object.o Gravestone.o Knife.o
	$(CXX) $(CXXFLAGS) -o main main.o Game.o Player.o Room.o Room1.o Room2.o Room3.o Feature.o Object.o Gravestone.o Knife.o

# The main.o target can be written more simply

main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.h Player.h Room.h Room1.h Room2.h Room3.h Object.h globals.h 

Player.o: Player.h globals.h

Room.o: Room.h Feature.h Globals.h

Room1.o: Room1.h Room.h Gravestone.h

Room2.o: Room2.h Room.h

Room3.o: Room3.h Room.h

Feature.o: Feature.h globals.h

Object.o: Object.h Feature.h

Gravestone.o: Gravestone.h Feature.h

Knife.o: Knife.h Object.h

clean:
	rm main *.o
