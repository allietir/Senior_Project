# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o Game.o Player.o Room.o Room1.o Room2.o Room3.o Room4.o Room5.o Room6.o Room7.o Room8.o Room9.o Room10.o Room11.o Room12.o Room13.o Room14.o Room15.o Feature.o Object.o Feature1.o Feature2.o Feature3.o Feature4.o Feature5.o Feature6.o Feature7.o Feature8.o Feature9.o Feature10.o Feature11.o Feature12.o Feature13.o Feature14.o Feature15.o Feature16.o Feature17.o Feature18.o Feature19.o Feature20.o Feature21.o Feature22.o Feature23.o Feature24.o Feature25.o Feature26.o Feature27.o Feature28.o Feature29.o Feature30.o Object1.o Object2.o Object3.o Object4.o Object5.o Object6.o Object7.o Object8.o
	$(CXX) $(CXXFLAGS) -o main main.o Game.o Player.o Room.o Room1.o Room2.o Room3.o Room4.o Room5.o Room6.o Room7.o Room8.o Room9.o Room10.o Room11.o Room12.o Room13.o Room14.o Room15.o Feature.o Object.o Feature1.o Feature2.o Feature3.o Feature4.o Feature5.o Feature6.o Feature7.o Feature8.o Feature9.o Feature10.o Feature11.o Feature12.o Feature13.o Feature14.o Feature15.o Feature16.o Feature17.o Feature18.o Feature19.o Feature20.o Feature21.o Feature22.o Feature23.o Feature24.o Feature25.o Feature26.o Feature27.o Feature28.o Feature29.o Feature30.o Object1.o Object2.o Object3.o Object4.o Object5.o Object6.o Object7.o Object8.o

# The main.o target can be written more simply

main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.h Player.h Room.h Room1.h Room2.h Room3.h Room4.h Room5.h Room6.h Room7.h Room8.h Room9.h Room10.h Room11.h Room12.h Room13.h Room14.h Room15.h Object.h globals.h 

Player.o: Player.h globals.h

Room.o: Room.h Feature.h Globals.h

Room1.o: Room1.h Room.h Feature1.h Feature2.h

Room2.o: Room2.h Room.h Feature3.h Feature4.h

Room3.o: Room3.h Room.h Feature5.h Feature6.h

Room4.o: Room4.h Room.h Feature7.h Feature8.h

Room5.o: Room5.h Room.h Feature9.h Feature10.h

Room6.o: Room6.h Room.h Feature11.h Feature12.h

Room7.o: Room7.h Room.h Feature13.h Feature14.h

Room8.o: Room8.h Room.h Feature15.h Feature16.h

Room9.o: Room9.h Room.h Feature17.h Feature18.h

Room10.o: Room10.h Room.h Feature19.h Feature20.h

Room11.o: Room11.h Room.h Feature21.h Feature22.h

Room12.o: Room12.h Room.h Feature23.h Feature24.h

Room13.o: Room13.h Room.h Feature25.h Feature26.h

Room14.o: Room14.h Room.h Feature27.h Feature28.h

Room15.o: Room15.h Room.h Feature29.h Feature30.h

Feature.o: Feature.h globals.h

Object.o: Object.h Feature.h

Feature1.o: Feature1.h Feature.h

Feature2.o: Feature2.h Feature.h

Feature3.o: Feature3.h Feature.h

Feature4.o: Feature4.h Feature.h

Feature5.o: Feature5.h Feature.h

Feature6.o: Feature6.h Feature.h

Feature7.o: Feature7.h Feature.h

Feature8.o: Feature8.h Feature.h

Feature9.o: Feature9.h Feature.h

Feature10.o: Feature10.h Feature.h

Feature11.o: Feature11.h Feature.h

Feature12.o: Feature12.h Feature.h

Feature13.o: Feature13.h Feature.h

Feature14.o: Feature14.h Feature.h

Feature15.o: Feature15.h Feature.h

Feature16.o: Feature16.h Feature.h

Feature17.o: Feature17.h Feature.h

Feature18.o: Feature18.h Feature.h

Feature19.o: Feature19.h Feature.h

Feature20.o: Feature20.h Feature.h

Feature21.o: Feature21.h Feature.h

Feature22.o: Feature22.h Feature.h

Feature23.o: Feature23.h Feature.h

Feature24.o: Feature24.h Feature.h

Feature25.o: Feature25.h Feature.h

Feature26.o: Feature26.h Feature.h

Feature27.o: Feature27.h Feature.h

Feature28.o: Feature28.h Feature.h

Feature29.o: Feature29.h Feature.h

Feature30.o: Feature30.h Feature.h

Object1.o: Object1.h Object.h

Object2.o: Object2.h Object.h

Object3.o: Object3.h Object.h

Object4.o: Object4.h Object.h

Object5.o: Object5.h Object.h

Object6.o: Object6.h Object.h

Object7.o: Object7.h Object.h

Object8.o: Object8.h Object.h

clean:
	rm main *.o
