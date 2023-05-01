test: test.o Node.o Set.o
	g++ -std=c++17 -Wall -Wextra -Werror test.o Node.o Set.o -o test

test.o: test.cpp
	g++ -std=c++17 -Wall -Wextra -Werror -c test.cpp

Node.o: Node.cpp
	g++ -std=c++17 -Wall -Wextra -Werror -c Node.cpp

Set.o: Set.cpp
	g++ -std=c++17 -Wall -Wextra -Werror -c Set.cpp

clean:
	rm -f *.o test