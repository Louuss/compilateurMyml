/*
 *  Attribut.h
 *
 *  Module for handling attributes
 *
 */

#ifndef ATTRIBUT_H
#define ATTRIBUT_H
#include <stdbool.h>
#include <stdio.h>


FILE * test_c;
FILE * test_h;


typedef enum {Int, Float} symb_type ;

typedef struct{
int value;
float valf; 
symb_type type;
char* sid ;
int reg ;
int more;
int usereg;
char* op;
} symb_value_type;

char* getType(symb_type);

int comp(int g, int d, int op);
static int ifCounter=0;
static int currentIfResultReg;
int branch(int b, int t, int e);

int newReg();
int getCurrentReg();

void affecter(symb_value_type id, symb_value_type value);
void effectuerPlus(symb_value_type un, symb_value_type trois);

#endif
