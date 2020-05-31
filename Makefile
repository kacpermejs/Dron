CPPFLAGS= -c -g -Wall -Iinc -pedantic -std=c++17 
OBJ=./obj
__start__: DronPodwodny
	./DronPodwodny

DronPodwodny: 	${OBJ} ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/main.o ${OBJ}/Macierz.o ${OBJ}/Wektor.o ${OBJ}/Przeszkoda.o\
				${OBJ}/MacierzOb.o ${OBJ}/InterfejsRysowania.o ${OBJ}/Bryla.o ${OBJ}/Prostopadloscian.o ${OBJ}/Graniastoslup6.o ${OBJ}/Dron.o ${OBJ}/InterfejsDrona.o\
				${OBJ}/Plaszczyzna.o ${OBJ}/Dno.o ${OBJ}/Tafla.o ${OBJ}/PrzeszkodaProst.o ${OBJ}/Sruba.o  ${OBJ}/LZespolona.o  ${OBJ}/AbsV.o 
				
	g++ -o DronPodwodny ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o -lpthread\
						${OBJ}/Wektor.o ${OBJ}/Macierz.o\
						${OBJ}/Przeszkoda.o\
						${OBJ}/MacierzOb.o ${OBJ}/InterfejsRysowania.o ${OBJ}/Bryla.o ${OBJ}/Prostopadloscian.o ${OBJ}/Graniastoslup6.o ${OBJ}/Dron.o ${OBJ}/InterfejsDrona.o\
						${OBJ}/Plaszczyzna.o ${OBJ}/Dno.o ${OBJ}/Tafla.o ${OBJ}/PrzeszkodaProst.o ${OBJ}/Sruba.o ${OBJ}/LZespolona.o  ${OBJ}/AbsV.o 

${OBJ}:
		mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp 	inc/Dr3D_gnuplot_api.hh inc/Macierz.hh inc/Wektor.hh\
        					inc/rozmiar.h inc/Przeszkoda.hh inc/Dno.hh inc/Tafla.hh inc/PrzeszkodaProst.hh\
							inc/MacierzOb.hh inc/InterfejsRysowania.hh inc/Bryla.hh inc/Prostopadloscian.hh inc/Dron.hh inc/InterfejsDrona.hh inc/Graniastoslup6.hh\
							inc/Plaszczyzna.hh inc/Sruba.hh inc/LZespolona.hh inc/AbsV.hh
	g++ ${CPPFLAGS} -o  ${OBJ}/main.o src/main.cpp

${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/AbsV.o: src/AbsV.cpp inc/AbsV.hh
	g++ ${CPPFLAGS} -o ${OBJ}/AbsV.o src/AbsV.cpp

${OBJ}/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Przeszkoda.o src/Przeszkoda.cpp

${OBJ}/Macierz.o: src/Macierz.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o ${OBJ}/Macierz.o src/Macierz.cpp

${OBJ}/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h inc/LZespolona.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Wektor.o src/Wektor.cpp

${OBJ}/MacierzOb.o: src/MacierzOb.cpp inc/MacierzOb.hh
	g++ ${CPPFLAGS} -o ${OBJ}/MacierzOb.o src/MacierzOb.cpp

${OBJ}/InterfejsRysowania.o: src/InterfejsRysowania.cpp inc/InterfejsRysowania.hh
	g++ ${CPPFLAGS} -o ${OBJ}/InterfejsRysowania.o src/InterfejsRysowania.cpp

${OBJ}/Bryla.o: src/Bryla.cpp inc/Bryla.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Bryla.o src/Bryla.cpp

${OBJ}/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Prostopadloscian.o src/Prostopadloscian.cpp

${OBJ}/Graniastoslup6.o: src/Graniastoslup6.cpp inc/Graniastoslup6.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Graniastoslup6.o src/Graniastoslup6.cpp

${OBJ}/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dron.o src/Dron.cpp

${OBJ}/InterfejsDrona.o: src/InterfejsDrona.cpp inc/InterfejsDrona.hh
	g++ ${CPPFLAGS} -o ${OBJ}/InterfejsDrona.o src/InterfejsDrona.cpp

${OBJ}/Plaszczyzna.o: src/Plaszczyzna.cpp inc/Plaszczyzna.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Plaszczyzna.o src/Plaszczyzna.cpp

${OBJ}/Dno.o: src/Dno.cpp inc/Dno.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dno.o src/Dno.cpp

${OBJ}/Tafla.o: src/Tafla.cpp inc/Tafla.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Tafla.o src/Tafla.cpp

${OBJ}/PrzeszkodaProst.o: src/PrzeszkodaProst.cpp inc/PrzeszkodaProst.hh
	g++ ${CPPFLAGS} -o ${OBJ}/PrzeszkodaProst.o src/PrzeszkodaProst.cpp

${OBJ}/Sruba.o: src/Sruba.cpp inc/Sruba.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Sruba.o src/Sruba.cpp

clear:
	rm ${OBJ}/*.o DronPodwodny