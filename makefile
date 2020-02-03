# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o Game.o Player.o Room/Room.o Room/Room1.o Room/Room2.o Room/Room3.o Room/Room4.o Room/Room5.o Room/Room6.o Room/Room7.o Room/Room8.o Room/Room9.o Room/Room10.o Room/Room11.o Room/Room12.o Room/Room13.o Room/Room14.o Room/Room15.o Feature/Feature.o Object/Object.o Feature/Feature1.o Feature/Feature2.o Feature/Feature3.o Feature/Feature4.o Feature/Feature5.o Feature/Feature6.o Feature/Feature7.o Feature/Feature8.o Feature/Feature9.o Feature/Feature10.o Feature/Feature11.o Feature/Feature12.o Feature/Feature13.o Feature/Feature14.o Feature/Feature15.o Feature/Feature16.o Feature/Feature17.o Feature/Feature18.o Feature/Feature19.o Feature/Feature20.o Feature/Feature21.o Feature/Feature22.o Feature/Feature23.o Feature/Feature24.o Feature/Feature25.o Feature/Feature26.o Feature/Feature27.o Feature/Feature28.o Feature/Feature29.o Feature/Feature30.o Object/Object1.o Object/Object2.o Object/Object3.o Object/Object4.o Object/Object5.o Object/Object6.o Object/Object7.o Object/Object8.o
	$(CXX) $(CXXFLAGS) -o main main.o Game.o Player.o Room/Room.o Room/Room1.o Room/Room2.o Room/Room3.o Room/Room4.o Room/Room5.o Room/Room6.o Room/Room7.o Room/Room8.o Room/Room9.o Room/Room10.o Room/Room11.o Room/Room12.o Room/Room13.o Room/Room14.o Room/Room15.o Feature/Feature.o Object/Object.o Feature/Feature1.o Feature/Feature2.o Feature/Feature3.o Feature/Feature4.o Feature/Feature5.o Feature/Feature6.o Feature/Feature7.o Feature/Feature8.o Feature/Feature9.o Feature/Feature10.o Feature/Feature11.o Feature/Feature12.o Feature/Feature13.o Feature/Feature14.o Feature/Feature15.o Feature/Feature16.o Feature/Feature17.o Feature/Feature18.o Feature/Feature19.o Feature/Feature20.o Feature/Feature21.o Feature/Feature22.o Feature/Feature23.o Feature/Feature24.o Feature/Feature25.o Feature/Feature26.o Feature/Feature27.o Feature/Feature28.o Feature/Feature29.o Feature/Feature30.o Object/Object1.o Object/Object2.o Object/Object3.o Object/Object4.o Object/Object5.o Object/Object6.o Object/Object7.o Object/Object8.o

# The main.o target can be written more simply

main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.h Player.h Room/Room.h Room/Room1.h Room/Room2.h Room/Room3.h Room/Room4.h Room/Room5.h Room/Room6.h Room/Room7.h Room/Room8.h Room/Room9.h Room/Room10.h Room/Room11.h Room/Room12.h Room/Room13.h Room/Room14.h Room/Room15.h Object/Object.h globals.h 

Player.o: Player.h globals.h

Room/Room.o: Room/Room.h Feature/Feature.h globals.h

Room/Room1.o: Room/Room1.h Room/Room.h Feature/Feature1.h Feature/Feature2.h

Room/Room2.o: Room/Room2.h Room/Room.h Feature/Feature3.h Feature/Feature4.h

#Room/Room3.o: Room/Room3.h Room/Room.h Feature/Feature5.h Feature/Feature6.h

Room/Room4.o: Room/Room4.h Room/Room.h Feature/Feature7.h Feature/Feature8.h

#Room/Room5.o: Room/Room5.h Room/Room.h Feature/Feature9.h Feature/Feature10.h

#Room/Room6.o: Room/Room6.h Room/Room.h Feature/Feature11.h Feature/Feature12.h

#Room/Room7.o: Room/Room7.h Room/Room.h Feature/Feature13.h Feature/Feature14.h

#Room/Room8.o: Room/Room8.h Room/Room.h Feature/Feature15.h Feature/Feature16.h

#Room/Room9.o: Room/Room9.h Room/Room.h Feature/Feature17.h Feature/Feature18.h

#Room/Room10.o: Room/Room10.h Room/Room.h Feature/Feature19.h Feature/Feature20.h

#Room/Room11.o: Room/Room11.h Room/Room.h Feature/Feature21.h Feature/Feature22.h

#Room/Room12.o: Room/Room12.h Room/Room.h Feature/Feature23.h Feature/Feature24.h

#Room/Room13.o: Room/Room13.h Room/Room.h Feature/Feature25.h Feature/Feature26.h

#Room/Room14.o: Room/Room14.h Room/Room.h Feature/Feature27.h Feature/Feature28.h

#Room/Room15.o: Room/Room15.h Room/Room.h Feature/Feature29.h Feature/Feature30.h

Feature/Feature.o: Feature/Feature.h globals.h 

Object/Object.o: Object/Object.h Feature/Feature.h

Feature/Feature1.o: Feature/Feature1.h Feature/Feature.h

Feature/Feature2.o: Feature/Feature2.h Feature/Feature.h 

Feature/Feature3.o: Feature/Feature3.h Feature/Feature.h

Feature/Feature4.o: Feature/Feature4.h Feature/Feature.h

Feature/Feature5.o: Feature/Feature5.h Feature/Feature.h

Feature/Feature6.o: Feature/Feature6.h Feature/Feature.h

Feature/Feature7.o: Feature/Feature7.h Feature/Feature.h

Feature/Feature8.o: Feature/Feature8.h Feature/Feature.h

Feature/Feature9.o: Feature/Feature9.h Feature/Feature.h

Feature/Feature10.o: Feature/Feature10.h Feature/Feature.h

Feature/Feature11.o: Feature/Feature11.h Feature/Feature.h

Feature/Feature12.o: Feature/Feature12.h Feature/Feature.h

Feature/Feature13.o: Feature/Feature13.h Feature/Feature.h

Feature/Feature14.o: Feature/Feature14.h Feature/Feature.h

Feature/Feature15.o: Feature/Feature15.h Feature/Feature.h

Feature/Feature16.o: Feature/Feature16.h Feature/Feature.h

Feature/Feature17.o: Feature/Feature17.h Feature/Feature.h

Feature/Feature18.o: Feature/Feature18.h Feature/Feature.h

Feature/Feature19.o: Feature/Feature19.h Feature/Feature.h

Feature/Feature20.o: Feature/Feature20.h Feature/Feature.h

Feature/Feature21.o: Feature/Feature21.h Feature/Feature.h

Feature/Feature22.o: Feature/Feature22.h Feature/Feature.h

Feature/Feature23.o: Feature/Feature23.h Feature/Feature.h

Feature/Feature24.o: Feature/Feature24.h Feature/Feature.h

Feature/Feature25.o: Feature/Feature25.h Feature/Feature.h

Feature/Feature26.o: Feature/Feature26.h Feature/Feature.h

Feature/Feature27.o: Feature/Feature27.h Feature/Feature.h

Feature/Feature28.o: Feature/Feature28.h Feature/Feature.h

Feature/Feature29.o: Feature/Feature29.h Feature/Feature.h

Feature/Feature30.o: Feature/Feature30.h Feature/Feature.h

Object/Object1.o: Object/Object1.h Object/Object.h

Object/Object2.o: Object/Object2.h Object/Object.h

Object/Object3.o: Object/Object3.h Object/Object.h

Object/Object4.o: Object/Object4.h Object/Object.h

Object/Object5.o: Object/Object5.h Object/Object.h

Object/Object6.o: Object/Object6.h Object/Object.h

Object/Object7.o: Object/Object7.h Object/Object.h

Object/Object8.o: Object/Object8.h Object/Object.h

clean:
	rm main *.o
	rm Feature/*.o
	rm Room/*.o
	rm Object/*.o
