test: Dictionary.o main.o
	g++ Dictionary.o main.o -o test

main.o: main.cpp
	g++ -Werror -Wall -O3 -std=c++17 main.cpp -c
	
Dictionary.o: Dictionary.cpp
	g++ -Werror -Wall -O3 -std=c++17 Dictionary.cpp -c

clean:
	rm -f test
	rm -f *.o

# ./test data/3.txt