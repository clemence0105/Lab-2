all: main.cpp bigClass.cpp bNum.cpp
	g++ -c -fPIC bigClass.cpp bNum.cpp
	g++ -shared -o libbigClass.so bigClass.o bNum.o
	LD_LIBRARY_PATH=./ g++ main.cpp -lbigClass -I. -Wl,-rpath,. -L. -o TCHMK_2
	rm *.o