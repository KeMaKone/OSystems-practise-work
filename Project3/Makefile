CFLAGS = -g -Wall -Werror

make: wish.o wishPrints.o
	gcc wish.o wishPrints.o $(CFLAGS) -o wish

wish.o: wish.c wish.h
	gcc -c wish.c $(CFLAGS)

wishPrints.o : wishPrints.c wish.h
	gcc -c wishPrints.c $(CFLAGS)

clean:
	rm *.o