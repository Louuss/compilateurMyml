all		:	myml

./src/y.tab.h ./src/y.tab.c :	./src/myml.y
			bison -o ./src/y.tab.c -y  -d -v  ./src/myml.y
./src/lex.yy.c	:	./src/myml.l ./src/y.tab.h
			flex -o src/lex.yy.c ./src/myml.l


test: tests

tests: myml
	./myml < ./test/test.myml
	cc ./compiled/test.c -o ./build/testsOut
	./build/testsOut

myml		:	./src/lex.yy.c ./src/y.tab.c ./src/Table_des_symboles.c ./src/Table_des_chaines.c ./src/Attribut.c
			gcc -g -o myml ./src/lex.yy.c ./src/y.tab.c ./src/Table_des_symboles.c ./src/Table_des_chaines.c ./src/Attribut.c
clean		:
			rm -f 	./src/lex.yy.c ./src/*.o ./src/y.tab.h ./src/y.tab.c ./src/myml *~ ./src/y.output ./build/*
