decrypt: decrypt.o
	gcc -Wall decrypt.o -o decrypt 
decrypt.o: decrypt.c

test:test1 test2
test1:
	./cipher 1 5 data.txt data.out
	./decrypt data.out data.bak
	diff data.txt data.bak
test2:
	./cipher 1 5 test_page test_page.out 
	./decrypt test_page.out test_page.bak
	diff test_page test_page.bak

