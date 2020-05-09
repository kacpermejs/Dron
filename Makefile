CPPFLAGS= -c -g -Wall -Iinc -pedantic -std=c++17 

__start__: DronPodwodny
	./DronPodwodny

DronPodwodny: obj/Dr3D_gnuplot_api.o obj/main.o obj/UkladRownanLiniowych.o obj/Macierz.o obj/Wektor.o obj/LZespolona.o obj/AbsV.o obj/Classes.o
	g++ -o DronPodwodny  obj/main.o obj/Dr3D_gnuplot_api.o obj/Classes.o -lpthread\
						obj/Wektor.o\
						obj/Macierz.o obj/UkladRownanLiniowych.o\
						obj/LZespolona.o obj/AbsV.o

obj/main.o: src/main.cpp 	inc/Dr3D_gnuplot_api.hh inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh\
        					inc/rozmiar.h inc/LZespolona.hh inc/AbsV.hh inc/Classes.hh
	g++ ${CPPFLAGS} -o  obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/AbsV.o: src/AbsV.cpp inc/AbsV.hh
	g++ ${CPPFLAGS} -o obj/AbsV.o src/AbsV.cpp

obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh
	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/UkladRownanLiniowych.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Classes.o: src/Classes.cpp inc/Classes.hh
	g++ ${CPPFLAGS} -o obj/Classes.o src/Classes.cpp

clear:
	rm obj/*.o DronPodwodny