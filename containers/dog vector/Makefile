objects = human.o dog.o kennel.o airport.o

animals: $(objects)
	g++ -o animals $(objects)

airport.o: human.h dog.h kennel.h
kennel.o: kennel.h dog.h 
human.o: human.h
dog.o: dog.h

.PHONY: clean
clean:
	rm animals $(objects)

