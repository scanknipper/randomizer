ifdef MING
CXX= i686-w64-mingw32-g++.exe
LD= i686-w64-mingw32-g++.exe

endif

randomizer: main.o randomnamen.o copyfile.o
	$(CXX) -o randomizer main.o randomnamen.o copyfile.o


main.o: main.cpp
	$(CXX) -c -Wall main.cpp


randomnamen.o: randomnamen.cpp
	$(CXX) -c -Wall randomnamen.cpp

copyfile.o: copyfile.cpp
	$(CXX) -c -Wall copyfile.cpp



clean:
	rm *.o randomizer

        
