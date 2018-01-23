all: count.c count.h
	gcc count.c -lm -o count

clean:
	rm ./count ./*.o