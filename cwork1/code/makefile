test0:main.c
	gcc main.c -o test0 ./libcwork.so -L. -lcworklib
main.o: main.c
	gcc main.c -c
menu.o: menu.c
	gcc menu.c -c
newfile.o: menu.c
	gcc newfile.c -c
writefile_1.o: writefile_1.c
	gcc writefile_1.c -c
readfile.o: readfile.c
	gcc readfile.c -c
modifyfile.o: modifyfile.c
	gcc modifyfile.c -c
viewfile.o: viewfile.c
	gcc viewfile.c -c
message.o: message.c
	gcc message.c -c
clean:
	-rm -rf *.o
