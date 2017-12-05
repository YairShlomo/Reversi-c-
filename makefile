# Name:Yair Shlomo
# ID: 308536150
# Name:Gal Eini
# ID: 305216962


a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: include/*.h src/*.cpp
	g++ -Iinclude/ -c src/*.cpp
