gcc -g -o myml ./src/lex.yy.c ./src/y.tab.c ./src/Table_des_symboles.c ./src/Table_des_chaines.c ./src/Attribut.c

./myml < $1
cc ./compiled/test.c -o ./build/testsOut
./build/testsOut
