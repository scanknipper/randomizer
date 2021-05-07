randomizer: main.o randomnamen.o copyfile.o
	g++ -o randomizer main.o randomnamen.o copyfile.o


main.o: main.cpp
	g++ -c -Wall main.cpp


randomnamen.o: randomnamen.cpp
	g++ -c -Wall randomnamen.cpp

copyfile.o: copyfile.cpp
	g++ -c -Wall copyfile.cpp



clean:
	rm *.o randomizer

        
