CPPFLAGS= -c -g -Wall -Iinc -pedantic -std=c++17 
OBJ=./obj
__start__: DronPodwodny
	./DronPodwodny

DronPodwodny: 	${OBJ} ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/main.o ${OBJ}/UkladRownanLiniowych.o ${OBJ}/Macierz.o ${OBJ}/Wektor.o ${OBJ}/LZespolona.o ${OBJ}/AbsV.o\
				${OBJ}/MacierzOb.o ${OBJ}/InterfejsRysowania.o ${OBJ}/Bryla.o ${OBJ}/Prostopadloscian.o ${OBJ}/Graniastoslup6.o ${OBJ}/Dron.o ${OBJ}/InterfejsDrona.o
				
	g++ -o DronPodwodny ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o -lpthread\
						${OBJ}/Wektor.o ${OBJ}/Macierz.o ${OBJ}/UkladRownanLiniowych.o\
						${OBJ}/LZespolona.o ${OBJ}/AbsV.o\
						${OBJ}/MacierzOb.o ${OBJ}/InterfejsRysowania.o ${OBJ}/Bryla.o ${OBJ}/Prostopadloscian.o ${OBJ}/Graniastoslup6.o ${OBJ}/Dron.o ${OBJ}/InterfejsDrona.o

${OBJ}:
		mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp 	inc/Dr3D_gnuplot_api.hh inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh\
        					inc/rozmiar.h inc/LZespolona.hh inc/AbsV.hh\
							inc/MacierzOb.hh inc/InterfejsRysowania.hh inc/Bryla.hh inc/Prostopadloscian.hh inc/Dron.hh inc/InterfejsDrona.hh inc/Graniastoslup6.hh
	g++ ${CPPFLAGS} -o  ${OBJ}/main.o src/main.cpp

${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/AbsV.o: src/AbsV.cpp inc/AbsV.hh
	g++ ${CPPFLAGS} -o ${OBJ}/AbsV.o src/AbsV.cpp

${OBJ}/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh
	g++ ${CPPFLAGS} -o ${OBJ}/UkladRownanLiniowych.o src/UkladRownanLiniowych.cpp

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

clear:
	rm ${OBJ}/*.o DronPodwodny