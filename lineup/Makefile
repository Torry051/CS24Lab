lineup: main.o Database.o 
	g++ main.o Database.o -o lineup

main.o: main.cpp
	g++ main.cpp -std=c++17 -Werror -Wall -c

Database.o: Database.cpp
	g++ Database.cpp -std=c++17 -Werror -Wall -c

clean:
	rm -f *.o
	rm -f lineup

#./lineup -i data/simple.tsv
#./lineup -i data/1000000reports.txt
#./lineup data/1000000reports.txt
#./quickgen.py 1000000 reports > 1000000reports.txt

