lattice_search: raycross.cpp stlread.o generateray.o intersection.o
	g++ raycross.cpp stlread.cpp generateray.cpp intersection.cpp -o lattice_search

stlread.o: stlread.cpp
	g++ -c stlread.cpp

generateray.o: generateray.cpp
	g++ -c generateray.cpp

intersection.o: intersection.cpp
	g++ -c intersection.cpp

clean:
	rm *.o lattice_search

